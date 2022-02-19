#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
const int MAXM=MAXN*2;
int edge,head[MAXN],tail[MAXM],nex[MAXM],w[MAXM];
int d[MAXN],t[MAXN*40][3];
int n,rt=1,M=1;
void add(int u,int v,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
void ins(int x){
	int u=rt;
//	cout<<x<<" : ";
	for (int i=30;i>-1;i--){
		int v=(x>>i)&1;
//		cout<<v;
		if (t[u][v]) u=t[u][v];
		else t[u][v]=++M,u=M;
	}
//	cout<<endl;
}
void dfs(int u,int p){
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		d[v]=w[e]^d[u];
		ins(d[v]);
		dfs(v,u);
	}
}
int qry(int x){
	int u=rt,ans=0;
	for (int i=30;i>-1;i--){
		int v=(x>>i)&1;
		if (t[u][v^1]) u=t[u][v^1],ans=ans*2+(v^1);
		else u=t[u][v],ans=ans*2+v;
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		int u,v,w; scanf("%d%d%d",&u,&v,&w);
		add(u,v,w); add(v,u,w);
	}
	dfs(1,0);
	int ans=0;
	for (int i=1;i<=n;i++) ans=max(ans,qry(d[i])^d[i]);
	printf("%d\n",ans);
	return 0;
}
