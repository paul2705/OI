#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=2e2+5;
const int MAXM=4e3+5;
const int inf=1e9;
int edge=1,head[MAXN],nex[MAXM],tail[MAXM],r[MAXM];
int n,m,x,ans;
int d[MAXN],cur[MAXN];
void add(int u,int v,int w){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,r[edge]=w;
}
void ins(int u,int v,int w){
	add(u,v,w); add(v,u,0);
}
bool bfs(){
	for (int i=1;i<=n;i++) d[i]=0; d[n]=1;
	queue<int> q; q.push(n); 
	while (!q.empty()){
		int v=q.front(); q.pop();
		for (int e=head[v];e;e=nex[e]){
			int u=tail[e];
			if (r[e^1]>0&&d[u]==0){
				d[u]=d[v]+1;
				q.push(u);
			}
		}
	}
	return d[1]>0;
}
int dfs(int u,int b){
	if (u==n) return b;
	int ans=0;
	for (int &e=cur[u];e;e=nex[e]){
		int v=tail[e];
		if (d[u]==d[v]+1&&r[e]>0){
			int res=dfs(v,min(r[e],b));
			ans+=res; r[e]-=res;
			r[e^1]+=res; b-=res;
		}
		if (b==0) break;
	}
	return ans;
}
int main(){
	scanf("%d%d%d",&n,&m,&x);
	for (int i=0,u,v,w;i<m;i++){
		scanf("%d%d%d",&u,&v,&w);
		ins(u,v,w);
	}
	while (bfs()){
		for (int i=1;i<=n;i++) cur[i]=head[i];
		ans+=dfs(1,inf);
	}
	if (ans==0) printf("Orz Ni Jinan Saint Cow\n");
	else printf("%d %d",ans,x%ans==0?x/ans:(x/ans+1));
	return 0;
}
