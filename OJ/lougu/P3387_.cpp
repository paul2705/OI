#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=1e4+5;
const int MAXM=1e5+5;
int edge,head[MAXN],tail[MAXM],nex[MAXM];
int ed,he[MAXN],ta[MAXM],ne[MAXM];
int n,m,a[MAXN];
int low[MAXN],st[MAXN],top;
int cnt,bel[MAXN],scc,dfn[MAXN];
int sz[MAXN],rd[MAXN];
bool use[MAXM];
queue<int> q;
int f[MAXN];
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void ad(int u,int v){
	ed++,ne[ed]=he[u],he[u]=ed,ta[ed]=v;
	rd[v]++;
}
void tarjan(int u){
	dfn[u]=low[u]=++cnt; st[++top]=u;
	use[u]=1;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if (use[v]) low[u]=min(low[u],dfn[v]);
	}
	if (low[u]==dfn[u]){
		int x=st[top--];
		bel[u]=++scc;
		sz[scc]+=a[u];
		use[u]=0;
		while (x!=u){
			bel[x]=scc; use[x]=0;
			sz[scc]+=a[x];
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
	for (int i=1;i<=n;i++) use[i]=0;
	for (int u=1;u<=n;u++){
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			if (bel[u]!=bel[v]) ad(bel[u],bel[v]);
		}
	}
//	for (int i=1;i<=n;i++){
//		printf("%d bel:%d\n",i,bel[i]);
//	}
	for (int i=1;i<=scc;i++){
//		printf("scc:%d %d\n",i,sz[i]);
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
