/* bsd-uthread.h: BSD user-level threads support.

   Copyright 2005 Free Software Foundation, Inc.

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

#ifndef BSD_UTHREAD_H
#define BSD_UTHREAD_H 1

struct so_list; /* Forward declaration. */

/* Set the function that supplies registers for an inactive thread for
   architecture GDBARCH to SUPPLY_UTHREAD.  */

extern void bsd_uthread_set_supply_uthread(struct gdbarch *gdbarch,
				    void (*supply_uthread)(struct regcache *,
							   int, CORE_ADDR));


/* Set the function that collects registers for an inactive thread for
   architecture GDBARCH to SUPPLY_UTHREAD.  */

extern void bsd_uthread_set_collect_uthread(struct gdbarch *gdbarch,
			     void (*collect_uthread)(const struct regcache *,
						     int, CORE_ADDR));

/* */
extern void bsd_uthread_inferior_created(struct target_ops *ops, int from_tty);
extern void bsd_uthread_solib_loaded(struct so_list *so);
extern void bsd_uthread_solib_unloaded(struct so_list *so);
extern struct target_ops *bsd_uthread_target(void);

#endif /* bsd-uthread.h */

/* EOF */
