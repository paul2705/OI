#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=250005;
const int MAXM=MAXN*2;
int edge,head[MAXN],nex[MAXM],tail[MAXM],w[MAXM];
int ed,he[MAXN],ne[MAXM],ta[MAXM],wa[MAXM];
int n,m,K;
int fa[MAXN][20],d[MAXN];
int dfn[MAXN],cnt;
int st[MAXN],top;
int f[MAXN][3],h[MAXN];
void ins(int u,int v,int W){
	ed++,ne[ed]=he[u],he[u]=ed,ta[ed]=v,wa[ed]=W;
}
void add(int u,int v,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
void dfs(int u,int p){
	fa[u][0]=p; d[u]=d[p]+1; d[u]=++cnt;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		len[v]=len[u]+w[e];
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
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		int u,v,w; scanf("%d%d%d",&u,&v,&w);
		add(u,v,w); add(v,u,w);
	}
	dfs(1,0);
	scanf("%d",&m);
	while (m--){
		scanf("%d",&K);
		for (int i=1;i<=K;i++) scanf("%d",h[i]);
		sort(h+1,h+K+1,cmp);
		top=0;
		st[++top]=1;
		for (int i=1;i<=K;i++){
			int pf=lca(st[top],h[i]);
			if (d[pf]<d[st[top]]) ins(pf,st[top],len[pf]-len[st[top]]);
			top--; if (st[top]!=pf) st[++top]=pf;
			if (st[top]!=h[i]) st[++top]=h[i];
		}
	}
