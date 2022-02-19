#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
const int MAXM=1e6+6;
int edge,head[MAXN],tail[MAXM],nex[MAXM],w[MAXM];
int n,m,d[MAXN],f[MAXN][21],pw[MAXN][21];
struct rec{
	int u,v,w,id,fl;
} ed[MAXM];
int fa[MAXN];
void add(int u,int v,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
int find(int x){ return fa[x]==x?x:fa[x]=find(fa[x]); }
void uion(int x,int y){ fa[find(x)]=find(y); }
void dfs(int u,int p){
	f[u][0]=p; d[u]=d[p]+1;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		pw[v][0]=w[e];
		dfs(v,u);
	}
}
void ini(){
	for (int k=1;k<=20;k++){
		for (int i=1;i<=n;i++){
			f[i][k]=f[f[i][k-1]][k-1];
			pw[i][k]=max(pw[i][k-1],pw[f[i][k-1]][k-1]);
		}
	}
}
int lca(int x,int y){
	if (d[x]<d[y]) swap(x,y);
	int res=0;
	for (int k=20;k>=0;k--){
		if (d[f[x][k]]>d[y]){
			res=max(res,pw[x][k]);
			x=f[x][k];
		}
	}
	if (d[x]>d[y]){
		res=max(res,pw[x][0]);
		x=f[x][0];
	}
	if (x==y) return res;
	for (int k=20;k>=0;k--){
		if (f[x][k]!=f[y][k]){
			res=max(res,pw[x][k]);
			res=max(res,pw[y][k]);
			x=f[x][k]; y=f[y][k];
		}
	}
	if (x!=y){
		res=max(res,pw[x][0]);
		res=max(res,pw[y][0]);
		return res;
	}
	return res;
}
bool cmp1(rec a,rec b){ return a.id<b.id; }
bool cmp(rec a,rec b){ return a.w<b.w; }
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int u,v,w; scanf("%d%d%d",&u,&v,&w);
		ed[i]=(rec){u,v,w,i,0};
	}
	sort(ed+1,ed+m+1,cmp);
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=m;i++){
		int u=ed[i].u,v=ed[i].v,w=ed[i].w;
		if (find(u)!=find(v)){
			ed[i].fl=1; uion(u,v); add(u,v,w); add(v,u,w);
		}
	}
	dfs(1,0); ini();
	sort(ed+1,ed+m+1,cmp1);
	for (int i=1;i<=m;i++){
		if (ed[i].fl) continue;
		int u=ed[i].u,v=ed[i].v;
		int ans=lca(u,v);
		printf("%d\n",ans);
	}
	return 0;
}
