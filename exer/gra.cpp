#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=1e2+5;
const int MAXM=1e5+5;
int edge,head[MAXN],nex[MAXM],w[MAXM],tail[MAXM];
int n,m,out[MAXN],cnt[MAXN],c[MAXN],o[MAXN];
int use[MAXN];
void add(int u,int v,int W){
	edge++,nex[edge]=head[u],head[u]=edge,w[edge]=W,tail[edge]=v;
	cnt[v]++; out[u]++;
}
queue<int> q;
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%d%d",&c[i],&o[i]);
		if (c[i]>0) q.push(i),use[i]=1,o[i]=0;
		c[i]-=o[i];
	}
	for (int i=1;i<=m;i++){
		int u,v,w; scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
	}
	while (!q.empty()){
		int u=q.front(); q.pop();
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			c[v]+=w[e]*c[u]; cnt[v]--;
			if (cnt[v]==0&&c[v]>0&&!use[v]){
				q.push(v); use[v]=1;
			}
		}
	}
	int res=1;
	for (int i=1;i<=n;i++){
		if (out[i]==0&&c[i]>0) printf("%d %d\n",i,c[i]);
		if (out[i]==0&&c[i]!=0) res=0;
	}
	if (res==1) printf("NULL\n");
	return 0;
}
