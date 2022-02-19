#include<cstdio>
#include<cstring>

int f[6402][82][82],mod,n,m;

int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	scanf("%d%d%d",&n,&m,&mod);
	memset(f,0,sizeof(f));
	f[1][1][1]=n*m;
	for (int i=1; i<n*m; i++)
		for (int j=1; j<=n; j++)
			for (int k=1; k<=m; k++)
				if (f[i][j][k])
				{
					f[i+1][j][k]=(f[i+1][j][k]+1ll*f[i][j][k]*(j*k-i))%mod;
					if (j<n) f[i+1][j+1][k]=(f[i+1][j+1][k]+1ll*f[i][j][k]*((n-j)*k))%mod;
					if (k<m) f[i+1][j][k+1]=(f[i+1][j][k+1]+1ll*f[i][j][k]*((m-k)*j))%mod;
				}
	printf("%d\n",f[n*m][n][m]);
	return 0;
}
