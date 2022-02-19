#define FIO "color"
#include <bits/stdc++.h>
#define fir first
#define sec second
#define MAX_N 100000
using namespace std;
typedef pair<int,int> pii;
template <class T> inline void read(T &x) {
	x = 0; int c = getchar(), f = 1;
	for (; !isdigit(c); c = getchar()) if (c == 45) f = -1;
	for (; isdigit(c); c = getchar()) (x *= 10) += f*(c-'0');
}
int n, m, c[MAX_N+5];
vector <int> G[MAX_N+5], E[MAX_N+5];
vector <int> p[MAX_N+5]; pii r[MAX_N+5];
int fa[MAX_N+5], son[MAX_N+5], top[MAX_N+5];
int ind, dfn[MAX_N+5], d[MAX_N+5], sz[MAX_N+5];
int into[MAX_N+5]; vector <int> seq;
void DFS(int u) {
	sz[u] = 1;
	for (int i = 0; i < (int)G[u].size(); i++) {
		int v = G[u][i]; if (v == fa[u]) continue;
		d[v] = d[u]+1, fa[v] = u, DFS(v), sz[u] += sz[v];
		if (!son[u] || sz[son[u]] < sz[v]) son[u] = v;
	}
}
void DFS(int u, int tp) {
	top[u] = tp, dfn[u] = ++ind; if (son[u]) DFS(son[u], tp);
	for (int i = 0, v; i < (int)G[u].size(); i++)
		if (((v = G[u][i])^fa[u]) && (v^son[u])) DFS(v, v);
}
int LCA(int u, int v) {
	for (; top[u] != top[v]; u = fa[top[u]])
		if (d[top[u]] < d[top[v]]) swap(u, v);
	return d[u] < d[v] ? u : v;
}
pii get(vector <int> pos) {
	if (!pos.size()) return pii(1, 1);
	if (pos.size() == 1) return pii(pos[0], pos[0]);
	int lca = pos[0], u = 0, v = 0;
	for (int i = 1; i < (int)pos.size(); i++)
		lca = LCA(lca, pos[i]);
	for (int i = 0; i < (int)pos.size(); i++)
		if (d[pos[i]] >= d[u]) u = pos[i];
	for (int i = 0; i < (int)pos.size(); i++)
		if (d[pos[i]] >= d[v] && LCA(u, pos[i]) == lca) v = pos[i];
	return pii(u, v);
}
void build() {
	for (int i = 1; i <= m; i++) {
		int lca = LCA(r[i].fir, r[i].sec);
		if (c[lca] ^ i) E[i].push_back(c[lca]), into[c[lca]]++;
		for (int j = r[i].fir; j ^ lca; j = fa[j])
			if (c[j] ^ i) E[i].push_back(c[j]), into[c[j]]++;
		for (int j = r[i].sec; j ^ lca; j = fa[j])
			if (c[j] ^ i) E[i].push_back(c[j]), into[c[j]]++;
	}
}
void topo() {
	queue <int> que;
	for (int i = 1; i <= m; i++)
		if (!into[i]) que.push(i);
	while (!que.empty()) {
		int u = que.front(); seq.push_back(u), que.pop();
		for (int i = 0, v; i < (int)E[u].size(); i++)
			if (!--into[v = E[u][i]]) que.push(v);
	}
}
int main() {
#ifndef LocalHost
	freopen(FIO".in", "r", stdin);
	freopen(FIO".out", "w", stdout);
#endif
	read(n), read(m);
	for (int i = 1; i <= n; i++)
		read(c[i]), p[c[i]].push_back(i);
	for (int i = 1, u, v; i < n; i++)
		read(u), read(v), 
		G[u].push_back(v), 
		G[v].push_back(u);
	DFS(1), DFS(1, 1);
	for (int i = 1; i <= m; i++) r[i] = get(p[i]);
	build(), topo();
	for (int i = 0; i < (int)seq.size(); i++)
		printf("%d %d %d\n", seq[i], r[seq[i]].fir, r[seq[i]].sec);
	return 0;
}
