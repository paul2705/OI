#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int MAXN=3e5+5;
const int MAXM=6e5+5;
int edge,head[MAXN],tail[MAXM],nex[MAXM];
int n,m;
ll d[MAXN],a[MAXN],ans;
bool use[MAXN];
struct rec{
	ll dat,id;
	bool operator < (const rec& b) const {
		return dat>b.dat;
	}
};
priority_queue<rec> q;
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void dfs(int u,int p){
	d[u]=d[p]+1;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		dfs(v,u);
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for (int i=1;i<n;i++){
		int u,v; scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	d[0]=-1; dfs(1,0);
	ll cnt=n-1; ans=0;
	q.push((rec){d[1]+a[1],1});
	while (!q.empty()){
		rec u=q.top(); q.pop();
		use[u.id]=1;
//		cout<<cnt<<" "<<u.id<<" "<<u.dat<<endl;
		ans=max(ans,cnt+u.dat); cnt--;
		for (int e=head[u.id];e;e=nex[e]){
			int v=tail[e];
			if (use[v]) continue;
			q.push((rec){d[v]+a[v],v});
		}
	}
	printf("%lld\n",ans);
	return 0;
}
