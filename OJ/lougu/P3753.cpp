#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=1e3+5;
const int MAXE=2e3+5;
int edge,head[MAXN],nex[MAXE],tail[MAXE],w[MAXE],t[MAXE];
int n,m,dist[MAXN],use[MAXN],cnt[MAXN][3];
void add(int u,int v,int T){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,t[edge]=T;
	cnt[v][T]++;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=0,u,v,t;i<m;i++){
		scanf("%d%d%d",&u,&v,&t);
		add(u,v,t);
	}
	for (int e=1;e<=edge;e++){
		int v=tail[e];
		if (t[e]==1) w[e]=cnt[v][1]-1;
		else w[e]=cnt[v][1]+1;
		cout<<tail[e]<<" "<<t[e]<<" "<<w[e]<<endl;
	}
	queue<int> q; q.push(1); use[1]=1;
	memset(dist,63,sizeof(dist)); dist[1]=0;
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
	printf("%d\n",dist[n]);
	return 0;
}
