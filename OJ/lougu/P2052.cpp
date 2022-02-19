#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e6+6;
typedef long long ll;
ll edge,head[MAXN],tail[MAXN*2],nex[MAXN*2],w[MAXN*2],from[MAXN*2];
ll n,cnt[MAXN],ans,size;
void add(ll u,ll v,ll W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,from[edge]=u,w[edge]=W;
}
ll dfs(ll u,ll p){
	ll sz=1;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v!=p) sz+=dfs(v,u);
	}
	return cnt[u]=sz;
}
void gen(ll u,ll p){
	for (int e=head[u];e;e=nex[e]){
		ll v=tail[e];
		if (v!=p){
			ans+=w[e]*abs(size-cnt[v]*2);
			gen(v,u);
		}
	}
}
int main(){
	scanf("%lld",&n);
	for (ll i=1,u,v,w;i<n;i++){
		scanf("%lld%lld%lld",&u,&v,&w);
		add(u,v,w); add(v,u,w);
	}
	size=dfs(1,0); gen(1,0);
	printf("%lld\n",ans);
	return 0;
}
