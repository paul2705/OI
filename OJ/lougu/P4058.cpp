#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAXN=2e5+5;
ll a[MAXN],h[MAXN],l,s,n;
bool check(ll x){
	ull cnt=0;
	for (int i=1;i<=n;i++){
		ull len=h[i]+a[i]*x;
		if (len>=l) cnt+=len;
	}
	return cnt>=s;
}
int main(){
	scanf("%lld%lld%lld",&n,&s,&l);
	for (int i=1;i<=n;i++) scanf("%lld",&h[i]);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	ll l=0,r=1e18,mid;
	while (l<=r){
		mid=(l+r)>>1;
		if (!check(mid)) l=mid+1;
		else r=mid-1;
	}
	printf("%lld\n",l);
	return 0;
}
