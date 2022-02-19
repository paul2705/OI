#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=2e2+5;
ll f[MAXN][MAXN],g[MAXN][MAXN];
ll n,m,p,dp[MAXN][MAXN];
ll inv[MAXN];
int main(){
	scanf("%lld%lld",&n,&p);
	inv[1]=1;
	for (int i=2;i<=n;i++){
		inv[i]=(p-inv[p%i]*(p/i)%p)%p;
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=i;j++){
			dp[i][j]=(dp[i][j]*(j-1)%p*inv[i]%p+dp[i-1][j]*(i-j)%p*inv[i]%p)%p;
		}
	}
	
