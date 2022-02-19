#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
const int MAXM=1e6+6;
int edge,head[MAXN],nex[MAXM],tail[MAXM];
int dfn[MAXN],low[MAXN];
int n,m,cnt;
int sz[MAXN];
ll ans[MAXN];
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void tarjan(int u){
	sz[u]=1; dfn[u]=low[u]=++cnt;
	int t=0;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (!dfn[v]){
			tarjan(v);
			sz[u]+=sz[v];
			low[u]=min(low[u],low[v]);
			if (dfn[u]<=low[v]){
				ans[u]+=(ll)t*sz[v];
				t+=sz[v];
			}
		}
		else low[u]=min(low[u],dfn[v]);
	}
	/*if (low[u]==dfn[u])*/ ans[u]+=(ll)t*(n-t-1);
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int u,v; scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	tarjan(1);
	for (int i=1;i<=n;i++) printf("%lld\n",(ans[i]+n-1)*2);
	return 0;
}
