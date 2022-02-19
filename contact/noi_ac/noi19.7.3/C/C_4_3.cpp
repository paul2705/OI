#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
typedef long long ll;
const int MAXN=66;
ll n,K,A[MAXN],w[MAXN],cnt[MAXN];
ll ans=0;
int main(){
	freopen("x4.in","r",stdin);
	scanf("%lld%lld",&n,&K);
	for (int i=1;i<=10;i++) scanf("%lld",&A[i]);
	for (int i=1;i<=n;i++) scanf("%lld%lld",&w[i],&cnt[i]);
	for (int i=1;i<=n;i++) scanf("%lld",&A[i]);
	for (int i=1;i<=n;i++){
		if (!A[i]) continue;
		ans+=w[i];
	}
	printf("%lld\n%lld\n",ans,K);
	return 0;
}
