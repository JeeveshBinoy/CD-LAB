#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *keywords[] = {"int","float","if","else"};
int n = 4;

int isKeyword(char *word){
	for(int i=0;i<n;i++){
		if(strcmp(word,keywords[i])==0){
			return 1;
		}
		return 0;
	}
}

int isDelimiter(char ch){
	return (ch==';' || ch==',' || ch=='(' || ch==')' || ch=='{' || ch=='}' || ch=='[' || ch==']');
}

int isOperator(char ch){
	return (ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='=' || ch=='<' || ch=='>');
}

int main(){
	char input[1000];
	printf("Enter the code : ");
	fgets(input,sizeof(input), stdin);
	
	int i=0;
	while(input[i]!='\0'){
	
		if(input[i]==' '||input[i]=='\t'||input[i]=='\n'){
			i++;
			continue;
		}
		
		if(input[i]=='/' && input[i+1]=='/'){
			while(input[i]!='\n' && input[i]!='\0'){
				i++;
			}
			continue;
		}
		
		if(input[i]=='/' && input[i+1]=='*'){
			i+=2;
			while(input[i] && !(input[i] == '*' && input[i+1] == '/')){
				i++;
			}
			i+=2;
			continue;
		}
		
		if(isalpha(input[i]) || input[i] == '_'){
			char word[100];
			int j=0;
			
			while(isalnum(input[i]) || input[i] == '_'){
				word[j++] = input[i++];
			}
			word[j]='\0';
			
			if(isKeyword(word))
				printf("KEYWORD: %s\n", word);
				
			else 
				printf("IDENTIFIER: %s\n", word);
		}
		
		else if(isdigit(input[i])){
			char num[100];
			int j=0;
			
			while(isdigit(input[i])){
				num[j++]=input[i++];
			}
			num[j]='\0';
			printf("NUMBER: %s\n", num);
		}
		
		else if(isDelimiter(input[i])){
			printf("DELIMITER: %c\n",input[i]);
			i++;
		}
		
		else if(isOperator(input[i])){
			printf("OPERATOR: %c\n",input[i]);
			i++;
		}
		
		else {
			printf("UNKNOWN: %c\n",input[i]);
			i++;
		}
		
	}
	
	return 0;
}
