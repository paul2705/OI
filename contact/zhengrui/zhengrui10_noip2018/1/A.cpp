#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a,b,c,n,ans;
int main(){
	scanf("%lld",&n);
	for (a=0;3*(a+1)*a+1<=n;a++); 
	a--;
	b=3*(a+1)*a+1;
	a++; ans=6*a; c=n-b;
	if (c==0) return printf("%lld\n",ans),0;
	ans++; c-=a-1;
	if (c>0) ans+=(c+a-1)/a;
	printf("%lld\n",ans);
	return 0;
}
