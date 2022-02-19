#pragma GCC optimize(2)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=1e5+5;
const int MAXM=3e6+6;
const int inf=1e9;
int edge=1,head[MAXN],tail[MAXM],nex[MAXM],w[MAXM],r[MAXM];
int d[MAXN],h[MAXN],preu[MAXN],pree[MAXN];
bool use[MAXN];
int n,m,S,T,tot;
int p[45],a[45][105],pos[105];
struct rq{
	int u,d;
	bool operator < (const rq& b) const {
		return d>b.d;
	}
};
//priority_queue<rq> q;
queue<int> q;
void add(int u,int v,int R,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W,r[edge]=R;
}
void ins(int u,int v,int R,int W){
	add(u,v,R,W); add(v,u,0,-W);
}
/*bool dij(){
	for (int i=1;i<=T;i++) d[i]=inf,use[i]=0;
	for (int i=1;i<=T;i++) preu[i]=pree[i]=0;
	d[S]=0; q.push((rq){S,0});
	while (!q.empty()){
		rq u=q.top(); q.pop();
//		cout<<u.u<<endl;
		if (use[u.u]) continue;
		use[u.u]=1;
		for (int e=head[u.u];e;e=nex[e]){
			int v=tail[e];
			int W=h[u.u]+w[e]-h[v];
			if (d[v]>d[u.u]+W&&r[e]>0){
				d[v]=d[u.u]+W;
				preu[v]=u.u; pree[v]=e;
				q.push((rq){v,d[v]});
			}
		}
	}
	cout<<"T: "<<d[T]<<endl;
	return d[T]<inf;
}*/
bool xpfa(){
	for (int i=1;i<=T;i++) d[i]=inf,use[i]=0;
	d[S]=0; q.push(S); use[S]=1;
	while (!q.empty()){
		int u=q.front(); q.pop();
		use[u]=0;
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			if (d[v]>d[u]+w[e]&&r[e]>0){
				d[v]=d[u]+w[e];
				preu[v]=u; pree[v]=e;
				if (!use[v]) q.push(v),use[v]=1;
			}
		}
	}
	return d[T]<inf;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&p[i]),tot+=p[i];
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) scanf("%d",&a[i][j]);
	}
	S=n+m*tot+1; T=S+1;
	for (int i=1;i<=n;i++) ins(S,i,p[i],0);
	for (int i=n+1;i<=n+m*tot;i++) ins(i,T,1,0);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			ins(i,n+(j-1)*tot+tot,1,a[i][j]);
			pos[j]=tot;
		}
	}
	int cost=0,flow=0;
	while (xpfa()){
		int res=inf;
		for (int u=T;u!=S;u=preu[u]){
			int v=preu[u],e=pree[u];
			res=min(res,r[e]);
		}
		flow+=res; cost+=res*d[T];
		for (int u=T;u!=S;u=preu[u]){
			int v=preu[u],e=pree[u];
			r[e]-=res; r[e^1]+=res;
		}
		int tmp1=preu[T];
		tmp1=(tmp1-1-n)/tot+1;
		int tmp3=pos[tmp1];
//		cout<<tmp1<<" "<<tmp3<<" "<<res<<" "<<cost<<endl;
		if (tmp3==1) continue;
//		cout<<"add: ";
		for (int i=1;i<=n;i++){
			ins(i,n+(tmp1-1)*tot+tmp3-1,1,a[i][tmp1]*(tot-(tmp3-1)+1));
//			cout<<n+(tmp1-1)*tot+tmp3-1<<" ";
		}
//		cout<<endl;
		pos[tmp1]--;
	}
	printf("%d\n",cost);
	return 0;
}
