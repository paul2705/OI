#include<bits/stdc++.h>
using namespace std;
int n,m,p,ans,a[1005],b[1005];
bool used[1005][1005];
void dfs(int x)
{
	if (!x)
	{
		ans++;
		return;
	}
	if (x==n*m)
	{
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++) a[i]++,b[j]++,used[i][j]=1,dfs(x-1),a[i]--,b[j]--,used[i][j]=0;
		return;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if ((a[i]||b[j])&&!used[i][j]) a[i]++,b[j]++,used[i][j]=1,dfs(x-1),a[i]--,b[j]--,used[i][j]=0;
}
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	scanf("%d%d%d",&n,&m,&p);
	dfs(n*m);
	printf("%d",ans%p);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
