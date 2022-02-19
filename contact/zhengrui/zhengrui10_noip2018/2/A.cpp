#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
ll a[MAXN],b[MAXN];
ll n,q;
int main(){
	scanf("%lld%lld",&n,&q);
	for (int i=1;i<=n;i++) scanf("%lld%lld",&a[i],&b[i]);
	for (int i=1;i<=q;i++){
		ll x=0,ans=0; scanf("%lld",&x);
		for (int i=1;i<=n;i++) ans=max(ans,a[i]*x*x+b[i]*x);
		printf("%lld\n",ans);
	}
	return 0;
}
