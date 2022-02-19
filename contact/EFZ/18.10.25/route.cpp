#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
const int MAXM=MAXN*2;
int edge,head[MAXN],from[MAXM],tail[MAXM],nex[MAXM];
ll ww[MAXM],w[MAXM],rw[MAXM],rrw[MAXM],rww[MAXM];
int redge,rhead[MAXN],rtail[MAXM],rnex[MAXM];
int n,m,ru[MAXM],rv[MAXM];
ll dist[3][MAXN],f[MAXM];
int rd[MAXN];
int ed,he[MAXN],ta[MAXM],ne[MAXM];
int red,rid[MAXM],rhe[MAXN],rta[MAXM],rne[MAXM];
int ale=0,id[MAXM];
bool use[MAXM];
struct rec{
	ll dis,u;
	bool operator < (const rec& a)const{
		return dis<a.dis;
	}
	bool operator > (const rec& a)const{
		return dis>a.dis;
	}
};
priority_queue<rec,vector<rec>,greater<rec> > q;
void ad(int id,int u,int v,ll W){
	ed=id,ne[ed]=he[u],he[u]=ed,ta[ed]=v,ww[ed]=W;
}
void rad(int id,int u,int v,ll W){
	red=id,rne[red]=rhe[u],rhe[u]=red,rta[red]=v,rww[red]=W;
}
void add(int u,int v,ll W){
	edge++,nex[edge]=head[u],from[edge]=u,head[u]=edge,tail[edge]=v,w[edge]=W;
}
void radd(int u,int v,ll W){
	redge++,rnex[redge]=rhead[u],rhead[u]=redge,rtail[redge]=v,rw[redge]=W;
}
void dij(int s,int id){
	for (int i=1;i<=n;i++) dist[id][i]=1e17;
	q.push((rec){0,s}); dist[id][s]=0;
	while (!q.empty()){
		rec u=q.top(); q.pop();
		if (u.dis>dist[id][u.u]) continue;
		for (int e=head[u.u];e;e=nex[e]){
			int v=tail[e];
			if (dist[id][v]>dist[id][u.u]+w[e]){
				dist[id][v]=dist[id][u.u]+w[e];
				q.push((rec){dist[id][v],v});
			}
		}
	}
}
void rdij(int s,int id){
	for (int i=1;i<=n;i++) dist[id][i]=1e17;
	q.push((rec){0,s}); dist[id][s]=0;
	while (!q.empty()){
		rec u=q.top(); q.pop();
		if (u.dis>dist[id][u.u]) continue;
		for (int e=rhead[u.u];e;e=rnex[e]){
			int v=rtail[e];
			if (dist[id][v]>dist[id][u.u]+rw[e]){
				dist[id][v]=dist[id][u.u]+rw[e];
				q.push((rec){dist[id][v],v});
			}
		}
	}
}
void ini(){
	for (int e=1;e<=m;e++){
		int u=from[e],v=tail[e];
		if (dist[1][u]+w[e]+dist[2][v]==dist[1][2]){
			use[e]=1;
			ad(e,u,v,w[e]); rd[v]++; rad(e,v,u,w[e]);
		}
	}
}
void bfs(){
	queue<int> q;
	for (int i=1;i<=n;i++) if (rd[i]==0) q.push(i),f[i]=1;
	while (!q.empty()){
		int u=q.front(); q.pop();
		ll ret=0;
		for (int e=rhe[u];e;e=rne[e]) ret+=f[e];
		for (int e=he[u];e;e=ne[e]){
			f[e]=ret;
			int v=ta[e];
			if (rd[v]>0){
				rd[v]--;
				if (rd[v]==0) q.push(v);
			}
		}
	}
}
int main(){
	freopen("route.in","r",stdin);
	freopen("route.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		scanf("%d%d%lld",&ru[i],&rv[i],&rrw[i]);
		add(ru[i],rv[i],rrw[i]); radd(rv[i],ru[i],rrw[i]);
	}
	dij(1,1); rdij(2,2);
	ini();
	bfs();
//	cout<<dist[1][2]<<endl;
	for (int e=rhe[2];e;e=rne[e]) ale+=f[e];
	for (int i=1;i<=m;i++){
		ll disuv=dist[2][ru[i]]+rrw[i]+dist[1][rv[i]];
		if (!use[i]){
			if (disuv<dist[1][2]&&disuv<1e17) printf("-1\n");
			else if (dist[1][2]>=1e17) printf("1\n");
			else printf("0\n");
			continue;
		}
		if (dist[1][2]>=1e17&&disuv>=1e17) printf("1\n");
		else if (f[i]==ale&&disuv>=1e17) printf("1\n");
		else if (disuv<dist[1][2]) printf("-1\n");
		else if (f[i]<ale) printf("0\n");
		else if (disuv==dist[1][2]) printf("0\n");
		else printf("1\n");
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
