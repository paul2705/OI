#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n,c[500005];
int f[500005],g[500005];
vector<int> G[500005];
int cmp(int x,int y)
{
	return (g[x]-f[x]>g[y]-f[y]);
}
void dfs(int u,int p)
{
	for (int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if (v!=p){
			dfs(v,u);
			f[v]+=2;
			g[v]++;
		}
	}
	sort(G[u].begin(),G[u].end(),cmp);
	for (int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if (v==p) continue;
	    g[u]=max(g[u],f[u]+g[v]);
	    f[u]+=f[v];
	}
	g[u]=max(g[u],c[u]);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&c[i]);
	for (int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0);
	for (int i=1;i<=n;i++) printf("%d %d %d\n",i,f[i],g[i]);
	printf("%d\n",max(g[1],c[1]+2*(n-1)));
}
