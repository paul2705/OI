#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=3e5+5;
const int MAXM=2*MAXN;
const int logn=25;
ll fa[MAXN][logn],fu[MAXN][logn],fd[MAXN][logn];
int n,q,m;
int c[MAXN][logn],a[MAXN],d[MAXN];
int edge,head[MAXN],tail[MAXM],nex[MAXM];
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void dfs(int u,int p){
	fa[u][0]=p; d[u]=d[p]+1;
	for (int i=0;i<=m;i++){
		c[u][i]=c[p][i]+!(a[u]&(1<<i));
//		cout<<"dfs: "<<u<<" "<<p<<" "<<i<<" "<<!(a[u]&(1<<i))<<endl;
//		cout<<(a[u]&(1<<i))<<endl;
	}
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		dfs(v,u);
	}
}
int lca(int u,int v){
	if (d[u]<d[v]) swap(u,v);
	int dis=d[u]-d[v];
	for (int i=m;i>=0;i--){
		if (dis&(1<<i)) u=fa[u][i];
	}
	if (u==v) return u;
	for (int i=m;i>=0;i--){
		if (fa[u][i]!=fa[v][i]){
			u=fa[u][i],v=fa[v][i];
		}
	}
	return fa[u][0];
}
ll qry1(int u,int v){
	ll res=0;
	int dis=d[u]-d[v];
	for (int i=m;i>=0;i--){
		if (dis&(1<<i)){
			res+=fu[u][i];
			u=fa[u][i];
			res+=(1ll<<i)*(c[u][i]-c[v][i]);
		}
	}
	return res;
}
ll qry2(int u,int dis){
	ll res=0;
	int v=u;
	for (int i=0;i<=m;i++){
		if (dis&(1<<i)){
			res+=fd[v][i];
			res+=(1ll<<i)*(c[u][i]-c[v][i]);
			v=fa[v][i];
		}
	}
	return res;
}

int main(){
	scanf("%d%d",&n,&q);
	while ((1<<m)<n) m++;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),fu[i][0]=fd[i][0]=a[i];
	for (int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	dfs(1,0);
	for (int i=1;i<=m;i++){
		for (int u=1;u<=n;u++){
			fa[u][i]=fa[fa[u][i-1]][i-1];
			fu[u][i]=fu[u][i-1]+fu[fa[u][i-1]][i-1]+(1ll<<(i-1))*(c[fa[u][i-1]][i-1]-c[fa[u][i]][i-1]);
			fd[u][i]=fd[u][i-1]+fd[fa[u][i-1]][i-1]+(1ll<<(i-1))*(c[u][i-1]-c[fa[u][i-1]][i-1]);
		}
	}
	for (int i=0,u,v;i<q;i++){
		scanf("%d%d",&u,&v);
		int x=lca(u,v);
		printf("%lld\n",qry1(u,fa[x][0])+qry2(v,d[u]+d[v]-2*d[x]+1)-qry2(x,d[u]-d[x]+1));
	}
//	for (int i=0;i<=m;i++){
//		for (int u=1;u<=n;u++) cout<<i<<" "<<u<<" "<<c[u][i]<<endl;
//	}
	return 0;
}
