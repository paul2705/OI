#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n;
ll mod_pow(ll x,ll p,ll mod){
	ll ret=1;
	while (p){
		if (p&1) ret=ret*x%mod;
		x=x*x%mod;
		p>>=1;
	}
	return ret;
}
bool mrr(ll x,ll p){
	ll mod=p;
	p--;
	ll res=mod_pow(x,p,mod);
	if (res!=1) return 1;
	p>>=1;
	while (p&&p%2==0){
		ll res=mod_pow(x,p,mod);
		if (res==1){
			p>>=1;
			continue;
		}
		if (res==mod-1) return 0;
		else return 1;
	}
	return 0;
}
bool mr(ll x){
	if (x==2||x==3||x==5||x==7) return 1;
	if (x%2==0) return 0;
	if (mrr(2,x)) return 0;
	if (mrr(3,x)) return 0;
	if (mrr(5,x)) return 0;
	if (mrr(7,x)) return 0;
	return 1;
}
int main(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	scanf("%lld",&n);
	for (ll i=2;i<=n;i++){
//		cout<<i<<endl;
		if (mr(i)) printf("%lld\n",i);
	}
	return 0;
}
