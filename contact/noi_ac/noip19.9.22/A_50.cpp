#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod=998244353;
ll n,m,k,ans;
int main(){
	scanf("%lld%lld%lld",&n,&m,&k);
	if (k==1){
		if (n%m!=0) ans=1;
		else ans=0;
	}
	if (k==2){
		if (n%m==0) ans=n-n/m;
		else ans=n-n/m*2;
	}
	if (k==3){
		ans=n*(n-3)/2ll+1;
		cout<<ans<<endl;
		ll tmp=n/m;
		cout<<tmp<<endl;
		if (n%m==0) ans-=tmp*tmp;
		if (n%m!=0) ans-=tmp*(tmp-1)*6ll+tmp*3ll;
		cout<<ans<<endl;
		if (n%m==0) ans-=n*tmp+(1-m)*(1+tmp)*tmp/2-tmp*tmp;
		else ans-=n*tmp+(2-m)*(1+tmp)*tmp/2-2*tmp*tmp;
		cout<<ans<<endl;
	}
	printf("%lld\n",ans);
	return 0;
}
