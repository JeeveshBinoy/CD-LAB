%{
	#include <stdio.h>
	int valid=1;
	int yyerror(const char *s);
	int yylex(void);
%}

%token LETTER DIGIT;

%%
start : LETTER s;
s	: LETTER s 
	| DIGIT s 
	| /* empty */    
	;
%%

int yyerror(const char *s){
	printf("Invalid identifier!\n");
	valid=0;
	return 0;
}

int main(){
	printf("Enter identifier : ");
	yyparse();
	if(valid){
		printf("Valid Identifier\n");
	}
	return 0;
}
