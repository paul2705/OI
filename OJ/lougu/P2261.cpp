#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,k,ans;
int main(){
	freopen("P2261.in","r",stdin);
	freopen("P2261.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	ans=n*k;
	for (ll i=1;i*i<=k;i++){
//		cout<<"in: "<<i<<" "<<floor((double)k/i)<<" "<<floor((double)k/(i+1))+1<<endl;
		ll l=floor((double)k/(i+1))+1,r=floor((double)k/i);
		if (l>n) l=r+1;
		else if (r>n) r=n;
		if (l*l<=k) l=floor(sqrt(k))+1;
		if (i<=n) ans-=i*(ll)floor((double)k/i);
		if (l>r) continue;
//		cout<<i<<" "<<l<<" "<<r<<endl;
//		cout<<(l+r)*(r-l+1)/2<<endl;
		ans-=i*(l+r)*(r-l+1)/2ll;
	}
	printf("%lld\n",ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
