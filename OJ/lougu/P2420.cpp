#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1e5*2+5;
int edge,head[MAXN],tail[MAXN],nex[MAXN],w[MAXN];
int d[MAXN],len[MAXN];
int n,m;
void add(int u,int v,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
void dfs(int u,int p){
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v!=p){
			len[v]=len[u]^w[e];
			dfs(v,u);
		}
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1,u,v,w;i<n;i++){
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w); add(v,u,w);
	}
	d[1]=1; dfs(1,0);
	scanf("%d",&m);
	for (int i=0,u,v;i<m;i++){
		scanf("%d%d",&u,&v);
		printf("%d\n",len[u]^len[v]);
	}
	return 0;
}
