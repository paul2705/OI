#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=5e4+5;
const int MAXM=2e5+5;
int edge,head[MAXN],nex[MAXM],tail[MAXM],w[MAXM];
int n,m,k,a[MAXN];
int dist[MAXN][5];
queue<int> q;
bool use[MAXN];
void add(int u,int v,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
int main(){
	freopen("dining.in","r",stdin);
	freopen("dining.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w); add(v,u,w);
	}
	for (int i=1;i<=k;i++){
		int x,val;
		scanf("%d%d",&x,&val);
		a[x]=max(a[x],val);
	}
	for (int i=1;i<=n;i++) dist[i][0]=dist[i][1]=1e9;
	dist[n][0]=0; if (a[n]>0) dist[n][1]=-a[n];
	q.push(n); use[n]=1;
	while (!q.empty()){
		int u=q.front(); q.pop();
//		if (u.dist0>dist[u.u][0]&&u.dist1>dist[u.u][1]) continue;
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			bool f=0;
			if (dist[v][0]>dist[u][0]+w[e]){
				dist[v][0]=dist[u][0]+w[e];
				f=1;
			}
			if (dist[v][1]>dist[u][1]+w[e]){
				dist[v][1]=dist[u][1]+w[e];
				f=1;
			}
			if (a[v]>0){
				if (dist[v][1]>dist[u][0]+w[e]-a[v]){
					dist[v][1]=dist[u][0]+w[e]-a[v];
					f=1;
				}
			}
			if (f&&!use[v]) q.push(v),use[v]=1;
		}
		use[u]=0;
	}
	for (int i=1;i<=n-1;i++){
//		cout<<dist[i][1]<<" "<<dist[i][0]<<endl;
		if (dist[i][1]<=dist[i][0]) printf("1\n");
		else printf("0\n");
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
