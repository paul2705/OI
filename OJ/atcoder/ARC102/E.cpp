#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod=998244353;
const int MAXN=4e3+5;
int k,n;
ll inv[MAXN],fac[MAXN],rfac[MAXN];
ll pow[MAXN];
ll C(int n,int m){
	if (n<m) return 0;
	return fac[n]*rfac[m]%mod*rfac[n-m]%mod;
}
ll f(int x,int y,int z){
	ll ret=0;
	for (int i=0;i<=z&&i<=x;i++){
		if (i+y-1>z+y-1||i+y-1<0) continue;
		ret=(ret+C(x,i)*pow[i]%mod*C(z+y-1,i+y-1)%mod)%mod;
	}
	return ret;
}
int main(){
	scanf("%d%d",&k,&n);
	inv[1]=1;
	for (int i=2;i<=4e3;i++){
		inv[i]=(mod-(mod/i)*inv[mod%i]%mod)%mod;
	}
	pow[0]=fac[0]=rfac[0]=1;
	for (int i=1;i<=4e3;i++){
		fac[i]=fac[i-1]*i%mod;
		rfac[i]=rfac[i-1]*inv[i]%mod;
		pow[i]=pow[i-1]*2ll%mod;
//		cout<<i<<" "<<fac[i]<<" "<<rfac[i]<<" "<<pow[i]<<endl;
	}
	for (int i=2;i<=2*k;i++){
		int cnt=0;
		for (int j=1;j<=k;j++){
			if (i-j<=k&&i-j>=1) cnt++;
		}
//		cout<<i<<" "<<cnt<<endl;
		if (i%2==0) printf("%lld\n",(f((cnt-1)/2,k-cnt,n)+f((cnt-1)/2,k-cnt,n-1))%mod);
		else printf("%lld\n",f(cnt/2,k-cnt,n)%mod);
	}
	return 0;
}
