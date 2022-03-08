%{
#include <stdio.h>
%}

/* union is to allow storing different kind of objects 
into nodes that are emitted by flex */
%union{
    int num;
    char* str;
}

/* declare tokens */
%token <num> num boollit OP2 OP3 OP4
%token <str> ident
%token LP RP ASGN SC
%token IF THEN ELSE BEGIN_STMT END WHILE DO PROGRAM VAR AS INT BOOL
%token READINT WRITEINT 

/* start from expression */
%start program


%%
program: 
    PROGRAM declarations BEGIN statementSequence END

declarations:
     VAR ident AS type SC declarations | ε

type:
    INT | BOOL

statementSequence:
    statement SC statementSequence | ε

statement:
    assignment | ifStatement | whileStatement | writeInt

assignment:
    ident ASGN expression | ident ASGN READINT

ifStatement: IF <expression> THEN <statementSequence> <elseClause> END

<elseClause> ::= ELSE <statementSequence>
             | ε

<whileStatement> ::= WHILE <expression> DO <statementSequence> END

<writeInt> ::= WRITEINT <expression>

<expression> ::= <simpleExpression>
             | <simpleExpression> OP4 <simpleExpression>

<simpleExpression> ::= <term> OP3 <term>
                   | <term>

<term> ::= <factor> OP2 <factor>
       | <factor>

<factor> ::= ident
         | num
         | boollit
         | LP <expression> RP

%%