#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll MAXN=15;
const ll MAXS=1<<15;
ll n,m,mp[MAXN][MAXN];
ll g[MAXN][MAXS];
ll w[MAXS];
ll f[MAXN][MAXS];
ll id[MAXS];
ll get(ll s1,ll s){
	ll ret=0;
	for (ll i=0;i<n;i++){
		if (!(s1&(1<<i))) continue;
		ret+=g[i+1][s];
	}
	return ret;
}
int main(){
	scanf("%lld%lld",&n,&m);
	for (ll i=1;i<=n;i++){
		for (ll j=1;j<=n;j++) mp[i][j]=1e9;
		for (ll s=0;s<(1<<n);s++) f[i][s]=g[i][s]=1e9;
	}
//	cout<<"fuck"<<endl;
	for (ll i=1,u,v,w;i<=m;i++){
		scanf("%lld%lld%lld",&u,&v,&w);
		mp[u][v]=mp[v][u]=min(mp[u][v],w);
	}
//	cout<<"fuck"<<endl;
	for (ll i=1;i<=n;i++){
		for (ll s=0;s<(1<<n);s++){
			for (ll j=0;j<n;j++){
				if (s&(1<<j)){
					g[i][s]=min(g[i][s],mp[i][j+1]);
				}
			}
		}
	}
//	cout<<"fuck"<<endl;
	for (ll i=1;i<=n;i++) id[1<<(i-1)]=i,f[1][1<<(i-1)]=0;
	for (ll i=2;i<=n;i++){
//		cout<<i<<endl;
		for (ll s=1;s<(1<<n);s++){
			ll s1=s^((1<<n)-1);
			w[s1]=get(s1,s);
//			cout<<w[s1]<<endl;
			f[i][s|s1]=min(f[i][s|s1],f[i-1][s]+w[s1]*(i-1));
			for (ll s2=(s1-1)&s1;s2;s2=(s2-1)&s1){
				w[s2]=w[s2|((s2^s1)&-(s2^s1))]-g[id[((s2^s1)&-(s2^s1))]][s];
				f[i][s|s2]=min(f[i][s|s2],f[i-1][s]+w[s2]*(i-1));
			}
		}
	}
	ll ans=f[1][(1<<n)-1];
	for (ll i=2;i<=n;i++) ans=min(ans,f[i][(1<<n)-1]);
	printf("%lld\n",ans);
	return 0;
}
