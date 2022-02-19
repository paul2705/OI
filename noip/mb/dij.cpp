#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=1e5+5;
const int MAXM=MAXN*2;
int edge,head[MAXN],nex[MAXM],tail[MAXM],w[MAXM];
int n,m,s,dist[MAXN];
struct rec{
	int dis,u;
	bool operator < (const rec& a)const {
		return dis<a.dis;
	}
	bool operator > (const rec& a)const {
		return dis>a.dis;
	}
};
priority_queue<rec,vector<rec>,greater<rec> > q;
void add(int u,int v,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
int main(){
	scanf("%d%d%d",&n,&m,&s);
	for (int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
	}
	memset(dist,63,sizeof(dist));
	dist[s]=0; q.push((rec){0,s});
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
	for (int i=1;i<=n;i++) printf("%d ",dist[i]);
	return 0;
}
