#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<set>
using namespace std;
const int inf=1e9;
const int MAXN=1e5+5;
const int MAXM=2e5+5;
int edge,head[MAXN],tail[MAXM],nex[MAXM],w[MAXM];
int n,m;
int d[MAXN],pre[MAXN],val[MAXN];
bool use[MAXN];
void add(int u,int v,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
void spfa1(){
	queue<int> q;
	for (int i=0;i<n;i++) d[i]=inf;
	q.push(0); d[0]=0;
	while (!q.empty()){
		int u=q.front(); q.pop();
		use[u]=0;
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			if (d[v]>d[u]+1){
				d[v]=d[u]+1;
				if (!use[v]) q.push(v),use[v]=1;
			}
		}
	}
}
struct rec{
	int val,c,d;
	bool operator < (const rec& b) const {
		return val<b.val;
	}
};
int md;
stack<rec> que;
int t;
int vis[MAXN];
void Get(queue<rec>& D){
	t++;
	set<int> ch;
	while (!D.empty()){
		rec u=D.front(); D.pop();
		for (int e=head[u.c];e;e=nex[e]){
			int v=tail[e];
			if (d[v]!=u.d-1) continue;
			if (vis[v]==0||(vis[v]==t&&val[v]>w[e])){
				vis[v]=t;
				val[v]=w[e];
				pre[v]=u.c;
				ch.insert(v);
			}
		}
	}
	set<pair<int,int> > CH;
	for (set<int>::iterator it=ch.begin();it!=ch.end();it++){
		CH.insert(make_pair(val[(*it)],(*it)));
	}
	stack<rec> t;
	for (set<pair<int,int> >:: iterator it=CH.begin();it!=CH.end();it++){
		t.push((rec){(*it).first,(*it).second,d[(*it).second]});
	}
	while (!t.empty()){
		rec u=t.top(); t.pop();
		que.push(u);
	}
}
void bfs(){
	while (!que.empty()) que.pop();
	for (int i=0;i<n;i++){
		if (vis[i]&&d[i]==md) que.push((rec){0,i,md});
	}
	memset(vis,0,sizeof(vis));
	while (!que.empty()){
		queue<rec> Q;
		Q.push(que.top());
		que.pop();
		while (!que.empty()){
			rec u=Q.front();
			if (u.d==que.top().d&&u.val==que.top().val){
				Q.push(que.top());
				que.pop();
			}
			else break;
		}
		Get(Q);
	}
}
vector<int> ans;
void spfa2(){
	memset(use,0,sizeof(use));
	memset(vis,0,sizeof(vis));
	memset(pre,-1,sizeof(pre));
	queue<int> q;
	q.push(n-1);
	md=d[n-1];
	vis[n-1]=1;
	while (!q.empty()){
		int u=q.front(); q.pop();
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			if (w[e]||vis[v]) continue;
			vis[v]=1;
			q.push(v);
			pre[v]=u;
			md=min(md,d[v]);
		}
	}
}
void solve(int idx){
	memset(pre,-1,sizeof(pre));
	memset(vis,0,sizeof(vis));
	queue<int> q[2];
	int cur=0,old=1;
	q[0].push(0);
	for (int i=0;i<=idx;i++){
		swap(cur,old);
		while (!q[old].empty()){
			int u=q[old].front(); q[old].pop(); vis[u]=1;
			for (int e=head[u];e;e=nex[e]){
				int v=tail[e];
				if (d[u]+1==d[v]&&w[e]==ans[i]){
					q[cur].push(v);
					pre[v]=u;
				}
			}
		}
	}
	while (!q[cur].empty()){
		int u=q[cur].front(); q[cur].pop();
		if (u==n-1) break;
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			if (vis[v]||pre[v]!=-1||w[e]) continue;
			vis[v]=1;
			if (w[e]==0){
				q[cur].push(v);
				pre[v]=u;
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int u,v,w; scanf("%d%d%d",&u,&v,&w);
		add(u,v,w); add(v,u,w);
	}
	spfa1(); spfa2();
	bfs();
	int u=0;
	while (1){
		ans.push_back(val[u]);
		if (u==n-1) break;
		u=pre[u];
	}
	int id=ans.size()-1;
	while (id){
		if (ans[id]) break;
		else id--;
	}
	solve(id);
	for (;id>=0;id--) printf("%d",ans[id]);
	printf("\n");
	ans.clear();
	int U=n-1;
	while (1){
		ans.push_back(U);
		if (U==0) break;
		U=pre[U];
	}
	reverse(ans.begin(),ans.end());
	int cnt=ans.size();
	printf("%d\n",cnt);
	for (int i=0;i<ans.size();i++){
		int x=ans[i];
		printf("%d ",x);
	}
	printf("\n");
	return 0;
}
