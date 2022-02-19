#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MAXN=1e5+5;
const int MAXM=2e5+5;
int edge,head[MAXN],tail[MAXM],nex[MAXM],rd[MAXN];
int a[MAXN],w[MAXN],f[MAXN];
vector<int> g[MAXN];
int n,m;
int tim,dfn[MAXN],use[MAXN],low[MAXN];
int st[MAXN],top;
int bel[MAXN],scc;
int ans;
queue<int> q;
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
	rd[v]++;
}
void tarjan(int u){
	use[u]=1; st[++top]=u;
	dfn[u]=low[u]=++tim;
	for (int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if (!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if (use[v]) low[u]=min(low[u],dfn[v]);
	}
	cout<<u<<" dfn:"<<dfn[u]<<" low:"<<low[u]<<endl;
	if (dfn[u]==low[u]){
		scc++; bel[u]=scc; w[scc]=a[u]; use[u]=0;
		while (st[top]!=u){
			int v=st[top--];
			bel[v]=scc; use[v]=0;
			w[scc]+=a[v];
		}
		top--;
//		cout<<scc<<" "<<w[scc]<<endl;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=m;i++){
		int u,v; scanf("%d%d",&u,&v);
		g[u].push_back(v);
	}
	for (int i=1;i<=n;i++){
		if (!dfn[i]) tarjan(i);
	}
	for (int i=1;i<=n;i++) printf("id:%d scc:%d\n",i,bel[i]);
	for (int i=1;i<=n;i++){
		for (int j=0;j<g[i].size();j++){
			int v=g[i][j];
			if (bel[i]!=bel[v]) add(bel[i],bel[v]);
		}
	}
	ans=0;
	for (int i=1;i<=scc;i++){
		if (rd[i]==0){
			q.push(i); use[i]=1;
			f[i]=w[i];
		}
		else use[i]=0;
	}
	while (!q.empty()){
		int u=q.front(); q.pop();
		ans=max(ans,f[u]);
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			rd[v]--;
			f[v]=max(f[v],f[u]+w[v]);
			if (rd[v]==0&&!use[v]){
				q.push(v); use[v]=1;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
