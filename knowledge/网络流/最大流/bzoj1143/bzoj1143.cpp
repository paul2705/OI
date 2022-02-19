#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=2e2+5;
const int MAXM=2e5+5;
const int inf=1e9;
int a[MAXN][MAXN];
int n,m,S,T;
int edge=1,head[MAXN],nex[MAXM],tail[MAXM],r[MAXM];
int d[MAXN],cur[MAXN];
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
			if (d[v]==inf&&r[e]>0){
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
			int res=dfs(v,min(b,r[e]));
			r[e]-=res; r[e^1]+=res;
			b-=res; ans+=res;
		}
		if (!b) break;
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++) a[i][j]=1e9;
	}
	for (int i=1;i<=m;i++){
		int u,v; scanf("%d%d",&u,&v);
		a[u][v]=1;
	}
	for (int k=1;k<=n;k++){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				if (a[i][j]>a[i][k]+a[k][j]){
					a[i][j]=a[i][k]+a[k][j];
				}
			}
		}
	}
	S=2*n+2;T=S+1;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (a[i][j]<inf&&i!=j) ins(2*i+1,2*j,1);
		}
		ins(S,2*i+1,1); ins(2*i,T,1);
//		ins(2*i,2*i+1,1);
	}
	int flow=0;
	while (bfs()){
		for (int i=1;i<=T;i++) cur[i]=head[i];
		flow+=dfs(S,inf);
	}
	printf("%d\n",n-flow);
	return 0;
}
