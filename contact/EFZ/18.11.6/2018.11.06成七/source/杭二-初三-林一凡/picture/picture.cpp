#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,ans;
int n1,n2,m1,m2,s1[905][905],s2[905][905];
int gcd(int a,int b)
{
	if (b) return gcd(b,a%b);
	return a;
}
ll lcm(int a,int b){return (ll)a*b/gcd(a,b);}
int main()
{
	freopen("picture.in","r",stdin);
	freopen("picture.out","w",stdout);
	scanf("%d%d",&n1,&m1);
	for (int i=1;i<=n1;i++)
		for (int j=1;j<=m1;j++) scanf("%1d",&s1[i][j]);
	scanf("%d%d",&n2,&m2);
	for (int i=1;i<=n2;i++)
		for (int j=1;j<=m2;j++) scanf("%1d",&s2[i][j]);
	n=lcm(n1,n2),m=lcm(m1,m2);
	for (int i=n;i>=1;i--)
		for (int j=m;j>=1;j--)
		{
			s1[i][j]=s1[(int)ceil(i/((double)n/n1))][(int)ceil(j/((double)m/m1))];
			s2[i][j]=s2[(int)ceil(i/((double)n/n2))][(int)ceil(j/((double)m/m2))];
			ans+=(s1[i][j]==s2[i][j]);
		}
/*	int x=1;
	for (int i=1;i<=n1;i++)
	{
		while (n/n2*x<=n/n1*i)
		{
			int y=1,t=min(n/n2,n/n2*x-n/n1*(i-1));
			x++;
			for (int j=1;j<=m1;j++)
			{
				if (m/m2*(y-1)<m/m1*(j-1))
				{
					if (s1[(i-1)*n1+j]==s2[(x-1)*n2+y]) ans+=(m/m2*y-m/m1*(j-1))*t;
					y++;
				}
				while (m/m2*y<=m/m1*j)
				{
					if (s1[(i-1)*n1+j]==s2[(x-1)*n2+y]) ans+=m/m2*t;
					y++;
				}
				if (m/m2*(y-1)<m/m1*j&&s1[(i-1)*n1+j]==s2[(x-1)*n2+y]) ans+=(m/m1*j-m/m2*(y-1))*t;
			}
		}
		if (n/n2*(x-1)<n/n1*i)
		{
			int y=1,t=min(n/n1*i-n/n2*(x-1),n/n1);
			for (int j=1;j<=m1;j++)
			{
				if (m/m2*(y-1)<m/m1*(j-1))
				{
					if (s1[(i-1)*n1+j]==s2[(x-1)*n2+y]) ans+=(m/m2*y-m/m1*(j-1))*t;
					y++;
				}
				while (m/m2*y<=m/m1*j)
				{
					if (s1[(i-1)*n1+j]==s2[(x-1)*n2+y]) ans+=m/m2*t;
					y++;
				}
				if (m/m2*(y-1)<m/m1*j&&s1[(i-1)*n1+j]==s2[(x-1)*n2+y]) ans+=(m/m1*j-m/m2*(y-1))*t;
			}
		}
	}*/
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
