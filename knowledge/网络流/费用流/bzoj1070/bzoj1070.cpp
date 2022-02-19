#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=1e3+6;
const int MAXM=1e6+6;
const int inf=1e9;
int edge=1,nex[MAXM],head[MAXN],tail[MAXM],w[MAXM],r[MAXM];
int n,m,S,T;
int d[MAXN],h[MAXN];
int preu[MAXN],pree[MAXN];
bool use[MAXN];
int a[MAXN][MAXN];
struct rq{
	int u,d;
	bool operator < (const rq& b) const{
		return d>b.d;
	}
};
priority_queue<rq> q;
void add(int u,int v,int R,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,r[edge]=R,w[edge]=W;
}
void ins(int u,int v,int R,int W){
	add(u,v,R,W); add(v,u,0,-W);
}
bool dij(){
	for (int i=1;i<=T;i++) d[i]=inf,use[i]=0;
	d[S]=0; q.push((rq){S,0});
	while (!q.empty()){
		rq u=q.top(); q.pop();
		if (use[u.u]) continue;
		use[u.u]=1;
		for (int e=head[u.u];e;e=nex[e]){
			int v=tail[e];
			int W=h[u.u]+w[e]-h[v];
			if (d[v]>d[u.u]+W&&r[e]>0){
				d[v]=d[u.u]+W; preu[v]=u.u; pree[v]=e;
				q.push((rq){v,d[v]});
			}
		}
	}
	return d[T]<inf;
}
int main(){
	scanf("%d%d",&n,&m);
	S=m+n*m+1; T=S+1;
	for (int i=1;i<=m;i++){
		for (int j=1;j<=n;j++) scanf("%d",&a[i][j]);
	}
	for (int i=1;i<=m;i++) ins(S,i,1,0);
	for (int i=m+1;i<=n*m+m;i++) ins(i,T,1,0);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			for (int k=1;k<=m;k++) ins(k,m+(i-1)*m+j,1,a[k][i]*j);
		}
	}
	int flow=0,cost=0;
	while (dij()){
//		cout<<"in"<<endl;
		for (int i=1;i<=T;i++) h[i]+=d[i];
		int res=inf;
		for (int u=T;u!=S;u=preu[u]){
			int v=preu[u],e=pree[u];
			res=min(res,r[e]);
		}
//		cout<<res<<" "<<h[T]<<endl;
		flow+=res; cost+=res*h[T];
		for (int u=T;u!=S;u=preu[u]){
			int v=preu[u],e=pree[u];
			r[e]-=res; r[e^1]+=res;
		}
	}
	printf("%.2lf\n",(double)cost/(double)m);
	return 0;
}
