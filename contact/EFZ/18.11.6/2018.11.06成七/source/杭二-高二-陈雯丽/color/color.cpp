#include<algorithm>
#include<vector>
#include<cstdio>

using namespace std;

#define rep(i,a,b) for (int i=(a);i<=(b);i++)
#define per(i,b,a) for (int i=(b);i>=(a);i--)
#define pb push_back

const int N=100005,M=200005;

int n,m,cnt,len,q[N],A[N],B[N],ls[N],dep[N],In[N],Out[N],fa[N][20];
int TOT,F[N],LNK[N],SON[M],NXT[M];
int tot,lnk[N],son[M],nxt[M];
vector<int>col[N];

int read()
{
	int x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x;
}
bool cmp(const int &x,const int &y) {return dep[x]>dep[y];}
bool check(int fa,int son) {return In[fa]<=In[son]&&In[son]<=Out[fa];}
void ADD(int x,int y) {TOT++;F[SON[TOT]=y]++;NXT[TOT]=LNK[x];LNK[x]=TOT;}
void add(int x,int y)
{
	tot++;son[tot]=y;nxt[tot]=lnk[x];lnk[x]=tot;
	tot++;son[tot]=x;nxt[tot]=lnk[y];lnk[y]=tot;
}
void dfs(int x,int y)
{
	In[x]=Out[x]=++cnt;dep[x]=dep[fa[x][0]=y]+1;
	rep(i,1,16) fa[x][i]=fa[fa[x][i-1]][i-1];
	for (int j=lnk[x];j;j=nxt[j]) if (son[j]!=y)
	  dfs(son[j],x),Out[x]=Out[son[j]];
}
int lca(int x,int y)
{
	if (dep[x]<dep[y]) swap(x,y);int t=dep[x]-dep[y];
	per(i,16,0) if (t&(1<<i)) x=fa[x][i];if (x==y) return x;
	per(i,16,0) if (fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];return fa[x][0];
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	n=read(),m=read();
	rep(i,1,n) col[read()].pb(i);
	rep(i,2,n) add(read(),read());dfs(1,0);
	rep(i,1,m) if (col[i].size())
	{
		len=col[i].size();rep(j,1,len) ls[j]=col[i][j-1];
		sort(ls+1,ls+len+1,cmp);A[i]=ls[1];
		rep(j,2,len) {if (!check(ls[j],ls[j-1])) {B[i]=ls[j];break;}}
		if (!B[i]) B[i]=ls[len];
	}
	else A[i]=B[i]=1;
	rep(i,1,m) if (col[i].size())
	  rep(j,1,m) if (col[j].size())
	    if (i!=j)
	    {
	    	int X=A[i],Y=B[i],Z=lca(X,Y);bool fl=0;
	    	rep(k,1,col[j].size()) if (check(Z,col[j][k-1]))
	    	  if (check(col[j][k-1],X)||check(col[j][k-1],Y)) {fl=1;break;}
	    	if (fl) ADD(i,j);
	    }
	int hed=0,tal=0;
	rep(i,1,m) if (!col[i].size()) q[++tal]=i;
	rep(i,1,m) if (col[i].size()&&!F[i]) q[++tal]=i;
	while (hed!=tal)
	  for (int x=q[++hed],j=LNK[x];j;j=NXT[j])
		if (!(--F[SON[j]])) q[++tal]=SON[j];
	rep(i,1,m) printf("%d %d %d\n",q[i],A[q[i]],B[q[i]]);
	return 0;
}
