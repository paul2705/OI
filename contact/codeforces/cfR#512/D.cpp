#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,m,k;
ll gcd(ll a,ll b){ return b==0?a:gcd(b,a%b); }
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	cin>>n>>m>>k;
//	cout<<n<<" "<<m<<" "<<k<<endl;
	ll d=gcd(n*m,k);
	if (k==1) return printf("NO\n"),0;
	if (k/d!=2&&k!=d) return printf("NO\n"),0;
	cout<<"YES"<<endl;
	if (k/d==2){
		ll d1=gcd(n,d);
		ll d2=gcd(m,d);
		if (d1*d2>d){ ll d3=gcd(d1,d2); d1/=d3; }
		n/=d1,m/=d2;
		cout<<0<<" "<<0<<endl;
		cout<<n<<" "<<0<<endl;
		cout<<0<<" "<<m<<endl;
	}
	else {
		ll d1=gcd(n,k);
		ll d2=gcd(m,k);
		if (d1*d2>d) {ll d3=gcd(d1,d2); d1/=d3;}
		n/=d1,m/=d2;
		cout<<0<<" "<<0<<endl;
		if (d1<d2){
			cout<<n<<" "<<0<<endl;
			cout<<0<<" "<<(ll)m*2<<endl;
		}
		else {
			cout<<(ll)2*n<<" "<<0<<endl;
			cout<<0<<" "<<m<<endl;
		}
	}
	return 0;
}
