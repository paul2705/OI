#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int MAXN=16;
int a[MAXN],p[MAXN];
int n,K;
ll ans;
void dfs(int d){
	if (d==K){
		for (int i=0;i<=n;i++){
//			cout<<p[i]<<" ";
			if (p[i]) ans=(ans+i)%mod;
		}
//		cout<<endl;
		return;
	}
	for (int i=1;i<=n;i++){
		int tmp=p[i],tmp1=p[i-1];
		p[i-1]|=p[i]; p[i]=0;
		dfs(d+1);
		p[i-1]=tmp1; p[i]=tmp;
	}
}
ll mod_pow(ll x,int n){
	ll ret=1;
	while (n){
		if (n&1) ret=ret*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return ret;
}
int main(){
	scanf("%d%d",&n,&K);
	for (int i=0;i<=n;i++) p[i]=1;
	dfs(0);
	ll x=mod_pow(n,K);
	ll inv=mod_pow(x,mod-2);
	cout<<ans<<" "<<inv<<endl;
	printf("%lld\n",ans*inv%mod);
	return 0;
}
