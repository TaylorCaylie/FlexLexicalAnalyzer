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
     PROGRAM = 258,
     IF = 259,
     THEN = 260,
     ELSE = 261,
     BEGINI = 262,
     END = 263,
     WHILE = 264,
     DO = 265,
     VAR = 266,
     AS = 267,
     INT = 268,
     BOOL = 269,
     LP = 270,
     RP = 271,
     ASGN = 272,
     SC = 273,
     WRITEINT = 274,
     READINT = 275,
     SYMBOL = 276,
     ident = 277,
     num = 278,
     boollit = 279,
     OP2 = 280,
     OP3 = 281,
     OP4 = 282,
     identifierType = 283
   };
#endif
/* Tokens.  */
#define PROGRAM 258
#define IF 259
#define THEN 260
#define ELSE 261
#define BEGINI 262
#define END 263
#define WHILE 264
#define DO 265
#define VAR 266
#define AS 267
#define INT 268
#define BOOL 269
#define LP 270
#define RP 271
#define ASGN 272
#define SC 273
#define WRITEINT 274
#define READINT 275
#define SYMBOL 276
#define ident 277
#define num 278
#define boollit 279
#define OP2 280
#define OP3 281
#define OP4 282
#define identifierType 283




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 14 "analyzerrules.y"
{
    int number;
    int boolVal;
    char str;
    Exp *statements;
    int fn;
    double d;
    struct symbol *symbol;
	struct symbolList *symbolList;
    char typeIdent;
}
/* Line 1529 of yacc.c.  */
#line 117 "analyzerrules.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

