#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
int head[131072],last[262144],to[262144],cnt=0;
void add(int u,int v)
{
	cnt++;
	last[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}
int d[131072],size[131072],fa[131072],son[131072],lr[131072],in[131072],out[131072],tim=0;
void dfs1(int u,int f)
{
	fa[u]=f;
	size[u]=1;
	d[u]=d[f]+1;
	for(int i=head[u];i;i=last[i])
	{
		int v=to[i];
		if(v==f)
		{
			continue;
		}
		dfs1(v,u);
		if(size[v]>size[son[u]])
		{
			son[u]=v;
		}
		size[u]+=size[v];
	}
}
void dfs2(int u,int root)
{
	lr[u]=root;
	tim++;
	in[u]=tim;
	if(son[u])
	{
		dfs2(son[u],root);
	}
	for(int i=head[u];i;i=last[i])
	{
		int v=to[i];
		if(v==fa[u]||v==son[u])
		{
			continue;
		}
		dfs2(v,v);
	}
}
int ans[131072];
int u[131072],v[131072];
struct point{
	int u;
	int wz;
	int col;
	bool operator<(point b) const
	{
		if(col==b.col)
		{
			return wz<b.wz;
		}
		return col<b.col;
	}
};
point p[131072];
int col[131072];
int n,m;
struct node{
	node* ls;
	node* rs;
	int l;
	int r;
	int mn;
	int flag;
	void pushdown()
	{
		ls->mn+=flag;
		rs->mn+=flag;
		ls->flag+=flag;
		rs->flag+=flag;
		flag=0;
	}
	void update()
	{
		mn=1000000000;
		if(ls->mn<mn)
		{
			mn=ls->mn;
		}
		if(rs->mn<mn)
		{
			mn=rs->mn;
		}
	}
};
node nn[262144];
int num=0;
node* build(int l,int r)
{
	node* root=&nn[num];
	num++;
	root->l=l;
	root->r=r;
	root->flag=0;
	if(l==r)
	{
		root->ls=NULL;
		root->rs=NULL;
		root->mn=0;
		return root;
	}
	int mid=(l+r)>>1;
	root->ls=build(l,mid);
	root->rs=build(mid+1,r);
	root->update();
	return root;
}
void inc(node* root,int l,int r)
{
	if(l<=root->l&&r>=root->r)
	{
		root->mn++;
		root->flag++;
		return;
	}
	root->pushdown();
	int mid=(root->l+root->r)>>1;
	if(l<=mid)
	{
		inc(root->ls,l,r);
	}
	if(r>mid)
	{
		inc(root->rs,l,r);
	}
	root->update();
}
queue<int> q;
void addn(int u)
{
	ans[col[u]]--;
	if(ans[col[u]]==0)
	{
		q.push(col[u]);
	}
}
void dec(node* root,int l,int r)
{
	if(l<=root->l&&r>=root->r&&root->mn>1)
	{
		root->flag--;
		root->mn--;
		return;
	}
	if(root->l==root->r)
	{
		root->mn=100000000;
		addn(root->l);
		return;
	}
	root->pushdown();
	int mid=(root->l+root->r)>>1;
	if(l<=mid)
	{
		dec(root->ls,l,r);
	}
	if(r>mid)
	{
		dec(root->rs,l,r);
	}
	root->update();
}
node* root;
void incc(int u,int v)
{
	while(lr[u]!=lr[v])
	{
		if(d[lr[u]]>d[lr[v]])
		{
			inc(root,in[lr[u]],in[u]);
			u=fa[lr[u]];
		}
		else
		{
			inc(root,in[lr[v]],in[v]);
			v=fa[lr[v]];
		}
	}
	if(in[u]<in[v])
	{
		inc(root,in[u],in[v]);
	}
	else
	{
		inc(root,in[v],in[u]);
	}
}
void decc(int u,int v)
{
	while(lr[u]!=lr[v])
	{
		if(d[lr[u]]>d[lr[v]])
		{
			dec(root,in[lr[u]],in[u]);
			u=fa[lr[u]];
		}
		else
		{
			dec(root,in[lr[v]],in[v]);
			v=fa[lr[v]];
		}
	}
	if(in[u]<in[v])
	{
		dec(root,in[u],in[v]);
	}
	else
	{
		dec(root,in[v],in[u]);
	}
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&col[i]);
		ans[col[i]]++;
	}
	for(int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	for(int i=1;i<=m;i++)
	{
		if(ans[i]==0)
		{
			printf("%d 1 1\n",i);
		}
	}
	dfs1(1,0);
	dfs2(1,1);
	for(int i=1;i<=n;i++)
	{
		p[i].u=i;
		p[i].wz=in[i];
		p[i].col=col[i];
	}
	sort(p+1,p+n+1);
	int lastcol=0;
	bool vis=true;
	for(int i=n;i>0;i--)
	{
		if(p[i].col!=lastcol)
		{
			if(!vis)
			{
				v[lastcol]=p[i+1].u;
			}
			vis=false;
			lastcol=p[i].col;
			u[lastcol]=p[i].u;
			continue;
		}
		if(vis)
		{
			continue;
		}
		if(out[p[i].u]<out[u[lastcol]])
		{
			vis=true;
			v[lastcol]=p[i].u;
		}
	}
	if(!vis)
	{
		v[lastcol]=p[1].u;
	}
	for(int i=1;i<=n;i++)
	{
		col[p[i].wz]=p[i].col;
	}
	root=build(1,n);
	for(int i=1;i<=m;i++)
	{
		if(ans[i])
		{
			incc(u[i],v[i]);
		}
	}
	dec(root,1,n);
	while(!q.empty())
	{
		int a=q.front();
		q.pop();
		printf("%d %d %d\n",a,u[a],v[a]);
		decc(u[a],v[a]);
	}
	return 0;
}
