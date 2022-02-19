#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
using namespace std;
typedef bool boolean;

const int N = 1e5 + 5;

typedef class Event {
	public:
		int u, v, c;

		Event() {	}
		Event(int u, int v, int c):u(u), v(v), c(c) {	}
}Event;

FILE* fin = fopen("color.in", "r");
FILE* fout = fopen("color.out", "w");

int n, m;
int tp;
Event E[N];
queue<int> q;
boolean vis[N];
boolean inq[N];
map<int, int> mp[N];
vector<int> g[N], col[N];
int d[N], uf[N], cnt[N], c[N], fa[N];

inline void init() {
	fscanf(fin, "%d%d", &n, &m), tp = m;
	for (int i = 1; i <= n; i++) {
		fscanf(fin, "%d", c + i);
		col[c[i]].push_back(i);
		cnt[c[i]]++;
	}
	for (int i = 1, u, v; i < n; i++) {
		fscanf(fin, "%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		uf[i] = i, mp[i][c[i]] = 1;
		if (cnt[c[i]] == 1)
			q.push(c[i]), inq[c[i]] = true;
	}
}

int find(int x) {
	return (uf[x] == x) ? (x) : (uf[x] = find(uf[x]));
}

void unit(int u, int v) {
	int fu = find(u), fv = find(v);
	if (fu == fv)
		return;
	if (mp[fu].size() < mp[fv].size())
		swap(fu, fv);
	map<int, int> :: iterator it = mp[fv].begin();
	for ( ; it != mp[fv].end(); it++) {
		mp[fu][it->first] += it->second;
		if (!inq[it->first] && mp[fu][it->first] == cnt[it->first])
			q.push(it->first), inq[it->first] = true;
	}
	uf[fv] = fu;
}

void dfs(int p, int f) {
	fa[p] = f, d[p] = d[f] + 1;
	for (auto e : g[p])
		if (e ^ f)
			dfs(e, p);
}

boolean cmp(const int& a, const int& b) {
	return d[a] < d[b];
}

void color(int c) {
	vector<int>& V = col[c];
	sort(V.begin(), V.end(), cmp);

	if (V.size() == 1)
		E[tp--] = Event(V[0], V[0], c);
	else {
		int lst = V[0];
		for (unsigned i = 1; i < V.size(); i++)
			if (fa[V[i]] == lst)
				lst = V[i], vis[V[i]] = true;
		boolean aflag = true;
		for (unsigned i = V.size() - 1; i; i--)
			if (!vis[V[i]]) {
				aflag = false;
				E[tp--] = Event(lst, V[i], c);
				break;
			}
		if (aflag) {
			E[tp--] = Event(V[0], lst, c);
		}
	}

	for (auto p : V)
		for (auto e : g[p])
			unit(e, p);
}

inline void solve() {
	dfs(1, 0);
	for (int i = 1; i <= n; i++)
		for (auto e : g[i])
			if (c[e] == c[i])
				unit(e, i);
	while (!q.empty()) {
		int c = q.front();
		q.pop();
		color(c);
	}
	for (int i = 1; i <= m; i++)
		if (!cnt[i])
			fprintf(fout, "%d 1 1\n", i);
	for (int i = tp + 1; i <= m; i++)
		fprintf(fout, "%d %d %d\n", E[i].c, E[i].u, E[i].v);
}

int main() {
	init();
	solve();
	return 0;
}
