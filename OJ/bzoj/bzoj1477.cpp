#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll x,y,m,n,l,a,b,c,t;
ll gcd(ll a,ll b){ return b==0?a:gcd(b,a%b); }
void extgcd(ll a,ll b,ll &x,ll &y){
	if (b==0){
		x=1,y=0;
		return;
	}
	extgcd(b,a%b,x,y);
	ll t=x; x=y,y=t-a/b*y;
}
int main(){
	scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&l);
//	cout<<"fuck"<<endl;
	a=n-m,b=l,c=x-y,t=gcd(a,b);
//	cout<<"fuck"<<endl;
	if (c%t!=0) return printf("Impossible\n"),0;
//	cout<<"fuck"<<endl;
	a/=t,b/=t,c/=t;
	extgcd(a,b,x,y);
//	cout<<"fuck"<<endl;
	x=((c*x)%b+b)%b;
	if (!x) x+=b;
	printf("%lld\n",x);
	return 0;
}
