#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll MAXN=5e5+5;
ll n,w,a[MAXN],b[MAXN];
ll ans;
ll f(ll i,ll j){
	return min(a[n]-a[n-j],b[n]-b[n-i+j])-i*w;
}
int main(){
	scanf("%lld%lld",&n,&w);
	for (ll i=1;i<=n;i++) scanf("%lld",&a[i]),a[i]+=a[i-1];
	for (ll i=1;i<=n;i++) scanf("%lld",&b[i]),b[i]+=b[i-1];
	if (b[n]<a[n]){
		for (ll i=1;i<=n;i++) swap(a[i],b[i]);
	}
	for (ll i=1;i<=2*n;i++){
//		for (ll j=1;j<=i;j++){
//			ans=max(ans,min(a[n]-a[n-j],b[n]-b[n-i+j])-i*w);
//			cout<<i<<" "<<j<<" "<<min(a[n]-a[n-j],b[n]-b[n-i+j])-i*w<<endl;
//		}
		ll l=1,r=i,mid,mmid;
		while (l+1<r){
			mid=(l+r)>>1;
			mmid=(mid+r)>>1;
			if (f(i,mmid)>f(i,mid)) l=mid;
			else r=mmid;
		}
		ans=max(ans,max(f(i,l),f(i,r)));
	}
	printf("%lld\n",ans);
	return 0;
}
