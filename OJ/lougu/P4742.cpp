#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=2e5+5;
const int MAXM=5e5+5;
int edge,head[MAXN],nex[MAXM],tail[MAXM];
int n,m,c[MAXN],scc,cnt,low[MAXN],dfn[MAXN];
bool use[MAXN];
int s[MAXN],top;
int f[MAXN][3],cmp[MAXN],num[MAXN],mn[MAXN];
int redge,rhead[MAXN],rnex[MAXM],rtail[MAXM];
int rd[MAXN];
queue<int> q;
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void radd(int u,int v){
	redge++,rnex[redge]=rhead[u],rhead[u]=redge,rtail[redge]=v;
}
void tarjan(int u){
	dfn[u]=low[u]=++cnt;
	use[u]=1; s[++top]=u;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (!dfn[v]){ tarjan(v); low[u]=min(low[u],low[v]); }
		else if (use[v]) low[u]=min(low[u],dfn[v]);
	}
	if (low[u]==dfn[u]){
		int x=0; scc++;
		while (x!=u){
			x=s[top--]; use[x]=0;
			cmp[x]=scc;
			num[scc]+=c[x]; mn[scc]=max(mn[scc],c[x]);
		}
	}
}		
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&c[i]);
	for (int i=0,u,v;i<m;i++){
		scanf("%d%d",&u,&v);
		add(u,v);
	}
	for (int i=1;i<=n;i++){
		if (!dfn[i]) tarjan(i);
	}
	for (int i=1;i<=n;i++){
		for (int e=head[i];e;e=nex[e]){
			int v=tail[e];
			if (cmp[i]!=cmp[v]){
				radd(cmp[i],cmp[v]);
				rd[cmp[v]]++;
			}
		}
	}
	for (int i=1;i<=scc;i++){
		if (!rd[i]) q.push(i);
	}
	while (!q.empty()){
		int u=q.front(); q.pop();
		f[u][0]+=num[u],f[u][1]=max(f[u][1],mn[u]);
		for (int e=rhead[u];e;e=rnex[e]){
			int v=rtail[e]; rd[v]--;
			if (!rd[v]) q.push(v);
			if (f[u][0]>f[v][0]) f[v][1]=f[u][1],f[v][0]=f[u][0];
			else if (f[u][0]==f[v][0]) f[v][1]=max(f[v][1],f[u][1]);
		}
	}
	int ans=0,mx=0;
	for (int i=1;i<=scc;i++){
		if (f[i][0]>ans) ans=f[i][0],mx=f[i][1];
		else if (f[i][0]==ans) mx=max(mx,f[i][1]);
	}
	printf("%d %d\n",ans,mx);
	return 0;
}
