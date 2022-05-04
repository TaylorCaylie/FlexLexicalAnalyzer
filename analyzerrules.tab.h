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
     OP2 = 258,
     OP3 = 259,
     OP4 = 260,
     PROGRAM = 261,
     IF = 262,
     THEN = 263,
     ELSE = 264,
     BEGINI = 265,
     END = 266,
     WHILE = 267,
     DO = 268,
     VAR = 269,
     AS = 270,
     INT = 271,
     BOOL = 272,
     LP = 273,
     RP = 274,
     ASGN = 275,
     SC = 276,
     WRITEINT = 277,
     READINT = 278,
     SYMBOL = 279,
     ident = 280,
     num = 281,
     boollit = 282,
     identifierType = 283
   };
#endif
/* Tokens.  */
#define OP2 258
#define OP3 259
#define OP4 260
#define PROGRAM 261
#define IF 262
#define THEN 263
#define ELSE 264
#define BEGINI 265
#define END 266
#define WHILE 267
#define DO 268
#define VAR 269
#define AS 270
#define INT 271
#define BOOL 272
#define LP 273
#define RP 274
#define ASGN 275
#define SC 276
#define WRITEINT 277
#define READINT 278
#define SYMBOL 279
#define ident 280
#define num 281
#define boollit 282
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

