#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

const int maxn = 2010;

typedef long long ll;

int fa[maxn][maxn], dep[maxn][maxn], vis[maxn][maxn];
int par[maxn], l[maxn], e = 0, n, m, q;

struct Edge {
	int v, x;
} E[maxn<<1];

inline void addEdge(int u, int v) {
	E[e].v = v; E[e].x = l[u]; l[u] = e++;
}

void dfs(int u, int f) {
	par[u] = f;
	for (int p = l[u]; p >= 0; p = E[p].x) {
		int v = E[p].v;
		if (v != f) {
			dfs(v, u);
		}
	}
}

int findroot(int i, int x) {
	if (fa[i][x] == x) return x;
	return (fa[i][x] = findroot(i, fa[i][x]));
}

int main() {
	memset(l, -1, sizeof(l));
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		addEdge(u, v);
		addEdge(v, u);
	}
	dfs(1, 0);
	for (int i = 1; i <= m; i++) {
		for (int j = 2; j <= n; j++) {
			fa[i][j] = par[j];
		}
		fa[i][1] = 1;
	}
	for (int i = 1; i <= q; i++) {
		int l, r, x; scanf("%d%d%d", &l, &r, &x);
		for (int j = l; j <= r; j++) {
			findroot(j, x);
		}
	}
	for (int i = 1; i <= m; i++) {
		vis[i][1] = 1; int ans = 0;
		for (int j = 2; j <= n; j++) {
			int cur = j, cnt = 0;
			while (cur != 1) {
				++ cnt;
				cur = fa[i][cur];
			}
			ans += cnt;
		}
		printf("%d ", ans);
	}
	puts("");
	return 0;
}