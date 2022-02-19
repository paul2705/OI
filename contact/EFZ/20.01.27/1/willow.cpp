#pragma GCC optimize(2)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=505*3;
const int MAXM=505*505*3;
const int MAXR=105;
const int inf=1e8;
const int dx[4]={1,-1,1,-1};
const int dy[4]={1,1,-1,-1};
int n,R,C,A,B;
int dist[MAXR*MAXR];
int a[MAXR*MAXR];
queue<int> q;
bool use[MAXN];
struct dot{
	int x,y;
} st[MAXN],ed[MAXN];
struct rec{
	int dat,id;
	bool operator < (const rec& b) const {
		return dat>b.dat;
	}
};
priority_queue<rec> qb;
int edge=1,head[MAXN],tail[MAXM],nex[MAXM],r[MAXM],w[MAXM];
int S,T,h[MAXN],d[MAXN],pree[MAXN],preu[MAXN];
int flow,cost;
void add(int u,int v,int R,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,r[edge]=R,w[edge]=W;
}
void ins(int u,int v,int R,int W){
	add(u,v,R,W); add(v,u,0,-W);
}
bool dij(){
	for (int i=1;i<=T;i++) d[i]=inf,use[i]=0;
	d[S]=0; qb.push((rec){0,S});
	while (!qb.empty()){
		rec u=qb.top(); qb.pop();
		if (use[u.id]) continue;
		use[u.id]=1;
		for (int e=head[u.id];e;e=nex[e]){
			int v=tail[e];
			int W=d[u.id]+w[e]+h[u.id]-h[v];
			if (d[v]>W&&r[e]>0){
				d[v]=W;
				pree[v]=e; preu[v]=u.id;
				qb.push((rec){d[v],v});
			}
		}
	}
	return d[T]<inf;
}
void aug(){
	int res=inf;
	for (int x=T;x!=S;x=preu[x]){
		int e=pree[x],v=preu[x];
		res=min(res,r[e]);
	}
//	cout<<res<<endl;
	flow+=res; cost+=res*h[T]; cost=min(cost,inf);
	for (int x=T;x!=S;x=preu[x]){
		int e=pree[x],v=preu[x];
		r[e]-=res; r[e^1]+=res;
	}
}
bool ub(int x,int y){
	return x<0||y<0||x>=R||y>=C;
}
inline int num(int x,int y){ return x*C+y; }
void bfs(int sx,int sy){
	for (int i=0;i<R;i++){
		for (int j=0;j<C;j++) dist[num(i,j)]=inf;
	}
	dist[num(sx,sy)]=0;
	q.push(num(sx,sy));
	while (!q.empty()){
		int unm=q.front(); q.pop();
		dot u=(dot){unm/C,unm%C};
//		cout<<u.x<<" "<<u.y<<endl;
		for (int i=0;i<4;i++){
			int nx=u.x+dx[i]*A,ny=u.y+dy[i]*B;
			int nm=num(nx,ny);
			if (!ub(nx,ny)){
				if (dist[nm]==inf&&a[nm]){
					dist[nm]=dist[unm]+1;
					q.push(nm);
				}
			}
			if (B==A) continue;
			nx=u.x+dx[i]*B,ny=u.y+dy[i]*A;
			nm=num(nx,ny);
			if (!ub(nx,ny)){
				if (dist[nm]==inf&&a[nm]){
					dist[nm]=dist[unm]+1;
					q.push(nm);
				}
			}
		}
	}
}
int main(){
	freopen("willow.in","r",stdin);
	freopen("willow.out","w",stdout);
	scanf("%d%d%d%d%d",&R,&C,&n,&A,&B);
	for (int i=0;i<R;i++){
		for (int j=0;j<C;j++){
			char c=getchar(); while (c!='.'&&c!='*') c=getchar();
			a[num(i,j)]=(c=='.');
		}
	}
	for (int i=1;i<=n;i++) scanf("%d%d",&st[i].x,&st[i].y),st[i].x--,st[i].y--;
	for (int i=1;i<=n;i++) scanf("%d%d",&ed[i].x,&ed[i].y),ed[i].x--,ed[i].y--;
	S=2*n+1; T=S+1;
	for (int i=1;i<=n;i++){
//		cout<<"in"<<endl;
//		cout<<st[i].x<<" "<<st[i].y<<endl;
		bfs(st[i].x,st[i].y);
		ins(S,i,1,0);
		for (int j=1;j<=n;j++){
			if (dist[num(ed[j].x,ed[j].y)]<inf) 
				ins(i,n+j,1,dist[num(ed[j].x,ed[j].y)]);
		}
		ins(n+i,T,1,0);
	}
	while (dij()){
		for (int i=1;i<=T;i++) h[i]+=d[i];
		aug();
	}
//	cout<<flow<<" "<<cost<<endl;
	if (cost>=inf||flow<n) printf("-1\n");
	else printf("%d\n",cost);
	fclose(stdin); fclose(stdout);
	return 0;
}
