#include<iostream>
#include<cstdio>
using namespace std;
#define N 200127
#define MAX_READ 1048576
inline char gc(void)
{
	static char buf[MAX_READ],*l=buf,*r=buf;
	if(l==r)r=(l=buf)+fread(buf,1,MAX_READ,stdin);
	return l==r?(~0):*(l++);
}
inline int read()
{
	int X=0,w=0;char ch=0;
	while('0'>ch||ch>'9'){w|=ch=='-';ch=gc();}
	while('0'<=ch&&ch<='9')X=(X<<3)+(X<<1)+(ch^48),ch=gc();
	return w?-X:X;
}
int n,a[N],L[N],R[N],Log[N],f[19][N],g[19][N],ma[19][19][N],mi[19][19][N];
inline void build(int d)
{
	for(int i=1;i<=n;i++){ma[d][0][i]=f[d][i];mi[d][0][i]=g[d][i];}
	for(int j=1;j<=Log[n];j++)
	for(int i=1;i+(1<<j)-1<=n;i++)
	{
		ma[d][j][i]=max(ma[d][j-1][i],ma[d][j-1][i+(1<<(j-1))]);
		mi[d][j][i]=min(mi[d][j-1][i],mi[d][j-1][i+(1<<(j-1))]);
	}
}
int ql,qr;
inline void Ask(int d,int l,int r)
{
	int p=Log[r-l+1];
	qr=max(ma[d][p][l],ma[d][p][r-(1<<p)+1]);
	ql=min(mi[d][p][l],mi[d][p][r-(1<<p)+1]);
}
inline void calc(int x,int k){ql=qr=x;while(k)Ask(Log[k&(-k)],ql,qr),k&=(k-1);}
int s[N];
inline bool can(int mid)
{
	--mid;s[0]=n+1;int i;
	for(i=1;i<=n;i++)
	{
		calc(i,mid);s[i]=min(s[i-1],qr+1);
		if(s[ql-1]<=i)return true;
	}return false;
}
int ans=0;
int main(){
	Log[0]=-1;for(int i=1;i<N;i++)Log[i]=Log[i>>1]+1;
	n=read();int i,j,l=1,r=n,mid;
	for(i=1;i<=n;i++){a[i]=read();g[0][i]=max(1,i-a[i]);f[0][i]=min(n,i+a[i]);}
	build(0);
	for(j=1;j<=Log[n];++j)
	{
		for(i=1;i<=n;++i)
		{
			ql=g[j-1][i];qr=f[j-1][i];Ask(j-1,ql,qr);
			g[j][i]=ql;f[j][i]=qr;
		}build(j);
	}
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(can(mid)){ans=mid;l=mid+1;}
		else r=mid-1;
	}printf("%d",ans);return 0;
}
