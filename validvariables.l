%{
	#include "y.tab.h"
%}

%%
[a-zA-Z_][a-zA-Z0-9_]*	{return LETTER;}
[0-9]+	{return DIGIT;}
[ \t] ;
.	{return yytext[0];}
\n	{return 0;}
%%

int yywrap(void){
	return 1;
}
