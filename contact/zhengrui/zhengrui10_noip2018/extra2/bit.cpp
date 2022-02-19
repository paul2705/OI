#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
ll n,s,T,i;
ll calc(ll x){
	x%=mod; 
	return x*(n%mod-x+1+mod)%mod;
}
int main(){
	scanf("%lld",&T);
	while (T--){
		s=0; scanf("%lld",&n);
		for (i=0;(1ll<<i)<=n;i++){
			s+=(ll)(n>>(i+1))%mod*calc(1ll<<i)%mod;
			if ((n>>i)&1) (s+=calc(((1ll<<i)-1&n)+1))%=mod;
		}
		printf("%lld\n",s);
	}
	return 0;
}
