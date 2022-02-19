#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=5e5+5;
const ll mod=323232323;
ll inv[2*MAXN],finv2[2*MAXN],fac[2*MAXN],finv[2*MAXN];
ll res[MAXN];
ll n,a,ans;
ll C(ll n,ll m){ return fac[n]*finv[m]%mod*finv[n-m]%mod; }
void ini(){
	inv[1]=1; finv2[0]=1; fac[0]=1; finv[0]=1;
	for (ll i=2;i<2*MAXN;i++) inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	for (ll i=1;i<2*MAXN;i++) fac[i]=fac[i-1]*i%mod;
	for (ll i=1;i<2*MAXN;i++) finv[i]=finv[i-1]*inv[i]%mod;
	for (ll i=1;i<2*MAXN;i++) finv2[i]=finv2[i-1]*inv[2]%mod;
	ll ret1=0,ret2=1;
	for (ll i=1;i<MAXN;i++){
		ll t=C(a-1+i-1,i-1)*finv2[a+i-1]%mod;
		ret1=(ret1+(i-1)*t%mod)%mod;
		ret2=(ret2+mod-t)%mod;
		res[i]=(ret1+i*ret2)%mod;
	}
}
int main(){
	scanf("%lld%lld",&n,&a);
	ini();
	ans=a;
	for (ll i=1,x;i<n;i++){
		scanf("%lld",&x);
		ans=(ans+res[x])%mod;
	}
	printf("%lld\n",ans);
	return 0;
}
