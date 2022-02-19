#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
const int MAXM=2e5+5;
int edge,head[MAXN],tail[MAXM],nex[MAXM];
int a[MAXN],mx[MAXN][30],mn[MAXN][30],fa[MAXN][30];
int d[MAXN],n,m,ansx,ansn;
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void dfs(int u,int p){
	fa[u][0]=p; mx[u][0]=max(a[u],a[p]);
	mn[u][0]=min(a[u],a[p]); d[u]=d[p]+1;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		dfs(v,u);
	}
}
int lca(int u,int v){
	if (d[u]<d[v]) swap(u,v);
	for (int k=29;k>=0;k--){
		if (d[fa[u][k]]>d[v]){
			ansx=max(ansx,mx[u][k]);
			ansn=min(ansn,mn[u][k]);
			u=fa[u][k];
		}
	}
	if (d[u]>d[v]){
		ansx=max(ansx,mx[u][0]);
		ansn=min(ansn,mn[u][0]);
		u=fa[u][0];
	}
	if (u==v) return u;
	for (int k=29;k>=0;k--){
		if (fa[u][k]!=fa[v][k]){
			ansx=max(ansx,max(mx[u][k],mx[v][k]));
			ansn=min(ansn,min(mn[u][k],mn[v][k]));
			u=fa[u][k]; v=fa[v][k];
		}
	}
	if (u!=v){
		ansx=max(ansx,max(mx[u][0],mx[v][0]));
		ansn=min(ansn,min(mn[u][0],mn[v][0]));
		u=fa[u][0]; v=fa[v][0];
	}
	return u;
}
int main(){
	freopen("profit.in","r",stdin);
	freopen("profit.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	dfs(1,1);
//	for (int k=0;k<30;k++){
//		for (int u=1;u<=n;u++) mn[u][k]=1e9+5;
//	}
	for (int k=1;k<30;k++){
		for (int u=1;u<=n;u++){
			fa[u][k]=fa[fa[u][k-1]][k-1];
			mx[u][k]=max(mx[u][k-1],mx[fa[u][k-1]][k-1]);
			mn[u][k]=min(mn[u][k-1],mn[fa[u][k-1]][k-1]);
		}
	}
	for (int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		ansx=0; ansn=1e9;
		int d=lca(u,v);
		printf("%d\n",ansx-ansn);
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
