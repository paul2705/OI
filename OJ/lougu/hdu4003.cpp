#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1e4+5;
const int INF=1e9;
int edge,head[MAXN],tail[MAXN*2],nex[MAXN*2],w[MAXN*2];
int f[MAXN][12];
bool vis[MAXN];
int n,m,k,sum;
void add(int u,int v,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
void dfs(int u){
	vis[u]=1;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (vis[v]) continue;
		dfs(v);
		for (int i=k;i>=1;i--){
			for (int j=1;j<=i;j++){
				f[u][i]=max(f[u][i],f[u][i-j]+f[v][j]+(2-j)*w[e]);
			}
		}
	}
}
int main(){
	while (~scanf("%d%d%d",&n,&m,&k)){
		memset(head,0,sizeof(head)); sum=edge=0;
		for (int i=1,u,v,w;i<n;i++){
			scanf("%d%d%d",&u,&v,&w);
			sum+=w;
			add(u,v,w); add(v,u,w);
		}
		memset(f,0,sizeof(f)); memset(vis,0,sizeof(vis));
		dfs(m);
		printf("%d\n",sum*2-f[m][k]);
	}
	return 0;
}
	
