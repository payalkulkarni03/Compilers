Q. Implement a parser for an expression grammar using YACC and LEX for the
subset of C. Cross check your output with Stanford LEX and YACC
var.y
%{
#include<stdio.h>
%}
%token ID BUILTIN SC NL COMMA
%%
start:BUILTIN varlist SC NL {printf("valid");}
|
varlist:varlist COMMA ID|ID;
%%
int yyerror(const char *str){printf("%s","error");}
int yywrap(){return 0;}
int main(){yyparse();}
var.l
%{
#include<stdio.h>
#include "y.tab.h"
%}
%%
int|float|char return BUILTIN;
"," return COMMA;
";" return SC;
[a-zA-Z]+[a-zA-Z0-9]* return ID;
"\n" return NL;
%%
