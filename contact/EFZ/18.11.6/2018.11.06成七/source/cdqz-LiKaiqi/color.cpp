//copied by aziint
//pch gay
//#include "pch.h"
#include<bits/stdc++.h>
using namespace std;

template <class T> void read(T& x) {
	x = 0; bool flag = 0; char ch = getchar(); for (; ch < '0' || ch > '9'; ch = getchar()) flag |= ch == '-';
	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = (x << 1) + (x << 3) + ch - 48; flag ? x = ~x + 1 : 0;
}

#pragma GCC diagnostic error "-std=c++98"
//#pragma GCC optimize(2)

#define N 100010
#define rep(i, a, b) for (auto i = (a); i <= (b); ++i)
#define drp(i, a, b) for (auto i = (a); i >= (b); --i)
#define ll long long

class Graph {
private:
	int tot = 0;
public:
	struct { int v, next; }e[N << 1];
	int head[N];
	inline void add(int u, int v) {
		e[++tot].v = v, e[tot].next = head[u], head[u] = tot;
	}
}T, G;

int n, m, col[N], fa[N][17], dep[N], dis[N], A[N], B[N], deg[N];
bool vis[N];

int getLca(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);
	drp(i, 16, 0) if (dep[fa[u][i]] >= dep[v]) u = fa[u][i]; if (u == v) return u;
	drp(i, 16, 0) if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i]; return fa[u][0];
}

void dfs(int u) {
	rep(i, 1, 16) fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (int i = T.head[u], v; i; i = T.e[i].next) if ((v = T.e[i].v) != fa[u][0])
		fa[v][0] = u, dep[v] = dep[u] + 1, dfs(v);
}

void dfs(int u, int pre) {
	for (int i = T.head[u], v; i; i = T.e[i].next) if ((v = T.e[i].v) != pre)
		dis[v] = dis[u] + 1, dfs(v, u);
}

queue<int> q;

int main() {
	freopen("color.in", "r", stdin); freopen("color.out", "w", stdout);
	read(n), read(m);
	rep(i, 1, n) read(col[i]);
	rep(i, 2, n) {
		int u, v; read(u), read(v);
		T.add(u, v), T.add(v, u);
	}
	dep[1] = 1; dfs(1);
	rep(i, 1, m) {
		int S = 0;
		rep(j, 1, n) if (col[j] == i && dep[j] > dep[S]) S = j;
		if (!S) {
			A[i] = 1, B[i] = n;
			continue;
		}
		dis[S] = 1, dfs(S, 0);
		int T = S;
		rep(j, 1, n) if (col[j] == i && dis[j] > dis[T]) T = j;
		A[i] = S, B[i] = T;
		//printf("col %d %d\n", S, T);
		int lca = getLca(S, T);
		memset(vis, 0, sizeof vis); vis[i] = 1;
		for (int t = S; t != fa[lca][0]; t = fa[t][0]) if (!vis[col[t]])
			G.add(i, col[t]), ++deg[col[t]], vis[col[t]] = 1;
		for (int t = T; t != fa[lca][0]; t = fa[t][0]) if (!vis[col[t]])
			G.add(i, col[t]), ++deg[col[t]], vis[col[t]] = 1;
	}
	rep(i, 1, m) if (!deg[i]) q.push(i);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		printf("%d %d %d\n", u, A[u], B[u]);
		for (int i = G.head[u], v; i; i = G.e[i].next)
			if (!--deg[v = G.e[i].v]) q.push(v);
	}
	return 0;
}
