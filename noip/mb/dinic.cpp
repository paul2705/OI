#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int inf=1e9;
const int MAXN=2e3+5;
const int MAXM=MAXN*MAXN;
int edge=1,head[MAXN],tail[MAXM],nex[MAXM],r[MAXM];
int d[MAXN],n,m,s,t,cur[MAXN];
queue<int> q;
void add(int u,int v,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,r[edge]=W;
}
void ins(int u,int v,int W){
	add(u,v,W); add(v,u,0);
}
bool bfs(){
	for (int i=s;i<=t;i++) d[i]=0;
	d[t]=1; q.push(t);
	while (!q.empty()){
		int v=q.front(); q.pop();
		for (int e=head[v];e;e=nex[e]){
			int u=tail[e];
			if (r[e^1]>0&&d[u]==0){
				d[u]=d[v]+1;
				q.push(u);
			}
		}
	}
	return d[s]>0;
}
int dinic(int u,int b){
	if (u==t) return b;
	int ans=0;
	for (int &e=cur[u];e;e=nex[e]){
		int v=tail[e];
		if (d[u]==d[v]+1&&r[e]>0){
			int res=dinic(v,min(b,r[e]));
			r[e]-=res;
			r[e^1]+=res;
			b-=res;
			ans+=res;
		}
		if (b==0) break;
	}
	return ans;
}
int main(){
	freopen("dinic.in","r",stdin);
	scanf("%d%d",&n,&m);
	int e;
	scanf("%d",&e);
	s=0,t=n+m+1;
	for (int i=1,u,v;i<=e;i++){
		scanf("%d%d",&u,&v); v+=n;
		if (v>n+m) continue;
		ins(u,v,1);
	}
	for (int i=1;i<=n;i++) ins(s,i,1);
	for (int i=n+1;i<=n+m;i++) ins(i,t,1);
	int ans=0;
	for (int i=s;i<=t;i++) cur[i]=head[i];
	while (bfs()){
		//		cout<<"fuck"<<endl;
		for (int i=s;i<=t;i++) cur[i]=head[i];
		ans+=dinic(s,inf);
	}
	printf("%d\n",ans);
	return 0;
}
