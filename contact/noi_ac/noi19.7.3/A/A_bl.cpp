#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=3e5+5;
const int MAXM=6e5+5;
int edge,head[MAXN],tail[MAXM],nex[MAXM];
int a[MAXN],d[MAXN];
int n,ans;
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void dfs(int u,int p){
	d[u]=max(d[p],a[p]);
	if (a[u]>d[u]) ans+=u;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		dfs(v,u);
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<n;i++){
		int u,v; scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++) d[j]=0;
		ans=0;
		dfs(i,0);
		printf("i:%d ",i);
		for (int j=1;j<=n;j++) printf("%d ",d[j]);
		printf("ans:%d\n",ans);
	}
	printf("\n");
	return 0;
}
