#include<bits/stdc++.h>
using namespace std;
#define LL long long

LL n,m,mod,ans,f[6403][83][83];

int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&mod);
	f[1][1][1]=n*m%mod;
	for (int i=1;i<=n*m;i++)
	  for (int j=1;j<=n;j++)
	    for (int k=1;k<=m;k++){
	    	LL res=(LL)j*k-i;
	    	f[i+1][j][k]=(f[i+1][j][k]+f[i][j][k]*res%mod)%mod;
	    	res=(LL)k*(n-j);
			f[i+1][j+1][k]=(f[i+1][j+1][k]+f[i][j][k]*res%mod)%mod;
			res=(LL)j*(m-k);
			f[i+1][j][k+1]=(f[i+1][j][k+1]+f[i][j][k]*res%mod)%mod;	
	    }
	ans=0;
	for (int i=1;i<=n;i++)
	  for (int j=1;j<=m;j++)
	    ans=(ans+f[n*m][i][j])%mod;
	printf("%lld\n",ans);
	return 0;	
}
