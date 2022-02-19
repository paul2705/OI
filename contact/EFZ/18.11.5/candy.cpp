#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
typedef long long ll;
ll n,m,c[MAXN],T;
struct rec{
	ll a,b;
} a[MAXN];
bool cmp(rec a,rec b){ return min(a.a,b.b)<min(a.b,b.a); }
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	scanf("%lld",&T);
	while (T--){
		scanf("%lld",&n);
		for (int i=1;i<=n;i++) scanf("%lld%lld",&a[i].a,&a[i].b);
		sort(a+1,a+n+1,cmp);
		c[1]=a[1].a+a[1].b;
		ll mx=c[1],s=a[1].a;
		for (int i=2;i<=n;i++){
			s+=a[i].a;
			c[i]=max(c[i-1],s)+a[i].b;
			mx=max(mx,c[i]);
		}
		printf("%lld\n",mx);
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
