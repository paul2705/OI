#include<bits/stdc++.h>
using namespace std;
int n,m;
int p[110000];
int hed[110000],nxt[210000],ed[210000],l = 0;
int num[110000];
int rehed[110000],renxt[110000],Reed[110000],r[110000],rl = 0,st[110000],end[110000];
inline void ReLine(int u,int v){renxt[++rl] = rehed[u],rehed[u] = rl,Reed[rl] = v,r[v]++;}
inline void Line(int u,int v)
{
	nxt[++l] = hed[u],hed[u] = l,ed[l] = v;
	nxt[++l] = hed[v],hed[v] = l,ed[l] = u;
}
inline int read()
{
	int s = 0,w = 1;char ch = getchar();
	while(ch<'0'||ch>'9'){if(ch == '-') w = -1;ch = getchar();}
	while(ch>='0'&&ch<='9'){s = (s << 1) + (s << 3) + ch - '0';ch = getchar();}
	return s * w;
}
inline void DFS(int u,int fa)
{
	if(st[p[u]]) num[p[u]]--;
	for(int i = hed[u];i;i=nxt[i])
	{
		int x = st[p[u]];
		if(ed[i] == fa) continue;
		DFS(ed[i],u);
		if(!x && st[p[u]])
		{
			x = 1;
			num[p[u]]--;
		}
		if(num[p[ed[i]]] && p[ed[i]] != p[u]) ReLine(p[ed[i]],p[u]);
	}
	if(!st[p[u]]) st[p[u]] = u,num[p[u]]--; 
	if(!num[p[u]]&&!end[p[u]]) end[p[u]] = u;
}
inline void Map()
{
	queue<int>Q;
	for(int i = 1;i<=m;i++)
		if(!r[i])
			if(!st[i]) printf("%d 1 %d\n",i,n);
			else Q.push(i);
	while(!Q.empty())
	{
		int k = Q.front();
		Q.pop();
		printf("%d %d %d\n",k,st[k],end[k]);
		for(int i = rehed[k];i;i=renxt[i])
		{
			int w = Reed[i];
			r[w]--;
			if(!r[w]) Q.push(w);
		}
	}
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	n = read(),m = read();
	for(int i = 1;i<=n;i++) p[i] = read(),num[p[i]]++;
	for(int i = 1;i<n;i++) Line(read(),read());
	DFS(1,0);
	Map();
	return 0;
}
