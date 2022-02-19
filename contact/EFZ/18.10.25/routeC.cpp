#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
const int MAXM=2e5+5;
int rv[MAXN],ru[MAXN],rrw[MAXN];
int edge,head[MAXN],nex[MAXM],tail[MAXM],w[MAXM];
int redge,rhead[MAXN],rnex[MAXM],rtail[MAXM],rw[MAXM];
int ed,he[MAXN],ne[MAXM],ta[MAXM],ww[MAXM];
int red,rhe[MAXN],rne[MAXM],rta[MAXM],rww[MAXM];
int n,m,f[MAXM],dist[MAXN],rdist[MAXN];
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
void radd(int u,int v,int W){
	redge++,rnex[redge]=rhead[u],rhead[u]=redge,rtail[redge]=v,rw[redge]=W;
}
void add_ini(int id,int u,int v,int W){
	ed=id,ne[ed]=he[u],he[u]=ed,ta[ed]=v,ww[ed]=W;
}
void radd_ini(int id,int u,int v,int W){
	red=id,rne[red]=rhe[u],rhe[u]=red,rta[red]=v,rww[red]=W;
}
void dij(int s){
	memset(dist,63,sizeof(dist)); 
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
}
void rdij(int s){
	memset(rdist,63,sizeof(rdist));
	q.push((rec){0,s}); rdist[s]=0;
	while (!q.empty()){
		rec u=q.top(); q.pop();
		if (u.dis>rdist[u.u]) continue;
		for (int e=rhead[u.u];e;e=rnex[e]){
			int v=rtail[e];
			if (rdist[v]>rdist[u]+rw[e]){
				rdist[v]=rdist[u]+rw[e];
				q.push((rec){rdist[v],v});
			}
		}
	}
}
void ini(){
	for (int u=1;u<=n;u++){
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			if (dist[u]+w[e]+rdist[v]==dist[2]){
				add_ini(e,u,v,w[e]); rd[v]++;
				radd_ini(e,v,u,w[e]);
			}
		}
	}
}
void topo(){
	queue<int> q;
	for (int i=1;i<=n;i++) if (rd[i]==0) q.push(i),f[i]=1;
	while (!q.empty()){
		int u=q.front(); q.pop();
		int ret=0;
		for (int e=rhe[u];e;e=rne[e]) ret+=f[e];
		for (int e=he[u];e;e=ne[e]){
			int v=ta[e];
			f[e]=ret; rd[v]--;
			if (rd[v]==0) q.push(v);
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		scanf("%d%d%d",&ru[i],&rv[i],&rrw[i]);
		add(ru[i],rv[i],rrw[i]); radd(rv[i],ru[i],rrw[i]);
	}
	dij(1); rdij(2); ini(); topo();
	int ale=0;
	for (int e=rhe[2];e;e=rne[e]) ale+=f[e];
	for (int i=1;i<=m;i++){
		int distuv=dist[rv[i]]+rdist[ru[i]]+rrw[i];
		if (dist[ru[i]]+rdist[rv[i]]+rrw[i]<=dist[2]) printf("-1\n");
		if (dist[ru[i]]+r
			
