#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int INF=1e9;
const int MAXN=55;
const int MAXM=MAXN*MAXN;
const int MAXK=205;
int edge,head[MAXN],nex[MAXM],tail[MAXM],w[MAXM];
int redge,rhead[MAXN],rnex[MAXM],rtail[MAXM],rw[MAXM];
int n,m,s,t,k,cnt;
int dist[MAXN];
struct rec{
	int u,g;
	vector<int> p;
	bool use[MAXN];
	bool operator < (const rec& b) const {
		return g+dist[u]>b.g+dist[b.u];
	}
};
struct rrec{
	int u,dat;
	bool operator < (const rrec& b) const {
		return dat>b.dat;
	}
};
rec ans[MAXK];
void add(int u,int v,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
void radd(int u,int v,int W){
	redge++,rnex[redge]=rhead[u],rhead[u]=redge,rtail[redge]=v,rw[redge]=W;
}
void rdij(){
	priority_queue<rrec> q;
	for (int i=1;i<=n;i++) dist[i]=INF;
	q.push((rrec){t,0}); dist[t]=0;
	while (!q.empty()){
		rrec u=q.top(); q.pop();
		if (u.dat>dist[u.u]) continue;
		for (int e=rhead[u.u];e;e=rnex[e]){
			int v=rtail[e];
			if (dist[v]>dist[u.u]+rw[e]){
				dist[v]=dist[u.u]+rw[e];
				q.push((rrec){dist[v],v});
			}
		}
	}
}
void Astar(){
	priority_queue<rec> q;
	rec x=(rec){s,0}; x.p.push_back(s);
	x.use[s]=1;
	q.push(x); 
	while (!q.empty()){
		rec u=q.top(); q.pop();
		if (u.u==t){
			cnt++;
			if (cnt>k&&u.g>ans[k].g){
				cnt--;
				break;
			}
//			cout<<cnt<<endl;
			ans[cnt]=u;
		}
		for (int e=head[u.u];e;e=nex[e]){
			int v=tail[e];
			if (u.use[v]) continue;
			rec nv=u;
			nv.use[v]=1; nv.u=v; nv.g+=w[e];
			nv.p.push_back(v);
			q.push(nv);
		}
	}
}
bool cmp(rec a,rec b){
	if (a.g!=b.g) return a.g<b.g;
	int len=min(a.p.size(),b.p.size());
	for (int i=0;i<len;i++){
		if (a.p[i]<b.p[i]) return 1;
		if (a.p[i]>b.p[i]) return 0;
	}
	return a.p.size()<b.p.size();
}
int main(){
	scanf("%d%d%d%d%d",&n,&m,&k,&s,&t);
	for (int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w); radd(v,u,w);
	}
	rdij();
	Astar();
	if (cnt<=k) return printf("No\n"),0;
	sort(ans+1,ans+cnt+1,cmp);
//	for (int i=1;i<=cnt;i++){
//		cout<<i<<" "<<ans[i].g<<endl;
//		for (int j=0;j<ans[i].p.size();j++){
//			printf("%d-",ans[i].p[j]);
//		}
//		cout<<endl;
//	}
//	cout<<k<<endl;
	for (int i=0;i<ans[k].p.size();i++){
		if (i==ans[k].p.size()-1) printf("%d\n",ans[k].p[i]);
		else printf("%d-",ans[k].p[i]);
	}
	return 0;
}
