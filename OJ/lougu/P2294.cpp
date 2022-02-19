#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=1e2+5;
const int MAXM=2e3+5;
int edge,head[MAXN],tail[MAXM],nex[MAXM],w[MAXM];
int dis[MAXN],tot[MAXN];
bool use[MAXN],f;
int n,m,T,cnt;
void add(int u,int v,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
bool spfa(int s){
	for (int i=0;i<=n;i++) dis[i]=-1e9;
	queue<int> q; q.push(s); dis[s]=0; use[s]=1;
	while (!q.empty()){
		int u=q.front(); q.pop(); use[u]=0; tot[u]++;
		if (tot[u]==n) return 0;
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			if (dis[v]<dis[u]+w[e]){
				dis[v]=dis[u]+w[e];
				if (!use[v]) q.push(v),use[v]=1;
			}
		}
	}
	return 1;
}
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m);
		memset(use,0,sizeof(use)); memset(head,0,sizeof(head));
		memset(tot,0,sizeof(tot)); edge=0;
		for (int i=1,u,v,w;i<=m;i++){
			scanf("%d%d%d",&u,&v,&w);
			add(u-1,v,w); add(v,u-1,-w);
		}
		f=0;
		for (int i=0;i<=n;i++){
			if (!tot[i])
				if (!spfa(i)){ f=1; break; }
		}
		if (!f) printf("true\n");
		else printf("false\n");
	}
	return 0;
}
