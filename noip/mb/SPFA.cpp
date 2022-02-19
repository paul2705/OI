#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=1e5+5;
const int MAXM=2e5+5;
int edge,head[MAXN],nex[MAXM],tail[MAXM],w[MAXM];
int n,m,s,dist[MAXN];
queue<int> q;
bool use[MAXN];
void add(int u,int v,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
int main(){
	scanf("%d%d%d",&n,&m,&s);
	for (int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		if (u==v) continue;
		add(u,v,w);
	}
	for (int i=1;i<=n;i++) dist[i]=2147483647;
	dist[s]=0;
	q.push(s); use[s]=1;
	while (!q.empty()){
		int u=q.front(); q.pop(); use[u]=0;
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			if (dist[v]>dist[u]+w[e]){
				dist[v]=dist[u]+w[e];
				if (!use[v]) q.push(v),use[v]=1;
			}
		}
	}
	for (int i=1;i<=n;i++) printf("%d ",dist[i]);
	return 0;
}
