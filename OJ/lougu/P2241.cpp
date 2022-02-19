#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
ll n,m,ans,sq;
int main(){
	scanf("%lld%lld",&n,&m); n++; m++;
	for (ll i=1;i<=n;i++){
		sq+=max(n-i,0ll)*max(m-i,0ll);
	}
	ans=n*(n-1ll)/2ll*m*(m-1ll)/2ll-sq;
	printf("%lld %lld\n",sq,ans);
	return 0;
}
