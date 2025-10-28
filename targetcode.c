#include <stdio.h>
#include <string.h>

char icode[10][30];
char str[30];
char opr[10];
int i=0;

int main(){
	printf("Enter the intermediate code : ");
	while(1){
		scanf("%s",icode[i]);
		if(strcmp(icode[i],"exit")==0){
			break;
		}
		i++;
	}
	
	printf("\nTarget Code Generation\n");
	printf("--------------------------\n");
	
	for(int j=0;j<i;j++){
		strcpy(str,icode[j]);
		char lhs = str[0];
		char op1 = str[2];
		char op = str[3];
		char op2 = str[4];
		
		switch(op) {
			case '+' :
				printf("MOV AX, %c\n",op1);
				printf("ADD AX, %c\n",op2);
				printf("MOV %c, AX\n\n",lhs);
				break;
				
			case '-' :
				printf("MOV AX, %c\n",op1);
				printf("SUB AX, %c\n",op2);
				printf("MOV %c, AX\n\n",lhs);
				break;
				
			case '*' :
				printf("MOV AX, %c\n",op1);
				printf("MUL %c\n",op2);
				printf("MOV %c, AX\n\n",lhs);
				break;
				
			case '/' :
				printf("MOV AX, %c\n",op1);
				printf("DIV %c\n",op2);
				printf("MOV %c, AX\n\n",lhs);
				break;
				
			case '=' :
				printf("MOV AX, %c\n",op1);
				printf("MOV %c, AX\n\n",lhs);
				break;
			
			default:
				printf("UNSUPPORTED OPERATION %s\n\n",str);
				break;
		}
	}
	return 0;
}
