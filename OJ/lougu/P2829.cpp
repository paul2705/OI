#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=5e3+5;
const int MAXM=2e5+6;
const int INF=1e6;
int edge,head[MAXN],tail[MAXM],nex[MAXM],w[MAXM];
int n,m,k,cnt,md,sd=INF;
int t[MAXN],dist[3][MAXN];
bool use[MAXN],vis[MAXN];
struct ep{
	int u,dis;
	bool operator < (const ep& a) const {
		return dis<a.dis;
	}
	bool operator > (const ep& a) const {
		return dis>a.dis;
	}
};
void add(int u,int v,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
void dij(int s,int id){
	for (int i=1;i<=n;i++) dist[id][i]=INF;
	priority_queue<ep,vector<ep>,greater<ep> > q; 
	q.push((ep){s,0}); use[s]=1; dist[id][s]=0;
	while (!q.empty()){
		ep x=q.top(); q.pop(); 
		int u=x.u; if (x.dis>dist[id][u]) continue;
//		cout<<u<<" "<<x.dis<<endl;
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			if (dist[id][v]>dist[id][u]+w[e]){
				dist[id][v]=dist[id][u]+w[e];
//				cout<<v<<" "<<dist[id][v]<<endl;
				q.push((ep){v,dist[id][v]});
			}
		}
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for (int i=0,u,v,e;i<m;i++){
		scanf("%d%d%d",&u,&v,&e);
		add(u,v,e); add(v,u,e);
	}
	for (int i=2;i<n;i++){
		memset(vis,0,sizeof(vis));
		for (int e=head[i];e;e=nex[e]){
			int v=tail[e];
			if (!vis[v]) vis[v]=1,t[i]++;
		}
	}
	t[1]=t[n]=INF;
	dij(1,0); dij(n,1);
	md=dist[0][n];
	for (int i=1;i<=n;i++){
		if (t[i]<k) continue;
		for (int e=head[i];e;e=nex[e]){
			int v=tail[e];
			int l=dist[0][i]+w[e]+dist[1][v];
			if (l>md&&t[v]>=k) sd=min(sd,l);
		}
	}
	printf("%d\n",sd>=INF?-1:sd);
	return 0;
}
