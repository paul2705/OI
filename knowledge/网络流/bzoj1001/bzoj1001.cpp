#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=2e6+15;
const int MAXM=8e6+60;
int edge,head[MAXN],tail[MAXM],nex[MAXM],w[MAXM];
int n,m,S,T,dist[MAXN];
bool use[MAXN];
struct rq{
	int u,dist;
	bool operator < (const rq& b) const {
		return dist>b.dist;
	}
};
priority_queue<rq> q;
void add(int u,int v,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
void ins(int u,int v,int W){
	add(u,v,W); add(v,u,W);
}
int main(){
	freopen("A.in","r",stdin);
	scanf("%d%d",&n,&m);
	if (n==1||m==1){
		if (n>m) swap(n,m);
		int ans=1e9;
		for (int i=1;i<m;i++){
			int x; scanf("%d",&x);
			ans=min(ans,x);
		}
		printf("%d\n",ans);
		return 0;
	}
	S=2*(n*m+1); T=S+1;
	for (int j=1;j<m;j++){
		int w; scanf("%d",&w);
		ins(S,2*j,w);
	}
	for (int i=2;i<n;i++){
		for (int j=1;j<m;j++){
			int id=(i-2)*m+j;
			int nid=(i-1)*m+j;
			int w; scanf("%d",&w);
			ins(2*id+1,2*nid,w);
		}
	}
	for (int j=1;j<m;j++){
		int w; scanf("%d",&w);
		int id=(n-2)*m+j;
		ins(2*id+1,T,w);
	}
	for (int i=1;i<n;i++){
		int w; scanf("%d",&w);
		ins(2*((i-1)*m+1)+1,T,w);
		for (int j=2;j<m;j++){
			scanf("%d",&w);
			int id=(i-1)*m+j;
			int nid=(i-1)*m+j-1;
			ins(2*id+1,2*nid,w);
		}
		scanf("%d",&w);
		ins(S,2*((i-1)*m+m-1),w);
	}
	for (int i=1;i<n;i++){
		for (int j=1;j<m;j++){
			int id=(i-1)*m+j;
			int w; scanf("%d",&w);
			ins(2*id,2*id+1,w);
		}
	}
//	for (int i=1;i<=T;i++){
//		for (int e=head[i];e;e=nex[e]){
//			int v=tail[e];
//			cout<<i<<" "<<v<<" "<<w[e]<<endl;
//		}
//	}
	for (int i=1;i<=T;i++) dist[i]=1e9,use[i]=0;
	dist[S]=0; q.push((rq){S,0});
	while (!q.empty()){
		rq u=q.top(); q.pop();
		if (use[u.u]) continue;
		use[u.u]=1;
		for (int e=head[u.u];e;e=nex[e]){
			int v=tail[e];
			if (dist[v]>dist[u.u]+w[e]){
				dist[v]=dist[u.u]+w[e];
				q.push((rq){v,dist[v]});
			}
		}
	}
	printf("%d\n",dist[T]);
	return 0;
}
