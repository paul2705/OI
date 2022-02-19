#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
const int MAXM=MAXN*2;
const ll inf=1e16;
int edge=1,head[MAXN],nex[MAXM],tail[MAXM];
ll w[MAXM];
int id[MAXN],n,m,xn,yn;
ll f[MAXN],g[MAXN];
ll ans=0;
bool usee[MAXM],use[MAXN];
void add(int u,int v,ll W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
/*void dfs(int u,int p){
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		if (id[u]+id[v]==3){
			usee[e]=usee[e^1]=1;
			ans+=w[e];
		}
	}
}*/
void dp(int u,int p){
	use[u]=1;
	for (int e=head[u];e;e=nex[e]){
//		if (usee[e]) continue;
		int v=tail[e];
		if (v==p) continue;
		dp(v,u);
		f[u]+=min(w[e]+g[v],f[v]);
		g[u]+=min(w[e]+f[v],g[v]);
	}
	if (id[u]==1) g[u]=inf;
	if (id[u]==2) f[u]=inf;
}
int main(){
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	scanf("%d",&n);
	scanf("%d",&xn);
	for (int i=1,x;i<=xn;i++){
		scanf("%d",&x);
		id[x]=1;
	}
	scanf("%d",&yn);
	for (int i=1,x;i<=yn;i++){
		scanf("%d",&x);
		id[x]=2;
	}
//	cout<<"fuck"<<endl;
	for (int i=1,u,v;i<n;i++){
		ll w;
		scanf("%d%d%lld",&u,&v,&w);
		add(u,v,w); add(v,u,w);
	}
//	cout<<"fuck"<<endl;
//	dfs(1,0);
//	cout<<"fuck"<<endl;
///	for (int i=1;i<=n;i++){
//		if (!use[i]){
//			dp(i,0);
//			ans+=min(f[i],g[i]);
//		}
//	}
	dp(1,0);
	ans=min(f[1],g[1]);
	printf("%lld\n",ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
