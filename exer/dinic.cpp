#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int MAXN=1e3+5;
const int MAXE=1e5+5;
const int INF=1e9*2;
#define s 0
#define t n 
int edge=1,head[MAXN],nex[MAXE],tail[MAXE],r[MAXE];
int d[MAXN],cur[MAXN];
int n,m,ans=0;
void ins(int u,int v,int C){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,r[edge]=C;
}
void add(int u,int v,int C){
	ins(u,v,C); ins(v,u,0);
}
bool bfs(){
	queue<int> q;
	for (int i=0;i<=n;i++) d[i]=0;
	q.push(t); d[t]=1;
	while (!q.empty()){
		int v=q.front(); q.pop();
		for (int e=head[v];e;e=nex[e]){
			int u=tail[e];
			if (d[u]==0&&r[e^1]>0){
				d[u]=d[v]+1;
				q.push(u);
			}
		}
	}
	return d[s]>0;
}
int dfs(int u,int b){
	if (u==t) return b;
	int ans=0;
	for (int &e=cur[u];e;e=nex[e]){
		int v=tail[e];
		if (d[v]+1==d[u]&&r[e]>0){
			int res=dfs(v,min(r[e],b));
			ans+=res; b-=res; 
			r[e]-=res; r[e^1]+=res;
		}
		if (b==0) break;
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=0,u,v,c;i<m;i++){
		scanf("%d%d%d",&u,&v,&c);
		add(u,v,c); add(s,u,INF); add(v,t,INF);
	}
	while (bfs()){
		for (int i=0;i<=n;i++) cur[i]=head[i];
		ans+=dfs(s,INF);
	}
	printf("%d\n",ans);
	return 0;
}
