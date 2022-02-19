#include<cstdio>
#include<cstdlib>
#include<list>
#include<algorithm>
#define oo (1<<30)
using namespace std;
 
inline char nc()
{
	static char buf[100000],*p1=buf,*p2=buf;
	if (p1==p2) { p2=(p1=buf)+fread(buf,1,100000,stdin); if (p1==p2) return EOF; }
	return *p1++;
}
 
inline void read (int &x){
	char c=nc(),b=1;
	for (;!(c>='0' && c<='9');c=nc()) if (c=='-') c=-1;
	for (x=0;c>='0' && c<='9';x=x*10+c-'0',c=nc()); x*=b;
}
 
const int N=250005;
 
int sx[2*N],icnt;
 
inline int Bin(int x){
	return lower_bound(sx+1,sx+icnt+1,x)-sx;
}
 
int val[N*8];
list<int> Lis[N*8];
 
int n,L;
int d[N],x[N],y[N];
int dp[N];
int Q[N],l,r;
 
void build(int rt,int l,int r){
	val[rt]=oo;
	int mid=(l+r)>>1;
	if (l!=r)
		build(rt<<1,l,mid),build(rt<<1|1,mid+1,r);
}
 
inline int get(int rt)
{
	return !Lis[rt].empty()?dp[Lis[rt].front()]:oo; 
}
 
void modify(int k,int rt,int l,int r,int L,int R,int pos)
{
	if (L<=l && r<=R){
		if (k)
		{
			while (!Lis[rt].empty() && Lis[rt].front()<=pos) 
				Lis[rt].pop_front();
		}
		else
		{
			while (!Lis[rt].empty() && dp[pos]<=dp[Lis[rt].back()]) 
				Lis[rt].pop_back();
			Lis[rt].push_back(pos);
		}
	}
	else
	{
		int mid=(l+r)>>1;
		if (R<=mid) 
			modify(k,rt<<1,l,mid,L,R,pos);
		else if (L>mid) 
			modify(k,rt<<1|1,mid+1,r,L,R,pos);
		else
		{
			modify(k,rt<<1,l,mid,L,mid,pos);
			modify(k,rt<<1|1,mid+1,r,mid+1,R,pos);
		}
	}
	val[rt]=min(get(rt),(l==r)?oo:min(val[rt<<1],val[rt<<1|1]));
}
 
int query(int rt,int l,int r,int L,int R)
{
	if (R<l || L>r) return oo;
	if (L<=l && r<=R) return val[rt];
	int ret=get(rt);
	if (l!=r)
	{
		int mid=(l+r)>>1;
		ret=min(ret,query(rt<<1,l,mid,L,R));
		ret=min(ret,query(rt<<1|1,mid+1,r,L,R));
	}	
	return ret;
}
 
int main()
{
	freopen("bzoj1171.in","r",stdin);
	freopen("bzoj1171_bl.out","w",stdout);
	read(n); read(L);
	for (int i=1;i<n;i++)
	{
		read(x[i]),read(y[i]),read(d[i]);
		sx[++icnt]=x[i]; sx[++icnt]=y[i];
	}
	sort(sx+1,sx+icnt+1);
	icnt=unique(sx+1,sx+icnt+1)-sx-1;
	for (int i=1;i<n;i++)
		x[i]=Bin(x[i]),y[i]=Bin(y[i]);
	build(1,1,icnt);
	x[0]=1; y[0]=icnt;
	l=r=-1; dp[0]=d[0]=0;
	Q[++r]=0;
	modify(0,1,1,icnt,x[0],y[0],0);
	for (int i=1;i<n;i++)
	{
		while (l<r && d[i]-d[Q[l+1]]>L) {
			int u=Q[++l];
			modify(1,1,1,icnt,x[u],y[u],u);
		}
		dp[i]=query(1,1,icnt,x[i],y[i]);
		if (dp[i]!=oo)
		{
			printf("%d\n",++dp[i]);
			modify(0,1,1,icnt,x[i],y[i],i);
			Q[++r]=i;
		}
		else
		{
			printf("-1\n");
		}
	}
	return 0;
}
