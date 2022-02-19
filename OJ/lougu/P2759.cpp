#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
ll n;
int main(){
	scanf("%lld",&n);
	ll l=1,r=1e18,mid;
	while (l<r){
//		cout<<l<<" "<<r<<endl;
		mid=(l+r)>>1;
		if (mid*log10(mid)+1<n) l=mid+1;
		else r=mid;
	}
	printf("%lld\n",l);
	return 0;
}
