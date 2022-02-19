#include<cstdio>
int n,m,dp[81][81][6401],mo;
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	scanf("%d%d%d",&n,&m,&mo);
	dp[n-1][m-1][1]=n*m;
	for(int k=1;k<n*m;k++)
	for(int i=n-1;i>=0;i--)
	for(int j=m-1;j>=0;j--)if(dp[i][j][k]>0)
	{
		dp[i][j][k+1]=(dp[i][j][k+1]+1ll*dp[i][j][k]*(1ll*(n-i)*(m-j)-1ll*k))%mo;
		if(i>0)dp[i-1][j][k+1]=(dp[i-1][j][k+1]+1ll*dp[i][j][k]*i*(m-j))%mo;
		if(j>0)dp[i][j-1][k+1]=(dp[i][j-1][k+1]+1ll*dp[i][j][k]*(n-i)*j)%mo;
	}
	printf("%d\n",dp[0][0][n*m]);
}
