#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef unsigned long long ll;
ll A,B,C,k;
ll extgcd(ll a,ll b,ll &x,ll &y){
	if (b==0){ x=1,y=0; return a; }
	ll t=extgcd(b,a%b,x,y);
	ll xx=x; x=y;
	y=xx-a/b*y;
	return t;
}
int main(){
	while (scanf("%llu%llu%llu%llu",&A,&B,&C,&k)){
		if (A+B+C+k==0) break;
		ll a=C,b=B-A,n=1<<k;
		if (b==0){ printf("0\n");continue; }
		ll x,y; ll d=extgcd(a,n,x,y);
		if (b%d) printf("FOREVER\n");
		else printf("%llu\n",((x*b/d)%(n/d)+(n/d))%(n/d));
	}
	return 0;
}

