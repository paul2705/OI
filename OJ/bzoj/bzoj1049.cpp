#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll MAXN=4e4+5;
const ll MAXM=MAXN*50;
ll a[MAXN],f[MAXN];
ll g[MAXN],mn[MAXN];
ll n,mx;
ll s1[MAXN],s2[MAXN];
ll edge,head[MAXN],nex[MAXM],tail[MAXM];
void add(ll u,ll v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
ll find(ll x){
	ll l=0,r=mx+1,mid;
	while (l+1<r){
		mid=(l+r)>>1;
		if (mn[mid]<=x) l=mid;
		else r=mid;
	}
	return l;
}
int main(){
	scanf("%lld",&n);
	for (ll i=1;i<=n;i++) scanf("%lld",&a[i]),a[i]-=i;
	a[++n]=1e9;
	memset(mn,63,sizeof(mn)); mn[0]=-1e9; mx=0;
	for (ll i=1;i<=n;i++){
		ll tmp=find(a[i]);	
		f[i]=tmp+1;
		mx=max(mx,f[i]);
		mn[f[i]]=min(mn[f[i]],a[i]);
	}
	printf("%lld ",n-f[n]);
	for (ll i=0;i<=n;i++){
		add(f[i],i);
		g[i]=1e18;
	}
	g[0]=0; a[0]=-1e9;
	for (ll i=1;i<=n;i++){
		for (ll e=head[f[i]-1];e;e=nex[e]){
			ll v=tail[e];
			if (v>i) break;
			if (a[v]>a[i]) continue;
			for (ll j=v;j<=i;j++) s1[j]=abs(a[j]-a[v]),s2[j]=abs(a[j]-a[i]);
			for (ll j=v+1;j<=i;j++) s1[j]+=s1[j-1],s2[j]+=s2[j-1];
			for (ll j=v;j<i;j++){
				g[i]=min(g[i],g[v]+s1[j]-s1[v]+s2[i]-s2[j]);
			}
		}
	}
	printf("%lld\n",g[n]);
	return 0;
}
