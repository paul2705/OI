#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
const int MAXM=2e6+6;
int edge,head[MAXN],tail[MAXM],nex[MAXM];
int dfn[MAXN],use[MAXN],st[MAXN],top;
int rd[MAXN],low[MAXN],tim;
int bel[MAXN],sz[MAXN],scc;
int n,m;
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void tarjan(int u){
	dfn[u]=low[u]=++tim;
	st[++top]=u; use[u]=1;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if (use[v]) low[u]=min(low[u],dfn[v]);
	}
	if (dfn[u]==low[u]){
		scc++;
		int x=0;
		while (x!=u){
			x=st[top--];
			bel[x]=scc; use[x]=0;
			sz[scc]++; 
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int u,v; scanf("%d%d",&u,&v);
		add(u,v);
	}
	for (int i=1;i<=n;i++){
		if (!dfn[i]) tarjan(i);
	}
	for (int i=1;i<=n;i++){
//		cout<<i<<" "<<bel[i]<<endl;
		for (int e=head[i];e;e=nex[e]){
			int v=tail[e];
			if (bel[i]!=bel[v]) rd[bel[i]]++;
		}
	}
	int cnt=0,ans=0;
	for (int i=1;i<=scc;i++){
//		cout<<i<<" "<<rd[i]<<" "<<sz[i]<<endl;
		if (!rd[i]) cnt++,ans=sz[i];
	}
	if (cnt==1) printf("%d\n",ans);
	else printf("0\n");
	return 0;
}
