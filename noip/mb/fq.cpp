#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=2e3+5;
const int MAXM=6e3+5;
int edge,head[MAXN],nex[MAXM],tail[MAXM],w[MAXM];
int n,m,dist[MAXN],cnt[MAXN];
bool use[MAXN];
queue<int> q;
void add(int u,int v,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--){
		edge=0;
		memset(head,0,sizeof(head));
		scanf("%d%d",&n,&m);
		for (int i=1;i<=m;i++){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			if (w>=0) add(v,u,w);
			add(u,v,w);
		}
		bool fl=0;
		memset(cnt,0,sizeof(cnt));
		memset(use,0,sizeof(use));
		memset(dist,63,sizeof(dist));
		q.push(1); dist[1]=0; use[1]=1;
		while (!q.empty()){
			if (fl) break;
//			cout<<u<<" "<<dist[u]<<endl;
			int u=q.front(); q.pop(); use[u]=0;
//			cout<<u<<" "<<dist[u]<<endl;
			for (int e=head[u];e;e=nex[e]){
				int v=tail[e];
//				cout<<v<<" "<<dist[v]<<endl;
				if (dist[v]>dist[u]+w[e]){
					dist[v]=dist[u]+w[e];
					if (!use[v]) q.push(v),cnt[v]++,use[v]=1;
					if (cnt[v]>=n){
						fl=1;
						break;
					}
				}
			}
		}
		if (fl) printf("YES\n");
		else printf("N0\n");
	}
	return 0;
}
