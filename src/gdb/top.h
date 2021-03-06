/* top.h: Top level stuff for GDB, the GNU debugger.

   Copyright 1986, 1987, 1988, 1989, 1990, 1991, 1992, 1993, 1994,
   1996, 1997, 1998, 1999, 2000, 2005 Free Software Foundation, Inc.

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

#ifndef TOP_H
#define TOP_H

/* APPLE LOCAL begin Inform users about debugging optimized code  */
extern int dwarf2_inform_debugging_optimized_code;
extern int currently_inside_optimized_code;
extern int gdb_prompt_is_optimized;
/* APPLE LOCAL end Inform users about debugging optimized code  */

/* From top.c.  */
extern int caution;
extern char *line;
extern size_t linesize;
extern FILE *instream;
extern char gdb_dirbuf[1024];
extern int inhibit_gdbinit;
extern int epoch_interface;
extern int xgdb_verbose;
extern char gdbinit[];
/* APPLE LOCAL global gdbinit */
extern char gdbinit_global[];

extern void print_gdb_version(struct ui_file *);

extern void source_command(const char *, int);
/* APPLE LOCAL cf cli/cli-cmds.c */
extern void source_file(const char *, int);

extern void cd_command(const char *, int);
extern void read_command_file(FILE *);
extern void init_history(void);
extern void command_loop(void);
extern void simplified_command_loop(char *(*read_input_func)(const char *),
				    void (*execute_command_func)(char *,
                                                                 int));
extern int quit_confirm(void);
extern NORETURN void quit_force(const char *, int);
extern void quit_command(const char *, int);
extern int quit_cover(void *);
extern void execute_command(const char *, int);

/* This function returns a pointer to the string that is used
   by gdb for its command prompt. */
extern const char *get_prompt(void);

/* This function copies the specified string into the string that
   is used by gdb for its command prompt. */
extern void set_prompt(char *);

/* From random places: */
extern int readnow_symbol_files;

/* Perform _initialize initialization */
extern void gdb_init(char *);

/* For use by event-top.c */
/* Variables from top.c. */
extern int source_line_number;
extern char *source_file_name;
extern int history_expansion_p;
extern int server_command;
extern char *lim_at_start;

extern void show_commands(const char *args, int from_tty);

extern void set_history(const char *, int);

extern void show_history(const char *, int);

extern void set_verbose(const char *, int, struct cmd_list_element *);

extern void do_restore_instream_cleanup(void *stream);

extern void dummy_func_to_use_unused_top_c_funcs(void) ATTR_NORETURN;

extern void (*window_hook)(FILE *, char *);
extern void (*pre_init_ui_hook)(void);

#endif /* !TOP_H */

/* EOF */
