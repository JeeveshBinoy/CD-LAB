#include <stdio.h>
#include <string.h>

char stack[100],input[100];
int top=-1, i = 0;

void shift(){
	stack[++top]=input[i++];
	stack[top+1]='\0';
	printf("Shift -> Stack : %s\n",stack);
}

int reduce(){
	
	if(top>=0 && stack[top]=='i'){
		stack[top]='E';
		printf("Reduce: E->i\n");
		return 1;
	}
	
	if(top>=2 && stack[top-2]=='E' && stack[top-1]=='+' && stack[top]=='E'){
		top-=2;
		stack[top]='E';
		stack[top+1]='\0';
		printf("Reduce: E->E+E\n");
		return 1;
	}
	
	if(top>=2 && stack[top-2]=='E' && stack[top-1]=='*' && stack[top]=='E'){
		top-=2;
		stack[top]='E';
		stack[top+1]='\0';
		printf("Reduce: E->E*E\n");
		return 1;
	}
	
	if(top>=2 && stack[top-2]=='(' && stack[top-1]=='E' && stack[top]==')'){
		top-=2;
		stack[top]='E';
		stack[top+1]='\0';
		printf("Reduce: E->(E)\n");
		return 1;
	}
	
	return 0;
}

int main(){
	printf("Enter the input : ");
	scanf("%s",input);
	
	while(input[i]!='$'){
		shift();
		while(reduce());
	}
	
	while(reduce());
	
	if(top==0 && stack[top]=='E'){
		printf("Valid\n");
	} else {
		printf("Invalid\n");
	}
	return 0;
}
