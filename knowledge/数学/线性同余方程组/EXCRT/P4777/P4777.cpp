#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,M,R;
bool flag=1;
ll exgcd(ll a,ll b,ll &x,ll &y){
	if (b==0){
		x=1;y=0;
		return a;
	}
	ll q=exgcd(b,a%b,x,y);
	ll tmp=x;
	x=y; y=tmp-(a/b)*y;
	return q;
}
int main(){
	scanf("%lld",&n);
	scanf("%lld%lld",&M,&R);
	for (int i=2;i<=n;i++){
		ll a,b; scanf("%lld%lld",&a,&b);
		if (!flag) continue;
		ll x=0,y=0;
		ll d=exgcd(M,a,x,y);
//		cout<<" :: "<<M*x+a*y<<endl;
		if ((R-b)%d) flag=false;
		ll tmp=(b-(b-R)/d*y%M*a);
//		ll tmp=(R-(R-b)/d*x%a*M);
		R=tmp;
		M=M/d*a;
		R%=M;
	}
	printf("%lld\n",(R%M+M)%M);
	return 0;
}
