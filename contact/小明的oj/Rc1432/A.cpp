#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=1e3+5;
const int MAXM=1e6+6;
int edge,head[MAXN],tail[MAXM],nex[MAXM],w[MAXM];
int n,s,t;
struct rec{
	int dis,u;
	bool operator < (const rec& b) const {
		return dis<b.dis;
	}
	bool operator > (const rec& b) const {
		return dis>b.dis;
	}
};
priority_queue<rec,vector<rec>,greater<rec> > q;
int dist[MAXN];
void add(int u,int v,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
int main(){
	scanf("%d%d%d",&n,&s,&t);
	for (int i=1,x;i<=n;i++){
		dist[i]=1e9;
		scanf("%d",&x);
		for (int j=1,v;j<=x;j++){
			scanf("%d",&v);
			if (j==1) add(i,v,0);
			else add(i,v,1);
		}
	}
	q.push((rec){0,s}); dist[s]=0;
	while (!q.empty()){
		rec u=q.top(); q.pop();
		if (u.dis>dist[u.u]) continue;
		for (int e=head[u.u];e;e=nex[e]){
			int v=tail[e];
			if (dist[v]>dist[u.u]+w[e]){
				dist[v]=dist[u.u]+w[e];
				q.push((rec){dist[v],v});
			}
		}
	}
	printf("%d\n",dist[t]==1e9?-1:dist[t]);
	return 0;
}
