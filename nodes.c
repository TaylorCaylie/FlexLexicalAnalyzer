#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "nodes.h"
#include <stdarg.h>
extern int yylineno;

Exp* var(char* name);
Exp* lit(struct symbol *symbole);
Exp* str(struct symbol *symbol);
Exp* opr(int operation, int ops, ...);
double eval(struct Exp *e);

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
	printf("Error: %s: line number %d\n", s, yylineno);
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
Exp *lit(struct symbol *symbol) { 
	Exp* pntr;

	if ((pntr = malloc(sizeof(Exp))) == NULL) {
		yyerror("Memory out of bound!");
    }

	pntr->types = literalType;
	pntr->symbol = symbol;

	return pntr;
}

Exp *str(struct symbol *symbol) {
	Exp* pntr;

	if ((pntr = malloc(sizeof(Exp))) == NULL) 
		yyerror("Memory out of bound!");
	
	pntr->types = identifierNodeType;
	pntr->symbol = symbol;

	return pntr;
}

double eval(struct Exp *e) {
    if(!e) {
		yyerror("expression passed in is null");

		return 0.0;
	}

    double type;
    switch(e->expType) {
        case 'S':
        default:
            printf("invalid node type %c", e->expType);
    }

    return type;
}

// two possible types to be declared for a variable - either number or bool
struct Exp *newDeclaration(struct symbol *symbol, char type) {
    struct declaration *d = malloc(sizeof(struct declaration));

	if(!d) {
		yyerror("out of space");
		
		exit(0);
	}

	d->nodeType ='X';
	d->symbol = symbol;
	d->type = type;

	return (Exp *)d;
}

struct Exp *newAssign(struct symbol *symbol, struct Exp *v) {
	struct symbolAssign *sa = malloc(sizeof(struct symbolAssign));

	if(!sa) {
		yyerror("out of space");

		exit(0);
	}

	sa->nodeType = ":=";
	sa->symbol = symbol;
	sa->v = v;

	return (struct Exp *)sa;
}

Exp* opr(int operation, int ops, ...) { // For operators
	printf("hi");
    Exp* assi;

	int i;

	if ((assi = malloc(sizeof(Exp))) == NULL)  // memory not available
		yyerror("out of memory");

	if ((assi->oper.operands = malloc(ops * sizeof(Exp*))) == NULL) // memory not available
		yyerror("out of memory!");

    assi->oper.numops = ops;

	assi->types = operatorType;

	assi->oper.operation = operation;
    
	return assi;
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