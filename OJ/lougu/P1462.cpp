#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int MAXN=1e4+5;
const int MAXM=1e5+5;
ll edge,head[MAXN],tail[MAXM],nex[MAXM],w[MAXM];
ll v[MAXN],n,m,b,dist[MAXN],use[MAXN];
void add(int u,int v,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
bool xpfa(ll cap){
	queue<ll> q; memset(dist,127,sizeof(dist));
	memset(use,0,sizeof(use));
	dist[1]=0; use[1]=1; q.push(1);
	while (!q.empty()){
		int u=q.front(); q.pop(); use[u]=0;
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			if (w[e]<=cap&&dist[v]>dist[u]+w[e]){
				dist[v]=dist[u]+w[e];
				if (!use[v]) q.push(v),use[v]=1;
			}
		}
	}
	return dist[n]<=b;
}
int main(){
	scanf("%lld%lld%lld",&n,&m,&b);
	ll res=0;
	for (int i=1;i<=n;i++) scanf("%lld",&v[i]),res=max(res,v[i]);
	for (ll i=0,u,v,w;i<m;i++){
		scanf("%lld%lld%lld",&u,&v,&w);
		add(u,v,w); add(v,u,w);
	}
	xpfa(res);
	if (dist[n]>=b) return printf("AFK\n"),0;
	ll l=max(v[1],v[n]),r=res,mid;
	while (l<=r){
		mid=(l+r)>>1;
		if (xpfa(mid)) r=mid-1;
		else l=mid+1;
	}
	printf("%lld\n",l);
	return 0;
}
