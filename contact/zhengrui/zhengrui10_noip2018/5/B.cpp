#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
const int MAXM=2e5+5;
ll fa[MAXN][30],w[MAXN][30],d[MAXN],f[MAXN];
int n,m;
int edge,head[MAXN],tail[MAXM],nex[MAXM];
int a[MAXN];
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void dfs(int u,int p){
	d[u]=d[p]+1; fa[u][0]=p; w[u][0]=1;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v!=p) dfs(v,u);
	}
}
void ini(){
	for (int i=1;i<30;i++){
		for (int u=1;u<=n;u++){
			fa[u][i]=fa[fa[u][i-1]][i-1];
			w[u][i]=w[u][i-1]+w[fa[u][i-1]][i-1];
		}
	}
}
ll lca(int u,int v){
	ll ret=0;
	if (d[u]<d[v]) swap(u,v);
	for (int k=29;k>=0;k--){
		if (d[fa[u][k]]>d[v]) ret+=w[u][k],u=fa[u][k];
	}
	if (d[u]>d[v]){
		ret+=w[u][0];
		u=fa[u][0];
	}
	for (int k=29;k>=0;k--){
		if (fa[u][k]!=fa[v][k]){
			ret+=w[u][k]+w[v][k];
			u=fa[u][k],v=fa[v][k];
		}
	}
	if (u!=v){
		ret+=w[u][0]+w[v][0];
		u=fa[u][0],v=fa[v][0];
	}
	return ret;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	dfs(1,0);
	ini();
	for (int i=1;i<=m;i++) scanf("%d",&a[i]);
	f[1]=lca(1,a[1]);
	for (int i=2;i<=m;i++) f[i]=f[i-1]+lca(a[i-1],a[i]);
	for (int i=1;i<=m;i++) printf("%lld\n",f[i]);
	return 0;
}
