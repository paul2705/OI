#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,p,w,d,a,b,c,x,y;
ll exgcd(ll a,ll b,ll &x,ll &y){
	if (b==0){
		x=1;y=0;
		return a;
	}
	ll q=exgcd(b,a%b,x,y);
	ll tmp=x;
	x=y;
	y=(tmp-(a/b)*y);
	return q;
}
int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	cin>>n>>p>>w>>d;
	a=w-d; b=w; c=n*w-p;
//	cout<<a<<" "<<b<<" "<<c<<endl;
	ll d=exgcd(a,b,x,y);
//	cout<<a*x+b*y<<" "<<d<<endl;
	if (c%d!=0) return printf("-1\n"),0;
	if (c<0) return printf("-1\n"),0;
//	cout<<a<<" "<<x<<" "<<b<<" "<<y<<" "<<c<<" "<<d<<endl;
	x*=(c/d); y*=(c/d);
	ll limx=ceil((double)-x/b),limy=floor((double)y/a);
	if (b>a){
		ll limn=floor((double)(n-x-y)/(b-a));
//		cout<<x<<" "<<y<<" "<<b<<" "<<a<<" "<<limx<<" "<<limn<<" "<<limy<<endl;
		if (limn>=limx&&limx<=limy){
			x=x+b*limx;
			y=y-a*limx;
		}
		else return printf("-1\n"),0;
	}
	else if (b==a){
		if (x+y>n) return printf("-1\n"),0;
		if (limx<=limy){
			x=x+b*limx;
			y=y-a*limx;
		}
	}
	else {
		ll limn=ceil((double)(n-x-y)/(b-a));
		if (limn<=limy&&limx<=limy){
			x=x+b*limy;
			y=y-a*limx;
		}
		else return printf("-1\n"),0;
	}
	if (x<0||y<0) return printf("-1\n"),0;
	if (x+y>n) return printf("-1\n"),0;
	cout<<n-x-y<<" "<<x<<" "<<y<<endl;
	fclose(stdin); fclose(stdout);
	return 0;
}
