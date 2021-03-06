/* hash-string.h
   Implements a string hashing function.
   Copyright (C) 1995, 1997 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU Library General Public
   License along with the GNU C Library; see the file COPYING.LIB.  If not,
   write to the Free Software Foundation, 51 Franklin Street - 5th Floor,
   Boston, MA 02110-1301, USA.  */

/* @@ end of prolog @@ */

#ifndef PARAMS
# if __STDC__ || defined __GNUC__ || defined __SUNPRO_C || defined __cplusplus || __PROTOTYPES
#  define PARAMS(Args) Args
# else
#  define PARAMS(Args) ()
# endif /* __STDC__ */
#endif /* !PARAMS */

/* We assume to have `unsigned long int' value with at least 32 bits: */
#define HASHWORDBITS 32


/* Defines the so-called `hashpjw' function by P.J. Weinberger
   [see Aho/Sethi/Ullman, COMPILERS: Principles, Techniques and Tools,
   1986, 1987 Bell Telephone Laboratories, Inc.]  */
static unsigned long hash_string PARAMS((const char *__str_param));

static
#if !defined(__STRICT_ANSI__)
inline
#endif /* !__STRICT_ANSI__ */
unsigned long hash_string(const char *str_param)
{
  unsigned long int hval, g;
  const char *str = str_param;

  /* Compute the hash value for the given string: */
  hval = 0;
  while (*str != '\0') {
      hval <<= 4;
      hval += (unsigned long)*str++;
      g = (hval & ((unsigned long)0xf << (HASHWORDBITS - 4)));
      if (g != 0) {
	  hval ^= (g >> (HASHWORDBITS - 8));
	  hval ^= g;
      }
  }
  return hval;
}

/* EOF */
