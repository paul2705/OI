#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int MAXN=1e5+5;
ll ans,a[MAXN],b[MAXN];
int n,id[MAXN];
bool use[MAXN];
int pos[MAXN];
void dfs(int d){
	if (d==n+1){
		ll ret=0;
		for (int i=1;i<=n;i++) ret=(ret+a[i]*b[id[i]]%mod)%mod;
		if (ans>ret){
			for (int i=1;i<=n;i++) pos[i]=id[i];
			ans=ret;
		}
	}
	for (int i=1;i<=n;i++){
		if (use[i]) continue;
		use[i]=1; id[d]=i;
		dfs(d+1);
		use[i]=0;
	}
}
void solve1(){
	ans=mod+1;
	dfs(1);
	printf("%lld\n",ans);
	for (int i=1;i<=n;i++) printf("%d ",pos[i]);
	printf("\n");
}
struct rec{
	ll x,id;
} aa[MAXN],bb[MAXN];
void solve2(){
	for (int i=1;i<=n;i++) aa[i]=(rec){a[i],i};
	for (int i=1;i<=n;i++) bb[i]=(rec){b[i],i};
	int cnt=1e7/n; ans=mod+1;
	while (cnt--){
		random_shuffle(bb+1,bb+n+1);
		ll ret=0;
		for (int i=1;i<=n;i++) ret=(ret+aa[i].x*bb[i].x%mod)%mod;
		if (ans>ret){
			ans=ret;
			for (int i=1;i<=n;i++) pos[i]=bb[i].id;
		}
	}
	printf("%lld\n",ans);
	for (int i=1;i<=n;i++) printf("%d ",pos[i]);
	printf("\n");
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for (int i=1;i<=n;i++) scanf("%lld",&b[i]);
//	solve2();
	if (n<=10) solve1();
	else solve2();
	return 0;
}
