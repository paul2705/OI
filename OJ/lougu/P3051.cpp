#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1e5+5;
long long a[MAXN],b[MAXN],c[MAXN];
long long  n,ans;
int main(){
	scanf("%lld",&n);
	for (int i=1;i<=n;i++) scanf("%lld%lld",&a[i],&b[i]);
	for (int i=1;i<=n;i++) c[i]=c[i-1]+a[i]-b[i];
	sort(c+1,c+n+1);
	int mid=c[(n+1)>>1];
	for (int i=1;i<=n;i++) ans+=abs(c[i]-mid);
	printf("%lld\n",ans);
	return 0;
}
