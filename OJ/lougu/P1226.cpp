#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
typedef long long ll;
ll a,b,p;
ll mod_pow(ll a,ll b,ll p){
	ll ans=1;
	while (b){
		if (b&1) ans=ans*a%p;
		a=a*a%p;
		b>>=1;
	}
	return ans;
}
int main(){
	scanf("%lld%lld%lld",&a,&b,&p);
	printf("%lld^%lld mod %lld=%lld\n",a,b,p,mod_pow(a,b,p));
	return 0;
}
