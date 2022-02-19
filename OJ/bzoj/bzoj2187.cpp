#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
ll a,b,c,d;
ll gcd(ll a,ll b){ return b==0?a:gcd(b,a%b); }
int main(){
	while (~scanf("%lld%lld%lld%lld",&a,&b,&c,&d)){
		ll ans_p=a+c,ans_q=b+d;
		int dd=gcd(ans_p,ans_q); ans_p/=dd,ans_q/=dd;
		for (ll i=1,x,y;i<=1e4;i++){
			x=ans_p+c,y=ans_q+d;
			int dd=gcd(x,y); x/=dd,y/=dd;
			if (ans_q>y) ans_q=y,ans_p=x;
			else if (ans_q==y) ans_p=min(ans_p,x);
		}
		printf("%lld/%lld\n",ans_p,ans_q);
	}
	return 0;
}
