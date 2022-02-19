#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5e5+5;
const int MAXM=MAXN*2;
int fa[MAXN][20];
int d[MAXN];
int edge,head[MAXN],nex[MAXM],tail[MAXM];
int n,m,s;
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void dfs(int u,int p){
	fa[u][0]=p; d[u]=d[p]+1;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		dfs(v,u);
	}
}
void ini(){
	for (int k=1;k<20;k++){
		for (int u=1;u<=n;u++){
			fa[u][k]=fa[fa[u][k-1]][k-1];
		}
	}
}
int lca(int u,int v){
	if (d[u]<d[v]) swap(u,v);
	for (int k=19;k>=0;k--){
		if (d[fa[u][k]]>d[v]) u=fa[u][k];
	}
	if (d[u]>d[v]) u=fa[u][0];
	for (int k=19;k>=0;k--){
		if (fa[u][k]!=fa[v][k]) u=fa[u][k],v=fa[v][k];
	}
	if (u!=v) u=fa[u][0];
	return u;
}
int main(){
	scanf("%d%d%d",&n,&m,&s);
	for (int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	dfs(s,0); ini();
	for (int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		int l=lca(u,v);
		printf("%d\n",l);
	}
	return 0;
}
