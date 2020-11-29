Q. Implement a Lexical Analyzer using LEX for a subset of C. Cross check your
output with Stanford LEX
add.c
#include<stdio.h>
int main(){
printf("Enter two numbers:\n");
int a,b,c;
scanf("%d,%d",&a,&b);
c=a+b;
printf("Addition:%d ",c);
return 0;
}
tokens.l
%{
#include <stdio.h>
int kw=0, iden=0, num=0,w=0;
%}
DIGIT [0-9]
NUMBER {DIGIT}+
REAL {DIGIT}*"."{DIGIT}+
TEXT [a-zA-Z]+
TEXT_NUMBERS [a-zA-Z0-9]
CONDITIONALS "if"|"else"|"else if"|"switch"|"case"
KEYWORD
"break"|"class"|"args"|"nextInt"|"continue"|"goto"|"print"|"Scanner"|"System"|"out"|"println"|"new"|"
try"|"cat
ch"|"Exception"|"public"|"close"|"return"|"int"|"float"|"char"|"unsigned"|"signed"|"String"|"long"|"d
ouble"|"st
atic"|"void"|"main"
ITERATORS "for"|"while"|"do"
PREPROCESSOR "import"|"java.util.Scanner"|"package"
DELIMITER [; :\t\n()"]
IDENTIFIER [a-zA-Z]{TEXT_NUMBERS}*|[a-zA-Z]{TEXT_NUMBERS}*[[{NUMBER}+]]
NON_IDENTIFIER {NUMBER}+[A-Za-z]+
COMMENT "/*"[a-zA-Z0-9 \t\n;.~!@#$%^&*()_+=<>?:"{}]*"*/"
OPERATOR "+"|"-"|"*"|"/"|"="
UNARY "++"|"--"
LOPERATOR "&"|"|"|"&&"|"~"|"||"|">"|"<"|">="|"<="|"=="
FUNCTION {IDENTIFIER}+"("{DELIMITER}*{TEXT}
{TEXT_NUMBERS}*{DELIMITER}*")"
%%
{CONDITIONALS} { printf("%s is a conditional\n", yytext); } {kw++;}
{ITERATORS} { printf("%s is an iterator\n", yytext); } {kw++;}
{DIGIT} { printf("%s is a digit\n", yytext); } {num++;}
{NUMBER} { printf("%s is a number\n", yytext); } {num++;}
{REAL} { printf("%s is a real number\n", yytext); } {num++;}
{PREPROCESSOR} { printf("%s is a preprocessor directive\n",yytext); } {kw++;}
{DELIMITER} { /*printf("%s is a delimiter\n", yytext);*/ }{KEYWORD} { printf("%s is a
keyword\n", yytext); } {kw++;}
{NON_IDENTIFIER} {printf("Could not process %s", yytext); }{w++;}
{IDENTIFIER} { printf("%s is an identifier\n", yytext); } {w++;}
{COMMENT} { printf("%s is a comment\n", yytext); } {w++;}
{OPERATOR} { printf("%s is a mathematical operator\n", yytext); }
{LOPERATOR} { printf("%s is a logical operator\n", yytext); }
{UNARY} { printf("%s is a unary operator\n", yytext); }
{FUNCTION} { printf("%s is a function\n", yytext); } {kw++;}
%%
int main(int argc, char *argv[]) {
yyin= fopen("add.c","r");
yylex();
printf("\nNumber of words: %d\nNumber of keywords: %d\nNumber of numbers: %d\
n",w,kw,num);
return 0;
}
int yywrap(){
return 1;
}
