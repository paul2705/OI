#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int MAXN=5e3+5;
const int MAXM=MAXN*13;
const int inf=1e18;
int edge=1,head[MAXN],tail[MAXM],nex[MAXM];
ll r[MAXM],w[MAXM];
ll dist[MAXN],h[MAXN];
ll n,flow,cost,S,T,a[MAXN];
int preu[MAXN],pree[MAXN];
struct rq{
	ll u,dist;
	bool operator < (const rq& b) const {
		return dist>b.dist;
	}
};
priority_queue<rq> q;
bool use[MAXN];
void add(int u,int v,ll R,ll W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W,r[edge]=R;
}
void ins(int u,int v,ll R,ll W){
	add(u,v,R,W); add(v,u,0,-W);
}
bool dij(){
	for (int i=1;i<=T;i++) dist[i]=inf,use[i]=0;
	dist[S]=0; q.push((rq){S,dist[S]});
	while (!q.empty()){
		rq u=q.top(); q.pop();
		if (use[u.u]) continue;
		use[u.u]=1;
		for (int e=head[u.u];e;e=nex[e]){
			int v=tail[e];
			ll W=-h[v]+h[u.u]+w[e];
			if (dist[v]>dist[u.u]+W&&r[e]>0){
				dist[v]=dist[u.u]+W;
				pree[v]=e; preu[v]=u.u;
				q.push((rq){v,dist[v]});
			}
		}
	}
	return dist[T]<inf;
}
int main(){
	scanf("%lld",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	int p,m,f,x,s;
	scanf("%d%d%d%d%d",&p,&m,&f,&x,&s);
	S=2*(n+1)+1; T=2*(n+1)+2;
	for (int i=1;i<=n;i++){
		ins(S,i*2,a[i],0);
		ins(S,i*2+1,inf,p);
		ins(i*2+1,T,a[i],0);
		if (i+1<=n) ins(i*2,(i+1)*2,inf,0);
		if (i+m<=n) ins(i*2,(i+m)*2+1,inf,f);
		if (i+x<=n) ins(i*2,(i+x)*2+1,inf,s);
	}
	while (dij()){
		for (int i=1;i<=T;i++) h[i]+=dist[i];
		ll res=inf;
		for (int u=T;u!=S;u=preu[u]){
			int v=preu[u],e=pree[u];
			res=min(res,r[e]);
		}
		flow+=res; cost+=h[T]*res;
		for (int u=T;u!=S;u=preu[u]){
			int v=preu[u],e=pree[u];
			r[e]-=res; r[e^1]+=res;
		}
	}
	printf("%lld\n",cost);
	return 0;
}
