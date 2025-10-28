%{
	#include <stdio.h>
	int yylex(void);
	int yyerror(const char *s);
%}

%token FOR LPAREN RPAREN LBRACE RBRACE SEMI GT LT ASSIGN ADD SUB MUL DIV INC DEC NUM ID

%left LT GT
%left ADD SUB
%left MUL DIV
%right ASSIGN
%left INC DEC

%%

s : FOR LPAREN E SEMI E SEMI E RPAREN BODY	{printf("Valid Syntax!\n");}
  ;
  
BODY : LBRACE STMT_LIST RBRACE
	 | /* empty */
	 ;

STMT_LIST : STMT
		  | STMT_LIST STMT
		  ;
		  
STMT : E SEMI
     | s
     ;
     
E : ID
  | NUM
  | ID ASSIGN E
  | E GT E
  | E LT E
  | E ADD E
  | E SUB E
  | E MUL E
  | E DIV E
  | ID INC
  | ID DEC
  ;
	
	
%%

int yyerror(const char *s){
	fprintf(stderr,"%s : Invalid Statement\n",s);
	return 0;
}

int main(){
	printf("Enter the for loop : ");
	yyparse();
	return 0;
}
