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
    identifierNodeType,
    operatorType
} TypesNodes;


struct declaration 
{
	int nodeType;

	struct symbol *symbol;

	char type;
};

typedef struct {
	int operation;
	int numops;
	struct opType **operands;
} operatorNode;

// if its an operator type encapsulates another type
// can either be an identifier, literal, or number
typedef struct Exp {
    int expType;

    union {
        int literalNode;
        char* identifierNode;
        operatorNode oper;
    };

    struct symbol *symbol;
    TypesNodes types;

    struct Exp *left;
    struct Exp *right;
} Exp;

struct Exp *newExp(int expType, Exp *left, Exp *right);
struct Exp *newDeclaration(struct symbol *symbol, char type);
struct Exp *str(struct symbol *symbol);
struct Exp *lit(struct symbol *symbol);

struct symbol 
{
	double *arrHead;
	double value;

	char *name;
	char type;

	int arrLength;
	int initialIndex;
};
double eval(struct Exp *e);

#define NHASH 9997
struct symbol symbolTable[NHASH];
struct symbol *lookUp(char *);

struct symbolAssign 
{
	char* nodeType;

	struct symbol *symbol;

	struct Exp *v;
};

Exp* opr(int operation, int ops, ...);
struct Exp *newAssign(struct symbol *symbol, struct Exp *v); 

struct symbolList 
{
	struct symbol *symbol;
	struct symbolList *next;
};

struct symbolList *newSymbolList(struct symbol *symbol, struct symbolList *next);
