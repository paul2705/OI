#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

const int inf=(1e9);
int tp[100001],n,m,hd[100001],cnt,p[100001],fa[100001],siz[100001],x,y,l[100001],r[100001],D0,D1,ans[100001],an,X[100001],Y[100001],tmp;
vector<int> v[100001];
bool bo[100001];

struct node
{
	int to,next;
}e[200001];

struct node2
{
	int l,r,mi,ma;
}t[400001];

int read()
{
	int p=0; char c=getchar();
	while (c>'9'||c<'0') c=getchar();
	while (c>='0'&&c<='9') p=p*10+c-48,c=getchar();
	return p;
}

void addedge(int x,int y)
{
	e[++cnt].next=hd[x];
	hd[x]=cnt;
	e[cnt].to=y;
}

void build(int i,int l,int r)
{
	t[i].l=l; t[i].r=r; t[i].mi=inf; t[i].ma=0;
	if (l==r) return;
	int mid=(l+r)>>1;
	build(i<<1,l,mid); build(i<<1|1,mid+1,r);
}

int getmin(int a,int b) {return a<b?a:b;}
int getmax(int a,int b) {return a>b?a:b;}

void change(int i,int x,int v)
{
	if (t[i].l==t[i].r) {t[i].mi=t[i].ma=v; return;}
	int mid=(t[i].l+t[i].r)>>1;
	if (x<=mid) change(i<<1,x,v);
	else change(i<<1|1,x,v);
	t[i].mi=getmin(t[i<<1].mi,t[i<<1|1].mi);
	t[i].ma=getmax(t[i<<1].ma,t[i<<1|1].ma);
}

int qmi(int i,int l,int r)
{
	if (l==t[i].l&&r==t[i].r) return t[i].mi;
	int mid=(t[i].l+t[i].r)>>1;
	if (r<=mid) return qmi(i<<1,l,r);
	if (l>mid) return qmi(i<<1|1,l,r);
	return getmin(qmi(i<<1,l,mid),qmi(i<<1|1,mid+1,r));
}

int qma(int i,int l,int r)
{
	if (l==t[i].l&&r==t[i].r) return t[i].ma;
	int mid=(t[i].l+t[i].r)>>1;
	if (r<=mid) return qma(i<<1,l,r);
	if (l>mid) return qma(i<<1|1,l,r);
	return getmax(qma(i<<1,l,mid),qma(i<<1|1,mid+1,r));
}

void mems(int i,int x)
{
	if (t[i].l==t[i].r) {t[i].mi=inf; t[i].ma=0; return;}
	int mid=(t[i].l+t[i].r)>>1;
	if (x<=mid) mems(i<<1,x); else mems(i<<1|1,x);
	t[i].mi=getmin(t[i<<1].mi,t[i<<1|1].mi);
	t[i].ma=getmax(t[i<<1].ma,t[i<<1|1].ma);
}

void DFS(int i)
{
	int xx=X[i],yy=Y[i];
	if (l[xx]<l[yy]) tmp=xx,xx=yy,yy=tmp;
	while (tp[xx]!=tp[yy])
	{
		int nw=qmi(1,l[tp[xx]],l[xx]);
		while (nw!=inf&&nw!=i) DFS(nw),nw=qmi(1,l[tp[xx]],l[xx]);
		nw=qma(1,l[tp[xx]],l[xx]);
		while (nw!=0&&nw!=i) DFS(nw),nw=qma(1,l[tp[xx]],l[xx]);
		xx=fa[tp[xx]];
		if (l[xx]<l[yy]) tmp=xx,xx=yy,yy=tmp;
	}
	int nw=qmi(1,l[yy],l[xx]);
	while (nw!=inf&&nw!=i) DFS(nw),nw=qmi(1,l[yy],l[xx]);
	nw=qma(1,l[yy],l[xx]);
	while (nw!=0&&nw!=i) DFS(nw),nw=qma(1,l[yy],l[xx]);
	bo[i]=1; xx=v[i].size(); ans[++an]=i;
	for (int j=0; j<xx; j++) mems(1,l[v[i][j]]);
}

void dfs(int x)
{
	siz[x]=1;
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to!=fa[x]) fa[e[i].to]=x,dfs(e[i].to),siz[x]+=siz[e[i].to];
}

void Dfs(int x)
{
	l[x]=(++cnt); int ma=0,maa;
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to!=fa[x]&&siz[e[i].to]>ma) ma=siz[e[i].to],maa=e[i].to;
	if (!ma) {r[x]=cnt; return;}
	tp[maa]=tp[x]; Dfs(maa);
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to!=fa[x]&&e[i].to!=maa) tp[e[i].to]=e[i].to,Dfs(e[i].to); 
	r[x]=cnt;
}

bool check(int x,int y) {return l[x]<=l[y]&&r[x]>=l[y];}

int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	n=read(); m=read(); cnt=0;
	for (int i=1; i<=n; i++) p[i]=read();
	memset(hd,0,sizeof(hd));
	for (int i=1; i<n; i++) x=read(),y=read(),addedge(x,y),addedge(y,x);
	cnt=fa[1]=0; dfs(1); tp[1]=1; Dfs(1);
	build(1,1,n);
	for (int i=0; i<=m; i++) v[i].clear();
	for (int i=1; i<=n; i++) v[p[i]].push_back(i),change(1,l[i],p[i]);
	memset(bo,0,sizeof(bo));
	for (int i=1; i<=m; i++)
	{
		if (!v[i].size()) printf("%d 1 1\n",i),bo[i]=1;
		else
		{
			D0=D1=1; x=v[i].size();
			for (int j=0; j<x; j++)
			{
				y=v[i][j];
				if (check(D0,y)) D0=y; else
				if (!check(y,D0)&&check(D1,y)) D1=y;
			}
			if (check(D0,D1)) D0=D1;
			if (check(D1,D0)) D1=D0;
			X[i]=D0;
			if (D0!=D1) Y[i]=D1; else
			{
				Y[i]=0;
				for (int j=0; j<x; j++)
				{
					y=v[i][j];
					if (!Y[i]||check(y,Y[i])) Y[i]=y;
				}
			}
		}
	}
	for (int i=1; i<=m; i++) if (!bo[i]) DFS(i);
	for (int i=an; i; i--) printf("%d %d %d\n",ans[i],X[ans[i]],Y[ans[i]]);
	return 0;
}
