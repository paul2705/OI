#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int MAXN=3e6+5;
int id1[MAXN],id2[MAXN];
ll n,Sq,w[MAXN],cnt;
ll pri[MAXN];
bool use[MAXN];
ll g[MAXN],h[MAXN],sp[MAXN];
// g(p)=i; h(p)=1; 
// g(x,j)=g(x,j-1)-f(p_j)*(g(x/p_j,j-1)-\sum_{i=1}^{j-1]f(p_i))
// S(x,j)=g(x,|P|)-h(x,|P|)-\sum_{i=1}^{j-1}f(p_i)+\sum_{i>=j)\sum_e(f(p_i^e)*S(x/(p_i^e),i+1)+f(p_i^{e+1})
ll S(ll x,int y){
	if (x<=1||pri[y]>x) return 0;
//	cout<<x<<" "<<y<<endl;
	int k=(x<=Sq?id1[x]:id2[n/x]);
	ll ret=(g[k]-h[k]-sp[y-1]+(y-1))%mod;
	if (y==1) ret=(ret+2)%mod;
	for (int i=y;i<=pri[0]&&pri[i]*pri[i]<=x;i++){
		ll t1=pri[i],t2=pri[i]*pri[i];
		for (int e=1;t2<=x;e++,t1=t2,t2*=pri[i]){
			ret=(ret+(pri[i]^e)%mod*S(x/t1,i+1)%mod+(pri[i]^(e+1))%mod)%mod;
		}
	}
	return (ret%mod+mod)%mod;
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
	scanf("%lld",&n);
	Sq=sqrt(n);
	for (int i=2;i<=Sq;i++){
		if (!use[i]){
			pri[++pri[0]]=i;
			sp[pri[0]]=(sp[pri[0]-1]+(ll)i)%mod;
		}
		for (int j=1;j<=pri[0]&&pri[j]*i<=Sq;j++){
			use[i*pri[j]]=1;
			if (i%pri[j]==0) break;
		}
	}
	ll inv2=mod_pow(2,mod-2);
	for (ll i=1,j=1;i<=n;i=j+1){
		j=n/(n/i); w[++cnt]=n/i;
		if (w[cnt]<=Sq) id1[w[cnt]]=cnt;
		else id2[n/w[cnt]]=cnt;
		g[cnt]=w[cnt]%mod*(w[cnt]+1)%mod*inv2%mod;
		g[cnt]=(g[cnt]+mod-1)%mod;
		h[cnt]=(w[cnt]-1)%mod;
	}
	for (int j=1;j<=pri[0];j++){
		for (int i=1;i<=cnt&&pri[j]*pri[j]<=w[i];i++){
			int k=w[i]/pri[j]<=Sq?id1[w[i]/pri[j]]:id2[n/(w[i]/pri[j])];
			g[i]=(g[i]-pri[j]*g[k]%mod+pri[j]*sp[j-1]%mod)%mod;
			g[i]=(g[i]+mod)%mod;
			h[i]=(h[i]-h[k]+j-1)%mod; h[i]=(h[i]+mod)%mod;
		}
	}
	printf("%lld\n",(S(n,1)+1)%mod);
	return 0;
}
