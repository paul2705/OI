#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
ll n,m;
ll ans,sq;
int main(){
	scanf("%lld%lld",&n,&m); n++; m++;
	for (ll i=1ll;i<=n;i++){
		for (ll j=i+1ll;j<=n;j++){
			ans+=(ll)m*(m-1ll)/2ll;
			sq+=max(m-(j-i),0ll);
//			if (i<=1)cout<<i<<" "<<j<<" "<<ans<<" "<<sq<<endl;
		}
	}
	printf("%lld %lld\n",sq,ans-sq);
	return 0;
}
