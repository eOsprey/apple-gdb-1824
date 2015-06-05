/* mkstemps.c
   Copyright (C) 1991-1992, 1996, 1998, 2004 Free Software Foundation, Inc.
   This file is derived from mkstemp.c from the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public License as
   published by the Free Software Foundation; either version 2 of the
   License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public
   License along with the GNU C Library; see the file COPYING.LIB.  If not,
   write to the Free Software Foundation, Inc., 51 Franklin St., 5th Floor,
   Boston, MA 02110-1301, USA.  */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif /* HAVE_CONFIG_H */

#include <sys/types.h>
#ifdef HAVE_STDLIB_H
# include <stdlib.h>
#endif /* HAVE_STDLIB_H */
#ifdef HAVE_STRING_H
# include <string.h>
#endif /* HAVE_STRING_H */
#include <errno.h>
#include <stdio.h>
#include <fcntl.h>
#ifdef HAVE_UNISTD_H
# include <unistd.h>
#endif /* HAVE_UNISTD_H */
#ifdef HAVE_SYS_TIME_H
# include <sys/time.h>
#else
# ifdef HAVE_TIME_H
#  include <time.h>
# endif /* HAVE_TIME_H */
#endif /* HAVE_SYS_TIME_H */
#include "ansidecl.h"

/* We need to provide a type for gcc_uint64_t.  */
#ifdef __GNUC__
__extension__ typedef unsigned long long gcc_uint64_t;
#else
typedef unsigned long gcc_uint64_t;
#endif /* __GNUC__ */

#ifndef TMP_MAX
# define TMP_MAX 16384
#endif /* !TMP_MAX */

/*

@deftypefn Replacement int mkstemps (char *@var{pattern}, int @var{suffix_len})

Generate a unique temporary file name from @var{pattern}.
@var{pattern} has the form:

@example
   @var{path}/ccXXXXXX@var{suffix}
@end example

@var{suffix_len} tells us how long @var{suffix} is (it can be zero
length).  The last six characters of @var{pattern} before @var{suffix}
must be @samp{XXXXXX}; they are replaced with a string that makes the
filename unique.  Returns a file descriptor open on the file for
reading and writing.

@end deftypefn

*/

int
mkstemps (char *pattern, int suffix_len)
{
  static const char letters[]
    = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
  static gcc_uint64_t value;
#ifdef HAVE_GETTIMEOFDAY
  struct timeval tv;
#endif /* HAVE_GETTIMEOFDAY */
  char *XXXXXX;
  size_t len;
  int count;

  len = strlen (pattern);

  if ((int) len < 6 + suffix_len
      || strncmp (&pattern[len - 6 - suffix_len], "XXXXXX", 6))
    {
      return -1;
    }

  XXXXXX = &pattern[len - 6 - suffix_len];

#ifdef HAVE_GETTIMEOFDAY
  /* Get some more or less random data.  */
  gettimeofday (&tv, NULL);
  value += ((gcc_uint64_t) tv.tv_usec << 16) ^ tv.tv_sec ^ getpid ();
#else
  value += getpid ();
#endif /* HAVE_GETTIMEOFDAY */

  for (count = 0; count < TMP_MAX; ++count)
    {
      gcc_uint64_t v = value;
      int fd;

      /* Fill in the random bits.  */
      XXXXXX[0] = letters[v % 62];
      v /= 62;
      XXXXXX[1] = letters[v % 62];
      v /= 62;
      XXXXXX[2] = letters[v % 62];
      v /= 62;
      XXXXXX[3] = letters[v % 62];
      v /= 62;
      XXXXXX[4] = letters[v % 62];
      v /= 62;
      XXXXXX[5] = letters[v % 62];

      fd = open (pattern, O_RDWR|O_CREAT|O_EXCL, 0600);
      if (fd >= 0)
	/* The file does not exist.  */
	return fd;

      /* This is a "random" value.  It is only necessary that the next
	 TMP_MAX values generated by adding 7777 to VALUE are different
	 with (module 2^32).  */
      value += 7777;
    }

  /* We return the null string if we cannot find a unique file name: */
  pattern[0] = '\0';
  return -1;
}

/* EOF */
