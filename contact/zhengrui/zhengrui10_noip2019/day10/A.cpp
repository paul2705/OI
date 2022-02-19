#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
ll a[MAXN],ans;
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for (int i=1;i<n;i++) ans+=max(0ll,max(a[i],a[i+1]));
	printf("%lld\n",ans);
	for (int i=1;i<=m;i++){
		ll x,y; scanf("%lld%lld",&x,&y);
		if (x!=1){
			ans-=max(0ll,max(a[x],a[x-1]));
			ans+=max(0ll,max(a[x-1],y));
		}
		if (x!=n){
			ans-=max(0ll,max(a[x],a[x+1]));
			ans+=max(0ll,max(a[x+1],y));
		}
		a[x]=y;
		printf("%lld\n",ans);
	}
	return 0;
}
