#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll inf=1e11;
const int MAXN=1e5+5;
const int MAXM=2e5+5;
int edge=1,head[MAXN],nex[MAXM],tail[MAXM];
ll w[MAXM],cnt[MAXN];
int n,m;
int fa[MAXN],d[MAXN];
int mx1[MAXN],mx2[MAXN];
ll ans=inf,mx=0,S,f[MAXN];
int sz[MAXN],son[MAXN],tp[MAXN];
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void dfs_son(int u,int p){
	fa[u]=p; d[u]=d[p]+1; sz[u]=1;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		dfs_son(v,u);
		sz[u]+=sz[v];
		if (sz[v]>sz[son[u]]) son[u]=v;
	}
}
void dfs_tp(int u,int p,int T){
	tp[u]=T;
	if (son[u]) dfs_tp(son[u],u,T);
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		if (v==son[u]) continue;
		dfs_tp(v,u,v);
	}
}
int lca(int x,int y){
	while (tp[x]!=tp[y]){
		if (d[tp[x]]<d[tp[y]]) swap(x,y);
		x=fa[tp[x]];
	}
	if (d[x]>d[y]) swap(x,y);
	return x;
}
void dfs_cnt(int u,int p){
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		dfs_cnt(v,u);
		cnt[u]+=cnt[v];
		w[e]=w[e^1]=cnt[v];
	}
}
void dfs1(int u,int p){
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		dfs1(v,u);
		if (w[e]>mx1[u]){
			mx2[u]=mx1[u];
			mx1[u]=w[e];
		}
		else if (w[e]>mx2[u]) mx2[u]=w[e];
		S+=w[e];
	}
	mx+=mx1[u];
}
void dfs2(int u,int p){
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		ll rmx=mx;
		ll mxu1=mx1[u],mxu2=mx2[u];
		ll mxv1=mx1[v],mxv2=mx2[v];
		if (w[e]==mx1[u]){
			mx-=w[e]; mx+=mx2[u];
		}
		if (w[e]>mx1[v]){
			mx-=mx1[v]; mx+=w[e];
			mx2[v]=mx1[v];
			mx1[v]=w[e]; 
		}
		else if (w[e]>mx2[v]) mx2[v]=w[e];
		ans=min(ans,S-mx);
//		cout<<v<<" "<<S<<" "<<mx<<" "<<mx1[v]<<" "<<mx2[v]<<endl;
		dfs2(v,u);
		mx1[v]=mxv1; mx2[v]=mxv2;
		mx=rmx;
	}
}
int main(){
	freopen("B.in","r",stdin);
//	freopen("B.ans","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<n;i++){
		int u,v; scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	dfs_son(1,0); dfs_tp(1,0,1);
	for (int i=1;i<=m;i++){
		int u,v; scanf("%d%d",&u,&v);
		int f=lca(u,v); 
//		cout<<u<<" "<<v<<" "<<f<<endl;
		cnt[u]++; cnt[v]++; cnt[f]-=2;
	}
	dfs_cnt(1,0);
	dfs1(1,0);
	ans=S-mx;
//	cout<<ans<<endl;
	dfs2(1,0);
	printf("%lld\n",ans);
	return 0;
}
