#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod=998244353;
const int MAXN=1e5+5;
ll inv[MAXN],fac[MAXN],rfac[MAXN],pow[MAXN];
int n,m,k,T;
ll C(ll n,ll m){
	if (n<m) return 0;
	return fac[n]*rfac[n-m]%mod*rfac[m]%mod;
}
int main(){
	scanf("%d",&T);
	inv[1]=1;
	for (int i=2;i<=1e5;i++){
		inv[i]=(mod-(mod/i)*inv[mod%i]%mod)%mod;
	}
	fac[0]=rfac[0]=fac[1]=rfac[1]=1;
	for (int i=2;i<=1e5;i++){
		fac[i]=fac[i-1]*(ll)i%mod;
		rfac[i]=rfac[i-1]*inv[i]%mod;
//		cout<<i<<" "<<inv[i]<<" "<<fac[i]<<" "<<rfac[i]<<endl;
	}
	while (T--){
		scanf("%d%d%d",&n,&m,&k);
		pow[0]=1;
		for (int i=1;i<=n;i++) pow[i]=pow[i-1]*(ll)(m-1ll)%mod;
		ll ans=0;
		for (int i=k;i<=n;i++){
			ans=(ans+C(n,i)*pow[n-i]%mod)%mod;
//			cout<<ans<<" "<<C(n,i)<<" "<<pow[n-i]<<endl;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
