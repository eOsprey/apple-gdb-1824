/* ptrace-core.c: BFD backend for core files using the ptrace_user struct
 * Copyright 1993, 1994, 1995, 1996, 1998, 1999, 2001, 2002, 2003, 2004
 * Free Software Foundation, Inc.
 * The structure of this file is based on trad-core.c, which was written
 * by John Gilmore of Cygnus Support.
 * Modified to work with the ptrace_user structure by Kevin A. Buettner.
 * (Longterm it may be better to merge this file with trad-core.c)  */
/*
This file is part of BFD, the Binary File Descriptor library.

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin St., 5th Floor, Boston, MA 02110-1301, USA */

#ifdef PTRACE_CORE

#include "bfd.h"
#include "sysdep.h"
#include "libbfd.h"

#include <sys/param.h>
#include <sys/dir.h>
#include <signal.h>
#include <sys/ptrace.h>

struct trad_core_struct
  {
    asection *data_section;
    asection *stack_section;
    asection *reg_section;
    struct ptrace_user u;
  };

#ifndef core_upage
# define core_upage(bfd) (&((bfd)->tdata.trad_core_data->u))
#endif /* !core_upage */
#define core_datasec(bfd) ((bfd)->tdata.trad_core_data->data_section)
#define core_stacksec(bfd) ((bfd)->tdata.trad_core_data->stack_section)
#define core_regsec(bfd) ((bfd)->tdata.trad_core_data->reg_section)

/* forward declarations */

const bfd_target *ptrace_unix_core_file_p PARAMS((bfd *abfd));
char *ptrace_unix_core_file_failing_command PARAMS((bfd *abfd));
int ptrace_unix_core_file_failing_signal PARAMS((bfd *abfd));
bfd_boolean ptrace_unix_core_file_matches_executable_p
  PARAMS((bfd *core_bfd, bfd *exec_bfd));
static void swap_abort PARAMS((void));

const bfd_target *
ptrace_unix_core_file_p(bfd *abfd)
{
  int val;
  struct ptrace_user u;
  struct trad_core_struct *rawptr;
  bfd_size_type amt;

  val = bfd_bread((void *)&u, (bfd_size_type)sizeof(u), abfd);
  if ((val != sizeof(u)) || (u.pt_magic != _BCS_PTRACE_MAGIC)
      || (u.pt_rev != _BCS_PTRACE_REV))
    {
      /* Too small to be a core file: */
      bfd_set_error(bfd_error_wrong_format);
      return 0;
    }

  /* OK, we believe you.  You are a core file (sure, sure).  */

  /* Allocate both the upage and the struct core_data at once, so
     a single free() will free them both.  */
  amt = sizeof(struct trad_core_struct);
  rawptr = (struct trad_core_struct *)bfd_zalloc(abfd, amt);

  if (rawptr == NULL)
    return 0;

  abfd->tdata.trad_core_data = rawptr;

  rawptr->u = u; /* Copy the uarea into the tdata part of the bfd */

  /* Create the sections: */
  core_stacksec(abfd) = bfd_make_section_anyway(abfd, ".stack");
  if (core_stacksec(abfd) == NULL)
    goto fail;
  core_datasec(abfd) = bfd_make_section_anyway(abfd, ".data");
  if (core_datasec(abfd) == NULL)
    goto fail;
  core_regsec(abfd) = bfd_make_section_anyway(abfd, ".reg");
  if (core_regsec(abfd) == NULL)
    goto fail;

  /* FIXME:  Need to worry about shared memory, library data, and library
     text.  I do NOT think that any of these things are supported on the
     system on which I am developing this for though.  */

  core_stacksec(abfd)->flags = (SEC_ALLOC + SEC_LOAD + SEC_HAS_CONTENTS);
  core_datasec(abfd)->flags = (SEC_ALLOC + SEC_LOAD + SEC_HAS_CONTENTS);
  core_regsec(abfd)->flags = SEC_HAS_CONTENTS;

  core_datasec(abfd)->size =  u.pt_dsize;
  core_stacksec(abfd)->size = u.pt_ssize;
  core_regsec(abfd)->size = sizeof(u);

  core_datasec(abfd)->vma = u.pt_o_data_start;
  core_stacksec(abfd)->vma = (USRSTACK - u.pt_ssize);
  core_regsec(abfd)->vma = (0UL - sizeof(u));	/* see trad-core.c */

  core_datasec(abfd)->filepos = (int)u.pt_dataptr;
  core_stacksec(abfd)->filepos = (int)(u.pt_dataptr + u.pt_dsize);
  core_regsec(abfd)->filepos = 0; /* Register segment is ptrace_user */

  /* Align to word at least: */
  core_stacksec(abfd)->alignment_power = 2;
  core_datasec(abfd)->alignment_power = 2;
  core_regsec(abfd)->alignment_power = 2;

  return abfd->xvec;

 fail:
  bfd_release(abfd, abfd->tdata.any);
  abfd->tdata.any = NULL;
  bfd_section_list_clear(abfd);
  return NULL;
}

char *
ptrace_unix_core_file_failing_command(bfd *abfd)
{
  char *com = abfd->tdata.trad_core_data->u.pt_comm;
  if (*com)
    return com;
  else
    return 0;
}

int
ptrace_unix_core_file_failing_signal(bfd *abfd)
{
  return abfd->tdata.trad_core_data->u.pt_sigframe.sig_num;
}

bfd_boolean
ptrace_unix_core_file_matches_executable_p(bfd *core_bfd, bfd *exec_bfd)
{
  /* FIXME: Use pt_timdat field of the ptrace_user structure to match
     the date of the executable */
  return TRUE;
}

/* If somebody calls any byte-swapping routines, then shoot them: */
static void ATTRIBUTE_NORETURN
swap_abort(void)
{
  /* This way does NOT require any declaration for ANSI to mess up (?) */
  abort();
}

#define	NO_GET ((bfd_vma (*)(const void *))swap_abort)
#define	NO_PUT ((void (*)(bfd_vma, void *))swap_abort)
#define	NO_GETS ((bfd_signed_vma (*)(const void *))swap_abort)
#define	NO_GET64 ((bfd_uint64_t (*)(const void *))swap_abort)
#define	NO_PUT64 ((void (*)(bfd_uint64_t, void *))swap_abort)
#define	NO_GETS64 ((bfd_int64_t (*)(const void *))swap_abort)

const bfd_target ptrace_core_vec =
  {
    "trad-core",
    bfd_target_unknown_flavour,
    BFD_ENDIAN_UNKNOWN,		/* target byte order */
    BFD_ENDIAN_UNKNOWN,		/* target headers byte order */
    (HAS_RELOC | EXEC_P |	/* object flags */
     HAS_LINENO | HAS_DEBUG |
     HAS_SYMS | HAS_LOCALS | WP_TEXT | D_PAGED),
    (SEC_HAS_CONTENTS | SEC_ALLOC | SEC_LOAD | SEC_RELOC), /* section flags */
    0,			                                /* symbol prefix */
    ' ',						  /* ar_pad_char */
    16,						/* ar_max_namelen */
    NO_GET64, NO_GETS64, NO_PUT64,	/* 64 bit data */
    NO_GET, NO_GETS, NO_PUT,		/* 32 bit data */
    NO_GET, NO_GETS, NO_PUT,		/* 16 bit data */
    NO_GET64, NO_GETS64, NO_PUT64,	/* 64 bit hdrs */
    NO_GET, NO_GETS, NO_PUT,		/* 32 bit hdrs */
    NO_GET, NO_GETS, NO_PUT,		/* 16 bit hdrs */

    {				/* bfd_check_format */
      _bfd_dummy_target,		/* unknown format */
      _bfd_dummy_target,		/* object file */
      _bfd_dummy_target,		/* archive */
      ptrace_unix_core_file_p		/* a core file */
    },
    {				/* bfd_set_format */
      bfd_false, bfd_false,
      bfd_false, bfd_false
    },
    {				/* bfd_write_contents */
      bfd_false, bfd_false,
      bfd_false, bfd_false
    },

    BFD_JUMP_TABLE_GENERIC(_bfd_generic),
    BFD_JUMP_TABLE_COPY(_bfd_generic),
    BFD_JUMP_TABLE_CORE(ptrace_unix),
    BFD_JUMP_TABLE_ARCHIVE(_bfd_noarchive),
    BFD_JUMP_TABLE_SYMBOLS(_bfd_nosymbols),
    BFD_JUMP_TABLE_RELOCS(_bfd_norelocs),
    BFD_JUMP_TABLE_WRITE(_bfd_generic),
    BFD_JUMP_TABLE_LINK(_bfd_nolink),
    BFD_JUMP_TABLE_DYNAMIC(_bfd_nodynamic),

    NULL,

    (PTR)0			/* backend_data */
  };

#ifdef core_upage
# undef core_upage
#endif /* core_upage */

#else
/* Prevent file from being empty: */
typedef int ptrace_core_c_dummy_t;
extern ptrace_core_c_dummy_t ptrace_core_c_dummy_var;
#endif /* PTRACE_CORE */

/* EOF */
