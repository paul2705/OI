#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1e3*2+5;
const int INF=1e9;
int dist[MAXN][MAXN],f[MAXN][MAXN];
int n,m,T,w[MAXN],d[MAXN],ans[MAXN];
int edge=1,head[MAXN],tail[MAXN],nex[MAXN],W[MAXN];
void add(int u,int v,int len){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,W[edge]=len;
}
void dfs(int u,int p,int root){
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v!=p&&dist[root][v]==0){
			dist[root][v]=dist[root][u]+W[e];
			dfs(v,u,root);
		}
	}
}
void dfs_dp(int u,int p){
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v!=p) dfs_dp(v,u);
	}
	for (int i=0;i<=n;i++){
		if (dist[u][i]<=d[u]){
			int tmp=0;
			for (int e=head[u];e;e=nex[e]){
				int v=tail[e];
				if (v!=p) tmp+=min(f[v][i]-w[i],ans[v]);
			}
			f[u][i]=w[i]+tmp;
		}
		else f[u][i]=INF;
	}
	for (int i=1;i<=n;i++) ans[u]=min(ans[u],f[u][i]);
}
int main(){
	scanf("%d",&T);
	while (T--){
		edge=1;
		memset(head,0,sizeof(head));
		memset(w,0,sizeof(w)); memset(d,0,sizeof(d));
		memset(dist,0,sizeof(dist));
		memset(ans,63,sizeof(ans));
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&w[i]);
		for (int i=1;i<=n;i++) scanf("%d",&d[i]);
		for (int i=1,u,v,w;i<n;i++){
			scanf("%d%d%d",&u,&v,&w);
			add(v,u,w); add(u,v,w);
		}
		for (int i=1;i<=n;i++) dfs(i,0,i);
		dfs_dp(1,0);
		printf("%d\n",ans[1]);
	}
	return 0;
}
