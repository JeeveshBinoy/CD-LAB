#include <stdio.h>
#include <string.h>
#define MAX 20

int n,m,t,f;
int dfa[MAX][MAX],final[MAX],mark[MAX][MAX],rep[MAX];

int main(){
	printf("Enter the number of states, symbols, transitions: ");
	scanf("%d%d%d",&n,&m,&t);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			dfa[i][j]=-1;
		}
	}
	
	printf("ENTER THE TRANSITIONS\n");
	for(int i=0;i<t;i++){
		int a,s,b;
		scanf("%d%d%d",&a,&s,&b);
		dfa[a][s] = b;
	}
	
	printf("Enter the no of final states : ");
	scanf("%d",&f);
	
	printf("Enter the final states\n");
	for(int i=0;i<f;i++){
		int x;
		scanf("%d",&x);
		final[x] = 1;
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			if(final[i]!=final[j]){
				mark[i][j]=1;
			}
		}
	}
	
	int change;
	do{
		change=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<i;j++){
				if(!mark[i][j]){
					for(int s=0;s<m;s++){
						int p = dfa[i][s], q=dfa[j][s];
						if(p==-1 || q==-1){
							continue;
						}
						if(p<q && mark[q][p] || p>q && mark[p][q]){
							mark[i][j] = 1;
							change=1;
							break;
						}
					}
				}
			}
		}
	} while(change);
	
	for(int i=0;i<n;i++){
		rep[i]=i;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			if(!mark[i][j]){
				rep[i]=rep[j];
			}
		}
	}
	
	printf("Minimised DFA groups\n");
	int printed[MAX] = {0};
	for(int i=0;i<n;i++){
		if(printed[rep[i]]){
			continue;
		}
		printed[rep[i]]=1;
		printf("{ ");
		for(int j=0;j<n;j++){
				if(rep[j]==rep[i]){
					printf("q%d ", j);
				}
		}
		printf("}\n");
	}
	
	printf("Transition Table\n");
	memset(printed,0,sizeof(printed));
	for(int i=0;i<n;i++){
		if(printed[rep[i]]){
			continue;
		}
		printed[rep[i]]=1;
		for(int s=0;s<m;s++){
			int to = dfa[i][s];
			if(to==-1){
				continue;
			}
			printf("{ ");
			for(int j=0;j<n;j++){
				if(rep[j]==rep[i]){
					printf("q%d ",j);
				}
			}
			printf("}--%d-->{",s);
			for(int j=0;j<n;j++){
				if(rep[j]==rep[to]){
					printf("q%d ",j);
				}
			}
			printf("}\n");
		}
	}
	
	return 0;
}
