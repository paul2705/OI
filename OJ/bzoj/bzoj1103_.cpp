#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5e5+5;
const int MAXM=1e6+6;
int edge,head[MAXN],tail[MAXM],nex[MAXM];
int dfn[MAXN],cnt,id[MAXN];
int out[MAXN];
int d[MAXN];
int n,m;
int t[MAXN];
void add_e(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void add(int x,int val){
	for (;x<=n;x+=x&-x) t[x]+=val;
}
int sum(int x){
	int ret=0;
	for (;x;x-=x&-x) ret+=t[x];
	return ret;
}
void dfs(int u,int p){
	dfn[u]=++cnt; id[cnt]=u; d[u]=d[p]+1;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		dfs(v,u);
	}
	out[u]=cnt;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		int u,v; scanf("%d%d",&u,&v);
		add_e(u,v); add_e(v,u);
	}
	d[0]=-1; dfs(1,0);
	scanf("%d",&m);
	for (int i=1;i<n+m;i++){
		char op=getchar(); while (op!='W'&&op!='A') op=getchar();
		if (op=='W'){
			int u; scanf("%d",&u);
			printf("%d\n",sum(dfn[u])+d[u]);
		}
		else {
			int u,v; scanf("%d%d",&u,&v);
			add(out[v]+1,1); add(dfn[v],-1);
		}
	}
	return 0;
}
