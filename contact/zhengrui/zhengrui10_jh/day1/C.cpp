#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=1e2+5;
typedef __int128 i128;
typedef pair<int,int> par;
typedef pair<i128,par> pxr;
typedef long long ll;
const ll mod=998244353;
i128 c[MAXN][MAXN];
int n,x,y,z,a[MAXN],lim[MAXN],sum;
ll fac[MAXN],rfac[MAXN],inv[MAXN];
ll f[MAXN][MAXN];
vector<pxr> lis;
ll C(int n,int m){
	if (m>n) return 0;
	return fac[n]*rfac[m]%mod*rfac[n-m]%mod;
}
ll rC(int n,int m){
	if (m>n) return 0;
	return fac[m]*fac[n-m]%mod*rfac[n]%mod;
}
ll dp(int col,int ub){
	for (int i=1;i<=n;i++){
		for (int j=0;j<=ub;j++) f[i][j]=0;
	}
	f[0][0]=1;
	for (int i=1;i<=n;i++){
		if (i==col){
			for (int j=0;j<=ub;j++) f[i][j]=f[i-1][j];
			continue;
		}
		for (int j=0;j<=lim[i];j++){
			for (int k=j;k<=ub;k++){
				f[i][k]=(f[i][k]+f[i-1][k-j]*C(a[i],j)%mod)%mod;
			}
		}
	}
	return f[n][ub];
}
ll calc(int i,int j){
	ll res=0;
	for (int k=0;k+z<=j&&k+j<=a[i]&&k<=y;k++){
		res=(res+C(a[i]-j,k)*C(sum-x-a[i]+j,y-k)%mod)%mod;
	}
	return res;
}
int main(){
	scanf("%d%d%d%d",&n,&x,&y,&z);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),sum+=a[i];
	inv[1]=1;
	for (int i=2;i<=sum;i++){
		inv[i]=(mod-(mod/i)*inv[mod%i]%mod)%mod;
	}
	fac[0]=rfac[0]=1;
	for (int i=1;i<=sum;i++){
		fac[i]=fac[i-1]*i%mod;
		rfac[i]=rfac[i-1]*inv[i]%mod;
	}
	c[0][0]=1;
	for (int i=1;i<=sum;i++){
		c[i][0]=c[i][i]=1;
		for (int j=1;j<i;j++){
			c[i][j]=c[i-1][j-1]+c[i-1][j];
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=z;j<=a[i]&&j<=x;j++){
			i128 res=0;
			for (int k=0;k+z<=j&&k<=y&&j+k<=a[i];k++){
				res+=c[a[i]-j][k]*c[sum-x-a[i]+j][y-k];
			}
			lis.push_back(make_pair(res,make_pair(i,j)));
		}
	}
	sort(lis.begin(),lis.end());
	for (int i=1;i<=n;i++) lim[i]=min(a[i],z-1);
	ll ans=0;
	for (int t=0;t<lis.size();t++){
		int i=lis[t].second.first,j=lis[t].second.second;
		ans=(ans+dp(i,x-j)*C(a[i],j)%mod*calc(i,j)%mod)%mod;
		lim[i]=j;
	}
	ans=ans*rC(sum,x)%mod*rC(sum-x,y)%mod;
	printf("%lld\n",(ans%mod+mod)%mod);
	return 0;
}
