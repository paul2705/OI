#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=1e4+5;
const int MAXM=3e4+5;
int edge,head[MAXN],tail[MAXM],nex[MAXM],w[MAXM];
int n,s,t;
int dist[MAXN];
bool use[MAXN];
void add(int u,int v,int W){
	if (u<0||v<0) return;
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
queue<int> q;
void xpfa(){
	memset(dist,63,sizeof(dist));
	dist[s]=0; use[s]=1; q.push(s);
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
}
int main(){
	scanf("%d%d%d",&n,&s,&t);
	for (int i=1,u,v,w;i<=n;i++){
		scanf("%d%d%d",&u,&v,&w);
		add(u,v+1,w);
	}
	for (int i=s;i<=t+1;i++) add(i,i-1,0);
	xpfa();
	printf("%d\n",dist[t+1]==1061109567?-1:dist[t+1]);
	return 0;
}
