#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e3+5;
typedef long long ll;
const ll mod=998244353;
ll f[MAXN],F[MAXN];
ll n,ans;
int main(){
	freopen("A.in","r",stdin);
	freopen("A.ans","w",stdout);
	scanf("%lld",&n);
	f[0]=f[1]=1;
	for (int i=2;i<=n;i++) f[i]=(f[i-1]+f[i-2])%mod;
	for (int i=0;i<=n;i++){
		for (int j=0;j<=i;j++) F[i]=(F[i]+f[j]*f[i-j]%mod)%mod;
		ans=(ans+F[i])%mod;
	}
	printf("%lld\n",(ans%mod+mod)%mod);
	fclose(stdin); fclose(stdout);
	return 0;
}
