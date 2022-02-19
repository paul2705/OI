#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5e5+5;
const int MAXM=2e6+5;
int edge,head[MAXN],tail[MAXM],nex[MAXM];
int n,m,fa[MAXN][24];
int rt;
int d[MAXN],use[MAXN];
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void dfs(int u,int p){
	if (use[u]) return;
	fa[u][0]=p; d[u]=d[p]+1;
	use[u]=1;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		dfs(v,u);
	}
}
int qry(int u,int v){
	if (d[u]<d[v]) swap(u,v);
	for (int k=23;k>=0;k--){
		if (d[fa[u][k]]>d[v]) u=fa[u][k];
	}
	if (d[u]>d[v]) u=fa[u][0];
	for (int k=23;k>=0;k--){
		if (fa[u][k]!=fa[v][k]) u=fa[u][k],v=fa[v][k];
	}
	if (u!=v) u=fa[u][0];
	return u;
}
int main(){
	 scanf("%d%d%d",&n,&m,&rt);
	 for (int i=1;i<n;i++){
		 int u,v; scanf("%d%d",&u,&v);
		 add(u,v); add(v,u);
	 }
	 for (int i=1;i<=n;i++){
		 for (int j=0;j<=23;j++) fa[i][j]=0;
	 }
	 dfs(rt,0);
	 for (int j=1;j<=23;j++){
		 for (int i=1;i<=n;i++) fa[i][j]=fa[fa[i][j-1]][j-1];
	 }
	 for (int i=1;i<=m;i++){
		 int u,v; scanf("%d%d",&u,&v);
		 printf("%d\n",qry(u,v));
	 }
	 return 0;
}
