%{
#include "y.tab.h"
#include <string.h>
%}


%%
[0-9]+            { strcpy(yylval.sval, yytext); return NUM; }
[a-zA-Z][a-zA-Z0-9]*  { strcpy(yylval.sval, yytext); return NUM; }
[+\-*/()]         { return yytext[0]; }
[ \t\n]+          ;    /* skip spaces and newlines */
.                 ;

%%
int yywrap() { return 1; }

