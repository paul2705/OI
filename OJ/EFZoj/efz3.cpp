#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int inf=1e9;
const int MAXN=1e2+5;
const int MAXE=MAXN*MAXN;
int edge=1,head[MAXN],nex[MAXE],r[MAXE],tail[MAXE];
int n,m,s,t,d[MAXN],cur[MAXN],u[MAXN],v[MAXN],use[MAXN];
void add(int u,int v,int w){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,r[edge]=w;
}
void ins(int u,int v,int w){
	add(u,v,w); add(v,u,0);
}
bool bfs(){
	memset(d,0,sizeof(d)); d[t]=1;
	queue<int> q; q.push(t);
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
			int res=dfs(v,min(b,r[e]));
			ans+=res; r[e]-=res;
			r[e^1]+=res; b-=res;
		}
		if (b==0) break;
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	s=0,t=n+1; int u,v;
	while (~scanf("%d%d",&u,&v)){
//		if (u+v==0) break; 
		ins(u,v,1); use[u]=1;
	}
	for (int i=1;i<=n;i++){
		if (use[i]) ins(s,i,1);
		else ins(i,t,1);
	}
	int ans=0;
	while (bfs()){
		for (int u=s;u<=t;u++) cur[u]=head[u];
		ans+=dfs(s,inf);
	}
	printf("%d\n",ans);
	return 0;
}
