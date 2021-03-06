/* varobj.h: GDB variable objects API.
   Copyright 1999, 2000, 2001, 2005 Free Software Foundation, Inc.

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

#ifndef VAROBJ_H
#define VAROBJ_H 1

#include "symtab.h"
#include "gdbtypes.h"

/* Enumeration for the format types.  If you add elements here, be sure
   to update format_code in varobj.c to match.  */
enum varobj_display_formats
  {
    FORMAT_NATURAL,		/* What gdb actually calls 'natural' */
    FORMAT_BINARY,		/* Binary display                    */
    FORMAT_DECIMAL,		/* Decimal display                   */
    FORMAT_HEXADECIMAL,		/* Hex display                       */
    FORMAT_OCTAL,		/* Octal display                     */
    FORMAT_UNSIGNED,		/* APPLE LOCAL: Unsigned decimal display */
    FORMAT_OSTYPE,              /* APPLE LOCAL: OSType display       */
    FORMAT_HEXFLOAT             /* APPLE LOCAL: Floating point in hex '%a' */
  };

enum varobj_type
  {
    USE_SPECIFIED_FRAME,        /* Use the frame passed to varobj_create */
    USE_CURRENT_FRAME,          /* Use the current frame */
    USE_SELECTED_FRAME,         /* Always reevaluate in selected frame */
    USE_BLOCK_IN_FRAME,          /* Use the address as a block in the current
				   frame. */
    NO_FRAME_NEEDED             /* No frame is needed, this is a file static
				   or a global variable.  */
  };

/* String representations of gdb's format codes (defined in varobj.c) */
extern const char *varobj_format_string[];

/* Languages supported by this variable objects system. */
enum varobj_languages
  {
    vlang_unknown = 0, vlang_c, vlang_cplus, vlang_java, vlang_end
  };

/* String representations of gdb's known languages (defined in varobj.c) */
extern const char *varobj_language_string[];

/* This represents the possible type-changed states: */

enum varobj_type_change {
  VAROBJ_TYPE_UNCHANGED,
  VAROBJ_TYPE_CHANGED,
  VAROBJ_SCOPE_CHANGED,
  VAROBJ_DYNAMIC_TYPE_CHANGED
};

/* Struct thar describes a variable object instance */
struct varobj;

/* A linked list of varobjs.  Used to package the result of
   varobj_update.  */

struct varobj_changelist;

/* API functions */

extern struct varobj *varobj_create(char *objname, const char *expression,
				    CORE_ADDR frame, struct block *block,
				    enum varobj_type type);

extern char *varobj_gen_name(void);

extern struct varobj *varobj_get_handle(char *name);

extern char *varobj_get_objname(struct varobj *var);

extern char *varobj_get_expression(struct varobj *var);

extern int varobj_delete(struct varobj *var, char ***dellist,
			 int only_children);

extern enum varobj_display_formats varobj_set_display_format(struct varobj *var,
					      enum varobj_display_formats frmt);

extern enum varobj_display_formats varobj_get_display_format(struct varobj *vo);

extern int varobj_get_num_children(struct varobj *var);

extern int varobj_list_children(struct varobj *var,
				struct varobj ***childlist);

extern int varobj_is_fake_child(struct varobj *var);

extern char *varobj_get_type(struct varobj *var);

/* APPLE LOCAL: Get the type without typedef's: */
char *varobj_get_resolved_type(struct varobj *var);

extern char *varobj_get_dynamic_type(struct varobj *var);

extern char *varobj_get_path_expr(struct varobj *var);

extern struct type *varobj_get_type_struct(struct varobj *var);

extern struct type *varobj_get_gdb_type(struct varobj *var);

extern enum varobj_languages varobj_get_language(struct varobj *var);

extern int varobj_get_attributes(struct varobj *var);

extern char *varobj_get_value(struct varobj *var);

extern int varobj_set_value(struct varobj *var, char *expression);

extern int varobj_list(struct varobj ***rootlist);

extern int varobj_in_scope_p(struct varobj *var);

extern int varobj_pc_in_valid_block_p(struct varobj *var);

extern int varobj_update(struct varobj **varp,
			 struct varobj_changelist **changelist);

extern struct varobj *varobj_changelist_pop(struct varobj_changelist *chglst,
					    enum varobj_type_change *typchgd);

extern void varobj_get_valid_block(struct varobj *var, CORE_ADDR *start,
				   CORE_ADDR *end);

extern void varobj_delete_objfiles_vars(struct objfile *ofile);

/* */
extern int varobjdebug;
extern int varobj_runs_all_threads;
#endif /* VAROBJ_H */

/* EOF */
