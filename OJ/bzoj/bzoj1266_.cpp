#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int MAXN=1e3+5;
const int MAXE=1e5*2;
const int INF=1e9;
#define S 1
#define T n
int edge,nex[MAXE],head[MAXN],tail[MAXE],t[MAXE],c[MAXE];
int redge=1,rnex[MAXE],rhead[MAXN],rtail[MAXE];
int r[MAXE],cur[MAXN],d[MAXN],vis[MAXN],dis[2][MAXN];
int n,m;
void add(int u,int v,int T,int C){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,t[edge]=T,c[edge]=C;
}
void ins(int u,int v,int C){
	redge++,rnex[redge]=rhead[u],rhead[u]=redge,rtail[redge]=v,r[redge]=C;
}
void dij(int id,int s){
	queue<int> q;
	for (int i=1;i<=n;i++) vis[i]=0,dis[id][i]=INF;
	q.push(s); vis[s]=1; dis[id][s]=0;
	while (!q.empty()){
		int u=q.front(); q.pop(); vis[u]=0;
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			if (dis[id][v]>dis[id][u]+t[e]){
				dis[id][v]=dis[id][u]+t[e];
				vis[v]=1,q.push(v);
			}
		}
	}
}
void make_G(){
	for (int u=1;u<=n;u++){
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			if (dis[0][u]+t[e]+dis[1][v]==dis[0][n]){
				ins(u,v,c[e]); ins(v,u,0);
			}
		}
	}
}
bool bfs(){
	queue<int> q;
	for (int i=1;i<=n;i++) d[i]=0;
	q.push(S); d[S]=1;
	while (!q.empty()){
		int u=q.front(); q.pop();
		for (int e=rhead[u];e;e=rnex[e]){
			int v=rtail[e];
			if (d[v]==0&&r[e]>0){
				d[v]=d[u]+1;
				q.push(v);
			}
		}
	}
//	cout<<d[T]<<endl;
	return d[T]>0;
}
int dfs(int u,int b){
	if (u==T) return b;
	int ans=0;
	for (int &e=cur[u];e;e=rnex[e]){
		int v=rtail[e];
		if (d[u]+1==d[v]&&r[e]>0){
			int res=dfs(v,min(r[e],b));
			ans+=res;
			b-=res;
			r[e]-=res;
			r[e^1]+=res;
		}
		if (b==0) break;
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=0,u,v,t,c;i<m;i++){
		scanf("%d%d%d%d",&u,&v,&t,&c);
		add(u,v,t,c); add(v,u,t,c);
	}
	dij(0,1); dij(1,n);
	printf("%d\n",dis[0][n]);
	make_G();
	int ans=0;
	while (bfs()){
//		cout<<ans<<endl;
		for (int i=1;i<=n;i++) cur[i]=rhead[i];
		ans+=dfs(S,INF);
	}
	printf("%d\n",ans);
	return 0;
}
