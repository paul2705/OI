#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a,b,x,y;
ll exgcd(ll a,ll b,ll &x,ll &y){
	if (b==0){
		x=1;y=0;
		return a;
	}
	ll q=exgcd(b,a%b,x,y);
	ll t=x;
	x=y;
	y=t-(a/b)*y;
	return q;
}
int main(){
	scanf("%lld%lld",&a,&b);
	ll d=exgcd(a,b,x,y);
	printf("%lld\n",(x%b+b)%b);
	return 0;
}
