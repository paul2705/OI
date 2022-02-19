#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=1e5+5;
const int MAXM=5e5+5;
int edge,head[MAXN],nex[MAXM],tail[MAXM],w[3][MAXM];
int n,m,dist[MAXN],ans,cnt;
bool use[MAXN];
void add(int u,int v,int p,int q);
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[1][edge]=p,w[2][edge]=q;
}
void dij(int id){
	memset(use,0,sizeof(use)); memset(dist,63,sizeof(dist));
	queue<int> q;
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1,u,v,p,q;i<=m;i++){
		scanf("%d%d%d%d",&u,&v,&p,&q);
		add(u,v,p,q);
	}
	dij(1); dij(2);
	printf("%d\n",ans-cnt);
	return 0;
}
