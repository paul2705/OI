#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const ll H=29;
const int MAXN=1e6+6;
const int MAXS=3e6+6;
string s[MAXN];
ll a[MAXS],b[MAXS];
ll pre[MAXS],sur[MAXS];
ll p[MAXS],d[MAXS];
void manacher(ll a[],ll n){
	ll id=0,mx=1;
	for (ll i=1;i<=n;i++){
		d[i*2]=a[i]; d[i*2+1]=-1;
	}
	d[1]=-1; d[0]=-123; d[2*n+2]=-456;
	p[0]=1;
	for(ll i=1;i<=2*n+2;i++){
	  p[i]=(i<mx ? min(p[2*id-i],mx-i) : 1);
	  while (d[i-p[i]]==d[i+p[i]]) p[i]++;
	  if (i+p[i]>mx){
		  id=i;
		  mx=i+p[i];
	  }
	}
	for (ll i=1;i<=n;i++) p[i]=p[i*2+1]/2;
}
ll work(ll a[],ll n){
	ll k,ans=0;
	memset(pre,0,sizeof(pre));
	memset(sur,0,sizeof(sur));
	memset(p,0,sizeof(p));
	manacher(a,n);
	k=0;
	for (ll i=1;i<n;i++){
		if(i-p[i]<=k){
			k=i; 
			pre[i]=1;
		}
	}
	k=n;
	for (ll i=n-1;i>0;i--){
		if(i+p[i]>=k){
			k=i;
			sur[i]=1;
		}
	}
	k=1;
	for (ll i=1;i<n;i++){
		if (sur[i]) ans+=k;
		if (pre[i]) k++;
	}
	ans+=k;
	return ans;
}
int main(){
	ll n,m;
	scanf("%lld%lld",&n,&m);
	for (ll i=1;i<=n;i++)cin>>s[i];
	for (ll i=1;i<=n;i++){
		for (ll j=m;j>0;j--){
		  s[i][j]=s[i][j-1];
		}
	}
	for (ll i=1;i<=n;i++){
		for (ll j=1;j<=m;j++){
			a[i]=(1ll*a[i]*H%mod+(s[i][j]-'a'))%mod;
		}
	}
	for	(ll i=1;i<=m;i++){
		for (ll j=1;j<=n;j++){
			b[i]=(1ll*b[i]*H%mod+(s[j][i]-'a'))%mod;
		}
	}
	printf("%lld\n",1ll*work(a,n)*work(b,m));
	return 0;
}
