#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e6+6;
const int MAXM=4e6+6;
int edge,head[MAXN],nex[MAXM],tail[MAXM];
int n,m;
int low[MAXN],dfn[MAXN],cnt;
int st[MAXN],top,scc;
int bel[MAXN];
bool use[MAXN];
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void tarjan(int u){
	dfn[u]=low[u]=++cnt;
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
		int x=st[top--];
		bel[u]=++scc; use[u]=0;
		while (x!=u){
			bel[x]=scc; use[x]=0;
			x=st[top--];
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int x,a,y,b;
		scanf("%d%d%d%d",&x,&a,&y,&b);
		int nx=x*2+a,ny=y*2+b;
		add(ny^1,nx); add(nx^1,ny);
	}
	for (int i=1;i<=2*n+1;i++){
		if (!dfn[i]) tarjan(i);
	}
	bool flag=1;
	for (int i=1;i<=n;i++){
		int x=2*i,y=2*i+1;
		if (bel[x]==bel[y]) flag=0;
	}
	if (!flag) return printf("IMPOSSIBLE\n"),0;
	printf("POSSIBLE\n");
	for (int i=1;i<=n;i++){
		printf("%d ",bel[2*i]>bel[2*i+1]);
	}
	printf("\n");
	return 0;
}
