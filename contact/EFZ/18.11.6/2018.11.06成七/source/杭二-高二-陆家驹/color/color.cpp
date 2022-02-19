#include<cstdio>
#include<cstring>
#include<map>
#include<queue>
#include<stack>
using namespace std;
const int N=100010;
int n,m,head[N],cnt,c[N],fa[N],du[N],A[N],f[N],ans[N][3],ansn,dep[N];
int l[N],r[N];
struct E{int to,nxt;}e[N<<1],ee[N<<1];
bool vis[N],exi[N],inq[N],ok[N];
map<int,bool>b[N];
queue<int>q,s[N];
void judge(){freopen("color.in","r",stdin);freopen("color.out","w",stdout);}
int read() {int d=0,f=1; char c=getchar(); while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();} while (c>='0'&&c<='9') d=(d<<3)+(d<<1)+c-48,c=getchar(); return d*f;}
void add(int x,int y)
{
	e[++cnt]=(E){y,head[x]}; head[x]=cnt;
	e[++cnt]=(E){x,head[y]}; head[y]=cnt;
}
void add2(int x,int y)
{
	ee[++cnt]=(E){y,head[x]}; head[x]=cnt;
	ee[++cnt]=(E){x,head[y]}; head[y]=cnt;
}
int ask(int x){return fa[x]==x?x:fa[x]=ask(fa[x]);}
void dfs(int u,int sum)
{
	if (f[c[u]]==sum)
	{
		ansn++;
		ans[ansn][0]=l[ask(u)],ans[ansn][1]=u,ans[ansn][2]=c[u];
		r[ask(u)]=u; ok[ask(u)]=1;
		return;
	}
	vis[u]=1; bool bo=0;
	for (int i=head[u];i;i=e[i].nxt)
	{
		int v=e[i].to;
		if (vis[v]||c[u]!=c[v]) continue;
		bo=1;
		fa[v]=u; dfs(v,sum+1);
	}
	if (!bo) r[ask(u)]=u;
}
void dfs2(int u)
{
	for (int i=head[u];i;i=e[i].nxt)
	{
		int v=e[i].to;
		if (exi[v]) continue;
		exi[v]=1; dep[v]=dep[u]+1; dfs2(v);
	}
}
int main()
{
	//judge();
	n=read(); m=read();
	for (int i=1;i<=n;i++) c[i]=read(),f[c[i]]++;
	for (int i=1;i<n;i++) add(read(),read());
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int u=1;u<=n;u++)
		for (int i=head[u];i;i=e[i].nxt)
		{
			int v=e[i].to;
			if (c[u]==c[v]) du[u]++,A[u]=v;
		}
	for (int i=1;i<=n;i++) if (du[i]==1&&!vis[i]) l[i]=i,dfs(i,1);
	dfs2(ans[1][0]);
	cnt=0; memset(head,0,sizeof head);
	for (int u=1;u<=n;u++)
		for (int i=head[u];i;i=e[i].nxt)
		{
			int v=e[i].to;
			int x=ask(v),y=ask(u);
			if (x==y||b[x][y]) continue;
			add2(x,y); b[x][y]=b[y][x]=1;
		}
	for (int i=1;i<=n;i++) exi[i]=0;
	for (int i=1;i<=n;i++) exi[ask(i)]=1;
	for (int i=1;i<=n;i++)
		if (exi[i])
			printf("%d ",i),printf("%d ",l[i]),printf("%d\n",r[i]);
	for (int i=1;i<=n;i++) if (exi[i]) if (dep[l[i]]<dep[r[i]]) l[i]=r[i];
	q.push(ans[1][0]);
	while (!q.empty())
	{
		int u=q.front(); q.pop(); inq[u]=0;
		while (!s[c[u]].empty())
		{
			int v=s[c[u]].front();
			if (!inq[v]) s[c[u]].pop(); else break;
		}
		if (!ok[u]&&!s[c[u]].empty())
		{
			ansn++;
			ans[ansn][0]=l[u]; ans[ansn][1]=l[s[c[u]].front()];
			ans[ansn][2]=c[u];
			s[c[u]].pop();
		}
		for (int i=head[u];i;i=ee[i].nxt)
		{
			int v=ee[i].to;
			if (exi[v]) q.push(v),exi[v]=0,inq[v]=1,s[c[v]].push(v);
		}
	}
	for (int i=ansn;i>=1;i--)
		printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);
	return 0;
}
