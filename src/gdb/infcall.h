/* infcall.h: Perform an inferior function call, for GDB, the GNU debugger.

   Copyright 2003 Free Software Foundation, Inc.

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

#ifndef INFCALL_H
#define INFCALL_H

struct value;
struct type;

extern ptid_t get_hand_call_ptid(void);

extern CORE_ADDR find_function_addr(struct value *function,
				    struct type **retval_type);

extern struct value *
/* APPLE LOCAL hand function call */
hand_function_call(struct value *function, struct type *expect_type,
                   int nargs, struct value **args, int restore_frame);

/* Perform a function call in the inferior.

   ARGS is a vector of values of arguments (NARGS of them).  FUNCTION
   is a value, the function to be called.  Returns a value
   representing what the function returned.  May fail to return, if a
   breakpoint or signal is hit during the execution of the function.

   ARGS is modified to contain coerced values. */

extern struct value *call_function_by_hand(struct value *function, int nargs,
					   struct value **args);

/* APPLE LOCAL */
extern int inferior_function_calls_disabled_p;
int set_hand_function_call_timeout(int newval);
int hand_function_call_timeout_p(void);

/* */
extern int objc_exceptions_interrupt_hand_call;
extern ptid_t hand_call_ptid;
extern int unwind_on_signal_p;

#endif /* !INFCALL_H */

/* EOF */
