#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN=1e5+5;
const int lim=12;
typedef long long ll;
int head[MAXN],tail[MAXN*2],nex[MAXN*2],edge;
ll dp[MAXN][15][5];
int n,m,u,v;
ll Q;
void add(int u,int v){
	nex[++edge]=head[u],head[u]=edge,tail[edge]=v;
	nex[++edge]=head[v],head[v]=edge,tail[edge]=u;
}
ll get(ll x){ return !x?0:x%Q?x%Q:Q;  }
void dfs(int u,int p){
	int cnt=0;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v!=p){
			dfs(v,u);
			cnt++;
		}
	}
	for (int i=0;i<=lim;i++) dp[u][i][0]=1;
	if (!cnt) return;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v!=p){
			for (int j=0;j<=lim;j++){
				ll t,f1=!j?0:dp[v][j-1][0]+dp[v][j-1][1]+dp[v][j-1][2],f2=dp[v][j][0]+dp[v][j][1];
				t=dp[u][j][2]*f1+dp[u][j][1]*f2; dp[u][j][2]=get(t);
				t=dp[u][j][1]*f1+dp[u][j][0]*f2; dp[u][j][1]=get(t);
				t=dp[u][j][0]*f1; dp[u][j][0]=get(t);
			}
		}
	}
}
int main(){
	scanf("%d%d%lld",&n,&m,&Q);
	for (int i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		add(u,v);
	}
	if (m<n-1) return printf("-1\n-1\n"),0;
	dfs(1,0);
	for (ll i=0,sum;i<=lim;i++){
		sum=dp[1][i][0]+dp[1][i][1]+dp[1][i][2];
		if (sum!=0){
			printf("%lld\n%lld\n",i,sum%Q);
			return 0;
		}
	}
	return 0;
}
