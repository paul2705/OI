#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
ll ans[MAXN],cnt;
ll n;
int main(){
	scanf("%lld",&n);
	for (ll i=1;i*i<=n;i++){
		if (n%i==0){
			ll k=(n-1)/i;
			ans[cnt++]=(k+1)*k*i/2ll+k+1ll;
			if (i*i==n) continue;
			k=(n-1)/(n/i);
			ans[cnt++]=(k+1)*k*(n/i)/2ll+k+1ll;
		}
	}
	sort(ans,ans+cnt);
	for (int i=0;i<cnt;i++) printf("%lld ",ans[i]);
	return 0;
}
