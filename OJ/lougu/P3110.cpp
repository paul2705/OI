#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int MAXN=4e4+5;
const int MAXE=8e4+5;
int n,m,p,b,e;
int edge,head[MAXN],tail[MAXE],nex[MAXE];
int dist[5][MAXN],ans=1e9,use[MAXN];
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void bfs(int id,int s){
	queue<int> q; q.push(s);
	memset(dist[id],63,sizeof(dist[id]));
	memset(use,0,sizeof(use));
	dist[id][s]=0; use[s]=1;
	while (!q.empty()){
		int u=q.front(); q.pop();
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			if (!use[v]) dist[id][v]=dist[id][u]+1,q.push(v),use[v]=1;
		}
	}
}
int main(){
	scanf("%d%d%d%d%d",&b,&e,&p,&n,&m);
	for (int i=0,u,v;i<m;i++){
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	bfs(1,1); bfs(2,2); bfs(3,n);
	for (int i=1;i<=n;i++)
		ans=min(ans,dist[1][i]*b+dist[2][i]*e+dist[3][i]*p);
	printf("%d\n",ans);
	return 0;
}
