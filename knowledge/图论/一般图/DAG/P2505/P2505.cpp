#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int MAXN=1505;
const int MAXM=5e3+5;
int edge,head[MAXN],tail[MAXM],from[MAXM],nex[MAXM],w[MAXM];
int dist[MAXN];
int res[MAXN],cnt,ins[MAXM],rd[MAXN];
int n,m,cnt1[MAXN],cnt2[MAXN];
ll ans[MAXM];
bool use[MAXN];
struct rq{
	int u,dist;
	bool operator < (const rq& b) const {
		return dist>b.dist;
	}
};
priority_queue<rq> q;
queue<int> q1;
void add(int u,int v,int W){
	edge++,nex[edge]=head[u],head[u]=edge,from[edge]=u,tail[edge]=v,w[edge]=W;
}
void dij(int S){
	for (int i=1;i<=n;i++) dist[i]=1e9,use[i]=0;
	for (int i=1;i<=m;i++) ins[i]=0;
	dist[S]=0; q.push((rq){S,0});
	while (!q.empty()){
		rq u=q.top(); q.pop();
		if (use[u.u]) continue;
		use[u.u]=1;
		for (int e=head[u.u];e;e=nex[e]){
			int v=tail[e];
			if (dist[v]>dist[u.u]+w[e]){
				dist[v]=dist[u.u]+w[e];
				q.push((rq){v,dist[v]});
			}
		}
	}
	for (int e=1;e<=m;e++){
		if (dist[from[e]]+w[e]==dist[tail[e]]) ins[e]=1;
	}
}
void solve(int S){
	dij(S);
	for (int i=1;i<=n;i++) rd[i]=cnt1[i]=cnt2[i]=0;
	cnt=0;
	cnt1[S]=1;
	for (int i=1;i<=m;i++) if (ins[i]) rd[tail[i]]++;
	q1.push(S); res[cnt++]=S;
	while (!q1.empty()){
		int u=q1.front(); q1.pop();
		for (int e=head[u];e;e=nex[e]){
			if (!ins[e]) continue;
			int v=tail[e];
			rd[v]--;
			if (rd[v]==0) q1.push(v),res[cnt++]=v;
			cnt1[v]=(cnt1[v]+cnt1[u])%mod;
		}
	}
	for (int i=cnt-1;i>=0;i--){
		int u=res[i]; cnt2[u]=1;
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			if (!ins[e]) continue;
			cnt2[u]=(cnt2[u]+cnt2[v])%mod;
		}
	}
	for (int e=1;e<=m;e++){
		if (ins[e]) ans[e]=(ans[e]+(ll)cnt1[from[e]]*cnt2[tail[e]]%mod)%mod;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int u,v,w; scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
	}
	for (int i=1;i<=n;i++) solve(i);
	for (int e=1;e<=m;e++) printf("%lld\n",ans[e]);
	return 0;
}
