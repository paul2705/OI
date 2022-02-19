#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1e4+5;
const int MAXE=1e5*2+5;
int edge,head[MAXN],nex[MAXE],tail[MAXE];
int n,m,col[MAXN],sum[MAXN],use[MAXN];
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
bool dfs(int u,int c){
	if (use[u]){
		if (col[u]==c) return 1;
		else return 0;
	}
	use[u]=1; sum[col[u]=c]++;
	bool f=true;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		f=f&&dfs(v,c^1);
	}
	return f;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=0,u,v;i<m;i++){
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	int ans=0;
	for (int i=1;i<=n;i++){
		if (!use[i]){
			sum[1]=sum[0]=0;
			if (!dfs(i,0)) return printf("Impossible\n"),0;
			else ans+=min(sum[1],sum[0]);
		}
	}
	printf("%d\n",ans);
	return 0;
}
