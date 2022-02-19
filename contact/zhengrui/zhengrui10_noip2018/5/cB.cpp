#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
const int MAXM=2e5+5;
int edge,head[MAXN],tail[MAXM],nex[MAXM];
int n,m,a[MAXN];
bool use[MAXN];
int ans,d[MAXN],fa[MAXN];
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void dfs(int u,int p){
	d[u]=d[p]+1; fa[u]=p;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		dfs(v,u);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	for (int i=1;i<=m;i++) scanf("%d",&a[i]);
	dfs(1,0); use[1]=1;
	for (int i=1;i<=m;i++){
		int u=a[i];
		while (!use[u]) use[u]=1,u=fa[u],ans+=2;
//		cout<<u<<" "<<ans<<" "<<d[a[i]]<<endl;
		printf("%d\n",ans-d[a[i]]+1);
	}
	return 0;
}
