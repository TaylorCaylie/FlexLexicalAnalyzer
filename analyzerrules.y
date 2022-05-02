%{
#include <stdio.h>
#include <stdlib.h>
#include "nodes.h"
#include <stdarg.h>
#include <string.h>
extern FILE *yyin;
%}


/* union is to allow storing different kind of objects 
into nodes that are emitted by flex */
%union{
    int number;
    int boolVal;
    char* str;
    Exp *statements;
    int fn;
    double d;
    struct symbol *symbol;
	struct symbolList *symbolList;
}

/* declare tokens */
%token <number> num boollit OP2 OP3 OP4
%token PROGRAM IF THEN ELSE BEGINI END WHILE DO VAR AS INT BOOL LP RP ASGN SC
%token <str> READINT WRITEINT 
%token <symbol> SYMBOL ident

/* types */
%type <statements> declarations statements statementExpression simpleExpression declaration assignment type writeInt expression factor term


/* start from expression */
%start program
%%

program: 
    PROGRAM declarations BEGINI statements END
    ;

declarations:
    declaration ';' declarations { if($3 == NULL) $$ = $1; else $$ = newExp('L', $1, $3); }
    | { $$ = NULL; }
    ;

declaration:
    VAR ident AS type { $$ = newDeclaration($2, $4); }
	| { $$ = NULL;  }
	;

type:
    INT { $$ = str("int");  }  
    | BOOL { $$ = str("bool"); } 
    ;

statements:
    statementExpression	{ $$ = $1; }
    | statements SC statementExpression { $$ = newExp('L', $1, $3); }
    | { $$ = NULL; }
    ;

statementExpression:
    WHILE expression DO statements END { $$ = newExp('W', $2, $4); }
    | IF expression THEN statements END { $$ = newExp('I', $2, $4); }
    | writeInt expression { $$ = $1; }
    | assignment { $$ = $1; } 
    | expression
    ;

assignment:
    ident ASGN expression { $$ = newExp('A', $1, $3); }
	| ident ASGN READINT { $$ = newExp('A', $1, $3); }
	;

writeInt:
	WRITEINT expression { $$ = newExp('WI', $2, NULL); }
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
    factor OP2 factor { $$ = newExp($2, $1, $3); }
	| factor { $$ = $1; }
	;

factor: 
    ident { $$ = str($1); }
	| num { $$ = lit($1);
		if(!($1 >=-2147483647 && $1 <= 2147483647)) {
			yyerror("Integer overflow at line number "); }
 		}
	| boollit { $$ = lit($1); }
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