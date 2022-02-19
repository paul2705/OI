#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=5e5+5;
const int MAXM=1e6+6;
ll edge,head[MAXN],nex[MAXM],tail[MAXM],w[MAXM];
ll f[MAXN],g[MAXN];
ll n,s;
void add(ll u,ll v,ll W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
void dfs(ll u,ll p){
	for (ll e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v!=p){
			dfs(v,u);
			g[u]=max(g[u],g[v]+w[e]);
		}
	}
	for (ll e=head[u];e;e=nex[e]){
		ll v=tail[e];
		if (v!=p){
			f[u]+=f[v]+g[u]-(g[v]+w[e]);
		}
	}
}
int main(){
	scanf("%lld%lld",&n,&s);
	for (ll i=1,u,v,w;i<n;i++){
		scanf("%lld%lld%lld",&u,&v,&w);
		add(u,v,w); add(v,u,w);
	}
	dfs(s,0);
	printf("%lld\n",f[s]);
	return 0;
}
