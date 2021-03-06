/* explodename.c
   Copyright (C) 1995, 1996, 1997, 1998 Free Software Foundation, Inc.
   Contributed by Ulrich Drepper <drepper@gnu.ai.mit.edu>, 1995.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation,
   Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */

#ifdef HAVE_CONFIG_H
# include "config.h"
#else
# if defined(__GNUC__) && !defined(__STRICT_ANSI__)
#  warning explodename.c expects "config.h" to be included.
# endif /* __GNUC__ && !__STRICT_ANSI__ */
#endif /* HAVE_CONFIG_H */

#if defined STDC_HEADERS || defined _LIBC || defined HAVE_STDLIB_H
# include <stdlib.h>
#else
# if defined(__GNUC__) && !defined(__STRICT_ANSI__)
#  warning "explodename.c expects <stdlib.h> to be included."
# endif /* __GNUC__ && !__STRICT_ANSI__ */
#endif /* HAVE_STDLIB_H */

#if defined HAVE_STRING_H || defined _LIBC
# include <string.h>
#else
# if defined HAVE_STRINGS_H
#  include <strings.h>
# else
#  if defined(__GNUC__) && !defined(__STRICT_ANSI__)
#   warning "explodename.c expects either <string.h> or <strings.h> to be included."
#  endif /* __GNUC__ && !__STRICT_ANSI__ */
# endif /* HAVE_STRINGS_H */
#endif /* HAVE_STRING_H || _LIBC */

#ifdef HAVE_SYS_TYPES_H
# include <sys/types.h>
#else
# if defined(__GNUC__) && !defined(__STRICT_ANSI__)
#  warning "explodename.c expects <sys/types.h> to be included."
# endif /* __GNUC__ && !__STRICT_ANSI__ */
#endif /* HAVE_SYS_TYPES_H */

#include "loadinfo.h"

/* On some strange systems still no definition of NULL is found. Sigh! */
#ifndef NULL
# if defined __STDC__ && __STDC__
#  define NULL ((void *)0)
# else
#  define NULL 0
# endif /* __STDC__ && __STDC__ */
#endif /* !NULL */

/* @@ end of prolog @@ */

int _nl_explode_name(char *name, const char **language,
                     const char **modifier, const char **territory,
                     const char **codeset, const char **normalized_codeset,
                     const char **special, const char **sponsor,
                     const char **revision)
{
  enum { undecided, xpg, cen } syntax;
  char *cp;
  int mask;

  *modifier = NULL;
  *territory = NULL;
  *codeset = NULL;
  *normalized_codeset = NULL;
  *special = NULL;
  *sponsor = NULL;
  *revision = NULL;

  /* Now we determine the single parts of the locale name.  First
     look for the language.  Termination symbols are `_' and `@' if
     we use XPG4 style, and `_', `+', and `,' if we use CEN syntax.  */
  mask = 0;
  syntax = undecided;
  *language = cp = name;
  while (cp[0] != '\0' && cp[0] != '_' && cp[0] != '@'
	 && cp[0] != '+' && cp[0] != ',')
    ++cp;

  if (*language == cp) {
    /* This does not make sense: language has to be specified. Use
     * this entry as it is without exploding. Perhaps it is an alias: */
    cp = strchr(*language, '\0');
  } else if (cp[0] == '_') {
      /* Next is the territory.  */
      cp[0] = '\0';
      *territory = ++cp;

      while ((cp[0] != '\0') && (cp[0] != '.') && (cp[0] != '@')
	     && (cp[0] != '+') && (cp[0] != ',') && (cp[0] != '_')) {
	++cp;
      }

      mask |= TERRITORY;

      if (cp[0] == '.') {
	  /* Next is the codeset: */
	  syntax = xpg;
	  cp[0] = '\0';
	  *codeset = ++cp;

	  while ((cp[0] != '\0') && (cp[0] != '@')) {
	    ++cp;
          }

	  mask |= XPG_CODESET;

	  if ((*codeset != cp) && ((*codeset)[0] != '\0')) {
	      *normalized_codeset =
                _nl_normalize_codeset((const unsigned char *)*codeset,
                                      (size_t)(cp - *codeset));
	      if (strcmp(*codeset, *normalized_codeset) == 0) {
		free((char *)*normalized_codeset);
	      } else {
		mask |= XPG_NORM_CODESET;
              }
          }
      }
  }

  if ((cp[0] == '@') || ((syntax != xpg) && (cp[0] == '+'))) {
      /* Next is the modifier: */
      syntax = ((cp[0] == '@') ? xpg : cen);
      cp[0] = '\0';
      *modifier = ++cp;

      while ((syntax == cen) && (cp[0] != '\0') && (cp[0] != '+')
	     && (cp[0] != ',') && (cp[0] != '_')) {
	++cp;
      }

      mask |= (XPG_MODIFIER | CEN_AUDIENCE);
  }

  if ((syntax != xpg) &&
      ((cp[0] == '+') || (cp[0] == ',') || (cp[0] == '_'))) {
      syntax = cen;

      if (cp[0] == '+') {
 	  /* Next is special application (CEN syntax): */
	  cp[0] = '\0';
	  *special = ++cp;

	  while ((cp[0] != '\0') && (cp[0] != ',') && (cp[0] != '_')) {
	    ++cp;
          }

	  mask |= CEN_SPECIAL;
      }

      if (cp[0] == ',') {
 	  /* Next is sponsor (CEN syntax): */
	  cp[0] = '\0';
	  *sponsor = ++cp;

	  while ((cp[0] != '\0') && (cp[0] != '_')) {
	    ++cp;
          }

	  mask |= CEN_SPONSOR;
      }

      if (cp[0] == '_') {
 	  /* Next is revision (CEN syntax): */
	  cp[0] = '\0';
	  *revision = ++cp;

	  mask |= CEN_REVISION;
      }
  }

  /* For CEN syntax values it might be important to have the
   * separator character in the file name, not for XPG syntax: */
  if (syntax == xpg) {
      if ((*territory != NULL) && ((*territory)[0] == '\0')) {
	mask &= ~TERRITORY;
      }
      if ((*codeset != NULL) && ((*codeset)[0] == '\0')) {
	mask &= ~XPG_CODESET;
      }
      if ((*modifier != NULL) && ((*modifier)[0] == '\0')) {
	mask &= ~XPG_MODIFIER;
      }
  }

  return mask;
}

/* EOF */
