#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "nodes.h"
#include <stdarg.h>

Exp* var(char* name);
Exp* lit(int value);
Exp* str(char* str);

int SymbolHash(char *symbol) {
	unsigned int hash = 0;

	unsigned ch;

	while(ch == *symbol++) {
		hash = hash * 9 ^ ch;

		return hash;
	}

    return 0;
}

// newExp creates a new expression using the type (+, -,  *, /) and then the left and right values that represent a num variable 
struct Exp *newExp(int expType, Exp *left, Exp *right) {
    // allocate memory for passed in expression
	Exp *expression = malloc(sizeof(Exp));

    // if the memory allocation was not successful return an error
	if(!expression) {
		yyerror("not enough space to allocate memory for expression");

		exit(0);
	}

	expression->expType = expType;
	expression->left = left;
	expression->right = right;

	return expression;
}

void yyerror(char *s) {
	fprintf(stderr, "error: %s\n", s);
}

struct symbol *lookUp(char *symbol) {
	struct symbol *s = &symbolTable[SymbolHash(symbol) % NHASH];

	int symbolCount = NHASH;

	while(--symbolCount >= 0) {
		if(s->name && !strcmp(s->name, symbol)) {
			return s;
		}

		if(!s->name) {
			s->name = strdup(symbol);
			s->value = 0;

			return s;
		}

		if(++s >= symbolTable + NHASH) {
			s = symbolTable;
		}
	}

	yyerror("symbol table overflow occurred\n");

	abort();
}


// if the node is a literal node type
Exp *lit(int value) { 
	Exp* pntr;

	if ((pntr = malloc(sizeof(Exp))) == NULL) {
		yyerror("Memory out of bound!");
    }

	pntr->types = literalType;
	pntr->literalNode = value;

	return pntr;
}

Exp *str(char* str) {
	Exp* pntr;

	if ((pntr = malloc(sizeof(Exp))) == NULL) 
		yyerror("Memory out of bound!");
	
	pntr->types = identifierNodeType;
	pntr->identifierNode = str;

	return pntr;
}

// two possible types to be declared for a variable - either number or bool
struct Exp *newDeclaration(struct symbolList *symbolList, char type) {
	struct declaration *d = malloc(sizeof(struct declaration));

	if(!d) {
		yyerror("out of space");
		
		exit(0);
	}

	d->nodeType ='X';
	d->symbolList = symbolList;
	d->type = type;

	return (Exp *)d;
}

struct symbolList *newSymbolList(struct symbol *symbol, struct symbolList *next) {
	struct symbolList *sl = malloc(sizeof(struct symbolList));

    	if(!sl) {
        	yyerror("out of space");

        	exit(0);
 	}
 
    	sl->symbol = symbol;
    	sl->next = next;
     
	return sl;
}