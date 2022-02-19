#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=2e3+5;
const int MAXM=6e4+5;
const int inf=1e9;
int edge=1,head[MAXN],tail[MAXM],nex[MAXM],r[MAXM],w[MAXM];
int n,m,S,T,cost,flow,p[MAXN];
int dist[MAXN],preu[MAXN],pree[MAXN],h[MAXN];
bool use[MAXN];
struct rq{
	int u,dist;
	bool operator < (const rq& b) const{
		return dist>b.dist;
	}
};
priority_queue<rq> q;
void add(int u,int v,int R,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W,r[edge]=R;
}
void ins(int u,int v,int R,int W){
//	cout<<u<<" "<<v<<endl;
	add(u,v,R,W); add(v,u,0,-W);
}
bool dij(){
	for (int i=1;i<=T;i++) dist[i]=inf,use[i]=0;
	dist[S]=0; q.push((rq){S,0});
	while (!q.empty()){
		rq u=q.top(); q.pop();
		if (use[u.u]) continue;
		use[u.u]=1;
		for (int e=head[u.u];e;e=nex[e]){
			int v=tail[e];
			int W=h[u.u]+w[e]-h[v];
			if (dist[v]>dist[u.u]+W&&r[e]>0){
				dist[v]=dist[u.u]+W;
				preu[v]=u.u; pree[v]=e;
				q.push((rq){v,dist[v]});
			}
		}
	}
	return dist[T]<inf;
}
int main(){
	scanf("%d%d",&n,&m);
	S=n+2,T=n+3;
	for (int i=1;i<=n;i++){
		scanf("%d",&p[i]);
		int del=p[i-1]-p[i];
		if (del>0) ins(i,T,del,0);
		else ins(S,i,-del,0);
		ins(i+1,i,inf,0);
	}
	ins(n+1,T,p[n],0);
	for (int i=1;i<=m;i++){
		int u,v,w; scanf("%d%d%d",&u,&v,&w);
		ins(u,v+1,inf,w);
	}
//	cout<<"fuck"<<endl;
	while (dij()){
//		cout<<"done"<<endl;
		for (int i=1;i<=T;i++) h[i]+=dist[i];
		int mn=inf;
		for (int u=T;u!=S;u=preu[u]){
//			cout<<u<<" "<<preu[u]<<endl;
			int v=preu[u],e=pree[u];
			mn=min(mn,r[e]);
		}
//		cout<<"fu"<<endl;
//		cout<<mn<<" "<<dist[T]<<endl;
		cost+=h[T]*mn;
		flow+=mn;
		for (int u=T;u!=S;u=preu[u]){
			int v=preu[u],e=pree[u];
			r[e]-=mn; r[e^1]+=mn;
		}
//		cout<<cost<<" "<<flow<<endl;
	}
	printf("%d\n",cost);
	return 0;
}
