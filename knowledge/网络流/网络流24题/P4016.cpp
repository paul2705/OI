#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=2e2+5;
const int MAXM=2e4+5;
const int inf=1e9;
int edge=1,head[MAXN],tail[MAXM],nex[MAXM],r[MAXM],w[MAXM];
int h[MAXN],dist[MAXN],preu[MAXN],pree[MAXN];
struct rq{
	int u,dist;
	bool operator < (const rq& b) const {
		return dist>b.dist;
	}
};
priority_queue<rq> q;
int n,S,T,flow,cost,a[MAXN];
bool use[MAXN];
void add(int u,int v,int R,int C){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,r[edge]=R,w[edge]=C;
}
void ins(int u,int v,int R,int C){
	add(u,v,R,C); add(v,u,0,-C);
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
			int W=w[e]+h[u.u]-h[v];
			if (dist[v]>dist[u.u]+W&&r[e]>0){
				dist[v]=dist[u.u]+W;
//				cout<<u.u<<" "<<v<<endl;
				pree[v]=e; preu[v]=u.u;
				q.push((rq){v,dist[v]});
			}
		}
	}
	return dist[T]<inf;
}
int main(){
	scanf("%d",&n);
	int sum=0;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),sum+=a[i];
	sum/=n; S=n+1;T=n+2;
	for (int i=1;i<=n;i++){
		ins(S,i,a[i],0); ins(i,T,sum,0);
		int pre=i-1,nxt=i+1;
		if (pre==0) pre=n;
		if (nxt==n+1) nxt=1;
//		cout<<pre<<" "<<i<<" "<<nxt<<endl;
		ins(i,pre,inf,1),ins(i,nxt,inf,1);
	}
	while (dij()){
//		cout<<"in"<<endl;
		for (int i=1;i<=n;i++) h[i]+=dist[i];
		int res=inf;
		for (int u=T;u!=S;u=preu[u]){
//			cout<<u<<endl;
			int e=pree[u],v=preu[u];
			res=min(res,r[e]); 
		}
		cost+=dist[T]*res;
		for (int u=T;u!=S;u=preu[u]){
			int e=pree[u],v=preu[u];
			r[e]-=res; r[e^1]+=res;
		}
	}
	printf("%d\n",cost);
	return 0;
}
