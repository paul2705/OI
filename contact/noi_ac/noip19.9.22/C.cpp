#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int MAXN=1e3+5;
const int MAXM=2e3+5;
int edge,head[MAXN],nex[MAXM],tail[MAXM];
ll w[MAXM];
ll dis[5][MAXN];
bool use[MAXN];
queue<int> q;
int n,T;
void add(int u,int v,ll W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
void bfs(int id,int S){
//	cout<<__func__<<" "<<id<<" "<<S<<endl;
	for (int i=1;i<=n;i++) use[i]=0;
	while (!q.empty()) q.pop();
	q.push(S); dis[id][S]=0; use[S]=1;
	while (!q.empty()){
		int u=q.front(); q.pop();
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			if (use[v]) continue;
			dis[id][v]=dis[id][u]+w[e];
			use[v]=1;
//			cout<<id<<" "<<v<<" "<<dis[id][v]<<endl;
			q.push(v);
		}
	}
}
int main(){
	scanf("%d%d",&n,&T);
	for (int i=1;i<n;i++){
		int u,v,w; scanf("%d%d%d",&u,&v,&w);
		add(u,v,w); add(v,u,w);
	}
	while (T--){
		int x,y; scanf("%d%d",&x,&y);
		for (int i=1;i<=n;i++) dis[1][i]=dis[2][i]=0;
		bfs(1,x); bfs(2,y);
		ll ans=0;
		for (int i=1;i<=n;i++) ans=max(ans,min(dis[1][i],dis[2][i]));
		printf("%lld\n",ans);
	}
	return 0;
}
