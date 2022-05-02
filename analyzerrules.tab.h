/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     num = 258,
     boollit = 259,
     OP2 = 260,
     OP3 = 261,
     OP4 = 262,
     PROGRAM = 263,
     IF = 264,
     THEN = 265,
     ELSE = 266,
     BEGINI = 267,
     END = 268,
     WHILE = 269,
     DO = 270,
     VAR = 271,
     AS = 272,
     INT = 273,
     BOOL = 274,
     LP = 275,
     RP = 276,
     ASGN = 277,
     SC = 278,
     READINT = 279,
     WRITEINT = 280,
     SYMBOL = 281,
     ident = 282
   };
#endif
/* Tokens.  */
#define num 258
#define boollit 259
#define OP2 260
#define OP3 261
#define OP4 262
#define PROGRAM 263
#define IF 264
#define THEN 265
#define ELSE 266
#define BEGINI 267
#define END 268
#define WHILE 269
#define DO 270
#define VAR 271
#define AS 272
#define INT 273
#define BOOL 274
#define LP 275
#define RP 276
#define ASGN 277
#define SC 278
#define READINT 279
#define WRITEINT 280
#define SYMBOL 281
#define ident 282




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 13 "analyzerrules.y"
{
    int number;
    int boolVal;
    char* str;
    Exp *statements;
    int fn;
    double d;
    struct symbol *symbol;
	struct symbolList *symbolList;
}
/* Line 1529 of yacc.c.  */
#line 114 "analyzerrules.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

