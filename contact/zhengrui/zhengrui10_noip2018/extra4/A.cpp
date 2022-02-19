#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll lim=1e18;
ll T,l,r,k;
int get(ll x){
	int ret=0;
	while (x){
		int d=x%10;
		ret+=d*d;
		x/=10;
	}
	return ret;
}
int main(){
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	scanf("%lld",&T);
	while (T--){
		scanf("%lld%lld%lld",&k,&l,&r);
		int ans=0;
		for (ll i=1;i<=9*9*18&&i<=lim/k;i++){
			ll x=i*k;
			if (x<l||x>r) continue;
			int s=get(x);
			if (i==s) ans++;
		}
		printf("%d\n",ans);
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
