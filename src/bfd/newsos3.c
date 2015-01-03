/* newsos3.c: BFD back-end for NewsOS3 (Sony, 68k) binaries.
 * Copyright 1990, 1991, 1994, 1995, 2000, 2001, 2003
 * Free Software Foundation, Inc.  */
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

#define	TARGET_PAGE_SIZE	4096
#define	SEGMENT_SIZE	TARGET_PAGE_SIZE
#define TEXT_START_ADDR 0

/* Do not "beautify" the CONCAT* macro args.  Traditional C will not
 * remove whitespace added here, and thus will fail to concatenate
 * the tokens.  */
#define MY(OP) CONCAT2 (newsos3_,OP)
#define TARGETNAME "a.out-newsos3"
#define ENTRY_CAN_BE_ZERO
#define N_SHARED_LIB(x) 0 /* Avoids warning when compiled with -Wall.  */
#define DEFAULT_ARCH bfd_arch_m68k
#define TARGET_IS_BIG_ENDIAN_P
#define N_HEADER_IN_TEXT(x) 0

#ifndef A_OUT_NEWSOS_THREE_C
# define A_OUT_NEWSOS_THREE_C 3
#endif /* !A_OUT_NEWSOS_THREE_C */

/* this needs to go after the usage of the CONCAT* macro mentioned above,
 * but before any other headers are included, or prototypes for functions
 * are declared: */
#if defined(__GNUC__) && (__GNUC__ >= 4)
 # pragma GCC diagnostic ignored "-Wtraditional"
#endif /* gcc 4+ */

#include "bfd.h"
#include "sysdep.h"
#include "libbfd.h"
#include "aout/aout64.h"
#include "aout/stab_gnu.h"
#include "aout/ar.h"
#include "libaout.h"           /* BFD a.out internal data structures */

#include "aout-target.h"

/* EOF */
