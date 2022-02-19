#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e3+5;
const ll mod=1e9+7;
ll f[MAXN][MAXN];
ll n,m,k;
ll invab,invb,y;
ll exgcd(ll a,ll b,ll& x,ll& y){
	if (b==0){
		x=1,y=0;
		return a;
	}
	ll ret=exgcd(b,a%b,x,y);
	ll tmp=x;
	x=y;
	y=tmp-(a/b)*y;
	return ret;
}
ll dp(ll a,ll b){
//	cout<<a<<" "<<b<<endl;
	if (b>=k) return b%mod;
	if (f[a][b]>=0) return f[a][b];
	ll ans=0;
	if (a+b>=k){
		ans=(a+b+n*invb)%mod;
		return f[a][b]=ans;
	}
	ans=(dp(a+1,b)*n%mod*invab%mod+dp(a,b+a)*m%mod*invab%mod)%mod;
	return f[a][b]=ans;
}
int main(){
	scanf("%lld%lld%lld",&k,&n,&m);
	for (int i=0;i<=k;i++){
		for (int j=0;j<=k;j++) f[i][j]=-1;
	}
	ll d=exgcd(n+m,mod,invab,y); invab=(invab%mod+mod)%mod;
	d=exgcd(m,mod,invb,y); invb=(invb%mod+mod)%mod;
	printf("%lld\n",dp(1,0)%mod);
	return 0;
}
