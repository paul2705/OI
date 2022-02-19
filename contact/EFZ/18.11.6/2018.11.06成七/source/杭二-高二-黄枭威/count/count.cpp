#include<cstdio>
#include<cstring>
typedef long long LL;
LL f[81][81],t[81][81],n,m,mod,res;
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&mod);
	memset(f,0,sizeof(f));
	f[1][1]=1;
	for (LL i=2;i<=n*m;i++)
	{
		for (LL j=1;j<=n;j++)
			for (LL k=1;k<=m;k++) t[j][k]=0;
		for (LL j=1;j<=n;j++)
			for (LL k=1;k<=m;k++)
			if (f[j][k]!=0)
			{
				if (j*k>=i) t[j][k]=(t[j][k]+f[j][k]*(j*k-i+1))%mod;
				if (j!=n) t[j+1][k]=(t[j+1][k]+f[j][k]*k)%mod;
				if (k!=m) t[j][k+1]=(t[j][k+1]+f[j][k]*j)%mod;
			}
		for (LL j=1;j<=n;j++)
			for (LL k=1;k<=m;k++) f[j][k]=t[j][k];
	}
	res=f[n][m];
	for (LL i=2;i<=n;i++) res=res*i%mod;
	for (LL i=2;i<=m;i++) res=res*i%mod;
	printf("%lld\n",res);
	return 0;
}
