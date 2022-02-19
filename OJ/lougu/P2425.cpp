#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN=1e5+5;
typedef long long ll;
ll n,x,d[MAXN];
bool check(ll x,ll a){
	ll now=0;
	while (a>0){
		d[++now]=a%x;
		a/=x;
	}
	int l=1,r=now;
	for (;l<=r;l++,r--){
		if (d[l]!=d[r]) return 0;
	}
	return 1;
}
int main(){
	scanf("%lld",&n);
	for (ll i=0,x;i<n;i++){
		scanf("%lld",&x);
		ll y=(ll)sqrt((double)x)+1; bool f=0;
		for (ll j=2;j<=y;j++){
			if (check(j,x)){
				printf("%lld\n",j);
				f=1;
				break;
			}
		}
		if (f) continue;
		for (ll j=x/y-1;j>=0;j--){
			if (x%j==x/j){
				printf("%lld\n",j);
				f=1;
				break;
			}
		}
		if (f) continue;
		printf("%lld\n",x+1);
	}
	return 0;
}
