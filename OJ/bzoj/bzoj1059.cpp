#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=205;
const int MAXM=80005;
const int inf=1e9;
int a[MAXN][MAXN];
int edge,head[MAXN*2],nex[MAXM],tail[MAXM],r[MAXM];
int d[MAXN*2],cur[MAXN*2];
int n,t;
int S,T;
queue<int> q;
void add(int u,int v,int R){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,r[edge]=R;
}
void ins(int u,int v,int R){
	add(u,v,R); add(v,u,0);
}
bool bfs(){
	for (int i=1;i<=T;i++) d[i]=inf;
	d[S]=0;
	q.push(S);
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
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (d[v]==d[u]+1&&r[e]>0){
			int res=dfs(v,min(r[e],b));
			r[e]-=res; r[e^1]+=res;
			b-=res; ans+=res;
		}
		if (!b) break;
	}
	return ans;
}
int main(){
	scanf("%d",&t);
	while (t--){
		memset(head,0,sizeof(head));
		edge=1;
		scanf("%d",&n);
		S=2*n+1,T=2*n+2;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				scanf("%d",&a[i][j]);
				if (a[i][j]) ins(i,j+n,1);
			}
		}
		for (int i=1;i<=n;i++) ins(S,i,1),ins(i+n,T,1);
		int flow=0;
		while (bfs()){
			for (int i=1;i<=T;i++) cur[i]=head[i];
			flow+=dfs(S,inf);
		}
		if (flow==n) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
