#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll lim=1e18;
ll l,r,T,k;
ll get(ll x){
	ll ret=0;
	while (x){
		ll d=x%10;
		ret+=d*d;
		x/=10;
	}
	return ret;
}
int main(){
	freopen("A.in","r",stdin);
	freopen("A1.out","w",stdout);
	scanf("%lld",&T);
	while (T--){
		int ans=0;
		scanf("%lld%lld%lld",&k,&l,&r);
		for (ll i=l;i<=r;i++){
			ll s=get(i);
			if (s>lim/k) continue;
			if (s*k==i) ans++;
		}
		printf("%d\n",ans);
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
