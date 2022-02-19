#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
typedef pair<ll,ll> par;
typedef long long ll;
const int MAXN=5e5+5;
const int MAXM=1e6+6;
ll edge,head[MAXN],nex[MAXM],tail[MAXM],c[MAXN];
ll n,f[MAXN],mn[MAXN];
ll cnt,ans;
void add(ll u,ll v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void ini(ll u,ll p){
//	cout<<u<<endl;
	ll res=c[u];
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v!=p){
			ini(v,u);
			res=max(res,mn[v]);
		}
	}
	mn[u]=res;
}
void dfs(ll u,ll p){
	priority_queue<par> q;
	if (u!=1){ f[u]=(++cnt)+c[u]; ans=max(ans,f[u]); }
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v!=p){
			q.push((par){mn[v],v});
		}
	}
	while (!q.empty()){
		int v=q.top().second; q.pop();
		dfs(v,u);
		cnt++;
	}
}
int main(){
	scanf("%lld",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&c[i]);
	for (ll i=1,u,v;i<n;i++){
		scanf("%lld%lld",&u,&v);
		add(u,v); add(v,u);
	}
	ini(1,0);
	dfs(1,0); f[1]=2*(n-1)+c[1]; ans=max(ans,f[1]);
//	for (ll i=1;i<=n;i++) printf("%d ",f[i]); cout<<endl;
	printf("%lld\n",ans);
	return 0;
}
