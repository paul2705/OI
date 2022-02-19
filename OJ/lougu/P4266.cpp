#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
struct rec{
	ll x,c;
} a[MAXN];
ll n,rf,rb,l;
bool cmp(rec a,rec b){
	return a.c>b.c;
}
int main(){
	scanf("%lld%lld%lld%lld",&l,&n,&rf,&rb);
	ll t=rf-rb;
	for (int i=0;i<n;i++) scanf("%lld%lld",&a[i].x,&a[i].c);
	sort(a,a+n,cmp);
	long long ans=a[0].c*a[0].x*t;
	ll last=a[0].x;
	for (int i=1;i<n;i++){
		if (a[i].x>last){
			ans+=a[i].c*(a[i].x-last)*t;
			last=a[i].x;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
