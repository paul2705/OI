#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<set>
#define lc (p<<1)
#define rc ((p<<1)|1)
using namespace std;
typedef long long ll;
class edge
{
	public:
		int e,nxt;
		edge(int e1=-1,int nxt1=-1)
		{
			e=e1,nxt=nxt1;
		}
};
class dat
{
	public:
		int x,y;
		dat(int tx=-1,int ty=-1)
		{
			x=tx,y=ty;
		}
		bool operator <(const dat &t)const
		{
			if(x==0)return 0;
			if(t.x==0)return 1;
			return x==t.x?y<t.y:x<t.x;
		}
};
class node
{
	public:
		int l,r;
		dat minval;
		int lazy;
};
class segment_tree
{
	public:
		node t[400010];
		void pushup(int p)
		{
			if(t[lc].minval<t[rc].minval)
			{
				t[p].minval=t[lc].minval;
			}
			else t[p].minval=t[rc].minval;
		}
		void pushnow(int p,int v)
		{
			t[p].lazy+=v;
			t[p].minval.x+=v;
		}
		void pushdown(int p)
		{
			if(t[p].lazy)
			{
				pushnow(lc,t[p].lazy);
				pushnow(rc,t[p].lazy);
				t[p].lazy=0;
			}
		}
		void build(int p,int l,int r)
		{
			t[p].l=l;
			t[p].r=r;
			if(l==r)
			{
				t[p].minval=dat(0,l);
				return;
			}
			int mid=(l+r)>>1;
			build(lc,l,mid);
			build(rc,mid+1,r);
			pushup(p);
		}
		void modify(int p,int ml,int mr,int v)
		{
			if(ml<=t[p].l&&mr>=t[p].r)
			{
				pushnow(p,v);
				return;
			}
			pushdown(p);
			int mid=(t[p].l+t[p].r)>>1;
			if(ml<=mid)modify(lc,ml,mr,v);
			if(mr>mid)modify(rc,ml,mr,v);
			pushup(p);
		}
		dat query(int p,int ql,int qr)
		{
			if(ql<=t[p].l&&t[p].r<=qr)return t[p].minval;
			pushdown(p);
			dat out=dat(1e9,1e9);
			int mid=(t[p].l+t[p].r)>>1;
			if(ql<=mid)out=min(out,query(lc,ql,qr));
			if(qr>mid)out=min(out,query(rc,ql,qr));
			pushup(p);
			return out;
		}
}t;
int top[100010],siz[100010],hevson[100010],dep[100010],fa[100010],dfn[100010],time=0,p[100010];
class color
{
	public:
		vector<int> pt;
		int cnt,l,side[2];
		bool operator <(const color &x)const
		{
			return cnt-pt.size()<x.cnt-x.pt.size();
		}
}c[100010];
int colored[100010];
class graph
{
	public:
		edge g[200010];
		int head[100010],tmpcnt;
		graph()
		{
			memset(head,255,sizeof(head));
			tmpcnt=0;
		}
		void addedge(int s,int e)
		{
			g[tmpcnt]=edge(e,head[s]),head[s]=tmpcnt++;
			g[tmpcnt]=edge(s,head[e]),head[e]=tmpcnt++;
		}
		void dfs1(int p,int fath)
		{
			fa[p]=fath;
			dep[p]=dep[fa[p]]+1;
			siz[p]=1;
			for(int i=head[p];i!=-1;i=g[i].nxt)
			{
				if(g[i].e==fa[p])continue;
				dfs1(g[i].e,p);
				siz[p]+=siz[g[i].e];
				if(!hevson[p]||siz[g[i].e]>siz[hevson[p]])
					hevson[p]=g[i].e;
			}
		}
		void dfs2(int p,int t)
		{
			dfn[p]=++time;
			top[p]=t;
			if(hevson[p])dfs2(hevson[p],t);
			for(int i=head[p];i!=-1;i=g[i].nxt)
			{
				if(g[i].e==fa[p]||g[i].e==hevson[p])continue;
				dfs2(g[i].e,g[i].e);
			}
		}
		void modify(int l,int r,int v)
		{
			while(top[l]!=top[r])
			{
				if(dep[top[l]]>dep[top[r]])
				{
					t.modify(1,dfn[top[l]],dfn[l],v);
					l=fa[top[l]];
				}
				else
				{
					t.modify(1,dfn[top[r]],dfn[r],v);
					r=fa[top[r]];
				}
			}
			if(dep[l]>dep[r])t.modify(1,dfn[r],dfn[l],v);
			else t.modify(1,dfn[l],dfn[r],v);
		}
		int lca(int l,int r)
		{
			while(top[l]!=top[r])
			{
				if(dep[top[l]]>dep[top[r]])l=fa[top[l]];
				else r=fa[top[r]];
			}
			if(dep[l]>dep[r])return r;
			else return l;
		}
}g;
int n,m;
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n<=100&&m<=100)
	{
		for(int i=1;i<=n;i++)scanf("%d",&p[i]);
		for(int i=1,ti,tj;i<n;i++)
		{
			scanf("%d%d",&ti,&tj);
			g.addedge(ti,tj);
		}
		g.dfs1(1,0);
		g.dfs2(1,1);
		for(int i=1;i<=n;i++)
		{
			if(c[p[i]].pt.size()==0)
			{
//				c[p[i]].cnt=1;
				c[p[i]].pt.push_back(i);
				c[p[i]].l=i;
			}
			else
			{
//				c[p[i]].cnt++;
				c[p[i]].pt.push_back(i);
				c[p[i]].l=g.lca(i,c[p[i]].l);
			}
		}
		for(int i=1;i<=m;i++)
		{
			for(int j=0;j<c[i].pt.size();j++)
			{
				if(!c[i].side[0]||dep[c[i].pt[j]]>dep[c[i].side[0]])
				{
					c[i].side[0]=c[i].pt[j];
				}
			}
			for(int j=0;j<c[i].pt.size();j++)
			{
				if(c[i].pt[j]==c[i].side[0])continue;
				if(c[i].side[1]&&dep[c[i].side[1]]>=dep[c[i].pt[j]])continue;
				if(g.lca(c[i].side[0],c[i].pt[j])!=c[i].l)continue;
				if(!c[i].side[1]||dep[c[i].side[1]]<dep[c[i].pt[j]])c[i].side[1]=c[i].pt[j];
			}
		}
		for(int i=1;i<=m;i++)
		{
			if(c[i].pt.size()==0)continue;
			colored[c[i].l]++;
			int np=c[i].side[0];
			while(np!=c[i].l)colored[np]++,np=fa[np];
			if(c[i].pt.size()<=1)continue;
			np=c[i].side[1];
			while(np!=c[i].l)colored[np]++,np=fa[np];			
		}
		for(int i=1;i<=n;i++)
			if(colored[i]==1)c[p[i]].cnt++;
		for(int i=1;i<=m;i++)
		{
			int minpos=0,minval=1e9;
			for(int j=1;j<=m;j++)
			{
				if(c[j].pt.size()-c[j].cnt<minval)
				{
					minpos=j;
					minval=c[j].pt.size()-c[j].cnt;
				}
			}
			if(c[minpos].pt.size()==0)
			{
				printf("%d %d %d\n",minpos,1,2);
				c[minpos].cnt=-1e9;
			}
			else if(c[minpos].pt.size()==1)
			{
				printf("%d %d %d\n",minpos,c[minpos].pt[0],c[minpos].pt[0]);
				c[minpos].cnt=-1e9;
			}
			else
			{
				printf("%d %d %d\n",minpos,c[minpos].side[0],c[minpos].side[1]);
				c[minpos].cnt=-1e9;
				colored[c[minpos].l]--;
				if(colored[c[minpos].l]==1)c[p[c[minpos].l]].cnt++;
				int np=c[minpos].side[0];
				while(np!=c[minpos].l)
				{
					colored[np]--;
					if(colored[np]==1)c[p[np]].cnt++;
					np=fa[np];
				}
				np=c[minpos].side[1];
				while(np!=c[minpos].l)
				{
					colored[np]--;
					if(colored[np]==1)c[p[np]].cnt++;
					np=fa[np];
				}
			}
		}
	}
	return 0;
}
