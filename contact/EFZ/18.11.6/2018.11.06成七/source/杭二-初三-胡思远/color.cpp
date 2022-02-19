#include <bits/stdc++.h> 
using namespace std;

const int MAXN=100001;

int n,m,len,edge[MAXN<<1],next[MAXN<<1],first[MAXN],deep[MAXN],fa[MAXN],degree[MAXN];
int color[MAXN],g[MAXN][101],deepest1[MAXN],deepest2[MAXN],q[MAXN+1];

int read()
{
	int t=0;
	char s=getchar();
	while (s<'0'||s>'9') s=getchar();
	while (s>='0'&&s<='9') {t=t*10+s-'0';s=getchar();}
	return t;
}

void add(int x,int y)
{
	edge[++len]=y;next[len]=first[x];first[x]=len;
}

void dfs(int x)
{
	for (int i=first[x];i>-1;i=next[i])
	if (!fa[edge[i]]&&edge[i]!=1)
	{
		deep[edge[i]]=deep[x]+1;
		fa[edge[i]]=x;
		dfs(edge[i]);
	}
}

void lca(int COLOR,int x,int y)
{
	int cnt=2,xx=x,yy=y;
    if (deep[x]<deep[y]) {int t=x;x=y;y=t;}
    while (deep[x]>deep[y])
    {
    	x=fa[x];
    	if (COLOR!=color[x]) 
    	{
    		add(COLOR,color[x]);
    		degree[color[x]]++;
		} else cnt++;
	}
	while (x!=y)
	{
		x=fa[x];y=fa[y];
		if (COLOR!=color[x]) 
    	{
    		add(COLOR,color[x]);
    		degree[color[x]]++;
		} else cnt++;
		if (COLOR!=color[y]) 
    	{
    		add(COLOR,color[y]);
    		degree[color[y]]++;
		} else cnt++;	
	}
	if (x==y&&color[x]==COLOR) cnt--;
	if (cnt==g[COLOR][0])
	{
		deepest1[COLOR]=xx;deepest2[COLOR]=yy;
	}
}

int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	n=read();m=read();
	memset(first,-1,sizeof(first));
	for (int i=1;i<=n;i++) 	{color[i]=read();g[color[i]][0]++;g[color[i]][g[color[i]][0]]=i;}
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		add(u,v);add(v,u);
	}
	dfs(1);
	memset(edge,0,sizeof(edge));
	memset(first,-1,sizeof(first));
	memset(next,0,sizeof(next));
	len=0;
	for (int i=1;i<=m;i++)
		for (int j=1;j<=g[i][0];j++) 
		    for (int k=j;k<=g[i][0];k++)
		        lca(i,g[i][j],g[i][k]);
	int t=0,w=0;
	for (int i=1;i<=m;i++)
		if (!degree[i])
			q[++w]=i;
	while (t<w)
	{
		int x=q[++t];
		for (int i=first[x];i>-1;i=next[i])
		{
			degree[edge[i]]--;
			if (!degree[edge[i]]) q[++w]=edge[i];
		}
	}
	for (int i=1;i<=w;i++)
	if (!g[i][0]) cout<<q[i]<<" 1 1"<<endl;
	else cout<<q[i]<<' '<<deepest1[q[i]]<<' '<<deepest2[q[i]]<<endl;
	return 0;
}
