#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e2+5;
const int MAXM=2e2+5;
int edge,head[MAXN],tail[MAXM],nex[MAXM],w[MAXM];
int n,q,f[MAXN][MAXM];
void add(int u,int v,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
int dfs(int u,int p){
	int sz=0;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v!=p){ 
			sz+=dfs(v,u)+1;
			for (int j=min(q,sz);j>=1;j--){
				for (int k=min(sz,j-1);k>=0;k--){
					f[u][j]=max(f[u][j],f[u][j-k-1]+f[v][k]+w[e]);
				}
			}
		}
	}
	return sz;
}
int main(){
	scanf("%d%d",&n,&q);
	for (int i=1,u,v,w;i<n;i++){
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w); add(v,u,w);
	}
	dfs(1,0);
	printf("%d\n",f[1][q]);
	return 0;
}
