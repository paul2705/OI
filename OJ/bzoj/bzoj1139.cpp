#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int inf=1e8;
const int MAXN=205;
const int MAXM=6005;
const int MAXS=1<<13;
int f[MAXN][MAXS],use[MAXN][MAXS];
int gt[MAXN],emy[MAXM];
int edge,head[MAXN],tail[MAXM],nex[MAXM],w[MAXM];
int n,m,p,k;
struct rq{
	int u,st,dist;
	bool operator < (const rq& b) const{
		return dist>b.dist;
	}
} pre[MAXN][MAXS];
priority_queue<rq> q;
void add(int u,int v,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&p,&k);
	for (int i=1;i<=k;i++){
		int u,cnt; scanf("%d%d",&u,&cnt);
		for (int j=1;j<=cnt;j++){
			int x; scanf("%d",&x); x--;
			gt[u]|=(1<<x);
		}
	}
	for (int i=1;i<=m;i++){
		int u,v,w,cnt; scanf("%d%d%d%d",&u,&v,&w,&cnt);
		add(u,v,w); add(v,u,w);
		for (int j=1;j<=cnt;j++){
			int x; scanf("%d",&x); x--;
			emy[edge]|=(1<<x);
		}
		emy[edge-1]=emy[edge];
	}
//	cout<<"done"<<endl;
	for (int i=1;i<=n;i++){
		for (int s=0;s<(1<<p);s++) f[i][s]=inf;
	}
	f[1][gt[1]]=0; q.push((rq){1,gt[1],0});
	while (!q.empty()){
		rq u=q.top(); q.pop();
		if (use[u.u][u.st]) continue;
		use[u.u][u.st]=1;
		for (int e=head[u.u];e;e=nex[e]){
			int v=tail[e];
			int nst=u.st|gt[v];
			if ((u.st&emy[e])==emy[e]){
				if (f[v][nst]>f[u.u][u.st]+w[e]){
					f[v][nst]=f[u.u][u.st]+w[e];
					pre[v][nst]=(rq){u.u,u.st,0};
					q.push((rq){v,nst,f[v][nst]});
				}
			}
		}
	}
	int ans=0;
	bool flag=0;
	for (int s=0;s<(1<<p);s++){
		if (f[n][s]>=inf) continue;
		flag|=1;
		if (f[n][ans]>f[n][s]) ans=s;
//		cout<<f[n][s]<<endl;
//		ans=min(ans,f[n][s]);
	}
//	printf("%d\n",ans);
	if (flag) printf("%d\n",f[n][ans]);
	else printf("-1\n");
//	for (int u=n;u!=1||ans!=gt[1];){
//		printf("%d %d\n",u,ans);
//		rq tmp=pre[u][ans];
//		ans=tmp.st; u=tmp.u;
//	}
	return 0;
}
