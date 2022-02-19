#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a0,a1,b0,b1,T;
ll ans;
ll gcd(ll a,ll b){ return b==0?a:gcd(b,a%b); }
bool check(ll k1,ll k2){
	ll x=a1*k1,xx=b1/k2;
	if (x!=xx) return 0;
	if (gcd(xx,a0)==a1&&(xx*b0/gcd(xx,b0)==b1)) return 1;
	else return 0;
}
int main(){
	scanf("%lld",&T);
	while (T--){
		ans=0;
		scanf("%lld%lld%lld%lld",&a0,&a1,&b0,&b1);
		if (b1%a1!=0||a0%a1!=0||b1%b0!=0){
			printf("0\n");
			continue;
		}
		ll x=b1/a1;
		for (ll i=1;i*i<=x;i++){
			if (x%i==0){
//				printf("%lld %lld\n",i,x/i);
				if (check(i,x/i)) ans++;
				if (x/i!=i&&check(x/i,i)) ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
