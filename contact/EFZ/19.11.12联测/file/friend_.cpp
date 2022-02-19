#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const ll inf=1e15;
const int MAXN=205;
const int MAXM=2e5+5;
int edge,head[MAXN],tail[MAXM],nex[MAXM];
ll w[MAXM];
int n,m,T;
ll ans[MAXN][MAXN][MAXN];
ll dist[MAXN];
bool use[MAXN];
struct rec{
	int u;
	ll dist;
	bool operator < (const rec& b) const{
		return dist>b.dist;
	}
};
priority_queue<rec> q;
void add(int u,int v,ll W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
ll dij(int STOP,int S,int T){
	for (int i=1;i<=n;i++) dist[i]=inf,use[i]=0;
	dist[S]=0; q.push((rec){S,dist[S]});
	while (!q.empty()){
		rec u=q.top(); q.pop();
		if (use[u.u]) continue;
		use[u.u]=1;
		for (int e=head[u.u];e;e=nex[e]){
			int v=tail[e];
			if (v==STOP) continue;
			if (dist[v]>dist[u.u]+w[e]){
				dist[v]=dist[u.u]+w[e];
				q.push((rec){v,dist[v]});
			}
		}
	}
	return dist[T];
}
int main(){
	freopen("friend.in","r",stdin);
	freopen("friend.out","w",stdout);
	scanf("%d%d%d",&n,&m,&T);
	for (int i=1;i<=m;i++){
		int u,v; ll w; scanf("%d%d%lld",&u,&v,&w);
		add(u,v,w); add(v,u,w);
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			for (int k=1;k<=n;k++) ans[i][j][k]=-1;
		}
	}
	for (int i=1;i<=T;i++){
		int x,u,v; scanf("%d%d%d",&x,&u,&v);
		ll tmp=ans[x][u][v];
		if (tmp!=-1){
			printf("%lld\n",tmp>=inf?-1:tmp);
		}
		else {
			tmp=ans[x][u][v]=dij(x,u,v);
			printf("%lld\n",tmp>=inf?-1:tmp);
		}
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
