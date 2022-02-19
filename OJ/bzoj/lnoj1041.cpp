#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=25;
const int mod=1e9+7;
ll a[1<<MAXN],n,m;
ll mod_pow(ll n){
	ll x=2,ret=1; n%=mod;
	while (n){
		if (n&1) ret=(ret*x)%mod;
		x=(x*x)%mod;
		n>>=1;
	}
	return ret;
}
void ini(int l,int r){
	if (l+1==r) return a[l]=mod_pow(a[l]),void();
	int mid=(l+r)>>1;
	for (int i=l;i<mid;i++) a[mid+i-l]+=a[i];
	ini(l,mid); ini(mid,r);
	for (int i=l;i<mid;i++)
		a[mid+i-l]=((a[mid+i-l]-a[i])%mod+mod)%mod;
}
int main(){
	scanf("%lld%lld",&n,&m);
	for (int i=1,x;i<=n;i++){
		scanf("%d",&x); int res=0;
		for (int j=1,y;j<=x;j++){
			scanf("%d",&y); y--;
			res|=(1<<y);
		}
		a[res]++;
	}
	ini(0,(1<<m));
	printf("%lld\n",a[(1<<m)-1]);
	return 0;
}
