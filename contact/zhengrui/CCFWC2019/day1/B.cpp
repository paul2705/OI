#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=405*3;
const int MAXM=MAXN*MAXN*4;
const int inf=1e9;
struct rec{
	int s,t,id;
	bool operator < (const rec& b) const {
		return t==b.t?id>b.id:t>b.t;
	}
} a[MAXN];
int n,m,sz,S,T,ans1,ans2;
int edge=1,head[MAXN],tail[MAXM],nex[MAXM];
int r[MAXM],d[MAXN],cur[MAXN];
priority_queue<rec> q;
bool cmp(rec a,rec b){ return a.s==b.s?a.id<b.id:a.s<b.s; }
void add(int u,int v,int R){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,r[edge]=R;
}
void ins(int u,int v,int R){
	add(u,v,R); add(v,u,0);
}
bool bfs(){
	queue<int> q;
	for (int i=1;i<=n;i++) d[i]=inf;
	d[S]=0; q.push(S);
	while (!q.empty()){
		int u=q.front(); q.pop();
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			if (r[e]>0&&d[v]==inf){
				d[v]=d[u]+1;
				q.push(v);
			}
		}
	}
	return d[T]<inf;
}
int dfs(int u,int t,int b){
	if (u==t) return b;
	int ans=0;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (d[v]==d[u]+1&&r[e]>0){
			int res=dfs(v,t,min(b,r[e]));
			r[e]-=res; r[e^1]+=res;
			ans+=res; b-=res;
			if (b==0) return ans;
		}
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%d%d",&a[i].s,&a[i].t);
		a[i].id=i;
		sz=max(sz,a[i].t);
	}
	S=n+2*sz+2; T=n+2*sz+3;
	for (int i=1;i<=m;i++){
		ins(S,i,1);
		for (int j=a[i].s;j<=a[i].t;j++){
			ins(i,n+j,inf);
		}
	}
	for (int i=m+1;i<=n;i++){
		ins(i,T,1);
		for (int j=a[i].s;j<=a[i].t;j++){
			ins(n+sz+j,i,inf);
		}
	}
	for (int i=1;i<=sz;i++) ins(n+i,n+sz+i,1);
	sort(a+1,a+m+1,cmp); sort(a+m+1,a+n+1,cmp);
	int b1=1,b2=m+1;
	for (int i=1;i<=sz;i++){
		while (b1<=m&&a[b1].s<=i) q.push(a[b1++]);
		while (b2<=n&&a[b2].s<=i) q.push(a[b2++]);
		while (!q.empty()&&q.top().t<i) q.pop();
		if (q.empty()) continue;
		ans1++; q.pop();
	}
	n=T;
	while (bfs()){
		for (int i=1;i<=n;i++) cur[i]=head[i];
		ans2+=dfs(S,T,inf);
	}
	printf("%d\n%d\n",ans1,ans2);
	return 0;
}
