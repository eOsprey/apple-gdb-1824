/* cf-i386lynx.c: BFD back-end for Intel 386 COFF LynxOS files.
 * Copyright 1993, 1994, 1995 Free Software Foundation, Inc.
 * Written by Cygnus Support. */
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
Foundation, Inc., 51 Franklin St., 5th Floor, Boston, MA 02110-1301, USA.
 */

#include "bfd.h"
#include "sysdep.h"

#define TARGET_SYM  i386lynx_coff_vec
#define TARGET_NAME "coff-i386-lynx"

#define LYNXOS /* (nothing) */

#define COFF_LONG_FILENAMES /* (nothing) */

#include "coff-i386.c"

/* EOF */
