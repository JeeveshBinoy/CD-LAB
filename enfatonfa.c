#include <stdio.h>
#include <string.h>

#define MAX 50

int n,nsym,neps,ntrans;
int eps[MAX][MAX];
int trans[MAX][MAX][MAX];
int clos[MAX][MAX];
int vis[MAX];

void closure(int s){
	if(vis[s]){
		return;
	}
	vis[s]=1;
	for(int t=0;t<n;t++){
		if(eps[s][t]){
			closure(t);
		}
	}
}

int main(){
	printf("Enter the number of states : ");
	scanf("%d",&n);
	
	printf("Enter the number of non-epsilon symbols : ");
	scanf("%d",&nsym);
	
	printf("Enter the number of epsilon transitions : ");
	scanf("%d",&neps);
	
	printf("Enter the number of normal transitions : ");
	scanf("%d",&ntrans);
	
	for(int i=0;i<neps;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		eps[a][b]=1;
	}
	
	for(int i=0;i<ntrans;i++){
		int a,b,s;
		scanf("%d%d%d",&a,&s,&b);
		trans[a][s][b]=1;
	}
	
	for(int i=0;i<n;i++){
		memset(vis,0,sizeof(vis));
		closure(i);
		for(int j=0;j<n;j++){
			if(vis[j]){
				clos[i][j]=1;
			}
		}
	}
	
	for(int i=0;i<n;i++){
		for(int sym=0;sym<nsym;sym++){
			int reachable[MAX] = {0};
			
			for(int p=0;p<n;p++){
				if(clos[i][p]){
					for(int q=0;q<n;q++){
						if(trans[p][sym][q]){
							for(int r=0;r<n;r++){
								if(clos[q][r]){
									reachable[r]=1;
								}
							}
						}
					}
				}
			}
			
			int printed = 0;
			for(int r=0;r<n;r++){
				if(reachable[r]){
					if(!printed){
						printf("q%d---%d---> { ",i,sym);
						printed = 1;
					}
					printf("q%d",r);
				}
			}
			if(printed)printf("}\n");
		}
	}
	return 0;
}
