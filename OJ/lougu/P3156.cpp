#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
int a[MAXN],ans,n,s;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),s+=a[i];
	for (int i=1;i<=n;i++) a[i]-=s/n,a[i]+=a[i-1];
	sort(a+1,a+n+1);
	int o=n&1?a[(n+1)/2]:(a[n/2]+a[(n+1)/2])/2;
	for (int i=1;i<=n;i++) ans+=abs(a[i]-o);
	printf("%d\n",ans);
	return 0;
}
