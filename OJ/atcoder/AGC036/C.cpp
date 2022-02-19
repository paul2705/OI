#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod=998244353;
const int MAXN=3e6+6;
ll ans,inv[MAXN],fac[MAXN],rfac[MAXN];
ll n,m,lim;
ll C(ll n,ll m){
	if (n<m) return 0;
	return fac[n]*rfac[m]%mod*rfac[n-m]%mod;
}
ll calc(ll n,ll M,ll m){
	ll ret=0;
	for (ll i=0;i<=m;i++){
		if ((M-i)%2==0){
			ret=(ret+C(n,i)*C((M-i)/2+n-1,n-1)%mod)%mod;
		}
	}
	return ret;
}
int main(){
	scanf("%lld%lld",&n,&m);
	lim=n+3*m; inv[1]=1;
	for (int i=2;i<=lim;i++){
		inv[i]=(mod-(mod/i)*inv[mod%i])%mod;
	}
	fac[0]=rfac[0]=1;
	for (int i=1;i<=lim;i++){
		fac[i]=fac[i-1]*i%mod;
		rfac[i]=rfac[i-1]*inv[i]%mod;
	}
	ans=(calc(n,3*m,m)-n*(calc(n,m,m)-calc(n-1,m,m))%mod)%mod;
	printf("%lld\n",(ans+mod)%mod);
	return 0;
}
