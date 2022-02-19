#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int MAXN=1e5+5;
const int MAXM=2e5+5;
int edge,head[MAXN],tail[MAXM],nex[MAXM],from[MAXM];
struct node{
	int u,d;
	bool operator < (const node &a) const {return d<a.d;}
	bool operator > (const node &a) const {return d>a.d;}
}; 
int n,k,t,cnt,ans;
int d[MAXN],fa[MAXN];
bool use[MAXN];
priority_queue<node> q;
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,from[edge]=u;
}
void dfs1(int u){
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (!d[v]) fa[v]=u,d[v]=d[u]+1,dfs1(v);
	}
}
int find(int x){
	int stp=1;
	while (stp<=k) stp++,x=fa[x];
	return x;
}
void dfs2(int u,int rt,int stp){
	use[u]=1; if (stp==k) return;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v!=rt) dfs2(v,u,stp+1);
	}
}
int main(){
	scanf("%d%d%d",&n,&k,&t);
	for (int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	d[1]=1,fa[1]=1; dfs1(1);
	for (int i=1;i<=n;i++) q.push((node){i,d[i]});
	while (!q.empty()){
		int u=q.top().u; q.pop();
		if (use[u]) continue;
		ans++; int v=find(u); dfs2(v,v,0);
	}
	printf("%d\n",ans);
	return 0;
}
