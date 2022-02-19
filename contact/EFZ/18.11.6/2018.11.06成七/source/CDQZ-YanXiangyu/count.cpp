#include<bits/stdc++.h>
using namespace std;
const int N=5,M=5,S=20;
int n,m,p,ans=0;
int s[N][M],mh[N],ml[M];
bool ud[S];
inline void mcheck()
{
	int i,j,zs=0;
	memset(mh,0,sizeof(mh));
	memset(ml,0,sizeof(ml));
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=m;++j)
		{
			if(mh[i]==0||s[i][j]>s[i][mh[i]]) mh[i]=j;
		}
	}
	for(j=1;j<=m;++j)
	{
		for(i=1;i<=n;++i)
		{
			if(ml[j]==0||s[i][j]>s[ml[j]][j]) ml[j]=i;
		}
	}
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=m;++j)
		{
			if(mh[i]==j&&ml[j]==i) zs++;
		}
	}
	if(zs==1) ans++;
}
inline void mdfs(int x,int y)
{
	if(x==n+1&&y==1)
	{
		mcheck();
		return ;
	}
	int i,j,sx=n*m;
	for(i=1;i<=sx;++i)
	{
		if(ud[i]==1) continue;
	    ud[i]=1;
		s[x][y]=i;
		if(y==m) mdfs(x+1,1);
		else mdfs(x,y+1);
		ud[i]=0;
	}
}
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	scanf("%d%d%d",&n,&m,&p);
	mdfs(1,1);
	printf("%d",ans);
	return 0;
}
