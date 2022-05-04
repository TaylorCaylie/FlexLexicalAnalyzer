/* defintion section */
%{
#include <stdio.h> 
#include <stdlib.h>
#include "nodes.h"
#include "analyzerrules.tab.h"
extern int yylex();
%}


EQ_OP "==" 
LESSTHAN_OP "<"
GREATERTHAN_OP ">"
NOTEQUAL_OP "!="
LESSEQUALTHAN_OP "<="
GREATEREQUALTHAN_OP ">="
ADD_OP "+"
SUBTRACT_OP "-"
MULTIPLY_OP "*"
OR "|"
EQUAL_OP "="
COMMA ","
COLON ":"
OPENINGBRACKET "["
CLOSINGBRACKET "]"
OPENINGPARANTHESIS "("
CLOSINGPARANETHESIS ")"
OPENINGBRACE "{"
CLOSINGBRACE "}"
DIV_OP "div"
MOD_OP "mod"


/* specifies that only one input file should be read in */
%option noyywrap

OP3 [ADD_OP|SUBTRACT_OP]
OP2 [MULTIPLY|DIV|MOD]
SINGLECHAR [OR|COMMA|COLON|OPENINGBRACE|OPENINGBRACKET|OPENINGPARANTHESIS|CLOSINGBRACE|CLOSINGBRACKET|CLOSINGPARANETHESIS]
COMPARISONS [EQ|NOTEQUAL|LESSEQUALTHAN|LESSTHAN|GREATEREQUALTHAN|GREATERTHAN|DIV|MOD]
NUMBER [1-9][0-9]*|0 
BOOLEX false|true
ID [A-Z][A-Z0-9]*

/* The rules section of the flex input contains a series of rules of the form: pattern -> action */
%%

{COMPARISONS} {
    printf("COMP OPERATOR: %s\n", yytext);
    if (strcmp(yytext, "==") == 0) {
        yylval.fn = 1;
    }else if (strcmp(yytext, "!=") == 0) {
        yylval.fn = 2;
    }else if (strcmp(yytext, "<=") == 0) {
        yylval.fn = 3;
    }else if (strcmp(yytext, ">=") == 0) {
        yylval.fn = 4;
    }else if (strcmp(yytext, ">") == 0) {
        yylval.fn = 5;
    }else {
        yylval.fn = 6;
    }

    return OP4;
}

"int" {
    printf("type: %s\n", yytext);
    yylval.typeIdent = 'a';
    return identifierType;
}

"bool" {
    printf("type: %s\n", yytext);
    yylval.typeIdent = 'a';
    return identifierType;
}

";" {
     printf("SC: %s\n", yytext);
    return yytext[0];
}

{SINGLECHAR} {
    printf("SINGLE CHAR: %s\n", yytext);
    return yytext[0];
}

{OP3} {
    printf("OP3 OPERATOR: %s\n", yytext);
    if (strcmp(yytext, "+") == 0) {
        yylval.number = ADD;
    }else {
         yylval.number = SUBTRACT;
    }

    return(OP3);
}

{OP2} {
    printf("OP2 OPERATOR: %s\n", yytext);
    if (strcmp(yytext, "*") == 0) {
        yylval.number = MULTIPLY;
    }else if (strcmp(yytext, "div") == 0) {
        yylval.number = DIV;
    }else {
        yylval.number = MOD;
    }

    return(OP2);
}

{NUMBER} {
    // yylval=atof(yytext);
    printf("integer: %s\n", yytext);
    yylval.number = atof(yytext); 
    return(num);
}

":=" {
    printf("ASGN: %s\n", yytext);
    return(ASGN); 
}

{BOOLEX} {
    if (strcmp(yytext, "false") == 0) {
        yylval.boolVal = 0;
    }else {
        yylval.boolVal = 1;
    }

    return(boollit);
}

"if" return(IF);
"then" return(THEN);
"else" return(ELSE);
"begin" return(BEGINI);
"end" return(END);
"while" return(WHILE);
"do" return(DO);
"program" {
    printf("keyword: %s\n", yytext);
    return(PROGRAM);
}
"var" {
    printf("keyword: %s\n", yytext);
    return(VAR);
}
"as" {
    printf("keyword: %s\n", yytext);
    return(AS);
}

"asgn" return(ASGN);

"readInt" {
    printf("Built-In Procedure: %s\n", yytext);
    return(READINT);
}

"writeInt" {
    printf("Built-In Procedure: %s\n", yytext);
    return(WRITEINT);
}

{ID} {
    // yylval=atof(yytext);
    printf("identifier: %s\n", yytext);
    yylval.symbol = lookUp(yytext);

    return(SYMBOL);
}

[\n]		{yylineno++;}


%%


