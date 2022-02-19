#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
struct matx{
	ll a[3][3];
	ll sum2(){
		return (a[2][1]+a[2][2])%mod;
	}
	ll sum1(){
		return (a[1][1]+a[1][2])%mod;
	}
	void clr(){
		for (int i=1;i<=2;i++){
			for (int j=1;j<=2;j++) a[i][j]=0;
		}
	}
	void prt(){
		for (int i=1;i<=2;i++){
			for (int j=1;j<=2;j++) cout<<a[i][j]<<" ";
			cout<<endl;
		}
	}
};
ll n,m,k;
matx mul(matx a,matx b){
	matx c; c.clr();
	for (int k=1;k<=2;k++){
		for (int i=1;i<=2;i++){
			for (int j=1;j<=2;j++){
				c.a[i][j]=(c.a[i][j]+a.a[i][k]*b.a[k][j]%mod)%mod;
			}
		}
	}
	return c;
}
matx mod_pow(matx a,ll n){
	if (n==1) return a;
	matx ret; ret=a; n--;
	while (n){
		if (n&1) ret=mul(ret,a);
		a=mul(a,a);
		n>>=1;
	}
	return ret;
}
ll mod_po1(ll x,ll n){
	if (n==1) return x;
	ll ret=x; n--;
	while (n){
		if (n&1) ret=(ret*x)%mod;
		x=x*x%mod;
		n>>=1;
	}
	return ret;
}	
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	ll len1=k-1,len2=m-k+1;
	if (k>m) len1=m*2-k+1,len2=k-m-1;
	matx x;
	x.a[1][1]=len1-1; x.a[1][2]=len2;
	x.a[2][1]=len1; x.a[2][2]=len2;
	x=mod_pow(x,n);
//	x.prt();
//	cout<<x.sum2()<<" "<<x.sum1()<<endl;
	printf("%lld\n",(x.sum2()+mod)%mod);
//	if (k>m) printf("%lld\n",(x.sum1()+mod)%mod);
	fclose(stdin); fclose(stdout);
	return 0;
}
