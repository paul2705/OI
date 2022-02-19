#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MAXN=1e5+5;
const int MAXM=2e5+550;
int edge,head[MAXN],tail[MAXM],nex[MAXM];
int n,m,rd[MAXN],ans,cnt=0;
vector<int> g[MAXN];
int bel[MAXN];
bool use[MAXN];
queue<int> q;
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
int low;
int dfs(int u,int f,int ms){
	use[u]=1;
	low+=(u<ms);
	int ret=0;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==f) continue;
		if (use[v]){
			if (v==ms&&!low) ret++;
		}
		else ret+=dfs(v,u,ms);
	}
	use[u]=0;
	low-=(u<ms);
	return ret;
}
void dfs2(int u,int id){
	if (use[u]||rd[u]!=2) return;
	use[u]=1;
	bel[u]=id;
	for (int i=0;i<g[u].size();i++){
		int v=g[u][i];
		dfs2(v,id);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
		rd[u]++; rd[v]++;
	}
	for (int i=1;i<=n;i++){
		if (rd[i]==1) q.push(i);
	}
	while (!q.empty()){
		int u=q.front(); q.pop();
		rd[u]=0;
		for (int i=0;i<g[u].size();i++){
			int v=g[u][i];
			if (rd[v]==0) continue;
			rd[v]--;
			if (rd[v]==1) q.push(v);
		}
	}
	for (int i=1;i<=n;i++){
		if (use[i]||rd[i]==0) continue;
		if (rd[i]>2) bel[i]=++cnt,use[i]=1;
		else dfs2(i,++cnt);
	}
	for (int i=1;i<=n;i++){
		if (rd[i]==0) continue;
		for (int j=0;j<g[i].size();j++){
			int v=g[i][j];
			if (bel[i]!=bel[v]&&bel[i]&&bel[v])
				add(bel[i],bel[v]);
		}
	}
	for (int i=1;i<=n;i++) use[i]=0;
	for (int i=1;i<=cnt;i++){
		low=0;
		ans+=dfs(i,i,i);
	}
	printf("%d\n",ans/2);
	return 0;
}
