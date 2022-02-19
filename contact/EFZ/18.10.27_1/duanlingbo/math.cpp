#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod=1e7+19;
ll inv[mod+5],fac[mod+5],rfac[mod+5];
ll n,m,q;
ll sum,s,ss;
ll C(ll n,ll m){
	if (n<m) return 0;
	return fac[n]*rfac[m]%mod*rfac[n-m]%mod;
}
ll lucas(ll n,ll m){
	if (n<m) return 0;
	if (m==0) return 1;
	if (n<mod&&m<mod) return C(n,m);
	else return lucas(n%mod,m%mod)*lucas(n/mod,m/mod);
}
ll mod_pow(ll x,ll n){
	ll ret=1;
	while (n){
		if (n&1) ret=ret*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return ret;
}
int main(){
	freopen("math.in","r",stdin);
	freopen("math.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	inv[1]=1;
	for (int i=2;i<mod;i++){
		inv[i]=(mod-inv[mod%i]*(mod/i)%mod)%mod;
	}
//	cout<<inv[2]<<endl;
	fac[0]=rfac[0]=rfac[1]=fac[1]=1;
	for (int i=2;i<mod;i++) fac[i]=fac[i-1]*i%mod;
	for (int i=2;i<mod;i++) rfac[i]=rfac[i-1]*inv[i]%mod;
	ll k=1,las=n;
	for (ll i=n/2;las>0;i/=2,k++){
//		cout<<las<<" "<<i<<" "<<k<<endl;
		ll res=(las-i-1)/2;
		if ((las&1)||((i+1)&1)) res++;
//		cout<<res<<endl;
		sum+=k/2*res;
		las=i;
		if (k&1) s+=res;
		else ss+=res;
	}
//	cout<<sum<<" "<<s<<" "<<ss<<endl;
	for (ll i=1;i<=q;i++){
		scanf("%lld",&m);
//		cout<<sum<<" "<<m<<endl;
		if (sum<=m) printf("%lld\n",lucas(s,m-sum)*mod_pow(2,ss)%mod);
		else printf("0\n");
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
