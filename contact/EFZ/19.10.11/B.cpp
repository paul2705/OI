#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,k,X,ans=0;
int T;
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%lld%lld%lld",&n,&k,&X);
		ll now=2;
		for (ll i=2;i*i<=n&&i<=k;i++){
			now=i;
			ll res=0,tmp=n;
			while (tmp){
				res+=tmp%i;
				tmp/=i;
			}
			if (res<=X) ans++;
		}
		ll l=1,r=1;
		while (r<=now){
			l=r+1;
			r=n/(n/l);
		}
		for (;l<=n&&l<=k;l=r+1ll){
			r=n/(n/l);
			if (r>k) r=k;
			if (r>n) r=n;
//			printf("%lld %lld %lld %lld\n",l,r,n/l,n/r);
			ll tmp=n/l;
			ll posl=(ll)ceil((double)(n-X)/tmp)+1ll;
			ll posr=(ll)floor((double)n/tmp)+1ll;
			posl=max(posl,l); posr=min(posr,r);
//			cout<<l<<" "<<posl<<" "<<posr<<" "<<r<<" "<<tmp*(posl-1)<<" "<<tmp*(posr-1)<<" "<<n-X<<endl;
			if (posl<=posr) ans+=(posr-posl+1ll);
		}
		if (k>=n&&n<=X) ans+=k-n;
		printf("%lld\n",ans);
		ans=0;
	}
	return 0;
}
