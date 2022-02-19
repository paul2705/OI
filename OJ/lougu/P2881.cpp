#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>
using namespace std;
const int MAXN=1e3+5;
const int MAXE=1e4+5;
int edge,head[MAXN],nex[MAXE],tail[MAXE];
int n,m;
bitset<1005> vis,mat[MAXN];
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void dfs(int u){
	mat[u][u]=vis[u]=1;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (!vis[v]) dfs(v);
		mat[u]|=mat[v];
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=0,u,v;i<m;i++){
		scanf("%d%d",&u,&v);
		add(u,v);
	}
	for (int i=1;i<=n;i++){
		if (!vis[i]) dfs(i);
	}
	int ans=0;
	for (int i=1;i<=n;i++) ans+=mat[i].count();
	printf("%d\n",(n*(n-1))/2-ans+n);
	return 0;
}
