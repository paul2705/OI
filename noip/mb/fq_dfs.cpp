#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e3+5;
const int MAXM=6e3+5;
int edge,head[MAXN],nex[MAXM],tail[MAXM],w[MAXM];
int n,m,dist[MAXN];
bool use[MAXN],fl=0;
void add(int u,int v,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
void spfa(int u){
	if (fl) return;
	use[u]=1;
//	cout<<u<<" "<<dist[u]<<endl;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (dist[v]>dist[u]+w[e]){
			dist[v]=dist[u]+w[e];
			if (use[v]) fl=1;
//			cout<<": "<<fl<<" "<<v<<" "<<u<<endl;
			spfa(v);
		}
	}
	use[u]=0;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--){
		fl=0;
		edge=0;
		memset(head,0,sizeof(head));
		scanf("%d%d",&n,&m);
		for (int i=1;i<=m;i++){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			add(u,v,w);
			if (w>=0) add(v,u,w);
		}
		memset(dist,63,sizeof(dist));
		memset(use,0,sizeof(use));
		dist[1]=0;
		spfa(1);
		if (fl) printf("YE5\n");
		else printf("N0\n");
	}
	return 0;
}
