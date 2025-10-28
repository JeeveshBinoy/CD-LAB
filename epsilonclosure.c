#include <stdio.h>

int eclose[100][2];
int n,ep,vis[100];

void eclosure(int state){
	if(vis[state]){
		return;
	}
	vis[state]=1;
	printf("q%d ",state);
	for(int i=0;i<ep;i++){
		if(eclose[i][0]==state){
			eclosure(eclose[i][1]);
		}
	}
}

int main(){
	printf("Enter the number of states : ");
	scanf("%d",&n);
	
	printf("Enter the number of epsilon transitions : ");
	scanf("%d",&ep);
	
	for(int i=0;i<ep;i++){
		scanf("%d%d",&eclose[i][0],&eclose[i][1]);
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			vis[j]=0;
		}
		
		printf("q%d : { ",i);
		eclosure(i);
		printf(" }\n");
	}
	return 0;
}
