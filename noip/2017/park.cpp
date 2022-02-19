#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=1e5+5;
const int MAXM=2e5+5;
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
queue<int> dq;
int edge,head[MAXN],tail[MAXM],nex[MAXM],w[MAXM];
int redge,rhead[MAXN],rtail[MAXM],rnex[MAXM],rw[MAXM];
int n,m,k,p,T,f[MAXN][800];
int dis[3][MAXN],d[MAXN],vs[MAXN];
bool fl,c[MAXN][800],use[MAXN];
void add(int u,int v,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
void radd(int u,int v,int W){
	redge++,rnex[redge]=rhead[u],rhead[u]=redge,rtail[redge]=v,rw[redge]=W;
}
void clr(){
	redge=edge=0;
	for (int i=1;i<=n;i++){
		for (int k=0;k<=55;k++) f[i][k]=-1;
	}
	for (int i=1;i<=n;i++) dis[1][i]=dis[2][i]=1e9,d[i]=rhead[i]=head[i]=0;
}
/*void dij(){
	dis[1][1]=0; q.push((rec){0,1});
	while (!q.empty()){
		rec u=q.top(); q.pop();
		if (dis[1][u.u]<u.dis||use[u.u]) continue;
//		use[u.u]=1;
		for (int e=head[u.u];e;e=nex[e]){
			int v=tail[e];
			if (dis[1][v]>dis[1][u.u]+w[e]){
				dis[1][v]=dis[1][u.u]+w[e];
				q.push((rec){dis[1][v],v});
			}
		}
	}
}*/
void dij(){
	dis[1][1]=0;use[1]=1; dq.push(1);
	while (!dq.empty()){
		int u=dq.front(); dq.pop();
		use[u]=0;
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			if (dis[1][v]>dis[1][u]+w[e]){
				dis[1][v]=dis[1][u]+w[e];
				if (!use[v]) dq.push(v),use[v]=1;
			}
		}
	}
}
int dfs(int u,int d){
//	cout<<u<<" "<<d<<endl;
	if (!fl) return 0;
	if (f[u][d]>=0) return f[u][d];
	c[u][d]=1; f[u][d]=0;
	for (int e=rhead[u];e;e=rnex[e]){
		int v=rtail[e];
		int x=dis[1][u]-rw[e]-dis[1][v]+d;
		if (x>=0){
			if (c[v][x]) fl=0;
			f[u][d]=(dfs(v,x)+f[u][d])%p;
		}
	}
	c[u][d]=0;
	return f[u][d];
}
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d%d%d",&n,&m,&k,&p);
		clr();
		for (int i=1;i<=m;i++){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			add(u,v,w); radd(v,u,w);
		}
		dij();
//		cout<<"fuck"<<endl;
		fl=1;
		int ans=0; f[1][0]=1;
		for (int j=0;j<=k;j++) ans=(ans+dfs(n,j))%p;
		dfs(n,k+1);
		if (!fl) printf("-1\n");
		else printf("%d\n",ans);
	}
	return 0;
}
