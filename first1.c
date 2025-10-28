#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 20

char prod[MAX][MAX];
char nonterminals[MAX];
int n,ntCount=0;

char firstSet[MAX][MAX];
char followSet[MAX][MAX];

int isTerminal(char c){
	return !isupper(c) && c!='e';
}

void add(char *set, char c){
	if(!strchr(set,c)){
		int len = strlen(set);
		set[len]=c;
		set[len+1]='\0';
	}
}

void findfirst(char symbol, char *result){
	for(int i=0;i<n;i++){
		if(prod[i][0]==symbol){
			for(int j=2;prod[i][j]!='\0';j++){
				char next = prod[i][j];
				
				if(isTerminal(next)){
					add(result,next);
					break;
				} else if (next == 'e'){
					add(result,'e');
					break;
				} else {
					char temp[20]="";
					findfirst(next,temp);
					for(int k=0;temp[k];k++){
						add(result,temp[k]);
					}
					
					if(!strchr(temp,'e')){
						break;
					}
				}
				
				if(prod[i][j+1]=='\0'){
					add(result,'e');
				}
			}
		}
	}
}

void findfollow(char symbol, char *result){
	if(symbol==prod[0][0]){
		add(result,'$');
	}
	
	for(int i=0;i<n;i++){
		for(int j=2;prod[i][j]!='\0';j++){
			if(prod[i][j]==symbol){
				if(prod[i][j+1]!='\0'){
					char next = prod[i][j+1];
					
					if(isTerminal(next)){
						add(result,next);
					} else {
						char temp[20]="";
						findfirst(next,temp);
						for(int k=0;temp[k];k++){
							if(temp[k]!='e'){
								add(result,temp[k]);
							}
						}
						
						if(strchr(temp,'e')){
							findfollow(prod[i][0],result);
						}
					}
				} else if(prod[i][0]!=symbol){
					findfollow(prod[i][0],result);
				}
			}
		}
	}
}


int main(){
	printf("Enter the number of productions : ");
	scanf("%d",&n);
	printf("Enter the productions : ");
	for(int i=0;i<n;i++){
		scanf("%s",prod[i]);
		char lhs = prod[i][0];
		if(!(strchr(nonterminals,lhs))){
			nonterminals[ntCount++] = lhs;
		}
	}
	
	for(int i=0;i<ntCount;i++){
		char temp1[20] = "", temp2[20] = "";
		findfirst(nonterminals[i],temp1);
		strcpy(firstSet[i],temp1);
		findfollow(nonterminals[i],temp2);
		strcpy(followSet[i],temp2);
	}
	
	printf("\n%-10s %-15s %-15s\n","Non-Term","First","Follow");
	for(int i=0;i<ntCount;i++){
		printf("%-10c %-15s %-15s\n",nonterminals[i],firstSet[i],followSet[i]);
	}
	return 0;
}
