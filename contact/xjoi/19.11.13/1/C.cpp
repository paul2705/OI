#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
const int MAXM=MAXN*2;
int edge,head[MAXN],tail[MAXM],nex[MAXM];
long double w[MAXM],d[MAXN],f[MAXN],g[MAXN],sz[MAXN];
int n,m;
long double ans;
double c[MAXN];
void add(int u,int v,double W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
void dfs(int u,int p){
	sz[u]=c[u];
//	g[u]=d[u]*c[u]; f[u]=d[u]*d[u]*c[u];
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		d[v]=d[u]+w[e];
		dfs(v,u);
		g[u]+=g[v]+w[e]*sz[v];
		f[u]+=f[v]+(double)2.0*w[e]*g[v]+sz[v]*w[e]*w[e];
		sz[u]+=sz[v];
	}
}
void solve(int u,int p){
	ans=min(ans,f[u]);
//	printf("%d %.6lf %.6lf %.6lf\n",u,f[u],g[u],sz[u]);
//	cout<<u<<" "<<f[u]<<endl;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		double gu=g[u],fu=f[u],su=sz[u];
		double gv=g[v],fv=f[v],sv=sz[v];
		g[u]-=g[v]+w[e]*sz[v];
		sz[u]-=sz[v];
		f[u]-=f[v]+(double)2.0*w[e]*g[v]+sz[v]*w[e]*w[e];
		f[v]+=f[u]+(double)2.0*w[e]*g[u]+sz[u]*w[e]*w[e];
		g[v]+=g[u]+w[e]*sz[u];
		sz[v]+=sz[u];
		solve(v,u);
		g[u]=gu; g[v]=gv;
		f[u]=fu; f[v]=fv;
		sz[u]=su; sz[v]=sv;
	}
}
int main(){
	freopen("problem3.in","r",stdin);
	freopen("problem3.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lf",&c[i]);
	for (int i=1;i<n;i++){
		int u,v; double w; scanf("%d%d%lf",&u,&v,&w);
		add(u,v,w); add(v,u,w);
	}
	ans=1e25;
//	cout<<ans<<endl;
	dfs(1,0);
	solve(1,0);
	printf("%.6lf\n",(double)ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
