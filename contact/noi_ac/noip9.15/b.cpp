#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e3+5;
typedef long long ll;
ll n,m,p;
ll ans,f[MAXN],fac=1;
ll mod_pow(int x,int n){
	ll ret=1;
	while (n){
		if (n&1) ret=x*ret%p;
		x=x*x%p;
		n>>=1;
	}
	return ret;
}
int main(){
	scanf("%lld%lld%lld",&n,&m,&p);
	for (int i=1;i<=m;i++) fac=fac*i%p;
	ans=(mod_pow(m,n)-fac%p*mod_pow(m,n-m)%p)%p;
	cout<<mod_pow(m,n)<<" "<<fac<<" "<<mod_pow(m,n-m)<<endl;
/*	f[m]=fac;
	for (int i=m+1;i<=n;i++){
		for (int l=1;l<=i-m;l++){
			f[i]=(f[i]+f[l]*fac)%p;
		}
		ans=(ans-f[i]+p)%p;
	}
*/	printf("%lld\n",(ans%p+p)%p);
	return 0;
}
