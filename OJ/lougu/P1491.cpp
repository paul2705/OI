#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
const int inf=1e9;
const int MAXN=2e2+5;
const int MAXM=MAXN*MAXN;
int edge=1,head[MAXN],nex[MAXM],tail[MAXM];
double w[MAXM],dis[MAXN];
bool use[MAXN];
int n,m,pre[MAXN];
double x[MAXN],y[MAXN];
void add(int u,int v,double W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
double sq(double x){ return x*x; }
double dist(int u,int v){ return sqrt(sq(x[u]-x[v])+sq(y[u]-y[v])); }
void dij(int E){
	memset(dis,63,sizeof(dis));
	memset(use,0,sizeof(use));
	queue<int> q; q.push(1); dis[1]=0; use[1]=1;
	while (!q.empty()){
		int u=q.front(); q.pop(); use[u]=0;
		cout<<u<<" "<<dis[u]<<endl;
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e]; if (E==e||(E^1)==e) continue;
			if (dis[v]>dis[u]+w[e]){
				dis[v]=dis[u]+w[e];
				pre[v]=e;
				if (!use[v]) use[v]=1,q.push(v);
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%lf%lf",&x[i],&y[i]);
	for (int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		add(u,v,dist(u,v));
		add(v,u,dist(u,v));
	}
	dij(-1); double ans=inf;
	cout<<dis[n]<<endl;
	for (int u=n;u>1;u=tail[pre[u]^1]){
		cout<<u<<" "<<pre[u]<<endl;
		int e=pre[u];
		dij(e);
		ans=min(ans,dis[n]);
	}
	if (ans==inf) printf("-1\n");
	else printf("%lf\n",ans);
	return 0;
}
