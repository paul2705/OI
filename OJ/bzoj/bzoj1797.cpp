#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int inf=1e9;
const int MAXN=4e3+5;
const int MAXM=2e5+5;
int edge=1,head[MAXN],tail[MAXM],nex[MAXM],r[MAXM];
int n,m,d[MAXN],cur[MAXN];
queue<int> q;
int S,T;
int st[MAXN],top;
bool use[MAXN];
int scc[MAXN],cnt,bel[MAXN];
int low[MAXN],dfn[MAXN],tim;
struct rec{
	int u,v,w;
} ed[MAXM];
int ced;
void add(int u,int v,int R){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,r[edge]=R;
}
void ins(int u,int v,int R){
	add(u,v,R); add(v,u,0);
}
bool bfs(){
	for (int i=1;i<=n;i++) d[i]=inf;
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
			ans+=res; b-=res;
			r[e]-=res; r[e^1]+=res;
		}
		if (!b) return ans;
	}
	return ans;
}
void tarjan(int u){
	low[u]=dfn[u]=++tim;
	st[++top]=u; use[u]=1;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (!r[e]) continue;
		if (!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if (use[v]) low[u]=min(low[u],dfn[v]);
	}
	if (dfn[u]==low[u]){
		bel[u]=++cnt; scc[cnt]=1;
		use[u]=0;
		int x=st[top--];
		while (x!=u){
			bel[x]=cnt; scc[cnt]++;
			use[x]=0;
			x=st[top--];
		}
	}
}
int main(){
	scanf("%d%d%d%d",&n,&m,&S,&T);
	for (int i=1;i<=m;i++){
		int u,v,w; scanf("%d%d%d",&u,&v,&w);
		ins(u,v,w);
		ed[ced++]=(rec){u,v,w};
	}
	int flow=0;
	while (bfs()){
		for (int i=1;i<=n;i++) cur[i]=head[i];
		flow+=dfs(S,inf);
	}
	for (int i=1;i<=n;i++){
		if (!dfn[i]) tarjan(i);
	}
	for (int i=0;i<ced;i++){
		int u=ed[i].u,v=ed[i].v,w=ed[i].w;
		if (r[i*2+2]){
			printf("0 0\n");
			continue;
		}
		if (bel[u]!=bel[v]) printf("1 ");
		else printf("0 ");
		if (bel[u]==bel[S]&&bel[v]==bel[T]) printf("1\n");
		else printf("0\n");
	}
	return 0;
}
