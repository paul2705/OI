#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod=998244353;
const int MAXN=1e6+6;
ll has,res[MAXN];
ll ans;
int n,top;
char s[MAXN],st[MAXN];
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
	scanf("%s",s+1);
	n=strlen(s+1);
	ll inv=mod_pow(29,mod-2);
	for (int i=1;i<=n;i++){
		if (top>0&&st[top]==s[i]){
			has=inv*(has-(ll)(st[top]-'a')-1ll)%mod;
			top--;
		}
		else {
			st[++top]=s[i];
			has=(has*29ll%mod+(ll)(st[top]-'a')+1ll)%mod;
		}
		has=(has%mod+mod)%mod;
		res[i]=has;
//		cout<<has<<endl;
	}
	sort(res,res+n+1);
	for (ll l=0,r=0;l<=n;l=r+1,r++){
		while (res[l]==res[r+1]) r++;
		ans+=(r-l+1ll)*(r-l)/2ll;
	}
	printf("%lld\n",ans);
	return 0;
}
