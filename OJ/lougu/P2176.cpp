#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e2+5;
const int MAXM=1e3*5+5;
int edge=1,head[MAXN],nex[MAXM],tail[MAXM],w[MAXM];
int n,m,ans,dist[MAXN],use[MAXN];
void add(int u,int v,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
void dij(int id,int u,int v){
	memset(dist[id],63,sizeof(dist[id]));
	queue<int> q; q.push(u); dist[id][u]=0;
	while (!q.empty()){
		int u=q.front(); q.pop();
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			if (dist[id][v]>dist[id][u]+w[e]){
				dist[id][v]=dist[id][u]+w[e];
`				pre[v]=u; pree[v]=e;
				if (!use[v]) q.push(v),use[v]=1;
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w); add(v,u,w);
	}
	dij(1,1,n);
	for (int u=n;u!=1;u=pre[u]){
		int e=pree[u];
		w[e]=w[e^1]=w[e]*2; 
		dij(2,1,n); ans=max(ans,dist[2][n]-dist[1][n]);
		w[e]=w[e^1]=w[e]/2;
	}
	printf("%d\n",ans);
	return 0;
}
