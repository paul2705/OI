//luogu_P3381
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int inf=1e9;
const int MAXN=5e3+5;
const int MAXM=MAXN*MAXN*4;
int edge=1,head[MAXN],nex[MAXM],tail[MAXM],w[MAXM],r[MAXM];
int n,m,s,t,dist[MAXN],preu[MAXN],pree[MAXN];
int flow=0,cost=0;
int h[MAXN];
bool use[MAXN];
queue<int> q;
void add(int u,int v,int R,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W,r[edge]=R;
}
void ins(int u,int v,int R,int W){
	add(u,v,R,W); add(v,u,0,-W);
}
void dij(){
	for (int i=1;i<=n;i++) dist[i]=inf;
	dist[s]=0; q.push(s);
	while (!q.empty()){
		int u=q.front(); q.pop();
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			if (r[e]>0&&dist[v]>dist[u]+w[e]){
				dist[v]=dist[u]+w[e];
				preu[v]=u; pree[v]=e;
				if (!use[v]) q.push(v),use[v]=1;
			}
		}
		use[u]=0;
	}
}
int main(){
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for (int i=1;i<=m;i++){
		int u,v,w,f;
		scanf("%d%d%d%d",&u,&v,&w,&f);
		ins(u,v,w,f);
	}
	while (true){
		dij();
		if (dist[t]==inf) break;
//		for (int i=1;i<=n;i++) h[i]+=dist[i];
		int del=inf;
		for (int x=t;x!=s;x=preu[x]){
			int e=pree[x];
			del=min(del,r[e]);
		}
		flow+=del; cost+=del*dist[t];
		for (int x=t;x!=s;x=preu[x]){
			int e=pree[x];
			r[e]-=del; r[e^1]+=del;
		}
	}
	printf("%d %d\n",flow,cost);
	return 0;
}
