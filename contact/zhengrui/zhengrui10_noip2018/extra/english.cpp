#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e3+5;
typedef long long ll;
const ll mod=1e9+7;
ll a[MAXN];
int n,m,op;
ll ans1,ans2;
int main(){
	scanf("%d%d",&n,&op);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for (int i=1;i<=n;i++){
		ll mx=a[i];
		for (int j=i;j<=n;j++){
			mx=max(mx,a[j]);
			ans1=(ans1+(a[i]^a[j])*mx)%mod;
			if ((a[i]^a[j])>mx) ans2=(ans2+mx)%mod;
		}
	}
	if (op==3) printf("%lld\n%lld",ans1,ans2);
	else if (op==2) printf("%lld\n",ans2);
	else if (op==1) printf("%lld\n",ans1);
	return 0;
}
