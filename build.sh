rm analyzerrules.tab.c
rm analyzerrules.tab.h
rm lex.yy.c
flex flexanalyzer.l
bison -d analyzerrules.y
gcc *.c -o compiler
./compiler
