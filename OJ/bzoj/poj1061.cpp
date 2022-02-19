#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll x,y,n,m,l;
ll extgcd(ll a,ll b,ll &x,ll &y){
	if (b==0){ x=1,y=0; return a; }
	ll t=extgcd(b,a%b,x,y);
	ll xx=x; x=y;
	y=xx-a/b*y;
	return t;
}
int main(){
	scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&l);
	if (m==n) return printf("Impossible\n"),0;
	ll a=m-n,b=y-x; if (a<0) a=-a,b=-b;
	ll x,y; ll d=extgcd(a,l,x,y);
	if (b%d) printf("Impossible\n");
	else printf("%lld\n",((x*b/d)%(l/d)+(l/d))%(l/d));
	return 0;
}
