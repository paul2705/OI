#include <bits/stdc++.h> 
using namespace std;

#define ll long long

int n,m,p,ans,a[10001],f[10001],matrix[1001][1001];

void pd()
{
	int cnt=0;
	for (int i=1;i<=n*m;i++)
	    matrix[(i-1)/m+1][(i-1)%m+1]=a[i];
	for (int i=1;i<=n;i++)
	    for (int j=1;j<=m;j++)
	    {
	    	bool flag=false;
	    	for (int k=1;k<=n;k++)
	    	if (matrix[k][j]>matrix[i][j])
	    	{
	    		flag=true;
	    		break;
			}
			if (flag) continue;
			for (int k=1;k<=m;k++)
			if (matrix[i][k]>matrix[i][j])
			{
				flag=true;
				break;
			}
			if (flag) continue;
			if (matrix[i][j]!=n*m) return;
		}
	++ans;
	if (ans>p) ans-=p;
}

void dfs(int i)
{
	if (i>n*m) {pd();return;}
	for (int j=1;j<=n*m;j++)
	if (!f[j])
	{
		f[j]=true;a[i]=j;
		dfs(i+1);
		f[j]=false;
	}
}

int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	cin>>n>>m>>p;
	dfs(1);
	cout<<ans<<endl;
}

