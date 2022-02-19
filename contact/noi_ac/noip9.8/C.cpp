#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=50+5;
const int mod=1e9+7;
int a[MAXN],n,pw[MAXN*MAXN],C[MAXN*MAXN][MAXN*MAXN];
int cnt[MAXN*MAXN],ret[MAXN*MAXN];
void solve(){
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++) cnt[a[i]]++;
	cnt[a[n]+1]=-1; int res=0;
	for (int i=1;cnt[i]!=-1;i++) if (!cnt[i]) ret[++res]=i;
	
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++) scanf("%d",&a[i]);
	pw[0]=1;
	for (int i=1;i<=n*n;i++) pw[i]=pw[i-1]*2%mod;
	for (int i=1;i<=n*n;i++){
		C[i][0]=C[i][i]=1;
		for (int j=1;j<i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	bool f=1;
	for (int i=1;i<n;i++) if (a[i]!=i) f=0;
	if (f) printf("%lld\n",(ll)C[n*(n-1)/2][n-1]*pw[n*(n-1)/2-n+1]%mod);
	else solve();
	return 0;
}
