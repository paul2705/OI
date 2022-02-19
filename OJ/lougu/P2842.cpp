#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll a,b;
ll mod_pow(ll a,ll b,ll mod){
	a%=mod; ll ans=1;
	while (b){
		if (b&1) ans=(ans*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return ans;
}
int main(){
	scanf("%lld%lld",&a,&b);
	printf("%lld\n",mod_pow(a,mod_pow(a,b-1,mod-1),mod));
	return 0;
}
