#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1e5+5;
int edge,head[MAXN],tail[MAXN],nex[MAXN];
int n,m,ans[MAXN];
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void dfs(int u,int root){
	ans[u]=root;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (ans[v]>root) continue;
		dfs(v,root);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		add(v,u);
	}
	for (int i=n;i>=1;i--){
		if (ans[i]<i) dfs(i,i);
	}
	for (int i=1;i<=n;i++) printf("%d ",ans[i]);
	return 0;
}
