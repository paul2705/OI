#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
ll n,k,sum;
double a[MAXN],l,r,mid,ans;
bool check(double t){
	ll sum=0;
	for (int i=1;i<=n;i++){
		double c=(sqrt(1+4*a[i]/t)-1)/2.0;
		sum+=ceil(c);
		if (sum>k) return 0;
	}
	return 1;
}
int main(){
	scanf("%lld%lld",&n,&k);
	for (int i=1;i<=n;i++) scanf("%lf",&a[i]);
	l=1e-9,r=12;
	while (r-l>1e-9){
		mid=(l+r)/2.0;
		if (check(mid)) r=mid;
		else l=mid;
	}
	for (int i=1;i<=n;i++){
		double c=(sqrt(1+4*a[i]/r)-1)/2.0;
		sum+=ceil(c);
		ans+=a[i]/ceil(c);
	}
	printf("%.0lf",ans-(k-sum)*r);
	return 0;
}
