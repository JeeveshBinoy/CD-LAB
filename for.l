%{
	#include "y.tab.h"
%}

%%

"for"		{return FOR;}
"("			{return LPAREN;}
")"			{return RPAREN;}
"{"			{return LBRACE;}
"}"			{return RBRACE;}
";"			{return SEMI;}
">"			{return GT;}
"<"			{return LT;}
"="			{return ASSIGN;}
"+"			{return ADD;}
"-"			{return SUB;}
"*"			{return MUL;}
"/"			{return DIV;}
"++"		{return INC;}
"--"		{return DEC;}
[0-9]+		{return NUM;}
[a-zA-Z_][a-zA-Z0-9_]*	{return ID;}
[ \t\n]		;
.			{return yytext[0];}

%%

int yywrap(void){
	return 1;
}


