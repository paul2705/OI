#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
const ll mod=998244353;
const int MAXN=4e5+5;
int n,m;
ll K;
int a[MAXN];
ll cnt[MAXN],ret[MAXN],ans[MAXN];
ll cnta[MAXN],pw[MAXN];
ll fac[MAXN],inv[MAXN],rfac[MAXN];
int pri[MAXN],mu[MAXN];
bool use[MAXN];
ll C(ll n,ll m){
	if (n<m) return 0;
	return fac[n]*rfac[m]%mod*rfac[n-m]%mod;
}
ll mod_pow(ll x,ll n){
	ll ret=1;
	while (n){
		if (n&1) ret=ret*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return ret;
}
int main(){
	scanf("%d%d%lld",&n,&m,&K);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	mu[1]=1;
	for (int i=2;i<=max(m,n);i++){
		if (!use[i]){
			pri[++pri[0]]=i;
			mu[i]=-1;
		}
		for (int j=1;j<=pri[0]&&i*pri[j]<=max(m,n);j++){
			int tmp=i*pri[j];
			use[tmp]=1; 
			if (i%pri[j]==0){
				mu[tmp]=0;
				break;
			}
			else mu[tmp]=-mu[i];
		}
	}
	for (int i=1;i<=max(m,n);i++) use[i]=0;
	inv[1]=1;
	for (int i=2;i<=max(m,n);i++){
		inv[i]=(mod-(mod/i)*inv[mod%i]%mod)%mod;
	}
	fac[0]=fac[1]=rfac[0]=rfac[1]=1;
	for (int i=2;i<=max(m,n);i++){
		fac[i]=fac[i-1]*i%mod;
		rfac[i]=rfac[i-1]*inv[i]%mod;
	}
	if (!K){
		for (int i=1;i<=m;i++){
			if (use[i]) continue;
			int tmp=floor((double)m/i);
			for (int j=1;j<=tmp;j++){
				ll res=floor((double)m/(double)(j*i));
				ret[j]=mod_pow(res,n);
			}
			for (int j=1;j<=tmp;j++){
				for (int k=1;k*i*j<=m;k++){
					ans[i*j]=(ans[i*j]+mu[k]*ret[k*j]%mod)%mod;
				}
				use[i*j]=1; ans[i*j]=(ans[i*j]%mod+mod)%mod;
			}
		}
		for (int i=1;i<=m;i++) printf("%lld ",ans[i]);
		printf("\n");
//		ll sum=0;
//		for (int i=1;i<=m;i++) sum=(sum+ans[i])%mod;
//		printf("%lld\n",sum);
		return 0;
	}
	for (int i=1;i<=m;i++){
		if (use[i]) continue;
		int tmp=floor((double)m/i);
		for (int j=1;j<=n;j++){
			for (int k=1;k<=tmp;k++){
				if (a[j]%(k*i)==0) cnta[k]++;
			}
		}
		for (int j=1;j<=tmp;j++){
			ll res=floor((double)m/(double)(j*i));
			ll tmp2=cnta[j];
			ll tmp1=mod_pow(res,n-tmp2);
			ret[j]=0;
			for (int k=0;k<=min(tmp2,n-K);k++){
				ret[j]=(ret[j]+C(tmp2,k)*tmp1%mod*mod_pow(res-1ll,tmp2-k)%mod)%mod;
			}
		}
		for (int j=1;j<=tmp;j++){
			for (int k=1;k*j*i<=m;k++){
				ans[i*j]=(ans[i*j]+mu[k]*ret[k*j]%mod)%mod;
			}
			use[i*j]=1; ans[i*j]=(ans[i*j]%mod+mod)%mod;
		}
	}
	for (int i=1;i<=m;i++) printf("%lld ",ans[i]);
	printf("\n");
//	ll sum=0;
//	for (int i=1;i<=m;i++) sum=(sum+ans[i])%mod;
//	printf("%lld\n",sum);
	return 0;
}
