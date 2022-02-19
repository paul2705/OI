#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=10;
ll a[MAXN],n,ans;
void solve1(){
	ans=a[1]*a[2]-a[1]-a[2];
	printf("%lld\n",ans);
}
void solve2(){
	ll ans=a[1]*a[2]-a[1]-a[2];
	for (int i=3;i<=n;i++){
		ll x=a[1]*a[i]-a[1]-a[i];
		ans=min(ans,x);
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("sequences.in","r",stdin);
	freopen("sequences.out","w",stdout);
	scanf("%lld",&n);
	ll mx=0;
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]),mx=max(mx,a[i]);
//	if (mx<=1000) solve2();
	if (n==2) solve1();
	else solve2();
	fclose(stdin); fclose(stdout);
	return 0;
}
