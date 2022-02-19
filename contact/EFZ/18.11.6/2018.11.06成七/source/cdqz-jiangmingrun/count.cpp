#include<stdio.h>
int jc[1048576],injc[1048576];
int dp[1024][1024];
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	int n,m,p;
	scanf("%d%d%d",&n,&m,&p);
	injc[1]=1;
	int k=n*m;
	for(int i=2;i<=k;i++)
	{
		injc[i]=(long long)p/i*injc[p%i]%p;
		injc[i]=p-injc[i];
	}
	injc[0]=1;
	jc[0]=1;
	for(int i=1;i<=k;i++)
	{
		jc[i]=(long long)jc[i-1]*i%p;
		injc[i]=(long long)injc[i-1]*injc[i]%p;
	}
	for(int i=n;i>0;i--)
	{
		for(int j=m;j>0;j--)
		{
			if(i==n&&j==m)
			{
				dp[i][j]=k;
				continue;
			}
			if(i<n)
			{
				int incans=(long long)jc[k-i*j-1]*injc[k-(i+1)*j]%p;
				incans=(long long)incans*dp[i+1][j]%p;
				incans=(long long)incans*(n-i)*j%p;
				dp[i][j]+=incans;
				if(dp[i][j]>=p)
				{
					dp[i][j]-=p;
				}
			}
			if(j<m)
			{
				int incans=(long long)jc[k-i*j-1]*injc[k-i*(j+1)]%p;
				incans=(long long)incans*dp[i][j+1]%p;
				incans=(long long)incans*i*(m-j)%p;
				dp[i][j]+=incans;
				if(dp[i][j]>=p)
				{
					dp[i][j]-=p;
				}
			}
		}
	}
	printf("%d\n",dp[1][1]);
	return 0;
}
