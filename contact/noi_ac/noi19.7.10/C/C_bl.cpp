#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
const int MAXM=4e5+5;
int edge=1,head[MAXN],tail[MAXM],nex[MAXM];
int d[MAXN],d1[MAXN],up[MAXN],n,m,q;
bool vis[MAXN],use[MAXM];
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void dfs1(int u,int p){
	d1[u]=d1[p]+1;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		up[v]=e;
		dfs1(v,u);
	}
}
void dfs(int u,int p){
	d[u]=d[p]+1; vis[u]=1;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		if (use[e]) continue;
		dfs(v,u);
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<n;i++){
		int u,v; scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	d1[0]=-1;
	dfs1(1,0);
	for (int i=1;i<=q;i++){
		int l,r,v; scanf("%d%d%d",&l,&r,&v);
		use[up[v]]=use[up[v]^1]=1;
	}
	ll ans=0;
	for (int i=1;i<=n;i++){
		ans+=(ll)d1[i];
//		cout<<i<<" "<<d1[i]<<endl;
	}
	ll ans1=0;
	for (int i=1;i<=n;i++){
		if (!vis[i]){
			if (i==1) d[0]=-1;
			else d[0]=0;
			dfs(i,0);
		}
//		cout<<i<<" "<<d[i]<<endl;
		ans1+=(ll)d[i];
	}
	printf("%lld ",ans1);
	for (int i=2;i<=m;i++) printf("%lld ",ans);
	printf("\n");
	return 0;
}
