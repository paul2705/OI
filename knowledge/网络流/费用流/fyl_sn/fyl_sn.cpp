//luogu_P3381
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int inf=1e9;
const int MAXN=5e3+5;
const int MAXM=MAXN*MAXN*4;
int edge=1,head[MAXN],nex[MAXM],tail[MAXM],w[MAXM],r[MAXM];
int dist[MAXN],h[MAXN],n,m;
int preu[MAXN],pree[MAXM];
int s,t,flow=0,cost=0;
bool use[MAXN];
struct rec{
	int dat,id;
	bool operator > (const rec& b) const {
		return dat<b.dat;
	}
	bool operator < (const rec& b) const {
		return dat>b.dat;
	}
};
priority_queue<rec> q;
void add(int u,int v,int R,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,r[edge]=R,w[edge]=W;
}
void ins(int u,int v,int R,int W){
	add(u,v,R,W); add(v,u,0,-W);
}
void dij(){
	for (int i=1;i<=n;i++) use[i]=0,dist[i]=inf;
	while (!q.empty()) q.pop();
	q.push((rec){0,s}); dist[s]=0;
	while (!q.empty()){
		rec u=q.top(); q.pop();
		if (use[u.id]) continue;
		use[u.id]=1;
		for (int e=head[u.id];e;e=nex[e]){
			int v=tail[e];
			if (r[e]>0&&dist[v]>dist[u.id]+w[e]+h[u.id]-h[v]){
				preu[v]=u.id; pree[v]=e;
				dist[v]=dist[u.id]+w[e]+h[u.id]-h[v];
				q.push((rec){dist[v],v});
			}
		}
	}
}
int main(){
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for (int i=1;i<=m;i++){
		int u,v,w,f;
		scanf("%d%d%d%d",&u,&v,&w,&f);
		ins(u,v,w,f);
	}
//	dij();
	while (true){
//		for (int i=1;i<=n;i++) h[i]+=dist[i];
		dij();
		if (dist[t]==inf) break;
		for (int i=1;i<=n;i++) h[i]+=dist[i];
		int del=inf;
		for (int x=t;x!=s;x=preu[x]){
			int e=pree[x];
			del=min(del,r[e]);
		}
		flow+=del; cost+=del*h[t];
//		cout<<del<<" "<<h[t]<<endl;
		for (int x=t;x!=s;x=preu[x]){
			int e=pree[x];
			r[e]-=del; r[e^1]+=del;
		}
	}
	printf("%d %d\n",flow,cost);
	return 0;
}
