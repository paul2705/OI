#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
const ll mod=998244353;
ll t[MAXN];
ll ans=0,n,m,a[MAXN];
void add(ll x,ll val){
	for (;x<=n;x+=x&-x) t[x]+=val;
}
ll sum(ll x){
	ll ret=0;
	for (;x>0;x-=x&-x) ret+=t[x];
	return ret;
}
int main(){
	freopen("station.in","r",stdin);
	freopen("station1.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for (ll i=1;i<=n;i++) scanf("%lld",&a[i]),add(i,a[i]);
	ll x=19260817%mod;
	ll ret=x;
	for (ll i=1;i<=m;i++){
		ll sx,sy;
		scanf("%lld%lld",&sx,&sy);
		add(sx,sy);
		ll s=sum(n);
		ll xx=(s+1)/2;
		ll l=1,r=n,mid;
		while (l+1<r){
			mid=(l+r)>>1;
			if (sum(mid)<xx) l=mid;
			else r=mid;
		}
//		cout<<r<<" "<<x<<endl;
		ans=(ans+r*ret%mod)%mod;
		ret=(ret*x)%mod;
	}
	printf("%lld\n",ans%mod);
	fclose(stdin); fclose(stdout);
	return 0;
}
