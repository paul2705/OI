#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
typedef long long ll;
ll f[MAXN],a[MAXN],q[MAXN],l,r,s;
int n,k;
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	l=0,r=0;
	for (int i=1;i<=n;i++){
		f[i]=f[q[l]]+a[i]; s+=a[i];
		while (l<r&&i-q[l]>k) l++;
		while (l<r&&f[q[r-1]]>=f[i]) r--;
		q[r++]=i;
	}
	ll ans=0;
	for (int i=n-k;i<=n;i++) ans=max(ans,s-f[i]);
	printf("%lld\n",ans);
	return 0;
}
