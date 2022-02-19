#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
const ll mod=998244353;
int n,k;
ll ans,h[MAXN],pow[MAXN];
int s[MAXN];
map<ll,ll> mp;
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++){
		char c=getchar(); while (c<'a'||c>'z') c=getchar();
		s[i]=c-'a'+1;
	}
	h[0]=pow[0]=1;
	for (int i=1;i<=n;i++) pow[i]=pow[i-1]*27%mod;
	for (int i=1;i<=n;i++) h[i]=(h[i]*27+s[i])%mod;
	for (int i=1;i<=n;i++){
		int l=i,r=i+k-1;
		ll res=((h[r]-h[l]*pow[r-l]%mod)%mod+mod)%mod;
		mp[res]++;
		ans=max(ans,mp[res]);
	}
	printf("%lld\n",ans);
	return 0;
}
