#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
const int MAXM=1e6+6;
struct edg{
	int u,v,w;
} ed[MAXM];
int edge,head[MAXN],tail[MAXM],nex[MAXM],we[MAXM];
int n,m,q,d[MAXN],f[MAXN];
int w[MAXN][30],fa[MAXN][30];
bool use[MAXM];
void add(int u,int v,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,we[edge]=W;
}
bool cmp(edg a,edg b){ return a.w>b.w; }
int find(int x){ return f[x]==x?x:f[x]=find(f[x]); }
void uion(int x,int y){ f[find(x)]=find(y); }
void dfs(int u,int p){
	d[u]=d[p]+1; fa[u][0]=p;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (d[v]!=0) continue;
		w[v][0]=we[e];
		dfs(v,u);
	}
}
int lca(int u,int v){
	int ret=1e9;
	if (d[u]<d[v]) swap(u,v);
	for (int i=29;i>=0;i--){
		if (d[fa[u][i]]>d[v]) ret=min(ret,w[u][i]),u=fa[u][i];
	}
//	cout<<u<<" "<<v<<endl;
	if (d[u]>d[v]){ ret=min(ret,w[u][0]); u=fa[u][0]; }
//	cout<<u<<" "<<v<<endl;
	for (int i=29;i>=0;i--){
		if (fa[u][i]!=fa[v][i]){
			ret=min(ret,w[u][i]); ret=min(ret,w[v][i]);
			u=fa[u][i]; v=fa[v][i];
		}
	}
	if (u!=v){
		ret=min(ret,w[u][0]); ret=min(ret,w[v][0]);
		u=fa[u][0]; v=fa[v][0];
	}
	return ret;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		ed[i]=(edg){v,u,w};
	}
	for (int i=1;i<=n;i++) f[i]=i;
	sort(ed+1,ed+m+1,cmp);
	for (int i=1;i<=m;i++){
		int u=ed[i].u,v=ed[i].v;
		if (find(u)!=find(v)) uion(u,v),add(u,v,ed[i].w),add(v,u,ed[i].w);
	}
	for (int i=1;i<=n;i++){
		if (d[i]==0) dfs(i,0);
	}
	for (int i=1;i<30;i++){
		for (int u=1;u<=n;u++){
			fa[u][i]=fa[fa[u][i-1]][i-1];
			w[u][i]=min(w[u][i-1],w[fa[u][i-1]][i-1]);
			}
	}
//	for (int i=1;i<=n;i++) cout<<w[i][0]<<endl;
	scanf("%d",&q);
	for (int i=1,x,y;i<=q;i++){
		scanf("%d%d",&x,&y);
		if (find(x)!=find(y)){ printf("-1\n"); continue; }
		int ans=lca(x,y);
		printf("%d\n",ans);
	}
	return 0;
}
