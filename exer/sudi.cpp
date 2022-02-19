#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MAXN=1e4+5;
const int MAXM=2e5+5;
int edge,head[MAXN],tail[MAXM],nex[MAXM];
int a[MAXN],dfn[MAXN],low[MAXM],tim;
int n,m,f[MAXN],rd[MAXN];
bool use[MAXN];
int st[MAXN],top,bel[MAXN],scc[MAXN],cnt;
vector<int> g[MAXN];
queue<int> q;
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void tarjan(int u){
	dfn[u]=++tim; low[u]=dfn[u];
	st[++top]=u; use[u]=1;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if (use[v]) low[u]=min(low[u],dfn[v]);
	}
	if (low[u]==dfn[u]){
		cnt++; bel[u]=cnt;
		scc[cnt]=a[u]; use[u]=0;
		int x=st[top--];
		while (x!=u){
			bel[x]=cnt; scc[cnt]+=a[x];
			use[x]=0;
			x=st[top--];
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=m;i++){
		int u,v; scanf("%d%d",&u,&v);
		add(u,v);
	}
	for (int i=1;i<=n;i++){
		if (!dfn[i]) tarjan(i);
	}
	for (int u=1;u<=n;u++){
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			if (bel[u]==bel[v]) continue;
			g[bel[u]].push_back(bel[v]);
			rd[bel[v]]++;
		}
	}
	for (int i=1;i<=cnt;i++){
		if (!rd[i]) f[i]=scc[i],q.push(i);
	}
	while (!q.empty()){
		int u=q.front(); q.pop();
		for (int i=0;i<g[u].size();i++){
			int v=g[u][i];
			rd[v]--; f[v]=max(f[v],f[u]+scc[v]);
			if (rd[v]==0) q.push(v);
		}
	}
	int ans=0;
	for (int i=1;i<=n;i++){
		ans=max(ans,f[i]);
	}
	printf("%d\n",ans);
	return 0;
}
