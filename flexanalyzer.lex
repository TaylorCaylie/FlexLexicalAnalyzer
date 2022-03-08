/* defintion section */
%{
#include <stdio.h> 
#include <stdlib.h>
#define num  0
#define ident 1
#define END 2
#define ASGN 3
#define LP 4
#define RP 5
#define SC 6
#define boollit 7
#define OP3 8
#define OP4 9
#define OP2 10
#define IF 11
#define THEN 12
#define ELSE 13
#define START 14
#define WHILE 15
#define DO 16
#define PROGRAM 17
#define VAR 18
#define AS 19
#define INT 20 
#define BOOL 21
#define READINT 22
#define WRITEINT 23
float yylval;
%}

OP4EX [=|!=|<|>|<=|>=]
OP3EX [+|-]
/*TODO how to fix this regex */
OP2EX [*|div|mod]
NUMBER [1-9][0-9]*|0 
BOOLEX false|true
ID [A-Z][A-Z0-9]*

/* The rules section of the flex input contains a series of rules of the form:
 pattern action */
%%
{NUMBER} {
    // yylval=atof(yytext);
    printf("integer: %s\n", yytext);
    return(num);
}
{ID} {
    // yylval=atof(yytext);
    printf("ident: %s\n", yytext);
    return(ident);
}
if|then|else|begin|end|while|do|program|var|as|int|bool {
    printf("keyword: %s\n", yytext);
}
":=" {
    printf("ASGN: %s\n", yytext);
    return(ASGN); 
}
"(" {
    printf("LP: %s\n", yytext);
    return(LP);
}
")" {
    printf("RP: %s\n", yytext);
    return(RP);
}
";" {
    printf("SC: %s\n", yytext);
    return(SC);
}
{BOOLEX} return(boollit);
{OP3EX} {
    printf("OP3: %s\n", yytext);
    return(OP3);
}
{OP2EX} {
    printf("OP2: %s\n", yytext);
    return(OP2);
}
{OP4EX} {
    printf("OP4: %s\n", yytext);
    return(OP4);
}
"if" return(IF);
"then" return(THEN);
"else" return(ELSE);
"begin" return(START);
"end" return(END);
"while" return(WHILE);
"do" return(DO);
"program" return(PROGRAM);
"var" return(VAR);
"as" return(AS);
"int" return(INT);
"bool" return(BOOL);
"readInt" {
    printf("Built-In Procedure: %s\n", yytext);
    return(READINT);
}
"writeInt" {
    printf("Built-In Procedure: %s\n", yytext);
    return(WRITEINT);
}
%%

int main ()
{

    FILE *fp;
    char filename[50];
    printf("Enter the filename: \n");
    scanf("%s",filename);
    fp = fopen(filename,"r");
    yyin = fp;

    int ret =0;
    while(ret != END) {
    ret = yylex();
    // printf("ret = %d, yylval = %f\n", ret, yylval);
    }
    return 0;
}
