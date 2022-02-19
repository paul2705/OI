#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
const int MAXM=1e6+6;
int edge,head[MAXN],nex[MAXM],tail[MAXM],w[MAXM];
int cnt,fa[MAXN][20],mn[MAXN][20];
int n,m,q;
int f[MAXN],d[MAXN];
struct rec{
	int u,v,w;
} e[MAXM];
bool cmp(rec a,rec b){ return a.w>b.w; }
void add(int u,int v,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
void dfs(int u,int p){
//	cout<<u<<" "<<p<<endl;
	fa[u][0]=p; d[u]=d[p]+1;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		mn[v][0]=w[e];
		dfs(v,u);
	}
}
void ini(){
	for (int k=1;k<20;k++){
		for (int u=1;u<=n;u++){
			fa[u][k]=fa[fa[u][k-1]][k-1];
			mn[u][k]=min(mn[u][k-1],mn[fa[u][k-1]][k-1]);
		}
	}
}
int lca(int u,int v){
	if (d[u]<d[v]) swap(u,v);
	int ret=1e9;
	for (int k=19;k>=0;k--){
		if (d[fa[u][k]]>d[v]) ret=min(ret,mn[u][k]),u=fa[u][k];
	}
	if (d[u]>d[v]) ret=min(ret,mn[u][0]),u=fa[u][0];
	for (int k=19;k>=0;k--){
		if (fa[u][k]!=fa[v][k]){
			ret=min(ret,mn[u][k]);
			ret=min(ret,mn[v][k]);
			u=fa[u][k];
			v=fa[v][k];
		}
	}
	if (u!=v){
		ret=min(ret,mn[u][0]);
		ret=min(ret,mn[v][0]);
		u=fa[u][0]; v=fa[v][0];
	}
//	cout<<u<<" "<<v<<" "<<ret<<endl;
	return ret;
}
int find(int x){ return f[x]==x?x:f[x]=find(f[x]); }
void uion(int x,int y){ f[find(x)]=find(y); }
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) f[i]=i;
	for (int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		e[++cnt]=(rec){u,v,w};
	}
	sort(e+1,e+cnt+1,cmp);
	for (int i=1;i<=cnt;i++){
		int u=e[i].u,v=e[i].v;
		if (find(u)==find(v)) continue;
//		cout<<u<<" "<<v<<" "<<e[i].w<<endl;
		uion(u,v); add(u,v,e[i].w); add(v,u,e[i].w);
	}
	for (int i=1;i<=n;i++){
		if (!fa[i][0]) dfs(i,0); 
	}
	ini();
	scanf("%d",&q);
	for (int i=1,u,v;i<=q;i++){
		scanf("%d%d",&u,&v);
		if (find(u)!=find(v)){
			printf("-1\n");
			continue;
		}
		int lim=lca(u,v);
		printf("%d\n",lim);
	}
	return 0;
}
