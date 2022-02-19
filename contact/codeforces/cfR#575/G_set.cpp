#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<queue>
using namespace std;
const int inf=1e9;
const int MAXN=1e5+5;
const int MAXM=2e5+5;
int edge,head[MAXN],nex[MAXM],tail[MAXM],w[MAXM];
int n,m;
int d[3][MAXN];
struct rec{
	int u,w;
	bool operator < (const rec& b) const {
		return w<b.w;
	}
} pre[3][MAXN];
queue<int> q;
set<int> S,nS;
void add(int u,int v,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
void bfs(int id){
	for (int i=0;i<n;i++) d[id][i]=inf;
	if (id==0) d[id][0]=0,q.push(0);
	else d[id][n-1]=0,q.push(n-1);
	while (!q.empty()){
		int u=q.front(); q.pop();
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			if (id){
				if (w[e]==0&&d[id][v]>d[id][u]+1){
					d[id][v]=d[id][u]+1;
					pre[id][v]=(rec){u,w[e]};
					q.push(v);
				}
			}
			else {
				if (d[id][v]>d[id][u]+1){
					d[id][v]=d[id][u]+1;
					pre[id][v]=(rec){u,w[e]};
					q.push(v);
				}
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
	bfs(0); bfs(1);
	int rlen=inf;
	for (int i=0;i<n;i++){
		if (i==n-1||d[1][i]<inf){
			rlen=min(rlen,d[0][i]);
		}
	}
	for (int i=0;i<n;i++) pre[0][i]=(rec){inf,0};
	for (int i=0;i<n;i++){
		if (i==n-1||d[1][i]<inf){
			if (d[0][i]==rlen){
				pre[0][i]=(rec){d[1][i],i};
				S.insert(i);
			}
		}
	}
	for (int i=0;i<rlen;i++){
		nS.clear();
		int b=10;
		for (set<int>::iterator it=S.begin();it!=S.end();it++){
			int u=(*it);
			for (int e=head[u];e;e=nex[e]){
				int v=tail[e];
				if (d[0][u]-1!=d[0][v]) continue;
				if (w[e]<b) b=w[e],nS.clear();
				if (w[e]==b){
					if (nS.find(v)!=nS.end()){
						pre[0][v]=min(pre[0][v],(rec){pre[0][u].w,u});
					}
					else {
						nS.insert(v); pre[0][v]=(rec){pre[0][u].w,u};
					}
				}
			}
		}
		printf("%d",b);
		S=nS;
	}
	if (rlen==0) printf("0");
	printf("\n");
	int cnt=rlen+pre[0][0].w;
	printf("%d\n",cnt+1);
	int u=0;
	for (int i=0;i<rlen;i++){
		printf("%d ",u);
		u=pre[0][u].u;
	}
	for (int i=0;i<cnt-rlen;i++){
		printf("%d ",u); u=pre[1][u].u;
	}
	printf("%d\n",u);
	return 0;
}
