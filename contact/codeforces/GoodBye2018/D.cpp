#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e6+6;
const ll mod=998244353;
ll f[MAXN],fac=1;
ll n;
int main(){
	f[1]=1;
	scanf("%lld",&n);
	for (ll i=2;i<=n;i++){
		fac=fac*i%mod;
		f[i]=((f[i-1]-1)*i%mod+fac)%mod;
	}
	printf("%lld\n",(f[n]%mod+mod)%mod);
	return 0;
}
