#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int inf=1e9;
const int MAXN=5e2+5;
const int MAXM=2e6+6;
int edge=1,head[MAXN],tail[MAXM],nex[MAXM],r[MAXM];
int d[MAXN],cur[MAXN];
int n,m,S,T;
queue<int> q;
void add(int u,int v,int R){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,r[edge]=R;
}
void ins(int u,int v,int R){
	add(u,v,R); add(v,u,0);
}
bool bfs(){
	for (int i=1;i<=T;i++) d[i]=inf;
	d[S]=0; q.push(S);
	while (!q.empty()){
		int u=q.front(); q.pop();
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			if (r[e]>0&&d[v]==inf){
				d[v]=d[u]+1;
				q.push(v);
			}
		}
	}
	return d[T]<inf;
}
int dfs(int u,int b){
	if (u==T) return b;
	int ans=0;
	for (int& e=cur[u];e;e=nex[e]){
		int v=tail[e];
		if (d[v]==d[u]+1&&r[e]>0){
			int res=dfs(v,min(r[e],b));
			r[e]-=res; r[e^1]+=res;
			ans+=res; b-=res;
		}
		if (!b) break;
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	int s,t;
	scanf("%d%d",&s,&t);
	S=2*n+2; T=S+1;
	ins(S,2*s,inf); ins(2*t+1,T,inf);
	for (int i=1;i<=n;i++){
		int x; scanf("%d",&x);
		ins(2*i,2*i+1,x);
	}
	for (int i=1;i<=m;i++){
		int u,v; scanf("%d%d",&u,&v);
		ins(2*u+1,2*v,inf);
		ins(2*v+1,2*u,inf);
	}
	int flow=0;
	while (bfs()){
		for (int i=1;i<=T;i++) cur[i]=head[i];
		flow+=dfs(S,inf);
	}
	printf("%d\n",flow);
	return 0;
}
