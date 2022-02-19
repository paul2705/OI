#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int MAXN=1e6+6;
int edge[3],head[3][MAXN],tail[3][MAXN],nex[3][MAXN];
int dist[MAXN];
bool use[MAXN];
int n,m;
ll ans,w[3][MAXN];
void add(int id,int u,int v,ll W){
	edge[id]++,nex[id][edge[id]]=head[id][u],head[id][u]=edge[id],tail[id][edge[id]]=v,w[id][edge[id]]=W;
}
void XPFA(int id){
	memset(use,0,sizeof(use)); memset(dist,63,sizeof(dist));
	queue<int> q;
	q.push(1); dist[1]=0; use[1]=1;
	while (!q.empty()){
		int u=q.front(); q.pop(); use[u]=0;
		for (int e=head[id][u];e;e=nex[id][e]){
			int v=tail[id][e];
			if (dist[v]>dist[u]+w[id][e]){
				dist[v]=dist[u]+w[id][e];
				if (!use[v]) use[v]=1,q.push(v);
			}
		}
	}
	for (int i=1;i<=n;i++) ans+=dist[i];
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++){
		int u,v; ll w;
		scanf("%d%d%lld",&u,&v,&w);
		add(1,u,v,w); add(2,v,u,w);
	}
	XPFA(1); XPFA(2);
	printf("%lld\n",ans);
	return 0;
}
