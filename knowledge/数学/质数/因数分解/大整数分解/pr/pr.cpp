#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include"sys/time.h"
using namespace std;
typedef long long ll;
typedef long double ld;
ll n;
ll gcd(ll a,ll b){ return b==0?a:gcd(b,a%b); }
ll mul(ld a,ld b,ll mod){ return a*b-(ld)((ll)floor(a*b/n))*n; }
ll f(ll x,ll c,ll mod){ return (mul(x,x,mod)+mod+c)%mod; }
ll pr(ll n){
	ll x=rand()%10,y=rand()%10,c=rand()%100;
	y=f(y,c,n);
	while (1){
		ll res=gcd((y-x+n)%n,n);
		if (res==n) return -1;
		if (res!=1) return res;
		y=f(y,c,n); y=f(y,c,n);
		x=f(x,c,n);
	}
	return -1;
}
ll mod_pow(ll x,ll n,ll mod){
	ll ret=1;
	while (n){
		if (n&1) ret=ret*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return ret;
}
bool mrr(ll x,ll p){
	ll mod=p; p--;
	ll res=mod_pow(x,p,mod); p>>=1;
	if (res!=1) return 1;
	while (p&&p%2==0){
		ll res=mod_pow(x,p,mod);
		if (res==1){
			p>>=1; continue;
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
	struct timeval tv;
	struct timezone tz;
	gettimeofday(&tv,&tz);
	srand(tv.tv_sec*1000000+tv.tv_usec);
	scanf("%lld",&n);
	if (mr(n)) return printf("is prime!\n"),0;
	ll ans=0;
	while (1){
		ans=pr(n);
		if (ans!=-1) break;
	}
	printf("%lld %lld %lld\n",ans,n/ans,ans*(n/ans));
	return 0;
}
