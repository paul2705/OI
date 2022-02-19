#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e6+6;
ll a[MAXN],n,ans,sum,ave;
int main(){
	scanf("%lld",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]),sum+=a[i]; ave=sum/n;
	for (int i=1;i<=n;i++) a[i]-=ave;
	for (int i=1;i<=n;i++) a[i]+=a[i-1];	
	sort(a+1,a+n+1);
	ll x=a[(n+1)>>1];
	for (int i=1;i<=n;i++) ans+=abs(a[i]-x);
	printf("%lld\n",ans);
	return 0;
}
