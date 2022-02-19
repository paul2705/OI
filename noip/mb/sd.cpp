#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=1e5+5;
const int MAXM=2e5+5;
int edge,head[MAXN],nex[MAXM],tail[MAXM];
int ed,he[MAXN],ne[MAXM],ta[MAXM];
int f[MAXN],rd[MAXN];
int a[MAXN],sz[MAXN];
int bel[MAXN],scc;
int dfn[MAXN],low[MAXN];
int s[MAXN],top;
int n,m,cnt;
bool use[MAXN];
queue<int> q;
void ad(int u,int v){
	ed++,ne[ed]=he[u],he[u]=ed,ta[ed]=v;
	rd[v]++;
}
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void tarjan(int u){
	dfn[u]=low[u]=++cnt;
	s[++top]=u; use[u]=1;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if (use[v]) low[u]=min(low[u],dfn[v]);
	}
	if (dfn[u]==low[u]){
		int x=s[top--];
		scc++; sz[scc]+=a[u];
		bel[u]=scc; use[u]=0;
		while (x!=u){
			bel[x]=scc;
			use[x]=0;
			sz[scc]+=a[x];
			x=s[top--];
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
	}
	for (int i=1;i<=n;i++){
		if (!dfn[i]) tarjan(i);
	}
	for (int u=1;u<=n;u++){
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			if (bel[u]!=bel[v]) ad(bel[u],bel[v]);
		}
	}
	for (int i=1;i<=scc;i++){
		if (rd[i]==0) q.push(i),f[i]=sz[i];
	}
	while (!q.empty()){
		int u=q.front(); q.pop();
		for (int e=he[u];e;e=ne[e]){
			int v=ta[e];
			rd[v]--;
			f[v]=max(f[v],f[u]+sz[v]);
			if (rd[v]==0) q.push(v);
		}
	}
	int ans=0;
	for (int i=1;i<=scc;i++) ans=max(ans,f[i]);
	printf("%d\n",ans);
	return 0;
}
