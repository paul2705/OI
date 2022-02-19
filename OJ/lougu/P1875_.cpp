#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e3+5;
const int MAXM=2e3+5;
int edge,head[MAXN],tail[MAXM],nex[MAXM];
int n,c[MAXN],f[MAXN],cnt[MAXN],a,b,x;
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void dfs(int u,int p){
	int res=0;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v!=p){
			dfs(v,u); res+=f[v];
		}
	}
	f[u]=min(f[u],res==0?(int)1e9:res);
}
void col(int u,int p){
	int res=0,cn=1;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v!=p){ col(v,u); res+=f[v]; cn*=cnt[v]; }
	}
	if (f[u]==(res==0?(int)1e9:res)) cnt[u]+=cn; 
	if (f[u]==c[u]) cnt[u]++;
}
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&c[i]),f[i]=c[i];
	while (~scanf("%d%d%d",&a,&b,&x)){
		add(a,x); add(x,a); add(b,x); add(x,b);
	}
	dfs(0,-1); col(0,-1);
	printf("%d %d\n",f[0],cnt[0]);
	return 0;
}
