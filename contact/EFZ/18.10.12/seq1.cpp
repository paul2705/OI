#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=10;
const int MAXM=1e6+6;
const ll INF=1e18;
ll a[MAXN],n,f[2][MAXM],mod;
int main(){
	scanf("%lld",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	mod=a[1];
	for (int i=1;i<=n;i++){
		int cur=i&1,pre=cur^1;
		for (ll k=0;k<=mod;k++) f[cur][k]=INF;
		for (ll k=0;k<=mod;k++){
			ll x=a[i]*k%mod;
			ll val=a[i]*k;
			f[cur][k]=min(f[cur][k],f[pre][k]+val);
		}
	}

