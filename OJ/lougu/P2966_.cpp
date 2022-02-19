#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=3e2+5;
const int MAXM=2e5+5;
int edge,head[MAXN],nex[MAXM],tail[MAXM],w[MAXM];
int n,m,k,dist[MAXN][MAXN],mx[MAXN][MAXN],a[MAXN];
bool use[MAXN];
void add(int u,int v,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
void dij(int s){
	memset(use,0,sizeof(use));
	queue<int> q; q.push(s); dist[s][s]=0; mx[s][s]=a[s];
	while (!q.empty()){
		int u=q.front(); q.pop(); use[u]=0;
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e],res=max(a[v],mx[s][u]);
			if (dist[s][v]+mx[s][v]>dist[s][u]+res+w[e]){
				dist[s][v]=dist[s][u]+w[e];
				mx[s][v]=res;
				if (!use[v]) q.push(v),use[v]=1;
			}
		}
	}
}
int main(){
//	freopen("P2966.in","r",stdin);
//	freopen("P2966.out","w",stdout);
	memset(mx,63,sizeof(mx));
	memset(dist,63,sizeof(dist));
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w); add(v,u,w);
	}
	for (int i=1;i<=n;i++) dij(i);
	for (int i=1,u,v;i<=k;i++){
		scanf("%d%d",&u,&v);
		printf("%d\n",dist[u][v]+mx[u][v]);
	}
	return 0;
}
