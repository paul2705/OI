#include<bits/stdc++.h>
#define MAXN 200010
using namespace std;
inline int read ()
{
	int s=0,w=1;char ch=getchar ();
	while (ch<'0'||ch>'9'){if (ch=='-') w=-1;ch=getchar ();}
	while ('0'<=ch&&ch<='9') s=(s<<1)+(s<<3)+(ch^48),ch=getchar ();
	return s*w;
}
struct edge{
	int v,nxt;
}e[MAXN<<1];
struct Edge{
	int v,nxt;
}E[MAXN<<1];
int n,m,cnt,tot,cnt2,h[MAXN],st[MAXN],ed[MAXN],in[MAXN];
int p[MAXN],head[MAXN],id[MAXN],num[MAXN];
bool used[MAXN];
void Add (int u,int v)
{
	in[v]++;
	E[++cnt2].v=v;
	E[cnt2].nxt=h[u];
	h[u]=cnt2;
}
void add (int u,int v)
{
	e[++cnt].v=v;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
void dfs (int u,int fa)
{
	for (int i=head[u];i!=0;i=e[i].nxt)
		if (e[i].v!=fa)
		{
			dfs (e[i].v,u);
			if (p[e[i].v]!=p[u]&&num[p[e[i].v]]!=0)
				Add (p[e[i].v],p[u]);
		}
	if (!st[p[u]]) st[p[u]]=u;
	if (--num[p[u]]==0) ed[p[u]]=u;
}
queue<int>Q;
void topu ()
{
	for (int i=1;i<=m;i++) if (in[i]==0) Q.push (i);
	while (!Q.empty ())
	{
		int u=Q.front ();Q.pop ();
		printf ("%d %d %d\n",u,st[u],ed[u]);
		for (int i=h[u];i!=0;i=E[i].nxt)
			if (--in[E[i].v]==0)
				Q.push (E[i].v);
	}
}
int main()
{
	freopen ("color.in","r",stdin);
	freopen ("color.out","w",stdout); 
	n=read (),m=read ();
	for (int i=1;i<=n;i++) p[i]=read (),num[p[i]]++;
	for (int i=1;i<n;i++)
	{
		int u=read (),v=read ();
		add (u,v);add (v,u);
	}
	dfs (1,0);
	topu ();
	return 0;
}
