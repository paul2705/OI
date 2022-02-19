#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=1e2+5;
const int MAXM=1e5+5;
int edge,head[MAXN],tail[MAXM],nex[MAXM],w[MAXM];
int n,m,c[MAXN],u[MAXN],d[MAXN],o[MAXN];
queue<int> q;
bool use[MAXN];
void add(int u,int v,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
	d[v]++; o[u]++;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%d%d",&c[i],&u[i]);
		if (c[i]>0) q.push(i),u[i]=0,use[i]=1;
		c[i]-=u[i];
	}
	for (int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w); //add(v,u,w);
	}
	while (!q.empty()){
		int u=q.front(); q.pop();
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			c[v]+=c[u]*w[e]; d[v]--;
			if (d[v]==0&&c[v]>0&&!use[v]){
				q.push(v); use[v]=1;
			}
		}
	}
	int res=0;
	for (int i=1;i<=n;i++){
		if (o[i]==0&&c[i]>0) printf("%d %d\n",i,c[i]),res++;
	}
	if (res==0) printf("NULL\n");
	return 0;
}
