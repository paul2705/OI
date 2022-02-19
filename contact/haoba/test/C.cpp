#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int inf=1e9;
const int MAXN=2e4+5;
const int MAXM=2e5+5;
int edge,head[MAXN],nex[MAXM],tail[MAXM],w[MAXM],num[MAXM];
int redge,rhead[MAXN],rnex[MAXM],rtail[MAXM],rw[MAXM],rnum[MAXM];
int dist[3][MAXN];
bool use[3][MAXN];
int dfn[MAXN],low[MAXN],tim;
vector<int> ans;
struct rec{
	int u,dist;
	bool operator < (const rec& b) const {
		return dist>b.dist;
	}
};
priority_queue<rec> q;
int n,m;
void add(int u,int v,int W,int id){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W,num[edge]=id;
}
void radd(int u,int v,int W,int id){
//	cout<<u<<" "<<v<<" "<<W<<" "<<id<<endl;
	redge++,rnex[redge]=rhead[u],rhead[u]=redge,rtail[redge]=v,rw[redge]=W,rnum[redge]=id;
}
void dij(int id){
	for (int i=1;i<=n;i++) dist[id][i]=inf;
	if (id==0) q.push((rec){1,0}),dist[id][1]=0;
	else q.push((rec){n,0}),dist[id][n]=0;
	while (!q.empty()){
		rec u=q.top(); q.pop();
		if (use[id][u.u]) continue;
		use[id][u.u]=1;
		for (int e=head[u.u];e;e=nex[e]){
			int v=tail[e];
			if (dist[id][v]>dist[id][u.u]+w[e]){
				dist[id][v]=dist[id][u.u]+w[e];
				q.push((rec){v,dist[id][v]});
			}
		}
	}
}
void tarjan(int u,int p){
	dfn[u]=low[u]=++tim;
	for (int e=rhead[u];e;e=rnex[e]){
		int v=rtail[e];
		if (v==p) continue;
//		cout<<u<<" "<<v<<endl;
		if (!dfn[v]){
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
			if (low[v]>dfn[u]) ans.push_back(rnum[e]);
		}
		else low[u]=min(low[u],dfn[v]);
	}
}
int main(){
	freopen("important.in","r",stdin);
	freopen("important.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int u,v,w; scanf("%d%d%d",&u,&v,&w);
		add(u,v,w,i); add(v,u,w,i);
	}
	dij(0); dij(1);
	for (int u=1;u<=n;u++){
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			if (dist[0][u]+w[e]+dist[1][v]==dist[0][n]){
				radd(u,v,w[e],num[e]); radd(v,u,w[e],num[e]);
			}
		}
	}
	for (int i=1;i<=n;i++){
		if (!dfn[i]) tarjan(i,0);
//		cout<<i<<" "<<low[i]<<endl;
	}
	int cnt=ans.size();
	printf("%d\n",cnt);
	sort(ans.begin(),ans.end());
	for (int i=0;i<cnt;i++){
		int x=ans[i];
		printf("%d ",x);
	}
	printf("\n");
	fclose(stdin); fclose(stdout);
	return 0;
}
