#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=3e5+5;
const int MAXM=MAXN*2;
int edge,head[MAXN],tail[MAXM],nex[MAXM];
int ed,he[MAXN],ta[MAXM],ne[MAXM],w[MAXM];
int n,m,k;
int h[MAXN],d[MAXN],fa[MAXN][20];
int dfn[MAXN],cnt;
int st[MAXN],top;
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void ins(int u,int v,int W){
	ed++,ne[ed]=he[u],he[u]=ed,ta[ed]=v,w[ed]=W;
}
void dfs(int u,int p){
	fa[u][0]=p; dfn[u]=++cnt;
	d[u]=d[p]+1;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		dfs(v,u);
	}
}
void ini(){
	for (int i=1;i<=n;i++){
		for (int k=1;k<20;k++){
			fa[i][k]=fa[fa[i][k-1]][k-1];
		}
	}
}
int lca(int u,int v){
	if (d[u]<d[v]) swap(u,v);
	for (int k=19;k>=0;k--){
		if (d[fa[u][k]]>d[v]) u=fa[u][k];
	}
	if (d[u]>d[v]) u=fa[u][0];
	if (u==v) return u;
	for (int k=19;k>=0;k--){
		if (fa[u][k]!=fa[v][k]){
			u=fa[u][k]; v=fa[v][k];
		}
	}
	if (u!=v) return fa[u][0];
	else return u;
}
bool cmp(int a,int b){ return dfn[a]<dfn[b]; }
void solve(){
	sort(h+1,h+k+1,cmp);
	top=0; st[++top]=1;
	for (int i=1;i<=k;i++){
		int pr=st[top],u=h[i];
		int pf=lca(pr,u);
		while (top>0&&d[pf]<d[pr]){
			ins(pf,pr,d[pr]-d[pf]);
			pr=st[--top];
		}
		if (st[top]!=pf) st[++top]=pf;
		st[++top]=u;
	}
	while (top>0){
		int u=st[top-1],v=st[top];
		ins(u,v,d[u]-d[v]);
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		int u,v; scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	dfs(1,0); ini();
	scanf("%d",&m);
	while (m--){
		scanf("%d",&k);
		for (int i=1;i<=k;i++) scanf("%d",&h[i]);
		solve();
		dfs1(1,0);
