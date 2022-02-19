#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e6+6;
ll n;
ll a[MAXN],q[MAXN],miq[MAXN],miz[MAXN],ans=0;
int main(){
	scanf("%lld",&n);
	miq[0]=1e17;miz[n+1]=1e17;
	for (ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		q[i]=q[i-1]+a[i];
		miq[i]=min(q[i],miq[i-1]);
	}
	for (ll i=n;i>=1;i--) miz[i]=min(q[i],miz[i+1]);
	for (ll i=1;i<=n;i++) if (miz[i]-q[i-1]>=0&&miq[i-1]+q[n]-q[i-1]>=0) ans++;
	printf("%lld\n",ans);
	return 0;
}
