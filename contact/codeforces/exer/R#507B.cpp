#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
typedef long long ll;
ll n,k;
char s[100];
bool ask(ll l,ll r){
	cout.flush();
	cout<<l<<" "<<r<<endl;
	cin>>s;
	return s[0]=='Y';
}
bool ask_ans(ll x){
	cout.flush();
	cout<<x<<" "<<x<<endl;
	cin>>s;
	return s[0]=='Y';
}
int main(){
	srand(time(0));
	cin>>n>>k;
	ll l=1,r=n,mid;
//	if (n==1) return printf("1 1\n"),0;
	while (l<=r){
		if (r-l<=50){
			ll x=l+rand()%(r-l+1);
			if (ask_ans(x)) break;
		}
		else {
			mid=(l+r)>>1;
			if (ask(l,mid)) r=mid;
			else l=mid+1;
		}
		l=max(1ll,l-k); r=min(n,r+k);
	}
	return 0;
}
