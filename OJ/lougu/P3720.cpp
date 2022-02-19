#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int INF=1e6;
const int MAXN=1e5+5;
int edge=1,head[MAXN],nex[MAXN],tail[MAXN],w[3][MAXN];
int n,m,pre[3][MAXN];
int dist[MAXN];
bool use[MAXN];
void add(int u,int v,int W1,int W2){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[1][edge]=W1,w[2][edge]=W2;
}
void dij(int id){
	queue<int> q; q.push(1); memset(use,0,sizeof(use));
	memset(dist,63,sizeof(dist));
	use[1]=1; dist[1]=0;
	while (!q.empty()){
		int u=q.front(); q.pop(); use[u]=0;
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			if (dist[v]>dist[u]+w[id][e]){
				dist[v]=dist[u]+w[id][e]; pre[id][v]=e;
				if (!use[v]) q.push(v),use[v]=1;
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=0,u,v,p,q;i<m;i++){
		scanf("%d%d%d%d",&u,&v,&p,&q);
		add(u,v,p,q);
	}
	dij(1); dij(2);
	cout<<"done"<<endl;
	for (int e=2;e<=edge;e++) w[1][e]=2;
	for (int v=n;v!=1;){
		cout<<v<<endl;
		int e=pre[1][v]; w[1][e]--;
		v=tail[e^1];
	}
	for (int v=n;v!=1;){
		int e=pre[2][v]; w[1][e]--;
		v=tail[e^1];
	}
	dij(1);
	printf("%d\n",dist[n]);
	return 0;
} 
