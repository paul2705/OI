#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
const int MAXM=1e6+6;
int edge,head[MAXN],nex[MAXM],tail[MAXM];
int n,m,low[MAXN],dfn[MAXN],cnt;
bool bel[MAXN];
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void tarjan(int u,int p){
	dfn[u]=low[u]=++cnt;
	int son=0;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (!dfn[v]){
			tarjan(v,u); son++;
			low[u]=min(low[u],low[v]);
			bel[u]|=low[v]>=dfn[u];
		}
		else low[u]=min(low[u],dfn[v]);
	}
//	cout<<u<<" "<<low[u]<<" "<<dfn[u]<<endl;
	if (u==p) bel[u]=son>=2;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	for (int i=1;i<=n;i++){
		if (!dfn[i]) tarjan(i,i);
	}
	int ans=0;
	for (int i=1;i<=n;i++){
		if (bel[i]) ans++;
	}
	printf("%d\n",ans);
	for (int i=1;i<=n;i++){
		if (bel[i]) printf("%d ",i);
	}
	return 0;
}
