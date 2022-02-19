#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=185;
const int MAXM=2e4+5;
const int inf=1e9;
int edge=1,head[MAXN],nex[MAXM],tail[MAXM],r[MAXM];
int n,S,T,dist[MAXN],cur[MAXN];
queue<int> q;
void add(int u,int v,int R){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,r[edge]=R;
}
void ins(int u,int v,int R){
	add(u,v,R); add(v,u,0);
}
bool bfs(){
	for (i=1;i<=T;i++) dist[i]=inf;
	dist[S]=0; q.push(S);
	while (!q.empty()){
		int u=q.front(); q.pop();
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			if (dist[v]==0&&r[e]>0){
				dist[v]=dist[u]+1;
				q.push(v);
			}
		}
	}
	return dist[T]<inf;
}
int dfs(int u,int b){
	if (u==T) return b;
	int ans=0;
	for (int& e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (d[v]==d[u]+1&&r[e]>0){
			int tmp=dfs(v,min(r[e],b));
			r[e]-=tmp; r[e^1]+=tmp;
			ans+=tmp; b-=tmp;
			if (!b) break;
		}
	}
	return ans;
}
bool dinic(){
	int ret=0;
	while (bfs()) ret+=dfs(S,inf);
	return ret;
}
int main(){
	scanf("%d",&n);
	int cnt=0,now=0;
	while (cnt>=now){
		now++;
		ins(S,now*2,1);
		ins(now*2+1,T,1);
		for (int i=sqrt(now*2);i>=now;i--){
			ins(now*2,(i*i-now)*2+1,1);
		}
		
	}
	now--;
	printf("%d\n",now);

