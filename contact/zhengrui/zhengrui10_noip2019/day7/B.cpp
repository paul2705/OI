#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll inf=1e18;
ll n,a,b;
ll pw(int x,int y){
	if (y==0) return 1;
	if (y==1) return x;
	int mid=pw(x,y>>1);
	if (y&1) return (ll)mid*mid*x;
	return (ll)mid*mid;
}
int srt(int n,int m){
	int x=pow(n,1.0/m);
	while (pw(x,m)<n) x++;
	while (pw(x-1,m)>=n) x--;
	return x;
}
int solve(int n,int m){
	int x=srt(n,m);
	for (int k=m;k;k--){
		if (pw(x-1,k)*pw(x,m-k)>=n)
			return (ll)(x-1)*k+(ll)x*(m-k);
	}
	return (ll)m*x;
}
signed main(){	
	ll T; scanf("%lld",&T);
	while (T--){
		scanf("%lld%lld%lld",&n,&b,&a);
		if (n==1){
			puts("0");
			continue;
		}
		ll ans=inf;
		for (int i=1;(1<<(i-1))<=n;i++){
			ans=min(ans,(ll)a*(solve(n,i)-i)+(ll)i*b);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
