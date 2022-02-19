#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e3+5;
const int INF=1e6;
int n,m;
int edge,head[MAXN],tail[MAXN],nex[MAXN],w[MAXN];
void add(int u,int v,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
int dfs(int u,int p,int cap){
	int res=0; bool f=false;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v!=p){
			f=true;
			if (w[e]>cap) res+=dfs(v,u,cap);
			else res+=min(dfs(v,u,cap),w[e]);
		}
	}
	if (!f) res=INF;
	return res;
}
int main(){
	scanf("%d%d",&n,&m);
	while (n+m!=0){
		memset(head,0,sizeof(head)); edge=0;
		memset(nex,0,sizeof(nex));
		int mx=0;
		for (int i=1,u,v,w;i<n;i++){
			scanf("%d%d%d",&u,&v,&w);
			add(u,v,w); add(v,u,w);
			mx=max(mx,w);
		}
		int l=1,r=mx,mid,x=-1;
		while (l<=r){
			mid=(l+r)>>1;
			if (dfs(1,0,mid)<=m) x=mid,r=mid-1;
			else l=mid+1;
		}
		printf("%d\n",x);
		scanf("%d%d",&n,&m);
	}
	return 0;
}
