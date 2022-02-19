#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1e5+5;
const int MAXM=5e5+5;
int edge,head[MAXN],nex[MAXM],tail[MAXM];
int cmp[MAXN],s[MAXN],top,dfn[MAXN],use[MAXN];
int n,m,low[MAXN],cm[MAXN],cnt,scc;
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void tarjan(int u){
	dfn[u]=low[u]=++cnt; use[u]=1; s[++top]=u;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (!dfn[v]){
			tarjan(v); low[u]=min(low[u],low[v]);
		}
		else if (use[v]) low[u]=min(low[u],dfn[v]);
	}
	if (low[u]==dfn[u]){
		scc++; int x=-1;
		while (x!=u){
			x=s[top--];
			cmp[x]=scc; use[x]=0;
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=0,u,v;i<m;i++){
		scanf("%d%d",&u,&v); if (u==v) continue;
		add(u,v);
	}
	for (int i=1;i<=n;i++) if (!dfn[i]) tarjan(i);
	for (int i=1;i<=n;i++){
		for (int e=head[i];e;e=nex[e]){
			int v=tail[e];
			if (cmp[i]!=cmp[v]) cm[cmp[v]]++;
		}
	}
	int ans=0;
	for (int i=1;i<=scc;i++) if (cm[i]==0) ans++;
	printf("%d\n",ans);
	return 0;
}
