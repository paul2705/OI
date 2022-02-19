#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll MAXN=5e2+5;
ll f[3][MAXN][MAXN];
ll n,m,a[MAXN][MAXN];
int main(){
	scanf("%lld%lld",&n,&m);
	for (ll i=1;i<=n;i++){
		for (ll j=1;j<=m;j++) scanf("%lld",&a[i][j]);
	}
//	memset(f,-1,sizeof(f));
	for (ll i=0;i<2;i++){
		for (ll j=1;j<=n;j++){
			for (ll k=1;k<=m;k++) f[i][j][k]=-1e9;
		}
	}
	f[2&1][1][1]=0;
	ll cur=0,old=1;
	for (ll k=3;k<n+m;k++){
		cur^=1,old^=1;
		for (ll i=1;i<=m;i++){
			for (ll j=i+1;j<=m;j++){
				ll mx=-1e9;
				mx=max(mx,f[old][i-1][j]);
				mx=max(mx,f[old][i][j]);
				mx=max(mx,f[old][i][j-1]);
				mx=max(mx,f[old][i-1][j-1]);
				if (mx==-1e9) continue;
				f[cur][i][j]=mx+a[k-i][i]+a[k-j][j];
			}
		}
	}
	printf("%lld\n",f[(n+m-1)&1][m-1][m]);
	return 0;
}
