#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int MAXN=1e3+5;
const int MAXM=MAXN*2;
int edge,head[MAXN],tail[MAXM],nex[MAXM];
ll w[MAXM],rw[MAXM];
int n,m,ru[MAXN],rv[MAXN];
ll dist[MAXN],dis;
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
void dij(int s){
	for (int i=1;i<=n;i++) dist[i]=1e9; dist[s]=0;
	q.push((rec){0,s});
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
void add(int u,int v,ll W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
int main(){
	freopen("route.in","r",stdin);
	freopen("route1.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		scanf("%d%d%lld",&ru[i],&rv[i],&rw[i]);
		add(ru[i],rv[i],rw[i]);
	}
	dij(1);
	dis=dist[2];
	for (int i=1;i<=m;i++){
		for (int j=1;j<=n;j++) head[j]=0;
		edge=0;
		for (int e=1;e<=m;e++){
			if (e==i) add(rv[e],ru[e],rw[e]);
			else add(ru[e],rv[e],rw[e]);
		}
		dij(1);
		if (dist[2]>=1e9) printf("1\n");
		else if (dis>dist[2]) printf("-1\n");
		else if (dis<dist[2]) printf("1\n");
		else printf("0\n");
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
