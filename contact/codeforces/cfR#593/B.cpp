#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll n,m,ans;
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
	cin>>n>>m;
	ans=(mod_pow(2ll,m)-1+mod)%mod;
	ans=mod_pow(ans,n);
	cout<<(ans%mod+mod)%mod<<endl;
	return 0;
}
