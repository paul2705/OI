#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll inf=3e18;
const int MAXN=3e6+6;
ll a[MAXN],b[MAXN];
int n;
ll ans=-inf;
int main(){
	freopen("1.in","r",stdin);
	freopen("1_bl.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for (int i=1;i<=n;i++) scanf("%lld",&b[i]);
	for (int i=1;i<=n;i++){
		ll sum=0,mn=inf;
		for (int j=i;j<=n;j++){
			mn=min(mn,a[j]);
			sum+=b[j];
//			cout<<mn<<" "<<sum<<" "<<mn*sum<<endl;
			ans=max(ans,mn*sum);
		}
	}
	printf("%lld\n",ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
