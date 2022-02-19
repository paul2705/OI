#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int MAXN=1e3+5;
const int MAXM=2e3+5;
const ll inf=1e10;
ll dist[MAXN][MAXN];
bool use[MAXN][MAXN];
struct rec{
	int u,k,dist;
	bool operator < (const rec& b) const {
		return dist>b.dist;
	}
};
priority_queue<rec> q;
int n,m,S,T,k;
int edge,head[MAXN],tail[MAXM],nex[MAXM],w[MAXM];
void add(int u,int v,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d%d%d%d%d",&n,&m,&S,&T,&k);
	for (int i=1;i<=m;i++){
		int u,v,w; scanf("%d%d%d",&u,&v,&w);
		if (u==v) continue;
		add(u,v,w); add(v,u,w);
	}
	for (int i=1;i<=n;i++){
		for (int j=0;j<=k;j++) dist[i][j]=inf;
	}
	dist[S][0]=0; q.push((rec){S,0,0});
	while (!q.empty()){
		rec u=q.top(); q.pop();
		if (use[u.u][u.k]) continue;
		use[u.u][u.k]=1;
		for (int e=head[u.u];e;e=nex[e]){
			int v=tail[e];
			if (dist[v][u.k]>dist[u.u][u.k]+w[e]){
				dist[v][u.k]=dist[u.u][u.k]+w[e];
				q.push((rec){v,u.k,dist[v][u.k]});
			}
			if (dist[v][u.k+1]>dist[u.u][u.k]){
				dist[v][u.k+1]=dist[u.u][u.k];
				q.push((rec){v,u.k+1,dist[v][u.k+1]});
			}
		}
	}
	ll mn=inf;
	for (int i=0;i<=k;i++){
		mn=min(mn,dist[T][i]);
	}
	printf("%lld\n",mn);
	fclose(stdin); fclose(stdout);
	return 0;
}

