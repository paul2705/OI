#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#define ll long long
using namespace std;
template <class T>
inline void read(T &x)
{
	x=0; char c=getchar(); int f=1;
	while(!isdigit(c)){if(c=='-')f=-1; c=getchar();}
	while(isdigit(c)) x=x*10-'0'+c,c=getchar(); x*=f;
}
const int N=1230,M=N*N*5,inf=1e8;
struct Graph{
	int head[N],cur[N],dep[N],ecnt;
	void init()
	{
		ecnt=0;
		memset(head,-1,sizeof(head));
	}
	struct ed{int to,next,w;}e[M];
	queue<int> q;
	void ad(int x,int y,int w)
	{
		e[ecnt]=(ed){y,head[x],w}; head[x]=ecnt++;
		e[ecnt]=(ed){x,head[y],0}; head[y]=ecnt++;
	}
	bool bfs(int s,int t)
	{
		memset(dep,-1,sizeof(dep));
		memcpy(cur,head,sizeof(head));
		while(!q.empty()) q.pop();
		q.push(s),dep[s]=0;
		while(!q.empty())
		{
			int u=q.front(); q.pop();
			for(int k=head[u];~k;k=e[k].next)
			if(e[k].w)
			{
				int v=e[k].to;
				if(!~dep[v])
				{
					dep[v]=dep[u]+1,q.push(v);
					if(v==t) return 1;
				}
			}
		}
		return 0;
	}
	int dfs(int u,int t,int f)
	{
		if(u==t||!f) return f;
		int ret=0,tmp;
		for(int &k=cur[u];~k;k=e[k].next)
		{
			int v=e[k].to;
			if(e[k].w&&dep[v]==dep[u]+1&&(tmp=dfs(v,t,min(f,e[k].w))))
			{
				e[k].w-=tmp,e[k^1].w+=tmp;
				ret+=tmp,f-=tmp;
				if(!f) return ret;
			}
		}
		return ret;
	}
	int work(int s,int t)
	{
		int ans=0;
		while(bfs(s,t)) ans+=dfs(s,t,inf);
		return ans;
	}
}G;
int n,m;
struct itm{
	int s,t,id;
	friend bool operator <(itm a,itm b){return a.t==b.t?a.id>b.id:a.t>b.t;}
}A[410];
bool cmp(itm a,itm b){return a.s<b.s;}
priority_queue<itm> q;
int sz=0;
int solve()
{
	int pa=1,pb=m+1,tot=0;
	sort(A+1,A+m+1,cmp),sort(A+m+1,A+n+1,cmp);
	for(int i=1;i<=sz;i++)
	{
		while(pa<=m&&A[pa].s<=i) q.push(A[pa]),pa++;
		while(pb<=n&&A[pb].s<=i) q.push(A[pb]),pb++;
		while(!q.empty()&&q.top().t<i) q.pop();
		if(q.empty()) continue;
		tot++,q.pop();
	}
	return tot;
}
int main()
{
	read(n),read(m); G.init();
	for(int i=1;i<=n;i++) read(A[i].s),read(A[i].t),A[i].id=i,sz=max(sz,A[i].t);
	int S=n+2*sz+2,T=n+2*sz+3;
	for(int i=1;i<=m;i++)
	{
		G.ad(S,i,1);
		for(int j=A[i].s;j<=A[i].t;j++) G.ad(i,n+j,inf);
	}
	for(int i=m+1;i<=n;i++)
	{
		G.ad(i,T,1);
		for(int j=A[i].s;j<=A[i].t;j++) G.ad(n+sz+j,i,inf);
	}
	for(int i=1;i<=sz;i++) G.ad(n+i,n+sz+i,1);
	int ans=G.work(S,T); printf("%d\n%d",solve(),ans);
	return 0;
}
