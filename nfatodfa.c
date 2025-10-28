#include <stdio.h>
#include <string.h>

#define MAX 10

int n,m,t;
int nfa[MAX][MAX][MAX];

int move(int set, int sym){
	int res = 0;
	for(int i=0;i<n;i++){
		if(set & (1<<i)){
			for(int j=0;j<n;j++){
				if(nfa[i][sym][j]){
					res |= (1<<j);
				}
			}
		}
	}
	return res;
}

void print(int mask){
	if(!mask){
		printf("-");
		return;
	}
	printf("{ ");
	for(int i=0;i<n;i++){
		if(mask & (1<<i)){
			printf("q%d ",i);
		}
	}
	printf("}");
}

int main(){
	printf("Enter the number of states : ");
	scanf("%d",&n);
	
	printf("Enter the number of symbols : ");
	scanf("%d",&m);
	
	printf("Enter the number of transitions: ");
	scanf("%d",&t);
	
	memset(nfa,0,sizeof(nfa));
	printf("Enter the transitions\n");
	for(int i=0;i<t;i++){
		int a,s,b;
		scanf("%d%d%d",&a,&s,&b);
		nfa[a][s][b]=1;
	}
	
	int seen[1<<MAX] ={0}, q[1<<MAX], head = 0, tail = 0;
	int start = 1<<0;
	q[tail++] = start;
	seen[start] = 1;
	
	while(head<tail){
		int curr = q[head++];
		
		for(int sym=0;sym<m;sym++){
			int next = move(curr,sym);
			
			if(curr==0 && next==0){
				continue;
			}
			
			print(curr);
			printf("---%d-->",sym);
			print(next);
			printf("\n");
			
			if(!seen[next]){
				seen[next]=1;
				q[tail++]=next;
			}
		}
	}
	
	return 0;
	
}
