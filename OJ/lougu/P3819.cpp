#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1e5+5;
typedef long long ll;
ll l,num,sum,ans;
int n,p;
struct rec{
	ll x,r;
} a[MAXN];
bool cmp(rec a,rec b){
	return a.x<b.x;
}
int main(){
	scanf("%lld%d",&l,&n);
	for (int i=1;i<=n;i++){
		scanf("%lld%lld",&a[i].x,&a[i].r);
		num+=a[i].r;
	}
	p=0;
	while (sum<num-sum){
		p++; sum+=a[p].r;
	}
	for (int i=1;i<=n;i++){
		ll ip=a[p].x-a[i].x;
		ans+=abs(ip)*a[i].r;
	}
	printf("%lld",ans);
	return 0;
}
