#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
const int MAXE=MAXN*2;
int edge,head[MAXN],tail[MAXE],nex[MAXE],w[MAXE];
int n,T,id[MAXN];
ll f[MAXE],h[MAXE],c[MAXE],maxd[MAXN],secd[MAXN],sh[MAXN];
void add(int u,int v,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
void dfs(int u,int pe){
	sh[u]=maxd[u]=secd[u]=id[u]=0;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (e!=(pe^1)){
			dfs(v,e);
			sh[u]+=h[e];
			ll del=f[e]-h[e];
			if (del>=maxd[u]){
				secd[u]=maxd[u];
				maxd[u]=del;
				id[u]=e;
			}
			else if (del>=secd[u]) secd[u]=del;
		}
	}
	if (u>1){
		f[pe]=max(0ll,c[u]-w[pe]+sh[u]+maxd[u]);
		h[pe]=max(0ll,c[u]-2*w[pe]+sh[u]);
	}
}
void efs(int u,int pe){
	int e=pe^1;
	sh[u]+=h[e];
	ll del=f[e]-h[e];
	if (del>=maxd[u]) secd[u]=maxd[u],maxd[u]=del,id[u]=e;
	else if (del>=secd[u]) secd[u]=del;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (e!=(pe^1)){
			h[e^1]=max(0ll,c[u]-2*w[e]+sh[u]-h[e]);
			if (e!=id[u]) f[e^1]=max(0ll,c[u]-w[e]+sh[u]-h[e]+maxd[u]);
			else f[e^1]=max(0ll,c[u]-w[e]+sh[u]-h[e]+secd[u]);
			efs(v,e);
		}
	}
}
int main(){
	int cnt=0;
	scanf("%d",&T);
	while (T--){
		cnt++;
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%lld",&c[i]);
		memset(head,0,sizeof(head)); edge=1;
		for (int i=1,u,v,w;i<n;i++){
			scanf("%d%d%d",&u,&v,&w);
			add(u,v,w); add(v,u,w);
		}
		dfs(1,0); efs(1,0);
		printf("Case #%d:\n",cnt);
		for (int u=1;u<=n;u++) printf("%lld\n",c[u]+sh[u]+maxd[u]);
	}
	return 0;
}
