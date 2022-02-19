#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int inf=1e9;
const int dx[4]={0,0,-1,1},dy[4]={1,-1,0,0};
const int MAXI=1e2+5;
const int MAXN=1e4+5;
const int MAXM=1e5+6;
int edge=1,head[MAXN],tail[MAXM],nex[MAXM],r[MAXM];
int n,m,S,T,a[MAXI][MAXI];
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
	for (int &e=cur[u];e;e=nex[e]){
		int v=tail[e];
		if (d[v]==d[u]+1&&r[e]>0){
			int res=dfs(v,min(r[e],b));
			r[e]-=res; r[e^1]+=res;
			ans+=res; b-=res;
		}
		if (!b) return ans;
	}
	return ans;
}
bool ub(int x,int y){
	return x<1||x>n||y<1||y>m;
}
int Get(int x,int y){ return (x-1)*m+y; }
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) scanf("%d",&a[i][j]);
	}
	S=Get(n+1,1); T=S+1;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			for (int k=0;k<4;k++){
				int nx=i+dx[k],ny=j+dy[k];
				if (ub(nx,ny)) continue;
				if (a[i][j]==0){
					if (a[nx][ny]==0) ins(Get(i,j),Get(nx,ny),1);
					else if (a[nx][ny]==1) ins(Get(nx,ny),Get(i,j),1);
					else ins(Get(i,j),Get(nx,ny),1);
				}
				else if (a[i][j]==1){
					ins(S,Get(i,j),inf);
					if (a[nx][ny]==2) ins(Get(i,j),Get(nx,ny),1);
				}
				else ins(Get(i,j),T,inf);
			}
		}
	}
	int flow=0;
	while (bfs()){
		for (int i=1;i<=T;i++) cur[i]=head[i];
		flow+=dfs(S,inf);
	}
	printf("%d\n",flow);
	return 0;
}
