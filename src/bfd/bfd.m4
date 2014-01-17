dnl# This file was derived from acinclude.m4.

dnl# Check for existence of a type $1 in sys/procfs.h

AC_DEFUN([BFD_HAVE_SYS_PROCFS_TYPE],
[AC_CHECK_HEADERS_ONCE([sys/procfs.h])
 AC_MSG_CHECKING([for $1 in sys/procfs.h])
 AC_CACHE_VAL([bfd_cv_have_sys_procfs_type_$1],
   [AC_COMPILE_IFELSE([AC_LANG_SOURCE([[
#define _SYSCALL32
#include <sys/procfs.h>]],
      [[$1 avar]])],
      [bfd_cv_have_sys_procfs_type_$1=yes],
      [bfd_cv_have_sys_procfs_type_$1=no])
   ])
 if test $bfd_cv_have_sys_procfs_type_$1 = yes; then
   AC_DEFINE([HAVE_]translit([$1],[a-z],[A-Z]),[1],
	     [Define if <sys/procfs.h> has $1.])
 fi
 AC_MSG_RESULT([$bfd_cv_have_sys_procfs_type_$1])
])

dnl# Check for existence of member $2 in type $1 in sys/procfs.h

AC_DEFUN([BFD_HAVE_SYS_PROCFS_TYPE_MEMBER],
[AC_CHECK_HEADERS_ONCE([sys/procfs.h])
 AC_MSG_CHECKING([for $1.$2 in sys/procfs.h])
 AC_CACHE_VAL([bfd_cv_have_sys_procfs_type_member_$1_$2],
   [AC_COMPILE_IFELSE([AC_LANG_SOURCE([[
#define _SYSCALL32
#include <sys/procfs.h>]],
      [[$1 avar; void* aref = (void*) &avar.$2]])],
      [bfd_cv_have_sys_procfs_type_member_$1_$2=yes],
      [bfd_cv_have_sys_procfs_type_member_$1_$2=no])
   ])
 if test $bfd_cv_have_sys_procfs_type_member_$1_$2 = yes; then
   AC_DEFINE([HAVE_]translit([$1],[a-z],[A-Z])[_]translit([$2],[a-z],[A-Z]),[1],
	     [Define if <sys/procfs.h> has $1.$2.])
 fi
 AC_MSG_RESULT([$bfd_cv_have_sys_procfs_type_member_$1_$2])
])

dnl# See whether we need a declaration for a function.

AC_DEFUN([BFD_NEED_DECLARATION],
[AC_REQUIRE([AC_HEADER_STDC])
AC_REQUIRE([AC_PROG_CC])
AC_MSG_CHECKING([whether $1 must be declared])
AC_CACHE_VAL([bfd_cv_decl_needed_$1],
[AC_COMPILE_IFELSE([AC_LANG_SOURCE([[
#include <stdio.h>
#ifdef HAVE_STRING_H
# include <string.h>
#else
# ifdef HAVE_STRINGS_H
#  include <strings.h>
# endif /* HAVE_STRINGS_H */
#endif /* HAVE_STRING_H */
#ifdef HAVE_STDLIB_H
# include <stdlib.h>
#else
# warning this conftest expects <stdlib.h> to be included.
#endif /* HAVE_STDLIB_H */
#ifdef HAVE_UNISTD_H
# include <unistd.h>
#else
# warning this conftest expects <unistd.h> to be included.
#endif /* HAVE_UNISTD_H */
]],[[
char *(*pfn) = (char *(*)) $1
]])],
[bfd_cv_decl_needed_$1=no],[bfd_cv_decl_needed_$1=yes])])
AC_MSG_RESULT([$bfd_cv_decl_needed_$1])
if test $bfd_cv_decl_needed_$1 = yes; then
  AC_DEFINE([NEED_DECLARATION_]translit([$1],[a-z],[A-Z]),[1],
	    [Define if $1 is not declared in system header files.])
fi
])dnl

