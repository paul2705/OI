#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll inf=1e15;
const int MAXN=1e6+6;
ll a[MAXN],pri[MAXN];
ll n=1e6,T;
int main(){
	scanf("%lld",&T);
	for (ll i=1;i<=n;i++) a[i]=i*i+1ll,pri[i]=inf;
	for (ll i=1;i<=n;i++){
//		cout<<i<<" "<<a[i]<<endl;
		if (a[i]==1) continue;
		ll t=a[i]; pri[i]=min(pri[i],a[i]);
//		cout<<i<<" "<<pri[i]<<endl;
		for (ll j=i;j<=n;j+=t){
//			cout<<j<<" "<<a[j]<<" "<<t<<" "<<n<<endl;
			while (a[j]%t==0) a[j]/=t;
			pri[j]=min(pri[j],t);
		}
	}
	while (T--){
		ll x; scanf("%lld",&x);
		if (pri[x]==x*x+1) printf("-1\n");
		else printf("%lld %lld\n",pri[x],(x*x+1)/pri[x]);
	}
	return 0;
}
