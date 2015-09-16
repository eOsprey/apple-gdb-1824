/* xm-ptx.h
   Definitions to make GDB run on a Sequent Symmetry under ptx, with
   Weitek 1167 and i387 support.
   Copyright 1986, 1987, 1989, 1992, 1993, 1994, 1995
   Free Software Foundation, Inc.

   This file is part of GDB.

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
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* Symmetry version by Jay Vosburgh (fubar@sequent.com) */

#ifdef _SEQUENT_PTX4_
#include "config/xm-sysv4.h"
#endif /* _SEQUENT_PTX4_ */

/* This machine doesn't have the siginterrupt call.  */
#define NO_SIGINTERRUPT

#define HAVE_WAIT_STRUCT

#undef HAVE_TERMIO
#define HAVE_TERMIOS
#define USG

#define USE_O_NOCTTY
