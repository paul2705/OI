#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
typedef long long ll;
ll n,a[MAXN],q[MAXN],sum[MAXN],f[MAXN],ans,tail;
int main(){
	scanf("%lld",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	n++;a[n]=0;
	for (int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		while (a[q[tail]]>a[i]){
			f[q[tail]]+=sum[i-1]-sum[q[tail]];
			tail--;
		}
		f[i]=sum[i]-sum[q[tail]];
		q[++tail]=i;
	}
	for (int i=1;i<=n-1;i++) ans=max(ans,f[i]*a[i]);
	printf("%lld",ans);
	return 0;
}
