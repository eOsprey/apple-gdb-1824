/*   -*- buffer-read-only: t -*- vi: set ro:
 *  
 *  DO NOT EDIT THIS FILE   (opts.c)
 *  
 *  It has been AutoGen-ed  February 26, 2012 at 11:09:16 AM by AutoGen 5.15pre14
 *  From the definitions    opts.def
 *  and the template file   options
 *
 * Generated from AutoOpts 36:3:11 templates.
 *
 *  AutoOpts is a copyrighted work.  This source file is not encumbered
 *  by AutoOpts licensing, but is provided under the licensing terms chosen
 *  by the columns author or copyright holder.  AutoOpts is
 *  licensed under the terms of the LGPL.  The redistributable library
 *  (``libopts'') is licensed under the terms of either the LGPL or, at the
 *  users discretion, the BSD license.  See the AutoOpts and/or libopts sources
 *  for details.
 *
 * The columns program is copyrighted and licensed
 * under the following terms:
 *
 *  Copyright (C) 1999-2012 Bruce Korb, all rights reserved.
 *  This is free software. It is licensed for use, modification and
 *  redistribution under the terms of the
 *  GNU General Public License, version 3 or later
 *      <http://gnu.org/licenses/gpl.html>
 *
 *  columns is free software: you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License as published by the
 *  Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *  
 *  columns is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *  See the GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License along
 *  with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#define OPTION_CODE_COMPILE 1
#include "opts.h"
#include <sys/types.h>

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#ifdef  __cplusplus
extern "C" {
#endif
extern FILE * option_usage_fp;

/* TRANSLATORS: choose the translation for option names wisely because you
                cannot ever change your mind. */
#define zCopyright      (columns_opt_strs+0)
#define zLicenseDescrip (columns_opt_strs+272)

extern tUsageProc optionUsage;
/*
 *  global included definitions
 */

#include <errno.h>

#define OPEN_ERROR_FMT      (columns_opt_strs+875)

#ifndef NULL
#  define NULL 0
#endif

/*
 *  columns option static const strings
 */
static char const columns_opt_strs[2002] =
/*     0 */ "columns (GNU AutoGen) 1.2\n"
            "Copyright (C) 1999-2012 Bruce Korb, all rights reserved.\n"
            "This is free software. It is licensed for use, modification and\n"
            "redistribution under the terms of the\n"
            "GNU General Public License, version 3 or later\n"
            "    <http://gnu.org/licenses/gpl.html>\n\0"
/*   272 */ "columns is free software: you can redistribute it and/or modify it under\n"
            "the terms of the GNU General Public License as published by the Free\n"
            "Software Foundation, either version 3 of the License, or (at your option)\n"
            "any later version.\n\n"
            "columns is distributed in the hope that it will be useful, but WITHOUT\n"
            "ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or\n"
            "FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License\n"
            "for more details.\n\n"
            "You should have received a copy of the GNU General Public License along\n"
            "with this program.  If not, see <http://www.gnu.org/licenses/>.\n\0"
/*   875 */ "Error %d (%s) opening %s\n\0"
/*   901 */ "Maximum Line Width\0"
/*   920 */ "WIDTH\0"
/*   926 */ "width\0"
/*   932 */ "Desired number of columns\0"
/*   958 */ "COLUMNS\0"
/*   966 */ "columns\0"
/*   974 */ "Set width of each column\0"
/*   999 */ "COL_WIDTH\0"
/*  1009 */ "col-width\0"
/*  1019 */ "maximum spread added to column width\0"
/*  1056 */ "SPREAD\0"
/*  1063 */ "spread\0"
/*  1070 */ "Fill lines with input\0"
/*  1092 */ "FILL\0"
/*  1097 */ "fill\0"
/*  1102 */ "Line prefix or indentation\0"
/*  1129 */ "INDENT\0"
/*  1136 */ "indent\0"
/*  1143 */ "First line prefix\0"
/*  1161 */ "FIRST_INDENT\0"
/*  1174 */ "first-indent\0"
/*  1187 */ "tab width\0"
/*  1197 */ "TAB_WIDTH\0"
/*  1207 */ "tab-width\0"
/*  1217 */ "Sort input text\0"
/*  1233 */ "SORT\0"
/*  1238 */ "sort\0"
/*  1243 */ "Formatting string for each input\0"
/*  1276 */ "FORMAT\0"
/*  1283 */ "format\0"
/*  1290 */ "Separation string - follows all but last\0"
/*  1331 */ "SEPARATION\0"
/*  1342 */ "separation\0"
/*  1353 */ "string at end of all lines but last\0"
/*  1389 */ "LINE_SEPARATION\0"
/*  1405 */ "line-separation\0"
/*  1421 */ "string at end of last line\0"
/*  1448 */ "ENDING\0"
/*  1455 */ "ending\0"
/*  1462 */ "Print entries in column order\0"
/*  1492 */ "BY_COLUMNS\0"
/*  1503 */ "by-columns\0"
/*  1514 */ "Input file (if not stdin)\0"
/*  1540 */ "INPUT\0"
/*  1546 */ "input\0"
/*  1552 */ "Display extended usage information and exit\0"
/*  1596 */ "help\0"
/*  1601 */ "Extended usage information passed thru pager\0"
/*  1646 */ "more-help\0"
/*  1656 */ "Output version information and exit\0"
/*  1692 */ "version\0"
/*  1700 */ "Save the option state to a config file\0"
/*  1739 */ "save-opts\0"
/*  1749 */ "Load options from a config file\0"
/*  1781 */ "LOAD_OPTS\0"
/*  1791 */ "no-load-opts\0"
/*  1804 */ "no\0"
/*  1807 */ "columns (GNU AutoGen) - Columnize Input Text - Ver. 1.2\n"
            "USAGE:  %s [ -<flag> [<val>] | --<name>[{=| }<val>] ]...\n\0"
/*  1921 */ ".\0"
/*  1923 */ "$HOME\0"
/*  1929 */ ".columnsrc\0"
/*  1940 */ "autogen-users@lists.sourceforge.net\0"
/*  1976 */ "columns (GNU AutoGen) 1.2";

/*
 *  width option description:
 */
#define WIDTH_DESC      (columns_opt_strs+901)
#define WIDTH_NAME      (columns_opt_strs+920)
#define WIDTH_name      (columns_opt_strs+926)
#define WIDTH_DFT_ARG   ((char const*)79)
#define WIDTH_FLAGS     (OPTST_DISABLED \
        | OPTST_SET_ARGTYPE(OPARG_TYPE_NUMERIC))

/*
 *  columns option description:
 */
#define COLUMNS_DESC      (columns_opt_strs+932)
#define COLUMNS_NAME      (columns_opt_strs+958)
#define COLUMNS_name      (columns_opt_strs+966)
#define COLUMNS_DFT_ARG   ((char const*)0)
#define COLUMNS_FLAGS     (OPTST_DISABLED \
        | OPTST_SET_ARGTYPE(OPARG_TYPE_NUMERIC))

/*
 *  col_width option description:
 */
#define COL_WIDTH_DESC      (columns_opt_strs+974)
#define COL_WIDTH_NAME      (columns_opt_strs+999)
#define COL_WIDTH_name      (columns_opt_strs+1009)
#define COL_WIDTH_DFT_ARG   ((char const*)0)
#define COL_WIDTH_FLAGS     (OPTST_DISABLED \
        | OPTST_SET_ARGTYPE(OPARG_TYPE_NUMERIC))

/*
 *  spread option description:
 */
#define SPREAD_DESC      (columns_opt_strs+1019)
#define SPREAD_NAME      (columns_opt_strs+1056)
#define SPREAD_name      (columns_opt_strs+1063)
#define SPREAD_DFT_ARG   ((char const*)0)
#define SPREAD_FLAGS     (OPTST_DISABLED \
        | OPTST_SET_ARGTYPE(OPARG_TYPE_NUMERIC))

/*
 *  fill option description with
 *  "Must also have options" and "Incompatible options":
 */
#define FILL_DESC      (columns_opt_strs+1070)
#define FILL_NAME      (columns_opt_strs+1092)
#define FILL_name      (columns_opt_strs+1097)
static int const aFillCantList[] = {
    INDEX_OPT_SPREAD,
    INDEX_OPT_COL_WIDTH,
    INDEX_OPT_BY_COLUMNS, NO_EQUIVALENT };
#define FILL_FLAGS     (OPTST_DISABLED)

/*
 *  indent option description:
 */
#define INDENT_DESC      (columns_opt_strs+1102)
#define INDENT_NAME      (columns_opt_strs+1129)
#define INDENT_name      (columns_opt_strs+1136)
#define INDENT_FLAGS     (OPTST_DISABLED \
        | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))

/*
 *  first_indent option description with
 *  "Must also have options" and "Incompatible options":
 */
#define FIRST_INDENT_DESC      (columns_opt_strs+1143)
#define FIRST_INDENT_NAME      (columns_opt_strs+1161)
#define FIRST_INDENT_name      (columns_opt_strs+1174)
static int const aFirst_IndentMustList[] = {
    INDEX_OPT_INDENT, NO_EQUIVALENT };
#define FIRST_INDENT_FLAGS     (OPTST_DISABLED \
        | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))

/*
 *  tab_width option description:
 */
#define TAB_WIDTH_DESC      (columns_opt_strs+1187)
#define TAB_WIDTH_NAME      (columns_opt_strs+1197)
#define TAB_WIDTH_name      (columns_opt_strs+1207)
#define TAB_WIDTH_DFT_ARG   ((char const*)8)
#define TAB_WIDTH_FLAGS     (OPTST_DISABLED \
        | OPTST_SET_ARGTYPE(OPARG_TYPE_NUMERIC))

/*
 *  sort option description:
 */
#define SORT_DESC      (columns_opt_strs+1217)
#define SORT_NAME      (columns_opt_strs+1233)
#define SORT_name      (columns_opt_strs+1238)
#define SORT_FLAGS     (OPTST_DISABLED \
        | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING) | OPTST_ARG_OPTIONAL)

/*
 *  format option description:
 */
#define FORMAT_DESC      (columns_opt_strs+1243)
#define FORMAT_NAME      (columns_opt_strs+1276)
#define FORMAT_name      (columns_opt_strs+1283)
#define FORMAT_FLAGS     (OPTST_DISABLED \
        | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))

/*
 *  separation option description:
 */
#define SEPARATION_DESC      (columns_opt_strs+1290)
#define SEPARATION_NAME      (columns_opt_strs+1331)
#define SEPARATION_name      (columns_opt_strs+1342)
#define SEPARATION_FLAGS     (OPTST_DISABLED \
        | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))

/*
 *  line_separation option description:
 */
#define LINE_SEPARATION_DESC      (columns_opt_strs+1353)
#define LINE_SEPARATION_NAME      (columns_opt_strs+1389)
#define LINE_SEPARATION_name      (columns_opt_strs+1405)
#define LINE_SEPARATION_FLAGS     (OPTST_DISABLED \
        | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))

/*
 *  ending option description:
 */
#define ENDING_DESC      (columns_opt_strs+1421)
#define ENDING_NAME      (columns_opt_strs+1448)
#define ENDING_name      (columns_opt_strs+1455)
#define ENDING_FLAGS     (OPTST_DISABLED \
        | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))

/*
 *  by_columns option description:
 */
#define BY_COLUMNS_DESC      (columns_opt_strs+1462)
#define BY_COLUMNS_NAME      (columns_opt_strs+1492)
#define BY_COLUMNS_name      (columns_opt_strs+1503)
#define BY_COLUMNS_FLAGS     (OPTST_DISABLED)

/*
 *  input option description:
 */
#define INPUT_DESC      (columns_opt_strs+1514)
#define INPUT_NAME      (columns_opt_strs+1540)
#define INPUT_name      (columns_opt_strs+1546)
#define INPUT_FLAGS     (OPTST_DISABLED \
        | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))

/*
 *  Help/More_Help/Version option descriptions:
 */
#define HELP_DESC       (columns_opt_strs+1552)
#define HELP_name       (columns_opt_strs+1596)
#ifdef HAVE_WORKING_FORK
#define MORE_HELP_DESC  (columns_opt_strs+1601)
#define MORE_HELP_name  (columns_opt_strs+1646)
#define MORE_HELP_FLAGS (OPTST_IMM | OPTST_NO_INIT)
#else
#define MORE_HELP_DESC  NULL
#define MORE_HELP_name  NULL
#define MORE_HELP_FLAGS (OPTST_OMITTED | OPTST_NO_INIT)
#endif
#ifdef NO_OPTIONAL_OPT_ARGS
#  define VER_FLAGS     (OPTST_IMM | OPTST_NO_INIT)
#else
#  define VER_FLAGS     (OPTST_SET_ARGTYPE(OPARG_TYPE_STRING) | \
                         OPTST_ARG_OPTIONAL | OPTST_IMM | OPTST_NO_INIT)
#endif
#define VER_DESC        (columns_opt_strs+1656)
#define VER_name        (columns_opt_strs+1692)
#define SAVE_OPTS_DESC  (columns_opt_strs+1700)
#define SAVE_OPTS_name  (columns_opt_strs+1739)
#define LOAD_OPTS_DESC     (columns_opt_strs+1749)
#define LOAD_OPTS_NAME     (columns_opt_strs+1781)
#define NO_LOAD_OPTS_name  (columns_opt_strs+1791)
#define LOAD_OPTS_pfx      (columns_opt_strs+1804)
#define LOAD_OPTS_name     (NO_LOAD_OPTS_name + 3)
/*
 *  Declare option callback procedures
 */
extern tOptProc
    optionBooleanVal,   optionNestedVal,    optionNumericVal,
    optionPagedUsage,   optionPrintVersion, optionResetOpt,
    optionStackArg,     optionTimeDate,     optionTimeVal,
    optionUnstackArg,   optionVendorOption;
static tOptProc
    doOptCol_Width, doOptColumns,   doOptInput,     doOptSpread,
    doOptWidth,     doUsageOpt;
#define VER_PROC        optionPrintVersion

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *  Define the Columns Option Descriptions.
 */
static tOptDesc optDesc[OPTION_CT] = {
  {  /* entry idx, value */ 0, VALUE_OPT_WIDTH,
     /* equiv idx, value */ 0, VALUE_OPT_WIDTH,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ WIDTH_FLAGS, 0,
     /* last opt argumnt */ { WIDTH_DFT_ARG },
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ doOptWidth,
     /* desc, NAME, name */ WIDTH_DESC, WIDTH_NAME, WIDTH_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 1, VALUE_OPT_COLUMNS,
     /* equiv idx, value */ 1, VALUE_OPT_COLUMNS,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ COLUMNS_FLAGS, 0,
     /* last opt argumnt */ { COLUMNS_DFT_ARG },
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ doOptColumns,
     /* desc, NAME, name */ COLUMNS_DESC, COLUMNS_NAME, COLUMNS_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 2, VALUE_OPT_COL_WIDTH,
     /* equiv idx, value */ 2, VALUE_OPT_COL_WIDTH,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ COL_WIDTH_FLAGS, 0,
     /* last opt argumnt */ { COL_WIDTH_DFT_ARG },
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ doOptCol_Width,
     /* desc, NAME, name */ COL_WIDTH_DESC, COL_WIDTH_NAME, COL_WIDTH_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 3, VALUE_OPT_SPREAD,
     /* equiv idx, value */ 3, VALUE_OPT_SPREAD,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ SPREAD_FLAGS, 0,
     /* last opt argumnt */ { SPREAD_DFT_ARG },
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ doOptSpread,
     /* desc, NAME, name */ SPREAD_DESC, SPREAD_NAME, SPREAD_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 4, VALUE_OPT_FILL,
     /* equiv idx, value */ 4, VALUE_OPT_FILL,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ FILL_FLAGS, 0,
     /* last opt argumnt */ { NULL }, /* --fill */
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, aFillCantList,
     /* option proc      */ NULL,
     /* desc, NAME, name */ FILL_DESC, FILL_NAME, FILL_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 5, VALUE_OPT_INDENT,
     /* equiv idx, value */ 5, VALUE_OPT_INDENT,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ INDENT_FLAGS, 0,
     /* last opt argumnt */ { NULL }, /* --indent */
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ NULL,
     /* desc, NAME, name */ INDENT_DESC, INDENT_NAME, INDENT_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 6, VALUE_OPT_FIRST_INDENT,
     /* equiv idx, value */ 6, VALUE_OPT_FIRST_INDENT,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ FIRST_INDENT_FLAGS, 0,
     /* last opt argumnt */ { NULL }, /* --first_indent */
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ aFirst_IndentMustList, NULL,
     /* option proc      */ NULL,
     /* desc, NAME, name */ FIRST_INDENT_DESC, FIRST_INDENT_NAME, FIRST_INDENT_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 7, VALUE_OPT_TAB_WIDTH,
     /* equiv idx, value */ 7, VALUE_OPT_TAB_WIDTH,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ TAB_WIDTH_FLAGS, 0,
     /* last opt argumnt */ { TAB_WIDTH_DFT_ARG },
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ optionNumericVal,
     /* desc, NAME, name */ TAB_WIDTH_DESC, TAB_WIDTH_NAME, TAB_WIDTH_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 8, VALUE_OPT_SORT,
     /* equiv idx, value */ 8, VALUE_OPT_SORT,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ SORT_FLAGS, 0,
     /* last opt argumnt */ { NULL }, /* --sort */
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ NULL,
     /* desc, NAME, name */ SORT_DESC, SORT_NAME, SORT_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 9, VALUE_OPT_FORMAT,
     /* equiv idx, value */ 9, VALUE_OPT_FORMAT,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ FORMAT_FLAGS, 0,
     /* last opt argumnt */ { NULL }, /* --format */
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ NULL,
     /* desc, NAME, name */ FORMAT_DESC, FORMAT_NAME, FORMAT_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 10, VALUE_OPT_SEPARATION,
     /* equiv idx, value */ 10, VALUE_OPT_SEPARATION,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ SEPARATION_FLAGS, 0,
     /* last opt argumnt */ { NULL }, /* --separation */
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ NULL,
     /* desc, NAME, name */ SEPARATION_DESC, SEPARATION_NAME, SEPARATION_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 11, VALUE_OPT_LINE_SEPARATION,
     /* equiv idx, value */ 11, VALUE_OPT_LINE_SEPARATION,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ LINE_SEPARATION_FLAGS, 0,
     /* last opt argumnt */ { NULL }, /* --line_separation */
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ NULL,
     /* desc, NAME, name */ LINE_SEPARATION_DESC, LINE_SEPARATION_NAME, LINE_SEPARATION_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 12, VALUE_OPT_ENDING,
     /* equiv idx, value */ 12, VALUE_OPT_ENDING,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ ENDING_FLAGS, 0,
     /* last opt argumnt */ { NULL }, /* --ending */
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ NULL,
     /* desc, NAME, name */ ENDING_DESC, ENDING_NAME, ENDING_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 13, VALUE_OPT_BY_COLUMNS,
     /* equiv idx, value */ 13, VALUE_OPT_BY_COLUMNS,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ BY_COLUMNS_FLAGS, 0,
     /* last opt argumnt */ { NULL }, /* --by_columns */
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ NULL,
     /* desc, NAME, name */ BY_COLUMNS_DESC, BY_COLUMNS_NAME, BY_COLUMNS_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 14, VALUE_OPT_INPUT,
     /* equiv idx, value */ 14, VALUE_OPT_INPUT,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ INPUT_FLAGS, 0,
     /* last opt argumnt */ { NULL }, /* --input */
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ doOptInput,
     /* desc, NAME, name */ INPUT_DESC, INPUT_NAME, INPUT_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ INDEX_OPT_VERSION, VALUE_OPT_VERSION,
     /* equiv idx value  */ NO_EQUIVALENT, VALUE_OPT_VERSION,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ VER_FLAGS, 0,
     /* last opt argumnt */ { NULL },
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ VER_PROC,
     /* desc, NAME, name */ VER_DESC, NULL, VER_name,
     /* disablement strs */ NULL, NULL },



  {  /* entry idx, value */ INDEX_OPT_HELP, VALUE_OPT_HELP,
     /* equiv idx value  */ NO_EQUIVALENT, VALUE_OPT_HELP,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ OPTST_IMM | OPTST_NO_INIT, 0,
     /* last opt argumnt */ { NULL },
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ doUsageOpt,
     /* desc, NAME, name */ HELP_DESC, NULL, HELP_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ INDEX_OPT_MORE_HELP, VALUE_OPT_MORE_HELP,
     /* equiv idx value  */ NO_EQUIVALENT, VALUE_OPT_MORE_HELP,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ MORE_HELP_FLAGS, 0,
     /* last opt argumnt */ { NULL },
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL,  NULL,
     /* option proc      */ optionPagedUsage,
     /* desc, NAME, name */ MORE_HELP_DESC, NULL, MORE_HELP_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ INDEX_OPT_SAVE_OPTS, VALUE_OPT_SAVE_OPTS,
     /* equiv idx value  */ NO_EQUIVALENT, VALUE_OPT_SAVE_OPTS,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ OPTST_SET_ARGTYPE(OPARG_TYPE_STRING)
                          | OPTST_ARG_OPTIONAL | OPTST_NO_INIT, 0,
     /* last opt argumnt */ { NULL },
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL,  NULL,
     /* option proc      */ NULL,
     /* desc, NAME, name */ SAVE_OPTS_DESC, NULL, SAVE_OPTS_name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ INDEX_OPT_LOAD_OPTS, VALUE_OPT_LOAD_OPTS,
     /* equiv idx value  */ NO_EQUIVALENT, VALUE_OPT_LOAD_OPTS,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, NOLIMIT, 0,
     /* opt state flags  */ OPTST_SET_ARGTYPE(OPARG_TYPE_STRING)
			  | OPTST_DISABLE_IMM, 0,
     /* last opt argumnt */ { NULL },
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ optionLoadOpt,
     /* desc, NAME, name */ LOAD_OPTS_DESC, LOAD_OPTS_NAME, LOAD_OPTS_name,
     /* disablement strs */ NO_LOAD_OPTS_name, LOAD_OPTS_pfx }
};


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *  Define the Columns Option Environment
 */
#define zPROGNAME       (columns_opt_strs+958)
#define zUsageTitle     (columns_opt_strs+1807)
#define zRcName         (columns_opt_strs+1929)
static char const * const apzHomeList[3] = {
    columns_opt_strs+1921,
    columns_opt_strs+1923,
    NULL };
#define zBugsAddr       (columns_opt_strs+1940)
#define zExplain        (NULL)
#define zDetail         (NULL)
#define zFullVersion    (columns_opt_strs+1976)
/* extracted from optcode.tlib near line 349 */

#if defined(ENABLE_NLS)
# define OPTPROC_BASE OPTPROC_TRANSLATE
  static tOptionXlateProc translate_option_strings;
#else
# define OPTPROC_BASE OPTPROC_NONE
# define translate_option_strings NULL
#endif /* ENABLE_NLS */


#define columns_full_usage (NULL)

#define columns_short_usage (NULL)

/*
 *  Create the static procedure(s) declared above.
 */
/**
 * The callout function that invokes the USAGE() macro.
 *
 * @param pOptions the AutoOpts option description structure
 * @param pOptDesc the descriptor for the "help" (usage) option.
 */
static void
doUsageOpt(tOptions * pOptions, tOptDesc * pOptDesc)
{
    (void)pOptions;
    USAGE(COLUMNS_EXIT_SUCCESS);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/**
 * Code to handle the width option.
 *
 * @param pOptions the columns options data structure
 * @param pOptDesc the option descriptor for this option.
 */
static void
doOptWidth(tOptions* pOptions, tOptDesc* pOptDesc)
{
    static struct {long rmin, rmax;} const rng[1] = {
        { 16, 4095 } };
    int  ix;

    if (pOptions <= OPTPROC_EMIT_LIMIT)
        goto emit_ranges;
    optionNumericVal(pOptions, pOptDesc);

    for (ix = 0; ix < 1; ix++) {
        if (pOptDesc->optArg.argInt < rng[ix].rmin)
            continue;  /* ranges need not be ordered. */
        if (pOptDesc->optArg.argInt == rng[ix].rmin)
            return;
        if (rng[ix].rmax == LONG_MIN)
            continue;
        if (pOptDesc->optArg.argInt <= rng[ix].rmax)
            return;
    }

    option_usage_fp = stderr;

emit_ranges:

    optionShowRange(pOptions, pOptDesc, (void *)rng, 1);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/**
 * Code to handle the columns option.
 *
 * @param pOptions the columns options data structure
 * @param pOptDesc the option descriptor for this option.
 */
static void
doOptColumns(tOptions* pOptions, tOptDesc* pOptDesc)
{
    static struct {long rmin, rmax;} const rng[1] = {
        { 1, 2048 } };
    int  ix;

    if (pOptions <= OPTPROC_EMIT_LIMIT)
        goto emit_ranges;
    optionNumericVal(pOptions, pOptDesc);

    for (ix = 0; ix < 1; ix++) {
        if (pOptDesc->optArg.argInt < rng[ix].rmin)
            continue;  /* ranges need not be ordered. */
        if (pOptDesc->optArg.argInt == rng[ix].rmin)
            return;
        if (rng[ix].rmax == LONG_MIN)
            continue;
        if (pOptDesc->optArg.argInt <= rng[ix].rmax)
            return;
    }

    option_usage_fp = stderr;

emit_ranges:

    optionShowRange(pOptions, pOptDesc, (void *)rng, 1);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/**
 * Code to handle the col_width option.
 *
 * @param pOptions the columns options data structure
 * @param pOptDesc the option descriptor for this option.
 */
static void
doOptCol_Width(tOptions* pOptions, tOptDesc* pOptDesc)
{
    static struct {long rmin, rmax;} const rng[1] = {
        { 1, 2048 } };
    int  ix;

    if (pOptions <= OPTPROC_EMIT_LIMIT)
        goto emit_ranges;
    optionNumericVal(pOptions, pOptDesc);

    for (ix = 0; ix < 1; ix++) {
        if (pOptDesc->optArg.argInt < rng[ix].rmin)
            continue;  /* ranges need not be ordered. */
        if (pOptDesc->optArg.argInt == rng[ix].rmin)
            return;
        if (rng[ix].rmax == LONG_MIN)
            continue;
        if (pOptDesc->optArg.argInt <= rng[ix].rmax)
            return;
    }

    option_usage_fp = stderr;

emit_ranges:

    optionShowRange(pOptions, pOptDesc, (void *)rng, 1);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/**
 * Code to handle the spread option.
 *
 * @param pOptions the columns options data structure
 * @param pOptDesc the option descriptor for this option.
 */
static void
doOptSpread(tOptions* pOptions, tOptDesc* pOptDesc)
{
    static struct {long rmin, rmax;} const rng[1] = {
        { 1, 1024 } };
    int  ix;

    if (pOptions <= OPTPROC_EMIT_LIMIT)
        goto emit_ranges;
    optionNumericVal(pOptions, pOptDesc);

    for (ix = 0; ix < 1; ix++) {
        if (pOptDesc->optArg.argInt < rng[ix].rmin)
            continue;  /* ranges need not be ordered. */
        if (pOptDesc->optArg.argInt == rng[ix].rmin)
            return;
        if (rng[ix].rmax == LONG_MIN)
            continue;
        if (pOptDesc->optArg.argInt <= rng[ix].rmax)
            return;
    }

    option_usage_fp = stderr;

emit_ranges:

    optionShowRange(pOptions, pOptDesc, (void *)rng, 1);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/**
 * Code to handle the input option.
 *
 * @param pOptions the columns options data structure
 * @param pOptDesc the option descriptor for this option.
 */
static void
doOptInput(tOptions* pOptions, tOptDesc* pOptDesc)
{
    /* extracted from opts.def, line 276 */
    FILE* fp = freopen(
        pOptDesc->optArg.argString, "r" FOPEN_BINARY_FLAG, stdin);

    if (fp == (FILE*)NULL) {
        fprintf(stderr, OPEN_ERROR_FMT, errno, strerror(errno),
                pOptDesc->optArg.argString);
        USAGE(EXIT_FAILURE);
    }
}
/* extracted from optmain.tlib near line 1093 */

#ifndef  PKGDATADIR
# define PKGDATADIR ""
#endif

#ifndef  WITH_PACKAGER
# define columns_packager_info NULL
#else
static char const columns_packager_info[] =
    "Packaged by " WITH_PACKAGER

# ifdef WITH_PACKAGER_VERSION
        " ("WITH_PACKAGER_VERSION")"
# endif

# ifdef WITH_PACKAGER_BUG_REPORTS
    "\nReport columns bugs to " WITH_PACKAGER_BUG_REPORTS
# endif
    "\n";
#endif

tOptions columnsOptions = {
    OPTIONS_STRUCT_VERSION,
    0, NULL,                    /* original argc + argv    */
    ( OPTPROC_BASE
    + OPTPROC_ERRSTOP
    + OPTPROC_SHORTOPT
    + OPTPROC_LONGOPT
    + OPTPROC_NO_REQ_OPT
    + OPTPROC_ENVIRON
    + OPTPROC_NO_ARGS ),
    0, NULL,                    /* current option index, current option */
    NULL,         NULL,         zPROGNAME,
    zRcName,      zCopyright,   zLicenseDescrip,
    zFullVersion, apzHomeList,  zUsageTitle,
    zExplain,     zDetail,      optDesc,
    zBugsAddr,                  /* address to send bugs to */
    NULL, NULL,                 /* extensions/saved state  */
    optionUsage, /* usage procedure */
    translate_option_strings,   /* translation procedure */
    /*
     *  Indexes to special options
     */
    { INDEX_OPT_MORE_HELP, /* more-help option index */
      INDEX_OPT_SAVE_OPTS, /* save option index */
      NO_EQUIVALENT, /* '-#' option index */
      NO_EQUIVALENT /* index of default opt */
    },
    20 /* full option count */, 15 /* user option count */,
    columns_full_usage, columns_short_usage,
    NULL, NULL,
    PKGDATADIR, columns_packager_info
};

#if ENABLE_NLS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <autoopts/usage-txt.h>

static char* AO_gettext(char const* pz);
static void  coerce_it(void** s);

static char*
AO_gettext(char const* pz)
{
    char* pzRes;
    if (pz == NULL)
        return NULL;
    pzRes = _(pz);
    if (pzRes == pz)
        return pzRes;
    pzRes = strdup(pzRes);
    if (pzRes == NULL) {
        fputs(_("No memory for duping translated strings\n"), stderr);
        exit(COLUMNS_EXIT_FAILURE);
    }
    return pzRes;
}

static void coerce_it(void** s) { *s = AO_gettext(*s);
}

/*
 *  This invokes the translation code (e.g. gettext(3)).
 */
static void
translate_option_strings(void)
{
    tOptions * const pOpt = &columnsOptions;

    /*
     *  Guard against re-translation.  It won't work.  The strings will have
     *  been changed by the first pass through this code.  One shot only.
     */
    if (option_usage_text.field_ct != 0) {
        /*
         *  Do the translations.  The first pointer follows the field count
         *  field.  The field count field is the size of a pointer.
         */
        tOptDesc * pOD = pOpt->pOptDesc;
        char **    ppz = (char**)(void*)&(option_usage_text);
        int        ix  = option_usage_text.field_ct;

        do {
            ppz++;
            *ppz = AO_gettext(*ppz);
        } while (--ix > 0);

        coerce_it((void*)&(pOpt->pzCopyright));
        coerce_it((void*)&(pOpt->pzCopyNotice));
        coerce_it((void*)&(pOpt->pzFullVersion));
        coerce_it((void*)&(pOpt->pzUsageTitle));
        coerce_it((void*)&(pOpt->pzExplain));
        coerce_it((void*)&(pOpt->pzDetail));
        coerce_it((void*)&(pOpt->pzPackager));
        option_usage_text.field_ct = 0;

        for (ix = pOpt->optCt; ix > 0; ix--, pOD++)
            coerce_it((void*)&(pOD->pzText));
    }

    if ((pOpt->fOptSet & OPTPROC_NXLAT_OPT_CFG) == 0) {
        tOptDesc * pOD = pOpt->pOptDesc;
        int        ix;

        for (ix = pOpt->optCt; ix > 0; ix--, pOD++) {
            coerce_it((void*)&(pOD->pz_Name));
            coerce_it((void*)&(pOD->pz_DisableName));
            coerce_it((void*)&(pOD->pz_DisablePfx));
        }
        /* prevent re-translation */
        columnsOptions.fOptSet |= OPTPROC_NXLAT_OPT_CFG | OPTPROC_NXLAT_OPT;
    }
}

#endif /* ENABLE_NLS */

#ifdef  __cplusplus
}
#endif
/* opts.c ends here */
