#include <stdbool.h>

void yyerror(char *s);

int yyparse();
int yylex();

typedef enum {
    EQ,
    LESSTHAN,
    GREATERTHAN,
    NOTEQUAL,
    LESSEQUALTHAN,
    GREATEREQUALTHAN,
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIV,
    MOD
}Compare_Arith_Operators;

// an enum 
typedef enum TypesNodes {
    literalType,
    numberType,
    identifierType,
    operatorType
} TypesNodes;

// can either be an identifier, literal, or number
typedef struct Node {
    union {
        int literalNode;
        char* identifierNode;
    };

    TypesNodes types;
} Node;

Node *str(char* str);
Node *lit(int value);

struct declaration 
{
	int nodeType;

	struct symbolList *symbolList;

	char type;
};

// if its an operator type encapsulates another type
typedef struct Exp {
    int expType;

    struct Exp *left;
    struct Exp *right;
} Exp;

struct Exp *newExp(int expType, Exp *left, Exp *right);
struct Exp *newDeclaration(struct symbolList *symbolList, char type);

struct symbol 
{
	double *arrHead;
	double value;

	char *name;
	char type;

	int arrLength;
	int initialIndex;
};

#define NHASH 9997
struct symbol symbolTable[NHASH];
struct symbol *lookUp(char *);

struct symbolList 
{
	struct symbol *symbol;
	struct symbolList *next;
};

struct symbolList *newSymbolList(struct symbol *symbol, struct symbolList *next);
