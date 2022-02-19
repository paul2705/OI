#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int edge,head[60],tail[1005],nex[1005],w[1005];
int n,m,T,x;
bool flag=1;
void adD(int u,int v,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
bool f=1,ff;
bool dfs(int u){
	if (!f) return ff; 
	use[u]=1;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (!use[v]) x^=w[e],dfs(v);
		else f=0,ff=x;
	}
}
int main(){
	scanf("%d",&T);
	while (T--){
		edge=0,memset(head,0,sizeof(head));
		scanf("%d%d",&n,&m);
		for (int i=0,u,v,w;i<m;i++){
			scanf("%d%d%d",&u,&v,&w);
			add(u,v,w); add(v,u,w);
		}
		for (int i=1;i<=n;i++){
			memset(use,0,sizeof(use));
			x=0;
			flag=flag&&dfs(i);
		}
		if (flag) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
