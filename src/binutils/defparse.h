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

#ifndef YY_YY_DEFPARSE_H_INCLUDED
# define YY_YY_DEFPARSE_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
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
     NAME = 258,
     LIBRARY = 259,
     DESCRIPTION = 260,
     STACKSIZE = 261,
     HEAPSIZE = 262,
     CODE = 263,
     DATA = 264,
     SECTIONS = 265,
     EXPORTS = 266,
     IMPORTS = 267,
     VERSIONK = 268,
     BASE = 269,
     CONSTANT = 270,
     READ = 271,
     WRITE = 272,
     EXECUTE = 273,
     SHARED = 274,
     NONSHARED = 275,
     NONAME = 276,
     PRIVATE = 277,
     SINGLE = 278,
     MULTIPLE = 279,
     INITINSTANCE = 280,
     INITGLOBAL = 281,
     TERMINSTANCE = 282,
     TERMGLOBAL = 283,
     ID = 284,
     NUMBER = 285
   };
#endif
/* Tokens.  */
#define NAME 258
#define LIBRARY 259
#define DESCRIPTION 260
#define STACKSIZE 261
#define HEAPSIZE 262
#define CODE 263
#define DATA 264
#define SECTIONS 265
#define EXPORTS 266
#define IMPORTS 267
#define VERSIONK 268
#define BASE 269
#define CONSTANT 270
#define READ 271
#define WRITE 272
#define EXECUTE 273
#define SHARED 274
#define NONSHARED 275
#define NONAME 276
#define PRIVATE 277
#define SINGLE 278
#define MULTIPLE 279
#define INITINSTANCE 280
#define INITGLOBAL 281
#define TERMINSTANCE 282
#define TERMGLOBAL 283
#define ID 284
#define NUMBER 285



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2053 of yacc.c  */
#line 27 "defparse.y"

  char *id;
  int number;


/* Line 2053 of yacc.c  */
#line 123 "defparse.h"
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

#endif /* !YY_YY_DEFPARSE_H_INCLUDED  */
