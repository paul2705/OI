#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int MAXN=1e3+5;
const int MAXM=1e6+5;
const ll inf=1e17;
int edge,head[MAXN],nex[MAXM],tail[MAXM];
ll r[MAXM];
int n,m,S,T,cur[MAXN];
ll d[MAXN],h[MAXN];
bool use[MAXN];
struct ed{
	int u,v;
	ll w;
} edg[MAXM];
queue<int> q;
struct rec{
	int u;
	ll d;
	bool operator < (const rec& b) const {
		return d>b.d;
	}
};
priority_queue<rec> rq;
void add(int u,int v,ll R){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,r[edge]=R;
}
void ins(int u,int v,ll R){
	add(u,v,R); add(v,u,0);
}
bool bfs(){
	for (int i=1;i<=T;i++) d[i]=inf;
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
ll dfs(int u,ll b){
	if (u==T) return b;
	ll ans=0;
	for (int &e=cur[u];e;e=nex[e]){
		int v=tail[e];
		if (d[v]==d[u]+1&&r[e]>0){
			ll res=dfs(v,min(r[e],b));
			r[e]-=res; r[e^1]+=res;
			b-=res; ans+=res;
		}
		if (!b) break;
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int u,v; ll w; scanf("%d%d%lld",&u,&v,&w);
		add(u,v,w); add(v,u,w);
		edg[i]=(ed){u,v,w};
	}
	for (int i=1;i<=n;i++) d[i]=inf,use[i]=0;
	rq.push((rec){1,0}); d[1]=0;
	while (!rq.empty()){
		rec u=rq.top(); rq.pop();
//		cout<<"u: "<<u.u<<endl;
		if (use[u.u]) continue;
		use[u.u]=1;
//		cout<<"rd:: "<<u.u<<" "<<u.d<<endl;
		for (int e=head[u.u];e;e=nex[e]){
			int v=tail[e];
			if (d[v]>d[u.u]+r[e]){
				d[v]=d[u.u]+r[e];
//				cout<<v<<" "<<d[v]<<endl;
				rq.push((rec){v,d[v]});
			}
		}
	}
//	cout<<use[n]<<endl;
//	for (int i=1;i<=n;i++) cout<<i<<" "<<d[i]<<endl;
	for (int i=1;i<=n;i++) h[i]=inf,use[i]=0;
	rq.push((rec){n,0}); h[n]=0;
	while (!rq.empty()){
		rec u=rq.top(); rq.pop();
		if (use[u.u]) continue;
		use[u.u]=1;
		for (int e=head[u.u];e;e=nex[e]){
			int v=tail[e];
			if (h[v]>h[u.u]+r[e]){
				h[v]=h[u.u]+r[e];
				rq.push((rec){v,h[v]});
			}
		}
	}
//	cout<<"done"<<endl;
	S=2*1+1; T=2*n;
	edge=1;
	memset(head,0,sizeof(head));
	memset(r,0,sizeof(r));
//	cout<<"n: "<<d[n]<<" "<<h[1]<<endl;
	for (int i=1;i<=m;i++){
		int u=edg[i].u,v=edg[i].v;
		ll w=edg[i].w;
//		cout<<d[u]<<" "<<w<<" "<<h[v]<<" "<<d[n]<<endl;
		if (d[u]+w+h[v]==d[n]||d[v]+w+h[u]==d[n]){
//			printf("%d %d %lld\n",u,v,w);
			ins(2*u+1,2*v,inf),ins(2*v+1,2*u,inf);
		}
	}
	for (int i=1;i<=n;i++){
		ll x; scanf("%lld",&x);
		if (i!=1&&i!=n) ins(2*i,2*i+1,x);
	}
	ll ans=0;
	while (bfs()){
//		cout<<ans<<endl;
		for (int i=1;i<=T;i++) cur[i]=head[i];
		ans+=dfs(S,inf);
	}
	printf("%lld\n",ans);
	return 0;
}
