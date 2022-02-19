#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<ctime>
#include<queue>
#include<cmath>
#include<algorithm>
#define inf 1000000000
#define ll long long
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,L,cnt;
int a[35005],mn[35005];
int f[35005],last[35005];
ll g[35005],s1[35005],s2[35005];
struct list{int to,next;}e[35005];
void insert(int u,int v)
{
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
}
int find(int x)
{
	int l=1,r=L,t=0;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(mn[mid]<=x)t=mid,l=mid+1;
		else r=mid-1;
	}
	return t;
}
void dp()
{
	memset(mn,127,sizeof(mn));
	mn[0]=-(1<<30);
	for(int i=1;i<=n;i++)
	{
		int t=find(a[i]);
		f[i]=t+1;
		L=max(L,t+1);
		mn[t+1]=min(mn[t+1],a[i]);
	}
}
void solve()
{
	for(int i=n;i>=0;i--)
	{
		insert(f[i],i);
		g[i]=1LL<<60;
	}
	g[0]=0;a[0]=-(1<<30);
	for(int x=1;x<=n;x++)
		for(int i=last[f[x]-1];i;i=e[i].next)
		{
			int p=e[i].to;
			if(p>x)break;
			if(a[p]>a[x])continue;
			for(int j=p;j<=x;j++)
				s1[j]=abs(a[p]-a[j]),s2[j]=abs(a[x]-a[j]);
			for(int j=p+1;j<=x;j++)
				s1[j]+=s1[j-1],s2[j]+=s2[j-1];
			for(int j=p;j<x;j++)
				g[x]=min(g[x],g[p]+s1[j]-s1[p]+s2[x]-s2[j]);
		}
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)a[i]=read()-i;
	a[++n]=1<<30;
	dp();
	solve();
	printf("%d\n%lld\n",n-f[n],g[n]);
	return 0;
}
