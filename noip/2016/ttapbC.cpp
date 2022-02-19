#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=1e5+5;
const int MAXM=MAXN*2;
int edge,head[MAXN],nex[MAXM],tail[MAXM];
int d[MAXN],fa[MAXN][30];
vector<int> out[MAXN],uout[MAXN];
int n,m,w[MAXN],uenter[MAXN],enter[MAXN],cnt[MAXN],ans[MAXN];
struct rec{
	int s,t,lca;
} a[MAXN];
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void dfs(int u,int p){
	fa[u][0]=p;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		dfs(v,u);
	}
}
void ddfs(int u,int p){
	int now=d[u]+w[u],pre=0; 
	if (now<=mx) pre=cnt[now];
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		ddfs(v,u);
	}
	cnt[d[s]]+=enter[s];
	if (now<=mx) ans=cnt[now]-pre;
	for (int i=0;i<out[u].size();i++){
		int t=out[u][i];
		cnt[d[t]]--;
	}
}
void udfs(int u,int p){
	int now=d[t]-w[t]+n,pre=cnt[now]; 
	for (e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		udfs(v,u);
	}
	for (int i=0;i<uenter[u].size();i++){
		int s=uenter[u][i];
		cnt[s+n]++;
	}
	ans[u]+=cnt[now]-cnt;
	for (int i=0;i<uout[u].size();i++){
		int t=uout[u][i];
		cnt[d[t]+n]--;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	dfs(1,0);
	for (int k=1;k<20;k++){
		for (int u=1;u<=n;u++){
			fa[u][k]=fa[fa[u][k-1]][k-1];
		}
	}
	for (int i=1;i<=n;i++) scanf("%d",&w[i]);
	for (int i=1;i<=m;i++){
		scanf("%d%d",&a[i].s,&a[i].t);
		a[u].lca=lca(a[i].s,a[i].t);
		enter[a[i].s]++;
		out[f].push_back(a[i].s);
	}
	ddfs(1,0);
	for (int i=0;i<=n;i++) cnt[i]=0;
	for (int i=1;i<=m;i++){
		int dis=d[a[i].t]+d[a[i].s]-2*d[a[i].lca];
		uenter[a[i].t].push_back(d[a[i].t]-dis);
		uout[a[i].lca].push_back(d[a[i].lca]-dis);
	}
	udfs(1,0);
	for (int i=1;i<=m;i++){
		if (d[a[i].t]-d[a[i].lca]==w[a[i].lca]) ans[a[i].lca]--;
	}
	for (int i=1;i<=n;i++) printf("%d ",ans[i]);
	cout<<endl;
	return 0;
}
