/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_NLMHEADER_H_INCLUDED
# define YY_YY_NLMHEADER_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     CHECK = 258,
     CODESTART = 259,
     COPYRIGHT = 260,
     CUSTOM = 261,
     DATE = 262,
     DEBUG = 263,
     DESCRIPTION = 264,
     EXIT = 265,
     EXPORT = 266,
     FLAG_ON = 267,
     FLAG_OFF = 268,
     FULLMAP = 269,
     HELP = 270,
     IMPORT = 271,
     INPUT = 272,
     MAP = 273,
     MESSAGES = 274,
     MODULE = 275,
     MULTIPLE = 276,
     OS_DOMAIN = 277,
     OUTPUT = 278,
     PSEUDOPREEMPTION = 279,
     REENTRANT = 280,
     SCREENNAME = 281,
     SHARELIB = 282,
     STACK = 283,
     START = 284,
     SYNCHRONIZE = 285,
     THREADNAME = 286,
     TYPE = 287,
     VERBOSE = 288,
     VERSIONK = 289,
     XDCDATA = 290,
     STRING = 291,
     QUOTED_STRING = 292
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2053 of yacc.c  */
#line 113 "nlmheader.y"

  char *string;
  struct string_list *list;


/* Line 2053 of yacc.c  */
#line 100 "nlmheader.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_NLMHEADER_H_INCLUDED  */
