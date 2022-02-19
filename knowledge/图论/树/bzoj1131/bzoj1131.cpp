#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e6+6;
const int MAXM=MAXN*2;
ll n,sz[MAXN],f[MAXN],d[MAXN];
ll ans,pos;
ll edge,head[MAXN],nex[MAXM],tail[MAXM];
void add(ll u,ll v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void dfs1(ll u,ll p){
	sz[u]=1; d[u]=d[p]+1; f[u]=d[u];
	for (ll e=head[u];e;e=nex[e]){
		ll v=tail[e];
		if (v==p) continue;
		dfs1(v,u);
		sz[u]+=sz[v];
		f[u]+=f[v];
	}
}
void dfs2(ll u,ll p){
//	cout<<"ans: "<<u<<" "<<f[u]<<endl;
//	if (f[u]>ans){
//		ans=f[u];
//		pos=u;
//	}
//	else if (f[u]==ans&&u<pos) pos=u;
	for (ll e=head[u];e;e=nex[e]){
		ll v=tail[e];
		if (v==p) continue;
//		ll ofv=f[v],ofu=f[u];
//		ll osu=sz[u],osv=sz[v];
//		sz[u]-=sz[v];
//		sz[v]=n;
//		f[u]-=f[v];
//		f[v]+=f[u]+sz[u];
		f[v]=f[u]+n-2*sz[v];
		dfs2(v,u);
//		sz[u]=osu; sz[v]=osv;
//		f[v]=ofv; f[u]=ofu;
	}
}
int main(){
	scanf("%lld",&n);
	for (int i=1;i<n;i++){
		ll u,v; scanf("%lld%lld",&u,&v);
		add(u,v); add(v,u);
	}
	dfs1(1,0);
	dfs2(1,0);
	for (int i=1;i<=n;i++){
		if (f[i]>f[ans]) ans=i;
	}
	printf("%lld\n",ans);
	return 0;
}
