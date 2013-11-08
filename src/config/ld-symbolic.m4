dnl# Copyright (C) 2007 Free Software Foundation, Inc.
dnl# This file is free software, distributed under the terms of the GNU
dnl# General Public License.  As a special exception to the GNU General
dnl# Public License, this file may be distributed as part of a program
dnl# that contains a configuration script generated by Autoconf, under
dnl# the same distribution terms as the rest of that program.

dnl# Set SYMBOLIC_LDFLAGS to -Bsymbolic-functions for GNU linker if it
dnl# is supported.
AC_DEFUN([ACX_PROG_LD_GNU_SYMBOLIC],
[AC_CACHE_CHECK([if the GNU linker ($LD) supports -Bsymbolic-functions],
[acl_cv_prog_gnu_ld_symbolic],[
acl_cv_prog_gnu_ld_symbolic=no
AC_REQUIRE([AC_LIB_PROG_LD_GNU])
if test x"$with_gnu_ld" = x"yes"; then
  if $LD --help 2>&1 </dev/null | grep Bsymbolic-functions 1>&5; then
    acl_cv_prog_gnu_ld_symbolic=yes
  fi
fi])
if test x"$acl_cv_prog_gnu_ld_symbolic" = x"yes"; then
  SYMBOLIC_LDFLAGS="-Wl,-Bsymbolic-functions"
else
  SYMBOLIC_LDFLAGS=''
fi
])

dnl# Set DYNAMIC_LIST_CPP_NEW_LDFLAGS to --dynamic-list-cpp-new for GNU
dnl# linker if it is supported.
AC_DEFUN([ACX_PROG_LD_GNU_DYNAMIC_LIST_CPP_NEW],
[AC_CACHE_CHECK([if the GNU linker ($LD) supports --dynamic-list-cpp-new],
[acl_cv_prog_gnu_ld_dynamic_list_cpp_new],[
acl_cv_prog_gnu_ld_dynamic_list_cpp_new=no
AC_REQUIRE([ACX_PROG_LD_GNU_SYMBOLIC])
if test x"$with_gnu_ld" = x"yes" -a \
	x"$acl_cv_prog_gnu_ld_symbolic" = x"yes"; then
  if $LD --help 2>&1 </dev/null | grep dynamic-list-cpp-new 1>&5; then
    acl_cv_prog_gnu_ld_dynamic_list_cpp_new=yes
  fi
fi])
if test x"$acl_cv_prog_gnu_ld_dynamic_list_cpp_new" = x"yes"; then
   DYNAMIC_LIST_CPP_NEW_LDFLAGS="$SYMBOLIC_LDFLAGS -Wl,--dynamic-list-cpp-new"
else
   DYNAMIC_LIST_CPP_NEW_LDFLAGS=''
fi
])
