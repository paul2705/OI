#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=5e5+5;
const int MAXM=1e6+6;
int n,S;
int edge,head[MAXN],tail[MAXM],nex[MAXM],w[MAXM];
ll f[MAXN],g[MAXN];
void add(int u,int v,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
void dfs(int u,int p){
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		dfs(v,u);
		g[u]=max(g[u],g[v]+w[e]);
	}
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		f[u]+=f[v]+g[u]-(g[v]+w[e]);
	}
}
int main(){
	scanf("%d%d",&n,&S);
	for (int i=1;i<n;i++){
		int u,v,w; scanf("%d%d%d",&u,&v,&w);
		add(u,v,w); add(v,u,w);
	}
	dfs(S,0);
	printf("%lld\n",f[S]);
	return 0;
}
