#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int MAXN=1e5+5;
int n;
struct rec{
	ll x,id;
} a[MAXN],b[MAXN];
bool cmps(rec a,rec b){ return a.x<b.x; }
bool cmpl(rec a,rec b){ return a.x>b.x; }
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i].x),a[i].id=i;
	for (int i=1;i<=n;i++) scanf("%lld",&b[i].x),b[i].id=i;
	sort(a+1,a+n+1,cmpl); 
	sort(b+1,b+n+1,cmpr);
	for (int i=1;i<=n;i++) printf("%lld ",a[i].id);
	cout<<endl;
	for (int i=1;i<=n;i++) printf("%lld ",b[i].id);
	cout<<endl;
	ll ans=0;
	for (int i=1;i<=n;i++) ans=(ans+a[i].x*b[i].x%mod)%mod;
	printf("%lld\n",ans);
	return 0;
}
