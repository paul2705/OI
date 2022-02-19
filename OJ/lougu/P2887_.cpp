#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=2e3+5e2+5;
const int MAXM=MAXN*MAXN;
const int inf=1e9;
int edge=1,head[MAXN],nex[MAXM],tail[MAXM],r[MAXM];
int n,m,rr[MAXN],l[MAXN],d[MAXN],cur[MAXN];
int s=0,t,ans;
void add(int u,int v,int w){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,r[edge]=w;
}
void ins(int u,int v,int w){ add(u,v,w); add(v,u,0); }
bool bfs(){
	memset(d,0,sizeof(d));
	queue<int> q; q.push(t); d[t]=1;
	while (!q.empty()){
		int v=q.front(); q.pop();
		for (int e=head[v];e;e=nex[e]){
			int u=tail[e];
			if (d[u]==0&&r[e^1]>0){
				d[u]=d[v]+1; q.push(u);
			}
		}
	}
	return d[s]>0;
}
int dfs(int u,int b){
	if (u==t) return b;
	int ans=0;
	for (int &e=cur[u];e;e=nex[e]){
		int v=tail[e];
		if (r[e]>0&&d[u]==d[v]+1){
			int res=dfs(v,min(r[e],b));
			r[e]-=res; r[e^1]+=res;
			ans+=res; b-=res;
		}
		if (b==0) break;
	}
	return ans;
}
int main(){
	freopen("P2887.in","r",stdin);
	scanf("%d%d",&n,&m); t=n+m+1;
	for (int i=1;i<=n;i++) scanf("%d%d",&l[i],&rr[i]),ins(s,i,1);
	for (int i=1,x,v;i<=m;i++){
		scanf("%d%d",&x,&v);
		for (int j=1;j<=n;j++){
			if (l[j]<=v&&v<=rr[j]) ins(j,i+n,1);
		}
		ins(i+n,t,x);
	}
	while (bfs()){
		for (int i=s;i<=t;i++) cur[i]=head[i];
		ans+=dfs(s,inf);
	}
	printf("%d\n",ans);
	return 0;
}
