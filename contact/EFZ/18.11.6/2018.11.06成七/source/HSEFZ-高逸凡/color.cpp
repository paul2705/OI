#include<bits/stdc++.h>

#define UPLOAD

const int maxn = 100005;
struct etype {
	int ed, nxt;
} e[maxn * 2], ge[maxn * 20];


int tot = 0, n, m;
int hd[maxn], ghd[maxn], p[maxn], first[maxn], last[maxn], top[maxn], q[maxn * 2], deg[maxn], d[maxn], pp[maxn];
int f[maxn][20];
bool v[maxn];

void addedge(int x, int y)
{
	e[++tot].ed = y, e[tot].nxt = hd[x], hd[x] = tot;
}

void addgraph(int x, int y)
{
	ge[++tot].ed = y, ge[tot].nxt = ghd[x], ghd[x] = tot;
}

void dfs1(int x, int fa)
{
	f[x][0] = fa;
	for(int i = 1; i <= 18; i++)
		f[x][i] = f[ f[x][i - 1] ][i - 1];
	if (!first[p[x]]) first[p[x]] = x;
	if (v[p[x]]) last[p[x]] = x; else first[p[x]] = x;

	//printf("%d %d\n", x, v[p[x]]);
	for(int k = hd[x]; k; k = e[k].nxt)
	{
		int j = e[k].ed; //printf("%d\n", j);
		if (j != fa) 
		{
			d[j] = d[x] + 1;
			dfs1(j, x);
		}
	}
	if (x == first[p[x]]) v[p[x]] = false;
}

int lca(int a, int b)
{
	if (d[a] < d[b]) std::swap(a, b);
	while (d[a] > d[b]) a = f[a][ pp[ d[a] - d[b] ] ];
	int j = 18;
	while (a != b)
	{
		if (f[a][0] == f[b][0]) break;
		while (f[a][j] == f[b][j] && j > 0) j--;
		a = f[a][j], b = f[b][j];
	}
	if (a == b) return a; else return f[a][0];
}

void dfs2(int x)
{
	for(int k = hd[x]; k; k = e[k].nxt)
	{
		int j = e[k].ed;
		if (j != f[x][0]) 
		{
			if (p[j] != p[x] && j != top[p[j]])
				addgraph(p[j], p[x]), deg[p[x]]++;
			dfs2(j);
		}
	}
}

int main()
{
	#ifdef UPLOAD
		freopen("color.in", "r", stdin);
		freopen("color.out", "w", stdout);
	#endif

	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &p[i]);
	for(int i = 1, j = 0; i <= n; i++)
		if (i >= (1 << (j + 1))) pp[i] = ++j; else pp[i] = j;

	for(int i = 1; i <= n - 1; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		//printf("%d %d\n", x, y);
		addedge(x, y); addedge(y, x);
	}

	memset(first, 0, sizeof(first));
	memset(last, 0, sizeof(last));
	memset(v, true, sizeof(v));
	memset(top, 0, sizeof(top));
	memset(d, 0, sizeof(d));
	dfs1(1, 0);

	//return 0;
	for(int i = 1; i <= m; i++)
	{
		if (!first[i]) 
		{
			printf("%d %d %d\n", i, 1, 1);
			return 0;
		}
		top[i] = lca(first[i], last[i]);
	}
	//return 0;

	tot = 0;
	dfs2(1);

	//return 0;
	memset(v, false, sizeof(v));
	int ft = 1, rr = 0; 
	for(int i = 1; i <= m; i++)
		if (!deg[i])
		{
			q[++rr] = i, v[i] = true;
			printf("%d %d %d\n", i, first[i], last[i]);
		}
	while (ft <= rr)
	{	
		int x = q[ft];
		for(int k = ghd[x]; k; k = ge[k].nxt)
		{
			int j = ge[k].ed;
			deg[j]--;
			if (!deg[j])
			{
				q[++rr] = j, v[j] = true;
				printf("%d %d %d\n", j, first[j], last[j]);
			}
		}
		ft++;
	}
	return 0;
}