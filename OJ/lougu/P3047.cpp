#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
const int MAXM=2e5+5;
int edge,head[MAXN],nex[MAXM],tail[MAXM];
int n,k,f[MAXN][25];
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void dfs1(int u,int p){
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v!=p){
			dfs1(v,u);
			for (int j=1;j<=k;j++) f[u][j]+=f[v][j-1];
		}
	}
}
void dfs2(int u,int p){
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v!=p){
			for (int j=k;j>=1;j--) f[v][j]+=f[u][j-1]-f[v][j-2];
			dfs2(v,u);
		}
	}
}
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	for (int i=1;i<=n;i++) scanf("%d",&f[i][0]);
	dfs1(1,0); dfs2(1,0);
	for (int i=1;i<=n;i++) for (int j=1;j<=k;j++) f[i][j]+=f[i][j-1];
	for (int i=1;i<=n;i++) printf("%d\n",f[i][k]);
	return 0;
}
