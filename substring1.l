%{
	#include <stdio.h>
	#include <string.h>
	char first[5];
%}

%%
[a-zA-Z]+ {	if(strstr(yytext,first)!=NULL){
				printf("%s contains '%s' as substring\n",yytext,first);
			} else {
				printf("%s does not contains '%s' as substring\n",yytext,first);
			}
		  }
\n
. 
%%

int yywrap(void){
	return 1;
}

int main(){
	printf("Enter the substring (upto 4 letters) : ");
	scanf("%s",first);
	first[4]='\0';
	printf("Enter the string: ");
	yylex();
	return 0;
}
