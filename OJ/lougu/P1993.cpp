#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e4+5;
const int MAXE=2e6+6;
int edge,head[MAXN],nex[MAXE],tail[MAXE],w[MAXE];
bool use[MAXN],flag=1;
int n,m,dist[MAXN];
void add(int u,int v,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
void dfs(int u){
	use[u]=1;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (dist[v]>dist[u]+w[e]){
			if (use[v]) return flag=0,void();
			dist[v]=dist[u]+w[e];
			dfs(v);
		}
	}
	use[u]=0;
}
int main(){
	memset(dist,63,sizeof(dist));
	scanf("%d%d",&n,&m);
	for (int i=1,op,u,v,c;i<=m;i++){
		scanf("%d",&op);
		if (op==1){
			scanf("%d%d%d",&u,&v,&c);
			add(u,v,-c);
		}
		else if (op==2){
			scanf("%d%d%d",&u,&v,&c);
			add(v,u,c);
		}
		else{
			scanf("%d%d",&u,&v);
			add(u,v,0); add(v,u,0);
		}
	}
	for (int i=1;i<=n;i++){
		if (!use[i]&&flag){
			dist[i]=0;
			dfs(i);
		}
	}
	if (flag) printf("Yes\n");
	else printf("No\n");
	return 0;
}
