/* The IGEN simulator generator for GDB, the GNU Debugger.

   Copyright 2002 Free Software Foundation, Inc.

   Contributed by Andrew Cagney.

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

/* Output a table of all the instructions */

extern void gen_itable_h (lf *file, insn_table *table);

extern void gen_itable_c (lf *file, insn_table *table);

/* EOF */
