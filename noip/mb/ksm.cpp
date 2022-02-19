#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,m,k;
ll mod_pow(ll x,ll n){
	if (n==0) return 1%k;
	ll ret=x; n--;
	while (n){
		if (n&1) ret=ret*x%k;
		x=x*x%k;
		n>>=1;
	}
	return ret;
}
int main(){
	scanf("%lld%lld%lld",&n,&m,&k);
	ll ans=mod_pow(n%k,m);
	printf("%lld^%lld mod %lld=%lld\n",n,m,k,ans);
	return 0;
}
