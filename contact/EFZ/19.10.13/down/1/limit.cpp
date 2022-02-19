#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
const ll mod=998244353;
const int MAXN=1e5+5;
int a[MAXN],n,m,K;
int cnt;
ll inv[MAXN],fac[MAXN],rfac[MAXN];
ll f[3][MAXN];
ll mod_pow(ll x,ll n){
	ll ret=1;
	while (n){
		if (n&1) ret=ret*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return ret;
}
void solve1(){

}
void solve2(){
	int lim=floor((double)cnt/K);
	f[0][0]=1; 
//	cout<<lim<<endl;
	for (int i=1;i<=m;i++){
		int cur=i&1; int old=cur^1;
		for (int j=0;j<=cnt;j++) f[cur][j]=0;
		for (int j=0;j<=cnt;j++){
			for (int k=0;k<=lim;k++){
				if (j+k<=cnt){
					f[cur][j+k]=(f[cur][j+k]+f[old][j]*rfac[k]%mod)%mod;
				}
			}
		}
//		for (int j=0;j<=cnt;j++) cout<<i<<" "<<j<<" "<<f[cur][j]<<endl;
	}
	ll ans=f[m&1][cnt]*fac[cnt]%mod;
	ans=ans*mod_pow(m,n-cnt)%mod;
	printf("%lld\n",(ans%mod+mod)%mod);
}
void solve3(){
	ll ans=1,tmp=m;
//	cout<<cnt<<endl;
	for (int i=1;i<=n;i++){
		if (a[i]==1){
			ans=ans*tmp%mod;
			tmp--;
		}
		else {
			ans=ans*(m-tmp)%mod;
		}
	}
	printf("%lld\n",(ans%mod+mod)%mod);
}
int main(){
	freopen("limit.in","r",stdin);
	freopen("limit.out","w",stdout);
	scanf("%d%d%d",&n,&m,&K);
	for (int i=1;i<=n;i++){
		char c=getchar(); while (c!='0'&&c!='1') c=getchar();
		int x=c=='1';
		a[i]=x; cnt+=x;
	}
	inv[1]=1;
	for (int i=2;i<=max(n,m);i++){
		inv[i]=(mod-(mod/i)*inv[mod%i]%mod)%mod;
//		cout<<i<<" "<<inv[i]<<endl;
	}
	fac[0]=rfac[0]=1;
	for (int i=1;i<=max(n,m);i++){
		fac[i]=fac[i-1]*i%mod;
		rfac[i]=rfac[i-1]*inv[i]%mod;
	}
//	if (n<=100&&m<=3) solve1();
	/*else*/ if (K!=cnt) solve2();
	else solve3();
	fclose(stdin); fclose(stdout);
	return 0;
}
