#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll p=1e9+7;
const int MAXN=4e4+5;
int pri[MAXN];
ll n,k;
bool use[MAXN];
int res[MAXN],cnt;
int T;
ll phi(ll x){
	ll ret=x;
	for (int i=0;i<cnt;i++){
		if (x%res[i]==0) ret=ret*(res[i]-1)/res[i]%p;
	}
	return ret;
}
ll mod_pow(ll x,ll n){
	ll ret=1;
	while (n){
		if (n&1) ret=ret*x%p;
		x=x*x%p;
		n>>=1;
	}
	return ret;
}
int main(){
	use[1]=1;
	for (int i=2;i<=4e4;i++){
//		cout<<i<<endl;
		if (!use[i]) pri[++pri[0]]=i;
//		cout<<pri[0]<<" "<<pri[1]<<endl;
		for (int j=1;j<=pri[0]&&pri[j]*i<=4e4;j++){
//			cout<<j<<" "<<pri[j]<<endl;
			use[pri[j]*i]=1;
			if (i%pri[j]==0) break;
		}
	}
//	scanf("%d",&T);
//	while (T--){
		scanf("%lld%lld",&n,&k);
		cnt=0;
		ll ans=0;
		for (int i=1;i<=pri[0]&&pri[i]<=n;i++){
			if (n%pri[i]==0) res[cnt++]=pri[i];
		}
		for (int i=1;i*i<=n;i++){
			if (i*i==n) ans=(ans+mod_pow(n,i-1)*phi(i)%p)%p;
			else if (n%i==0){
				ans=(ans+mod_pow(k,i)*phi(n/i)%p)%p;
				ans=(ans+mod_pow(k,n/i)*phi(i)%p)%p;
			}
		}
		ll inv=mod_pow(n,p-2);
		printf("%lld\n",ans*inv%p);
//	}
	return 0;
}

