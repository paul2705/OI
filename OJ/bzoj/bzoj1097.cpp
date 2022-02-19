#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<bitset>
using namespace std;
const int MAXN=2e4+5;
const int MAXM=4e5+6;
const int MAXK=21;
const int MAXS=(1<<MAXK);
const int inf=1e9;
int n,m,k,x;
int edge,head[MAXN],nex[MAXM],tail[MAXM],w[MAXM];
int dist[MAXK+5][MAXK+5],dis[MAXN],rd[MAXN];
int pow[MAXK+5];
bool use[MAXN];
int f[MAXS][MAXK];
struct rq{
	int u,dist;
	bool operator < (const rq& b) const {
		return dist>b.dist;
	}
};
priority_queue<rq> q;
void add(int u,int v,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
void dij(int id,int S){
	for (int i=1;i<=n;i++) dis[i]=inf,use[i]=0;
	dis[S]=0; q.push((rq){S,0});
	while (!q.empty()){
		rq u=q.top(); q.pop();
		if (use[u.u]) continue;
		use[u.u]=1;
		for (int e=head[u.u];e;e=nex[e]){
			int v=tail[e];
			if (dis[v]>dis[u.u]+w[e]){
				dis[v]=dis[u.u]+w[e];
				q.push((rq){v,dis[v]});
			}
		}
	}
	for (int i=1;i<=k+1;i++) dist[id][i]=dis[i];
	dist[id][0]=dis[n];
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	pow[0]=1;
	for (int i=1;i<=k;i++) pow[i]=pow[i-1]*2;
	for (int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w); add(v,u,w);
	}
	scanf("%d",&x);
	for (int i=1;i<=x;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		rd[v]+=pow[u-2];
	}
	for (int i=1;i<=k+1;i++) dij(i,i);
	memset(f,-1,sizeof(f));
	f[0][1]=0;
	for (int s=0;s<(1<<k);s++){
		for (int i=1;i<=k+1;i++){
			if (f[s][i]!=-1)
			for (int j=2;j<=k+1;j++){
				int vs=j-2;
				int tst=(s|pow[vs]);
//				if (s&pow[vs]) continue;
				if ((s&rd[j])==rd[j])
				if (f[tst][j]>f[s][i]+dist[i][j]||f[tst][j]==-1){
					f[tst][j]=f[s][i]+dist[i][j];
				}
			}
		}
	}
	int ans=inf;
	for (int i=1;i<=k+1;i++){
		if (f[(1<<k)-1][i]==-1) continue;
		ans=min(ans,f[(1<<k)-1][i]+dist[i][0]);
	}
	printf("%d\n",ans);
	return 0;
}
