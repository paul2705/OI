#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=2e3+5;
const int MAXM=MAXN*MAXN;
int edge,head[MAXN],nex[MAXM],tail[MAXM],w[MAXM];
int n,m,mp[MAXN][MAXN],dist[MAXN],f[MAXN];
struct rec{
	int dis,u;
	bool operator < (const rec& a) const {
		return dis<a.dis;
	}
	bool operator > (const rec& a) const {
		return dis>a.dis;
	}
};
priority_queue<rec,vector<rec>,greater<rec> > q;
void add(int u,int v,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++) mp[i][j]=-1;
	}
	for (int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		mp[u][v]=min(mp[u][v],w);
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (mp[i][j]>=0) add(i,j,mp[i][j]);
		}
	}
//	memset(dist,63,sizeof(dist)); 
	for (int i=1;i<=n;i++) dist[i]=1e9;
	memset(f,0,sizeof(f)); f[1]=1;
	dist[1]=0; q.push((rec){0,1});
	while (!q.empty()){
		rec u=q.top(); q.pop();
		if (u.dis>dist[u.u]) continue;
		for (int e=head[u.u];e;e=nex[e]){
			int v=tail[e];
			if (dist[v]>dist[u.u]+w[e]){
				dist[v]=dist[u.u]+w[e];
				f[v]=f[u.u];
				q.push((rec){dist[v],v});
			}
			else if (dist[v]==dist[u.u]+w[e]) f[v]+=f[u.u];
		}
	}
//	for (int i=1;i<=n;i++) cout<<dist[i]<<" "<<f[i]<<endl;
	if (dist[n]<1e9) printf("%d %d\n",dist[n],f[n]);
	else printf("No answer\n");
	return 0;
}
