#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e4+5;
const int MAXM=2e5+5;
int edge,head[MAXN],tail[MAXM],nex[MAXM],w[MAXM];
int up[MAXN],dn[MAXN];
int n,m,a[MAXN],sn[MAXN];
struct rec{
	int u,v,rw,w;
} ed[MAXM];
int fa[MAXN];
void add(int u,int v,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
int find(int x){ return fa[x]==x?x:fa[x]=find(fa[x]); }
void uion(int x,int y){ fa[find(x)]=find(y); }
bool cmp(rec a,rec b){ return a.w<b.w; }
void dfs1(int u,int p){
	dn[u]=a[u];
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		dfs1(v,u);
		dn[u]+=w[e]*2+dn[v]+a[u];
	}
}
void dfs2(int u,int p){
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		up[v]=up[u]+dn[u]-dn[v]-a[u]+a[v];
		dfs2(v,u);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),fa[i]=i;
	for (int i=1;i<=m;i++){
		int u,v,w; scanf("%d%d%d",&u,&v,&w);
		ed[i]=(rec){u,v,w,w*2+a[u]+a[v]};
	}
	sort(ed+1,ed+m+1,cmp);
	for (int i=1;i<=m;i++){
		int u=ed[i].u,v=ed[i].v,w=ed[i].rw;
		if (find(u)!=find(v)){
			uion(u,v); add(u,v,w); add(v,u,w);
//			cout<<u<<" "<<v<<" "<<w<<endl;
		}
	}
	dfs1(1,0);
	dfs2(1,0);
	int ans=1e9;
	for (int i=1;i<=n;i++){
//		cout<<i<<" "<<up[i]+dn[i]<<endl;
		ans=min(ans,up[i]+dn[i]);
	}
	printf("%d\n",ans);
	return 0;
}
