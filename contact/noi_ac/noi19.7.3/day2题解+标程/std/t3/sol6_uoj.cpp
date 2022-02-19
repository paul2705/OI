#include <bits/stdc++.h>
#define range(i,c,o) for(register int i=(c);i<(o);++i)
using namespace std;

// QUICK_IO BEGIN HERE
#ifdef __linux__
	#define get_c getchar_unlocked
#else
	#define get_c getchar
#endif

template<typename T> inline T __getu()
{
	char c; T r=0;
	while(isspace(c=get_c()));
	for(;isdigit(c);c=get_c())
	{
		r=(r<<3)+(r<<1)+c-'0';
	}
	return r;
}

#define get_u __getu<unsigned>
// QUICK_IO END HERE

static int N;
bool vis[505];
int fat[505],match[505],pre[505],sgn[505];
queue<int> que;
vector<int> edg[505];

int getfa(const int&x) {return fat[x]==x?x:fat[x]=getfa(fat[x]);}

inline int LCA(int x,int y)
{
	vis[x]=1; for(int i=x;match[i];vis[i=pre[match[i]]]=1);
	for(;!vis[y];y=getfa(pre[match[y]]));
	vis[x]=0; for(int i=x;match[i];vis[i=pre[match[i]]]=0);
	return y;
}

inline void link(int x,int y,const int&z)
{
	for(;getfa(x)!=getfa(z);x=pre[y])
	{
		pre[x]=y,y=match[x];
		if(fat[x]==x) fat[x]=z;
		if(fat[y]==y) fat[y]=z;
		if(sgn[y]<0) sgn[y]=1,que.push(y);
	}
}

inline int find(const int&S)
{
	memset(pre,0,sizeof pre);
	memset(sgn,0,sizeof sgn);
	range(i,1,N+1) fat[i]=i;
	sgn[S]=1;
	for(;!que.empty();que.pop());
	for(que.push(S);!que.empty();que.pop())
	{
		int x=que.front();
		for(int y:edg[x]) if(getfa(x)!=getfa(y))
		{
			if(!sgn[y])
			{
				sgn[y]=-1,pre[y]=x;
				if(int z=match[y]) sgn[z]=1,que.push(z);
				else return y;
			}
			if(sgn[y]>0)
			{
				int z=LCA(x,y); link(x,y,z),link(y,x,z);
			}
		}
	}
	return 0;
}

inline void update(const int&T)
{
	for(int x=T;x;)
	{
		int y=pre[x],z=match[y]; match[y]=x,match[x]=y,x=z;
	}
}

int main()
{
	N=get_u();
	for(int M=get_u();M--;)
	{
		int u=get_u(),v=get_u();
		edg[u].push_back(v);
		edg[v].push_back(u);
	}
	int ans=0;
	range(i,1,N+1) if(!match[i])
	{
		if(int x=find(i)) ++ans,update(x);
	}
	printf("%d\n",ans);
	range(i,1,N) printf("%d ",match[i]);
	return printf("%d\n",match[N]),0;
}
