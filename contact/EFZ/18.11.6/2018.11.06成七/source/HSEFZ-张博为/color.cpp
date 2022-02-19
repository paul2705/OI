#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 100010;

queue<int> q;
vector<int> G[maxn];
int fa[maxn], son[maxn], top[maxn], dfn[maxn], rdfn[maxn], col[maxn], dep[maxn], sz[maxn], S[maxn], T[maxn], deg[maxn*5], tag[maxn*5];
int n, m, tot = 0;
vector<int> vec[maxn];

vector<int> ng[maxn*5];

void update(int p, int v, int l, int r, int rt) {
	tag[rt] = v;
	if (l == r) {
		return;
	}
	int m = (l + r) >> 1;
	if (p <= m) update(p, v, l, m, rt<<1);
	else update(p, v, m+1, r, rt<<1|1);
}

void addEdge(int x, int L, int R, int l, int r, int rt) {
	if (L <= l && r <= R && !tag[rt]) {
		ng[rt+m].push_back(x);
		deg[x] ++;
		return;
	}
	if (l == r) {
		return;
	}
	int m = (l + r) >> 1;
	if (L <= m) addEdge(x, L, R, l, m, rt<<1);
	if (R > m) addEdge(x, L, R, m+1, r, rt<<1|1);
}

void build(int l, int r, int rt) {
	if (l == r) {
		ng[col[rdfn[l]]].push_back(rt+m);
		deg[rt+m] ++;
		return;
	}
	int mid = (l + r) >> 1;
	ng[(rt<<1)+m].push_back(rt+m);
	deg[rt+m] ++;
	ng[(rt<<1|1)+m].push_back(rt+m);
	deg[rt+m] ++;
	build(l, mid, rt<<1);
	build(mid+1, r, rt<<1|1);
}

void dfs_init(int u, int f) {
	fa[u] = f; sz[u] = 1;
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (v != f) {
			dep[v] = dep[u] + 1;
			dfs_init(v, u);
			sz[u] += sz[v];
			if (!son[u] || sz[v] > sz[son[u]]) son[u] = v;
		}
	}
}

void dfs_find(int u, int t) {
	top[u] = t;
	dfn[u] = ++tot;
	rdfn[tot] = u;
	if (!son[u]) return;
	dfs_find(son[u], t);
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (v != fa[u] && v != son[u]) {
			dfs_find(v, v);
		}
	}
}

int lca(int u, int v) {
	while (top[u] != top[v]) {
		if (dep[top[u]] > dep[top[v]]) {
			u = fa[top[u]];
		} else v = fa[top[v]];
	}
	return dep[u] < dep[v] ? u : v;
}

void addEdge(int x, int u, int v) {
	while (top[u] != top[v]) {
		if (dep[top[u]] > dep[top[v]]) {
			addEdge(x, dfn[top[u]], dfn[u], 1, n, 1);
			u = fa[top[u]];
		} else {
			addEdge(x, dfn[top[v]], dfn[v], 1, n, 1);
			v = fa[top[v]];
		}
	}
	if (dep[u] > dep[v]) swap(u, v);
	addEdge(x, dfn[u], dfn[v], 1, n, 1);
}

vector<int> ans;

int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &col[i]);
		vec[col[i]].push_back(i);
	}
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs_init(1, 0);
	dfs_find(1, 0);
	build(1, n, 1);
	for (int i = 1; i <= m; i++) {
		if (vec[i].empty()) {
			printf("%d %d %d\n", i, 1, 1);
			continue;
		}
		int l = vec[i][0], x = 0;
		for (int j = 0; j < vec[i].size(); j++) {
			int u = vec[i][j];
			l = lca(l, u);
			if (!x || dep[u] > dep[x]) x = u;
		}
		int y = 0;
		for (int j = 0; j < vec[i].size(); j++) {
			int u = vec[i][j];
			if (u == l || lca(u, x) == u) continue;
			if (!y || dep[u] > dep[y]) y = u;
		}
		if (y) {
			S[i] = x; T[i] = y;
		} else {
			S[i] = x; T[i] = l;
		}
		for (int j = 0; j < vec[i].size(); j++) {
			int u = vec[i][j];
			update(dfn[u], 1, 1, n, 1);
		}
		addEdge(i, S[i], T[i]);
		for (int j = 0; j < vec[i].size(); j++) {
			int u = vec[i][j];
			update(dfn[u], 0, 1, n, 1);
		}
	}
	queue<int> q;
	for (int i = 1; i <= 4*n+m; i++) {
		if (deg[i] == 0) q.push(i);
	}
	while (!q.empty()) {
		int u = q.front();
		if (u <= m) {
			if (!vec[u].empty()) {
				ans.push_back(u);
			}
		}
		q.pop();
		for (int i = 0; i < ng[u].size(); i++) {
			int v = ng[u][i];
			deg[v] --;
			if (deg[v] <= 0) q.push(v);
		}
	}
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		int u = ans[i];
		printf("%d %d %d\n", u, S[u], T[u]);
	}
	return 0;
}
