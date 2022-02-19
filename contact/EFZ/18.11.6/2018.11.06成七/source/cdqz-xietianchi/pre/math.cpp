#include <bits/stdc++.h>
#define mod 10000019
using namespace std;
typedef long long ll;

ll n , odd , even , g , k;
ll l[100] , r[100] , cnt[100];//of log 
int q , fac[mod + 10] , inv[mod + 10] , facinv[mod + 10];
int C(ll m,ll n){
	if (n > m || n < 0 || m < 0) return 0;return 1ll * fac[m] * facinv[n] % mod * facinv[m - n] % mod;
}
ll qpow(ll x,ll y){
	ll res = 1;
	while (y){
		if (y & 1) res = x * res % mod;
		x = x * x % mod;y >>= 1;
	}
	return res;
}
int lucas(ll m,ll n){
	if (n > m || n < 0 || m < 0) return 0;
	if (m < mod){
		return 1ll * fac[m] * facinv[n] % mod * facinv[m - n] % mod;
	}else{
		
		return 1ll * lucas(m / mod , n / mod) * C(m % mod , n % mod) % mod;
	}
}
int main(){
//	freopen("math.in","r",stdin);
//	freopen("math.out","w",stdout);
	
	fac[0] = 1;for (int i = 1;i < mod;i++) fac[i] = 1ll * fac[i-1] * i % mod;
	inv[1] = 1;for (int i = 2;i < mod;i++) inv[i] = 1ll * (mod - (mod / i) ) * inv[mod % i] % mod;
	facinv[0] = facinv[1] = 1;for (int i = 2;i < mod;i++) facinv[i] = 1ll * facinv[i-1] * inv[i] % mod;
	
	
	scanf("%lld%d",&n,&q);
//	int f = log2(n);
	for (int Log = 0;1ll << Log <= n;Log++){
		l[Log] = ( n / ( ( 1ll << (Log + 1) ) ) ) + 1 , r[Log] = n / (1ll << (Log) );
		ll L = l[Log] & 1 ? l[Log] : l[Log] + 1 , R = r[Log] & 1 ? r[Log] : r[Log] - 1;
		if (L <= R){
			cnt[Log] = ( ( R - L ) / 2 ) + 1;
		}	
//		printf("faf %d %lld %lld %lld\n",Log,l[Log],r[Log]);
		g += 1ll * cnt[Log] * ( ( Log + 1 ) / 2 );
		if ( ( Log + 1 ) & 1 ){
			odd += cnt[Log];
		}else {
			even += cnt[Log];
		}
	}
	/*
	for (int Log = 0;Log < 20;Log++){
//		printf("ass %d [%lld %lld] %lld\n",i,l[i],r[i],cnt[i]);
		
	
	}
	*/
	
	printf("%lld\n",g);
	ll p = qpow(2 , even);
	while (q--){
		scanf("%lld",&k);
		printf("%lld\n", g);
	}
	
	
//	printf("%d\n",lucas(10000019,10000019));
	return 0;	
}
