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
int n,m,st[MAXN],fa[MAXN],w[MAXN];
struct rec{
	int u,c;
};
vector<rec> ch[MAXN];
int sz[MAXN],dep[MAXN];
bool use[MAXN];
const rq null=(rq){0,0};
struct rq{
	priority_queue<int> q,del;
	int cnt;
	rq(){ cnt=0; }
	void push(int x){ q.push(x); cnt++; }
	void erase(int x){ del.push(x); cnt--; }
	int top(){
		while (!del.empty()&&q.top()==del.top()){
			q.pop(); del.pop();
		}
		return q.top();
	}
	int pop(){
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
	bool empty(){ 
		return cnt==0;
	}
} q1[MAXN],q2[MAXN];
// q1: return update
// q2: interval ans
/*rq ret[MAXN];
int cnt=0;
rq getpres1(int id){
	if (q1[id].empty()) return null;
	cnt=0;
	rq mx=q1[id].top(); q1[id].pop();
	while (st[mx.id]){
		ret[cnt++]=mx;
		mx=q1[id].top();
		q1[id].pop();
	}
	for (int i=0;i<cnt;i++) q1[id].push(ret[i]);
	q1[id].push(mx);
	return mx;
}
rq getpres2(int id){
	if (q2[id].empty()) return null;
	rq mx=q2[id].top(); q2[id].pop();
	while (d[mx.id].x!=mx.x){
		mx=q2[id].top(); q2[id].pop();
	}
	return mx;
}
int getans(int id){
	rq mx1=getpres2(id);
	rq mx2=getpres2(id);
	q2[id].push(mx1); q2[id].push(mx2);
	return mx1.x+mx2.x;
}*/
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void dfs1(int u,int p){
	sz[u]=1; dep[u]=dep[p]+1;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		if (use[v]) continue;
		dfs1(v,u);
		sz[u]+=sz[v];
	}
}
int sel(int u){
	for (int i=1;i<=n;i++) sz[i]=-1,dep[i]=-1;
	dep[u]=0;
	dfs1(u,u);
	int alsz=sz[u];
	for (int i=1;i<=n;i++){
		if (sz[i]==-1) continue;
		int mx=0;
//		cout<<i<<": ";
		for (int e=head[i];e;e=nex[e]){
			int v=tail[e];
			if (sz[v]>sz[i]) continue;
			if (use[v]) continue;
			mx=max(mx,sz[v]);
//			cout<<sz[v]<<" ";
		}
//		cout<<alsz-sz[i]<<endl;
		mx=max(mx,alsz-sz[i]);
//		cout<<i<<" "<<mx<<" "<<sz[i]<<" "<<alsz<<endl;
		if (mx<=alsz/2) return i;
	}
	return u;
}
void dfs2(int u,int p){
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		if (use[v]) continue;
		dep[v]=dep[u]+1;
		dfs2(v,u);
	}
}
void solve(int u,int p){
	cout<<__func__<<" "<<u<<" "<<p<<endl;
	use[u]=1; fa[u]=p;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (use[v]) continue;
		int rt=sel(v);
		for (int i=1;i<=n;i++) dep[i]=-1;
		dep[v]=1;
		dfs2(v,u);
//		cout<<u<<": "<<v<<endl;
		for (int i=1;i<=n;i++){
			if (dep[i]==-1) continue;
//			cout<<i<<" "<<dep[i]<<endl;
			q1[rt].push((rq){dep[i],i});
		}
//		cout<<getpres1(v).x<<endl;
		d[v]=getpres1(v);
		q2[u].push((rq){d[v].x,v});
		solve(rt,u);
	}
//	cout<<u<<" "<<p<<" "<<getpres2(u).x<<" "<<getpres2(u).id<<endl;
/*	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (use[v]) continue;
		int rt=sel(v);
		w[rt]=dep[rt];
		solve(rt,u);
	}*/
}
void modify(int u,int v){
	if (u==0) return;
	int pos=0;
	for (int i=0;i<ch[u].size();i++){
		rec nv=ch[u][i];
		if (nv.c==v){
			pos=nv.u;
			break;
		}
	}
	rq res=getpres1(pos);
	q2[u].push(res);
	modify(fa[u],u);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
//	for (int i=1;i<=n;i++) sz[i]=-1,dep[i]=-1;
//	dep[1]=0;
//	dfs1(1,1); 
//	for (int i=1;i<=n;i++) cout<<i<<" "<<sz[i]<<" "<<dep[i]<<endl;
//	q1[1].push((rq){1,1}); q1[1].push((rq){3,1});
//	cout<<q1[1].top().x<<endl;
	int rt=sel(1); solve(rt,0);
	scanf("%d",&m);
	for (int i=1;i<=m;i++){
		char c=getchar(); while (c!='G'&&c!='C') c=getchar();
		if (c=='C'){
			int op; scanf("%d",&op);
			st[op]^=1;
			modify(op,0);
		}
		else printf("%d\n",getans(rt));
	}
	return 0;
}
