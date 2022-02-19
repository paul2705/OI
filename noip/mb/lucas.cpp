#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
ll n,m,p;
ll inv[MAXN],fac[MAXN],rfac[MAXN];
ll C(ll n,ll m){
//	cout<<"1: "<<n<<" "<<m<<endl;
	if (m>n) return 0;
	if (m>n-m) m=n-m;
	return fac[n]*rfac[n-m]%p*rfac[m]%p;
}
ll lucas(ll n,ll m){
//	cout<<n<<" "<<m<<endl;
	if (m==0) return 1;
	return lucas(n/p,m/p)*C(n%p,m%p);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--){
		scanf("%lld%lld%lld",&n,&m,&p);
		inv[1]=1;
		for (ll i=2;i<p;i++){
			inv[i]=(p-inv[p%i]*(p/i)%p)%p;
		}
		fac[0]=rfac[0]=fac[1]=rfac[1]=1;
		for (int i=2;i<=n+m;i++) fac[i]=fac[i-1]*i%p;
		for (int i=2;i<=n+m;i++) rfac[i]=rfac[i-1]*inv[i]%p;
//		printf("%lld\n",fac[n+m]*rfac[n]%p*rfac[m]%p);
		printf("%lld\n",lucas(n+m,m)%p);
	}
	return 0;
}
