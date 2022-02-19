#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e3+5;
const int MAXM=2e3+5;
const int mod=998244353;
int edge,head[MAXN],nex[MAXM],tail[MAXM];
int mx[MAXN][MAXN],mn[MAXN][MAXN];
int f[MAXN][MAXN];
int n,a[MAXN];
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void dfs(int u,int p,int tp){
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		mn[tp][v]=min(mn[tp][u],a[v]);
		mx[tp][v]=max(mx[tp][u],a[v]);
		f[tp][v]=mn[tp][v]*mx[tp][v];
		dfs(v,u,tp);
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<n;i++){
		int u,v; scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	for (int i=1;i<=n;i++){
		mn[i][i]=mx[i][i]=a[i];
		f[i][i]=a[i]*a[i];
		dfs(i,0,i);
	}
	ll ans=0;
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
//			cout<<i<<" "<<j<<" "<<mn[i][j]<<" "<<mx[i][j]<<" "<<f[i][j]<<endl;
			ans+=(ll)f[i][j];
		}
	}
	printf("%lld\n",ans%mod);
	return 0;
}
