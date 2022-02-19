#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int MAXN=1e5+5;
int edge,head[MAXN],tail[MAXN*2],nex[MAXN*2];
ll f[MAXN],ans;
int n;
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void dfs(int u,int p){
	f[u]=1;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v!=p){
			dfs(v,u);
			f[u]*=1+f[v]; f[u]%=mod;
		}
	}
	ans+=f[u]; ans%=mod;
}
int main(){
	scanf("%d",&n);
	for (int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	dfs(1,0);
	printf("%lld\n",ans);
	return 0;
}
