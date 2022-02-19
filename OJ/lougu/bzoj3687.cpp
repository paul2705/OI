#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<bitset>
using namespace std;
typedef long long ll;
const int MAXN=1e3+5;
bitset<2000000> f;
ll ans,n;
int main(){
	scanf("%lld",&n);
	f[0]=1;
	for (ll i=1,x;i<=n;i++){
		scanf("%lld",&x);
		f=(f<<x)^f;
	}
	for (ll x=2000000;x>=0;x--){
		if (f[x]==1) ans^=x;
	}
	printf("%lld\n",ans);
	return 0;
}
