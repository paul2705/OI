#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=1e5+5;
const int MAXM=2e6+6;
int edge,head[MAXN],nex[MAXM],tail[MAXM],w[MAXM];
int n,m,d[MAXN],ans;
queue<int> q;
bool use[MAXN];
void add(int u,int v,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
int gcd(int a,int b){ return b==0?a:gcd(b,a%b);}
void bfs1(int S){
	q.push(S); d[S]=1; use[S]=1;
	while (!q.empty()){
		int u=q.front(); q.pop();
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			if (use[v]) ans=gcd(abs(d[u]+w[e]-d[v]),ans);
			else d[v]=d[u]+w[e],use[v]=1,q.push(v);
		}
	}
}
int bfs2(int S){
	q.push(S);
	int mx=d[S],mn=d[S];
	while (!q.empty()){
		int u=q.front(); q.pop();
		use[u]=1;
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			if (use[v]) continue;
			mx=max(mx,d[v]);
			mn=min(mn,d[v]);
			q.push(v);
		}
	}
	return mx-mn+1;
}
void solve1(){
	int ans1=ans,ans2=ans;
	if (ans<3) return printf("-1 -1\n"),void();
	for (ans2=3;ans2<=ans;ans2++){
		if (ans%ans2==0) break;
	}
	printf("%d %d\n",ans1,ans2);
}
void solve2(){// 无环
	int ans1=0;
	memset(use,0,sizeof(use));
	for (int i=1;i<=n;i++){
		if (!use[i]) ans1+=bfs2(i);
	}
	if (ans1<3) return printf("-1 -1\n"),void();
	printf("%d 3\n",ans1);
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v,1); add(v,u,-1);
	}
	for (int i=1;i<=n;i++){
		if (!use[i]) bfs1(i);
	}
//	cout<<ans<<endl;
	if (ans) solve1();
	else solve2();
}
