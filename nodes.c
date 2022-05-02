#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "nodes.h"
#include <stdarg.h>

Node* opr(int operation, int num_ops, ...);
Node* var(char* name);
Node* lit(int value);
Node* str(char* str);

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
Node *lit(int value) { 
	Node* pntr;

	if ((pntr = malloc(sizeof(Node))) == NULL) {
		yyerror("Memory out of bound!");
    }

	pntr->types = literalType;
	pntr->literalNode = value;

	return pntr;
}

Node *str(char* str) {
	Node* pntr;

	if ((pntr = malloc(sizeof(Node))) == NULL)  // memory not available
		yyerror("Memory out of bound!");
	
	pntr->types = identifierType;
	pntr->identifierNode = str;

	return pntr;
}

// for nodes of operator type
// Node* opr(int operation, int num_ops, ...) { 
// 	va_list ap;
// 	Exp* pntr;
// 	int i;
        	
// 	if ((pntr = malloc(sizeof(Node))) == NULL)  // memory not available
// 		yyerror("Memory out f bound!");

// 	if ((pntr->op.operands = malloc(num_ops * sizeof(Node*))) == NULL) // memory not available
// 		yyerror("Memory out of bound!");

// 	pntr->types = typeOp;
// 	pntr->op.operation = operation;
// 	pntr->op.num_ops = num_ops;
// 	va_start(ap, num_ops);

// 	for (i = 0; i < num_ops; i++)
// 		pntr->op.operands[i] = va_arg(ap, Node*);
		
// 	va_end(ap);
// 	return pntr;
// }


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