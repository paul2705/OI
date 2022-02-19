#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline int read()
{
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+c-'0';c=getchar();}
	return x*f;
}
#define pb push_back
const int maxn = 105;
vector<int> linker[maxn], hav[maxn];
int n, fa[maxn], w[maxn], p[maxn], m, dep[maxn], s[maxn], t[maxn];
bool tag[maxn][maxn], vis[maxn];
inline void dfs(int x)
{
	dep[x] = dep[fa[x]] + 1;
	for(int cur : linker[x])
	{
		if(cur == fa[x])
			continue;
		fa[cur] = x;
		dfs(cur);
	}
}
inline int lca(int x, int y)
{
	int col = p[x];
	while(x != y)
	{
		if(dep[x] < dep[y])
			swap(x, y);
		if(p[x] != col)
			tag[x][col] = 1;
		x = fa[x];
	}
	if(p[x] != col)
		tag[x][col] = 1;
	return x;
}
bool g[maxn][maxn];
inline void dfs2(int col)
{
	for(int i = 1; i <= m; i ++)
		if(g[col][i] && !vis[i] && i != col) dfs2(i);
	printf("%d %d %d\n", col, s[col], t[col]);
	vis[col] = 1;
}
int main()
{
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	n = read(), m = read();
	for(int i = 1; i <= n; i ++) hav[p[i] = read()].pb(i);
	for(int i = 1; i < n; i ++)
	{
		int u = read(), v = read();
		linker[u].pb(v);
		linker[v].pb(u);
	}
	dfs(1);
	for(int i = 1; i <= m; i ++)
	{
		if(hav[i].empty())
		{
			printf("%d %d %d\n", i, 1, 1);
			continue;
		}
		int curx = 0, cury = 0, dis = 0;
		for(int cur : hav[i])
			for(int cur2 : hav[i])
			{
				int l = lca(cur, cur2);
				int d = dep[cur] + dep[cur2] - dep[l] * 2 + 1;
				if(d > dis) dis = d, curx = cur, cury = cur2;
			}
		s[i] = curx, t[i] = cury;
	}
//	for(int i = 1; i <= n; i ++)
//	{
//		cerr << tag[i][1] << " " << tag[i][2] << " " << tag[i][3] << endl;
//	}
//	cerr << "--- ------ ---" << endl;
//	for(int i = 1; i <= m; i ++)
//		cerr << s[i] << " " << t[i] << endl;
//	cerr << "--- ------ ---" << endl;
	for(int i = 1; i <= m; i ++)
		if(hav[i].size())
		{
			for(int cur : hav[i])
				for(int j = 1; j <= m; j ++)
					if(tag[cur][j])
						g[i][j] = 1;
		}
	for(int i = 1; i <= m; i ++)
		if(hav[i].size() && !vis[i])
			dfs2(i);
	return 0;
}
