#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
const int MAXM=2e5+5;
int edge,head[MAXN],tail[MAXM],nex[MAXM];
int n,m,dfn[MAXN],low[MAXN],tim;
bool use[MAXN];
int ans[MAXN];
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void tarjan(int u,int rt){
	dfn[u]=++tim; low[u]=dfn[u];
	use[u]=1;
	int tmp=0;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (!dfn[v]){
			tarjan(v,rt);
			low[u]=min(low[u],low[v]);
			tmp++; 
			if (u!=rt&&low[v]>=dfn[u]) ans[u]=1;
		}
		else if (use[v]) low[u]=min(low[u],dfn[v]);
	}
	if (u==rt&&tmp>1) ans[rt]=1;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int u,v; scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	for (int i=1;i<=n;i++){
		if (!dfn[i]) tarjan(i,i);
	}
	int cnt=0;
	for (int i=1;i<=n;i++) cnt+=ans[i];
	printf("%d\n",cnt);
	for (int i=1;i<=n;i++){
		if (ans[i]) printf("%d\n",i);
	}
	return 0;
}
