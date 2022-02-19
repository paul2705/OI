#include <algorithm>
#include <utility>
#include <cstring>
#include <cstdio>
#include <vector>
#define pb push_back
int lst[3000005], to[40000005], pre[40000005], tot;
int fa[100005][25], idx[100005][25], dep[100005];
int deg[3000005], que[3000005], col[100005];
bool del[100005];
std::pair<int, int> dia[100005];
std::vector<int> vec[100005];
inline void add_edge(int u, int v)
{
	to[tot] = v;
	pre[tot] = lst[u];
	lst[u] = tot++;
	deg[v]++;
}
void dfs(int u, int f = -1)
{
	fa[u][0] = f;
	for (int i = 1; i < 20; i++)
		fa[u][i] = fa[u][i - 1] == -1 ? -1 : fa[fa[u][i - 1]][i - 1];
	for (int i = lst[u]; ~i; i = pre[i])
	{
		int v = to[i];
		if (v == f)
			continue;
		dep[v] = dep[u] + 1;
		dfs(v, u);
	}
}
inline int jump(int u, int d)
{
	for (int i = 0; i < 20; i++)
	{
		if (d & (1 << i))
			u = fa[u][i];
	}
	return u;
}
inline int lca(int u, int v)
{
	if (dep[u] > dep[v])
		std::swap(u, v);
	v = jump(v, dep[v] - dep[u]);
	if (u == v)
		return u;
	for (int i = 19; i >= 0; i--)
	{
		if (fa[u][i] != fa[v][i])
		{
			u = fa[u][i];
			v = fa[v][i];
		}
	}
	return fa[u][0];
}
inline int dis(int u, int v) { return dep[u] + dep[v] - (dep[lca(u, v)] << 1); }
int main()
{
	freopen("color.in", "r", stdin);
	freopen("color.out", "wt", stdout);
	memset(lst, -1, sizeof(lst));
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", col + i);
		vec[--col[i]].pb(i);
	}
	for (int i = 1; i < n; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		add_edge(--u, --v);
		add_edge(v, u);
	}
	dfs(0);
	for (int i = 0; i < m; i++)
	{
		if (vec[i].empty())
			continue;
		int u = vec[i][0];
		for (int x : vec[i])
		{
			if (dis(x, vec[i][0]) > dis(u, vec[i][0]))
				u = x;
		}
		int v = u;
		for (int x : vec[i])
		{
			if (dis(x, u) > dis(v, u))
				v = x;
		}
		dia[i] = {u, v};
		for (int x : vec[i])
		{
			if (x != u && x != v)
				del[x] = true;
		}
	}
	memset(lst, -1, sizeof(lst));
	memset(deg, 0, sizeof(deg));
	tot = 0;
	int cnt = m;
	for (int i = 0; i < n; i++)
	{
		idx[i][0] = cnt++;
		if (!del[i])
			add_edge(idx[i][0], col[i]);
	}
	for (int i = 1; i < 20; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (-1 == fa[j][i - 1])
				continue;
			idx[j][i] = cnt++;
			add_edge(idx[j][i], idx[j][i - 1]);
			add_edge(idx[j][i], idx[fa[j][i - 1]][i - 1]);
		}
	}
	for (int i = 0; i < m; i++)
	{
		if (vec[i].empty())
			continue;
		int u = dia[i].first, v = dia[i].second, x = lca(u, v);
		if (u == v)
			continue;
		if (u == x)
			std::swap(u, v);
		if (v == x)
		{
			u = fa[u][0];
			for (int j = 19; j >= 0; j--)
			{
				if (~u && (dep[u] - dep[x] & (1 << j)))
				{
					add_edge(i, idx[u][j]);
					u = fa[u][j];
				}
			}
		}
		else
		{
			u = fa[u][0];
			v = fa[v][0];
			for (int j = 19; j >= 0; j--)
			{
				if (~u && (dep[u] - dep[x] + 1 & (1 << j)))
				{
					// printf("= %d %d %d\n", i, u, j);
					add_edge(i, idx[u][j]);
					u = fa[u][j];
				}
				if (~v && (dep[v] - dep[x] + 1 & (1 << j)))
				{
					// printf("- %d %d %d\n", i, v, j);
					add_edge(i, idx[v][j]);
					v = fa[v][j];
				}
			}
		}
	}
	int he = 0, ta = 0;
	for (int i = 0; i < cnt; i++)
	{
		if (!deg[i])
			que[ta++] = i;
	}
	std::sort(que, que + ta, [&] (int x, int y) { return vec[x].size() < vec[y].size(); });
	while (he < ta)
	{
		int u = que[he++];
		if (u < m)
			printf("%d %d %d\n", u + 1, dia[u].first + 1, dia[u].second + 1);
		for (int i = lst[u]; ~i; i = pre[i])
		{
			if (!--deg[to[i]])
				que[ta++] = to[i];
		}
	}
	return 0;
}
