#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int MAXN=1e5+5;
const int MAXM=2e5+5;
int edge,head[MAXN],tail[MAXM],nex[MAXM];
int n,m,st[MAXN],fa[MAXN],lf[MAXN][20];
int dist[MAXN];
int sz[MAXN];
bool use[MAXN];
struct rq{
	priority_queue<int> q,del;
	int cnt;
	rq(){ cnt=0; }
	void push(int x){ q.push(x); cnt++; }
	void erase(int x){ del.push(x); cnt--; }
	int top(){
//		if (q.empty()) return 0;
		while (!del.empty()&&q.top()==del.top()){
			q.pop(); del.pop();
		}
		return q.top();
	}
	void pop(){
//		if (q.empty()) return;
		while (!del.empty()&&q.top()==del.top()){
			q.pop(); del.pop();
		}
		q.pop();
	}
	int sec(){
		int tmp=top(); pop();
		int sec=top(); push(tmp);
		return sec;
	}
	int size(){ 
		return cnt;
	}
} q1[MAXN],q2[MAXN],ans;
void ins(int id){
	if (q2[id].size()>1) ans.push(q2[id].top()+q2[id].sec());
}
void era(int id){
	if (q2[id].size()>1) ans.erase(q2[id].top()+q2[id].sec());
}
// q1: return update
// q2: interval ans
// ans: outerval
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
int lca(int u,int v){
	if (u==v) return 0;
	if (dist[u]>dist[v]) swap(u,v);
	for (int k=19;k>=0;k--){
		if (dist[lf[v][k]]>dist[u]) v=lf[v][k];
	}
	if (dist[v]>dist[u]) v=lf[v][0];
	if (u==v) return u;
	for (int k=19;k>=0;k--){
		if (lf[u][k]!=lf[v][k]){
			u=lf[u][k];
			v=lf[v][k];
		}
	}
	if (u!=v) return lf[u][0];
	else return u;
}
int dis(int u,int v){
	int f=lca(u,v);
	return dist[u]+dist[v]-2*dist[f];
}
void dfs1(int u,int p){
	sz[u]=1;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		if (use[v]) continue;
		dfs1(v,u);
		sz[u]+=sz[v];
	}
}
int cg,alsz;
void dfs3(int u,int p){
	int mx=0;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		if (use[v]) continue;
		dfs3(v,u);
		mx=max(mx,sz[v]);
	}
	mx=max(mx,alsz-sz[u]);
	if (mx<=alsz/2) cg=u;
}
int sel(int u){
	dfs1(u,0);
	alsz=sz[u]; cg=u;
	dfs3(u,0);
	return cg;
}
void dfs2(int u,int p,int g){
	q1[g].push(dis(u,fa[g]));
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		if (use[v]) continue;
		dfs2(v,u,g);
	}
}
void solve(int u,int p){
//	cout<<__func__<<" "<<u<<" "<<p<<endl;
	use[u]=1;
	q2[u].push(0);
	q1[u].push(0);
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (use[v]) continue;
		int rt=sel(v);
		fa[rt]=u;
		dfs2(rt,0,rt);
		solve(rt,u);
		q2[u].push(q1[rt].top());
	}
	ins(u);
}
void modify(int u,bool flag){
	era(u);
	if (flag) q2[u].erase(0);
	else q2[u].push(0);
	ins(u);
	for (int v=u;fa[v];v=fa[v]){
		era(fa[v]);
		if (q1[v].size()) q2[fa[v]].erase(q1[v].top());
		if (flag) q1[v].erase(dis(u,fa[v]));
		else q1[v].push(dis(u,fa[v]));
		if (q1[v].size()) q2[fa[v]].push(q1[v].top());
		ins(fa[v]);
	}
}
void dfs(int u,int p){
	lf[u][0]=p; dist[u]=dist[p]+1;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		dfs(v,u);
	}
}
void ini(){
	for (int k=1;k<20;k++){
		for (int i=1;i<=n;i++){
			lf[i][k]=lf[lf[i][k-1]][k-1];
		}
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	dfs(1,0); ini();
	int rt=sel(1); solve(rt,0);
	scanf("%d",&m);
	int cnt=n;
	for (int i=1;i<=m;i++){
		char c=getchar(); while (c!='G'&&c!='C') c=getchar();
		if (c=='C'){
			int op; scanf("%d",&op);
			st[op]^=1;
			cnt+=(st[op]?1:-1);
			modify(op,st[op]);
		}
		else{
			if (cnt<=1) printf("%d\n",cnt-1);
			else printf("%d\n",ans.top());
		}
	}
	return 0;
}
