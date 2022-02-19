#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
ll a[MAXN],b[MAXN];
int n;
ll k;
bool check(ll mid){
	ll ret=0;
	for (int i=1;i<=n;i++){
		ll tmp=mid/b[i];
		if (a[i]>tmp) tmp=a[i]-tmp;
		else tmp=0;
		ret+=tmp;
	}
	return ret<=k;
}
bool cmp(ll a,ll b){ return a>b; }
int main(){
	scanf("%d%lld",&n,&k);
	ll mx=0;
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for (int i=1;i<=n;i++) scanf("%lld",&b[i]);
	sort(a+1,a+n+1);
	sort(b+1,b+n+1,cmp);
	ll l=-1,r=1e12,mid;
	while (l+1<r){
		mid=(l+r)>>1;
		if (check(mid)) r=mid;
		else l=mid;
	}
	while (r>=1&&check(r-1)) r--;
	printf("%lld\n",r);
	return 0;
}
