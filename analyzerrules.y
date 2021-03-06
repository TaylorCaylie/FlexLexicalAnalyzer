%{
#include <stdio.h>
#include <stdlib.h>
#include "nodes.h"
#include <stdarg.h>
#include <string.h>
extern FILE *yyin;
extern int yylineno;
%}


/* union is to allow storing different kind of objects 
into nodes that are emitted by flex */
%union{
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

/* declare tokens */

%token <number> OP2 OP3 OP4
%token PROGRAM IF THEN ELSE BEGINI END WHILE DO VAR AS INT BOOL LP RP ASGN SC 
%token <str> WRITEINT READINT
%token <symbol> SYMBOL ident num boollit 
%token <typeIdent> identifierType


/* types */
%type <statements> declarations statements statementExpression simpleExpression declaration assignment writeInt expression factor term


/* start from expression */
%start program
%%

program: 
    PROGRAM declarations BEGINI statements END { eval($2); eval($4); }
    ;

declarations:
    declaration SC declarations { if($3 == NULL) $$ = $1; else $$ = newExp('L', $1, $3); }
    | { $$ = NULL; }
    ;

declaration:
    VAR SYMBOL AS identifierType { $$ = opr(AS, 4, $4, str($2)); }
	| { $$ = NULL;  }
	;

statements:
    statements SC statementExpression { $$ = newExp('L', $1, $3); }
    | statementExpression	{ $$ = $1; }
    | { $$ = NULL; }
    ;

statementExpression:
    assignment { $$ = $1; } 
    | WHILE expression DO statements END { $$ = newExp('W', $2, $4); }
    | IF expression THEN statements END { $$ = newExp('I', $2, $4); }
    | writeInt expression { $$ = $1; }
    ;

assignment:
    ident ASGN expression { $$ = opr(ASGN, 2, str($1), $3); }
	| ident ASGN READINT { $$ = newDeclaration($1, $3);; }
	;

writeInt:
	WRITEINT expression { $$ = newExp('R', $2, NULL); }
	;

expression:
   simpleExpression { $$ = $1; }
	| simpleExpression OP4 simpleExpression { $$ = newExp($2, $1, $3); }
	;

simpleExpression:
   term OP3 term { $$ = newExp($2, $1, $3); }
	| term { $$ = $1; }
	;

term:
    factor OP2 factor { $$ = opr($2, 2, $1, $3); }
	| factor { $$ = $1; }
	;

factor: 
    ident { $$ = str($1);; }
    | boollit { $$ = lit($1); }
	| num { $$ = lit($1); }
	| LP expression RP { $$ = $2; }
	;

%%

int main(int argc, char** argv) {
  // Open a particular file:
  FILE *myfile = fopen("input.lex", "r");

  // Make sure file is valid
  if (!myfile) {
    printf("failed to open file\n");
    return -1;
  }

  // Set Flex to read from it instead of defaulting to STDIN:
  yyin = myfile;
  
  // Parse through the input:
  yyparse();
}