#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int inf=1e9;
const int MAXN=6e4+5;
const int MAXM=5e5+5;
int edge=1,head[MAXN],tail[MAXM],nex[MAXM],r[MAXM];
int n,m,S,T,ans;
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
int main(){
	scanf("%d%d",&n,&m);
	S=n+m+1; T=S+1;
	for (int i=1;i<=n;i++){
		int x; scanf("%d",&x);
		ins(S,i,x);
	}
	for (int i=1;i<=m;i++){
		int u,v,w; scanf("%d%d%d",&u,&v,&w);
		ins(u,i+n,inf); ins(v,i+n,inf); 
		ins(i+n,T,w); ans+=w;
	}
	while (bfs()){
		for (int i=1;i<=T;i++) cur[i]=head[i];
		ans-=dfs(S,inf);
	}
	printf("%d\n",ans);
	return 0;
}
