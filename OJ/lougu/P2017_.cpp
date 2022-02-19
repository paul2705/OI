#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=1e5+5;
const int MAXE=4e5+5;
struct awr{
	int u,v;
} ans[MAXE];
int edge=1,head[MAXN],tail[MAXE],id[MAXE],nex[MAXE],use[MAXE],typ[MAXE];
int n,m,k,rd[MAXN];
void add(int u,int v,int tp,int ind){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,typ[edge]=tp,id[edge]=ind;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		add(u,v,1,0); edge++; rd[v]++;
	}
	for (int i=1,u,v;i<=k;i++){
		scanf("%d%d",&u,&v);
		add(u,v,2,i); add(v,u,2,i);
	}
	queue<int> q;
	for (int i=1;i<=n;i++) if (rd[i]==0) q.push(i);
	while (!q.empty()){
		int u=q.front(); q.pop();
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			if (typ[e]==1){
				rd[v]--;
				if (rd[v]==0) q.push(v);
			}
			else {
				if (use[e]) continue;
				ans[id[e]]=(awr){u,v};
				use[e]=use[e^1]=1;
			}
		}
	}
	for (int i=1;i<=k;i++) printf("%d %d\n",ans[i].u,ans[i].v);
	return 0;
}
