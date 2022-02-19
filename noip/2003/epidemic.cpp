#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=305;
const int MAXM=MAXN*2;
int edge,head[MAXN],nex[MAXM],tail[MAXM];
int ans,fa[MAXN],cnt[MAXN];
int n,m,d[MAXN],sz[MAXN];
bool use[MAXN];
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
int dfs(int u,int p){
	d[u]=d[p]+1; sz[u]=1;
	fa[u]=p;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (p==v) continue;
		sz[u]+=dfs(v,u);
	}
	return sz[u];
}
void col(int u,int p,bool id){
	use[u]=id;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		col(v,u,id);
	}
}
void work(int dep,int ret){
//	cout<<dep<<" "<<ret<<endl;
	ans=min(ans,ret); cnt[dep]=min(cnt[dep],ret);
	if (ret>cnt[dep]) return;
	for (int i=1;i<=n;i++){
		if (d[i]==dep&&!use[i]){
			col(i,fa[i],1);
			work(dep+1,ret-sz[i]);
			col(i,fa[i],0);
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	for (int i=1;i<=n;i++) cnt[i]=1e9;
	dfs(1,0);
	ans=1e9;
	work(2,n);
	printf("%d\n",ans);
	return 0;
}
