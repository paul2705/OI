#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=505;
const ll mod=1e9+7;
int n,tot;
ll a[MAXN],b[MAXN],num[MAXN*2],g[MAXN],c[MAXN],inv[MAXN];
int main(){
	scanf("%d",&n);
	inv[1]=1;
	for (int i=2;i<=n;i++) inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod;
	for (int i=1;i<=n;i++){
		scanf("%lld%lld",&a[i],&b[i]);
		num[++tot]=a[i]; num[++tot]=b[i]+1;
	}
	sort(num+1,num+1+tot); tot=unique(num+1,num+1+tot)-num-1;
	for (int i=1;i<=n;i++){
		a[i]=lower_bound(num+1,num+1+tot,a[i])-num;
		b[i]=lower_bound(num+1,num+1+tot,b[i]+1)-num;
	}
	c[0]=1; g[0]=1;
	for (int j=1;j<tot;j++){
		ll l=num[j+1]-num[j];
		for (int i=1;i<=n;i++)
			c[i]=c[i-1]*(l+i-1)%mod*inv[i]%mod;
		for (int i=n;i>0;i--){
			if (a[i]>j||j+1>b[i]) continue;
			ll f=0,m=1,C=l;
			for (int p=i-1;p>=0;p--){
				ll t=C*g[p]%mod;
				f+=t; f%=mod;
				if (a[p]<=j&&j+1<=b[p]) C=c[++m];
			}
			g[i]+=f; g[i]%=mod;
		}
	}
	ll ans=0;
	for (int i=1;i<=n;i++) ans+=g[i],ans%=mod;
	printf("%lld\n",(ans+mod)%mod);
	return 0;
}

