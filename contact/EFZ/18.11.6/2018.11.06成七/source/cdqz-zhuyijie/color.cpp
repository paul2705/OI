#include<bits/stdc++.h>
#define LL long long
#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
using namespace std;
const LL N=1e5+9,M=1e5+9,V=1e5+9;
struct Graph
{
	struct Edge
	{
		LL v;
	}E[M<<1];
	LL last,first[N],nxt[M<<1],rd[N];
	Graph()
	{
		last=0;
		memset(first,0,sizeof(first));
		memset(rd,0,sizeof(rd));
	}
	void add(LL u,LL v)
	{
		++last;
		E[last].v=v;
		nxt[last]=first[u];
		first[u]=last;
		++rd[v];
	}
}g,tg;
struct Node
{
	LL u,v,d,col;
}a[V];
LL n,m,maxd,pos;
LL p[N];
LL fa[N],dep[N];
bool vis[N];
vector<LL> G[V];
template<typename T>
inline void read(T &x)
{
	x=0;T w=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')w=-1;	c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+c-'0';	c=getchar();}
	x*=w;
}
void dfs1(LL u,LL father,LL depth)
{
	fa[u]=father;
	dep[u]=depth;
	for(LL i=g.first[u];i;i=g.nxt[i])
	{
		LL v=g.E[i].v;
		if(v==fa[u])	continue;
		dfs1(v,u,depth+1);
	}
}
void dfs(LL u,LL col,LL dis)
{
	vis[u]=1;
	for(LL i=g.first[u];i;i=g.nxt[i])
	{
		LL v=g.E[i].v;
		if(vis[v])	continue;
		vis[v]=1;
		if(p[v]==col)
		{
			if(dis>maxd)
			{
				maxd=dis;
				pos=v;
			}
		}
		dfs(v,col,dis+1);
	}
}
void toposort()
{
	queue<LL> q;
	for(LL i=1;i<=m;++i)
		if(!tg.rd[i])	q.push(i);
	while(!q.empty())
	{
		LL u=q.front();	q.pop();
		printf("%lld %lld %lld\n",u,a[u].u,a[u].v);
		for(LL i=tg.first[u];i;i=tg.nxt[i])
		{
			LL v=tg.E[i].v;
			--tg.rd[v];
			if(!tg.rd[v])	q.push(v);
		}
	}	
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	read(n);read(m);
	for(LL i=1;i<=n;++i)
	{
		read(p[i]);
		G[p[i]].push_back(i);
	}
	for(LL i=1;i<=n-1;++i)
	{
		LL u,v;
		read(u);read(v);
		g.add(u,v);
		g.add(v,u);
	}
	for(LL i=1;i<=m;++i)
	{
		if(G[i].empty())
		{
			printf("%lld 1 1\n",i);
			continue;
		}
		if(G[i].size()==1)
		{
			a[i]=(Node){G[i][0],G[i][0],0,i};
			continue;
		}
		LL d=-1;
		Node t;
		for(LL j=0;j<(LL)G[i].size();++j)
		{
			memset(vis,0,sizeof(vis));
			maxd=-1;
			dfs(G[i][j],i,0);
			if(maxd>d)
			{
				d=maxd;
				t=(Node){G[i][j],pos,d,i};
			}
		}
		a[i]=t;
	}
//		for(LL i=1;i<=m;++i)
//			printf("%lld:%lld %lld %lld \n",i,a[i].u,a[i].v,a[i].d);
	dfs1(1,0,0);
	for(LL i=1;i<=m;++i)
	{
		Node t=a[i];
		LL u=t.u,v=t.v;
		if(dep[u]<dep[v])	swap(u,v);
		while(dep[u]!=dep[v])
		{
			if(p[u]!=i)	tg.add(i,p[u]);
			u=fa[u];
		}
		while(u!=v)
		{
			if(p[u]!=i)	tg.add(i,p[u]);
			if(p[v]!=i)	tg.add(i,p[v]);
			u=fa[u];v=fa[v];
		}
		if(p[u]!=i)	tg.add(i,p[u]);
	}
	toposort();	
	return 0;
}
