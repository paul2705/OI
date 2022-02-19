#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod=998244353;
const int MAXN=1e5;
int n,m;
ll ans;
ll mod_pow(ll x,ll n){
	ll ret=1;
	while (n){
		if (n&1) ret=ret*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return ret;
}
ll a[MAXN];
ll gcd(ll a,ll b){ return b==0?a:gcd(b,a%b); }
void dfs(int d){
//	cout<<d<<endl;
	if (d>=n+1){
		ll res=a[1],mul=a[1];
//		cout<<"("<<res<<")";
		for (int i=2;i<=n;i++){
//			cout<<a[i]<<" ";
			res=gcd(res,a[i]);
			mul=mul*a[i]/gcd(mul,a[i]);
//			cout<<"("<<res<<")";
		}
//		cout<<": ";	cout<<mul<<" "<<res<<endl;
		ans=ans*mod_pow(mul,res)%mod;
		return;
	}
	for (int i=1;i<=m;i++){
		a[d]=i;
		dfs(d+1);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	ans=1;
//	cout<<gcd(4,2)<<endl;
	dfs(1);
//	cout<<gcd(4,gcd(4,gcd(2,2)))<<endl;
	printf("%lld\n",(ans%mod+mod)%mod);
	return 0;
}
