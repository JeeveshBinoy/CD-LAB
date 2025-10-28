#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char input[100];
int i=0;
char lookahead;

void next(){
	lookahead = input[i++];
}

void match(char c){
	if(lookahead == c){
		next();
	} else {
		printf("Error : expected '%c' , got '%c'\n",c,lookahead);
		exit(1);
	}
}

void F();
void E();
void T();
void Tprime();
void Eprime();

void F(){
	if(lookahead == 'i'){
		printf("F->i\n");
		match('i');
	} else if (lookahead == '('){
		match('(');
		E();
		match(')');
	} else {
		printf("Error in F at '%c'\n",lookahead);
		exit(1);
	}
}

void Tprime(){
	if(lookahead == '*'){
		printf("T'->*FT'\n");
		match('*');
		F();
		Tprime();
	} else {
		printf("T'->e\n");
	}
}

void T(){
	printf("T->FT'\n");
	F();
	Tprime();
}

void Eprime(){
	if(lookahead == '+'){
		printf("E'->+TE'\n");
		match('+');
		T();
		Eprime();
	} else {
		printf("E'->e\n");
	}
}

void E(){
	printf("E->TE'\n");
	T();
	Eprime();
}

int main(){
	printf("Enter the input string : ");
	scanf("%s",input);
	
	next();
	E();
	
	if(lookahead=='$'){
		printf("Parsing Successfull\n");
	} else {
		printf("Error in input\n");
	}
	return 0;
}
