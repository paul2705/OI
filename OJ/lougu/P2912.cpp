#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e3+5;
int dist[MAXN][MAXN],use[MAXN];
int edge,head[MAXN],nex[MAXN*2],tail[MAXN*2],w[MAXN*2];
int n,m;
void add(int u,int v,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
void dfs(int u,int root){
	use[u]=1;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (!use[v]){
			dist[root][v]=dist[root][u]+w[e];
			dfs(v,root);
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1,u,v,w;i<n;i++){
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w); add(v,u,w);
	}
	for (int i=1;i<=n;i++){
		memset(use,0,sizeof(use));
		dfs(i,i);
	}
	for (int i=0,u,v;i<m;i++){
		scanf("%d%d",&u,&v);
		printf("%d\n",dist[u][v]);
	}
	return 0;
}
