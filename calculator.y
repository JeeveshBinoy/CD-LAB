%{
	#include <stdio.h>
	int yylex(void);
	int yyerror(const char *s);
%}

%token DIGIT

%%

start : E	{printf("Result : %d\n",$1);}
	  ;
	  
E : E '+' T	{$$ = $1 + $3;}
  | E '-' T	{$$ = $1 - $3;}
  | T	{$$ = $1;}
  ;
  
T : T '*' F	{$$ = $1 * $3;}
  | T '/' F	{if($3!=0) {$$ = $1 / $3;} else return yyerror("Cannot divide by zero\n");}
  | F	{$$ = $1;}
  ;
  
F : '(' E ')' {$$ = $2;}
  | DIGIT	{$$ = $1;}
  ;

%%

int yyerror(const char *s){
	fprintf(stderr, "%s\n",s);
	return 0;
}

int main(){
	printf("Input the expression: ");
	yyparse();
}
