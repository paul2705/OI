#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=5e2+5;
const int MAXM=MAXN*2;
int edge,head[MAXN],tail[MAXM],nex[MAXM];
int a[MAXN],n,m,h[MAXN][MAXM],f[MAXN][MAXM];
int sz[MAXN];
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void dfs(int u,int p){
	sz[u]=1;
	for (int i=1;i<=m;i++) h[u][i]=f[u][i]=a[u];
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		dfs(v,u); sz[u]+=sz[v];
		for (int k=min(m,sz[u]*3);k>=1;k--){
			for (int x=0;k-x-1>=0;x++) f[u][k]=max(f[u][k],h[u][x]+f[v][k-x-1]);
			for (int x=0;k-x-2>=0;x++) f[u][k]=max(f[u][k],f[u][x]+h[v][k-x-2]);
			for (int x=0;k-x-2>=0;x++) h[u][k]=max(h[u][k],h[u][x]+h[v][k-2-x]);
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	dfs(1,0);
	int ans=0;
	for (int i=1;i<=m;i++) ans=max(ans,max(f[1][i],h[1][i]));
	printf("%d\n",ans);
	return 0;
}
