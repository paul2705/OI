#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll inf=1e15;
const int MAXN=2e3+10;
const int MAXM=4e4+20;
int edge=1,head[MAXN],tail[MAXM],nex[MAXM];
ll dist[MAXN],r[MAXM],w[MAXM];
int n,S,T,pree[MAXN],preu[MAXN];
int q[MAXM];
bool use[MAXN];
ll flow=0,cost=0;
// |x1-x2|+|y1-y2|=max(x1+y1-(x2+y2),x1-y1-(x2-y2),(y1-x1)-(y2-x2),-(x1+y1)+x2+y2
void add(int u,int v,ll R,ll W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,r[edge]=R,w[edge]=W;
}
void ins(int u,int v,ll R,ll W){
	add(u,v,R,-W); add(v,u,0,W);
}
bool spfa(){
	for (int i=1;i<=T;i++) use[i]=0,dist[i]=inf;
	dist[S]=0; int L=0,R=0; q[++R]=S; use[S]=1;
	while (L<R){
		int u=q[++L];
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			if (dist[v]>dist[u]+w[e]&&r[e]>0){
				dist[v]=dist[u]+w[e];
				preu[v]=u; pree[v]=e;
				if (!use[v]) q[++R]=v,use[v]=1;
			}
		}
		use[u]=0;
	}
	return dist[T]<inf;
}
void argument(){
	ll res=inf;
	for (int now=T;now!=S;now=preu[now]){
		int e=pree[now];
		res=min(res,r[e]);
	}
	flow+=res; cost+=res*dist[T];
	for (int now=T;now!=S;now=preu[now]){
		int e=pree[now];
		r[e]-=res; r[e^1]+=res;
	}
}
int main(){
	scanf("%d",&n);
	S=2*n+5; T=S+1;
	for (int i=1;i<=n;i++){
		int x,y,c; scanf("%d%d%d",&x,&y,&c);
		ins(S,i,c,0);
		ins(i,2*n+1,inf,x+y);
		ins(i,2*n+2,inf,x-y);
		ins(i,2*n+3,inf,y-x);
		ins(i,2*n+4,inf,-x-y);
	}
	for (int i=1;i<=n;i++){
		int x,y,c; scanf("%d%d%d",&x,&y,&c);
		ins(i+n,T,c,0);
		ins(2*n+1,i+n,inf,-x-y);
		ins(2*n+2,i+n,inf,y-x);
		ins(2*n+3,i+n,inf,x-y);
		ins(2*n+4,i+n,inf,x+y);
	}
	while (spfa()) argument();
	printf("%lld\n",-cost);
	return 0;
}
