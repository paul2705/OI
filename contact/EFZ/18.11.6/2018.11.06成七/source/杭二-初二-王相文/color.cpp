#include <bits/stdc++.h>
#define CIOS ios::sync_with_stdio(false);
#define For(i, a, b) for(register int i = a; i <= b; i++)
#define Rof(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> ";
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename T>
inline void read(T &f) {
	f = 0; T fu = 1; char c = getchar();
	while(c < '0' || c > '9') {if(c == '-') fu = -1; c = getchar();}
	while(c >= '0' && c <= '9') {f = (f << 3) + (f << 1) + (c & 15); c = getchar();}
	f *= fu;
}

template <typename T>
void print(T x) {
	if(x < 0) putchar('-'), x = -x;
	if(x < 10) putchar(x + 48);
	else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
	print(x); putchar(t);
}

const int N = 1e5 + 5;

vector <int> G[N], G2[N], t[N];
vector <int> :: iterator it;
int d[N], top[N], siz[N], wson[N], fa[N], a[N], l[N], r[N], in[N];
int n, m;

void dfs1(int u, int f) {
	siz[u] = 1;
	for(vector <int> :: iterator it = G2[u].begin(); it != G2[u].end(); it++) { if(*it == f) continue; fa[*it] = u; d[*it] = d[u] + 1; dfs1(*it, u); siz[u] += siz[*it]; if(siz[*it] > siz[wson[u]]) wson[u] = *it; }
}

void dfs2(int u, int tp) {
	top[u] = tp;
	if(wson[u]) dfs2(wson[u], tp);
	for(vector <int> :: iterator it = G2[u].begin(); it != G2[u].end(); it++) { if(*it == wson[u] || *it == fa[u]) continue; dfs2(*it, *it); }
}

int LCA(int x, int y) {
	while(top[x] != top[y]) { if(d[top[x]] < d[top[y]]) swap(x, y); x = fa[top[x]]; }
	return d[x] < d[y] ? x : y;
}

int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	read(n); read(m);
	for(register int i = 1; i <= n; i++) read(a[i]), t[a[i]].push_back(i);
	for(register int i = 1; i < n; i++) { int a, b; read(a); read(b); G2[a].push_back(b); G2[b].push_back(a); }
	dfs1(1, 0); dfs2(1, 1);
	for(register int i = 1; i <= m; i++) { 
		int len = t[i].size(); 
		if(len == 0) {
			print(i, ' ');
			print(1, ' ');
			print(1, '\n');
			continue;
		}
		l[i] = r[i] = t[i][0];
		for(register int j = 1; j < len; j++) {
			int lca = LCA(l[i], r[i]);
			int lca2 = LCA(l[i], t[i][j]);
			if(d[l[i]] + d[r[i]] - 2 * d[lca] < d[l[i]] + d[t[i][j]] - 2 * d[lca2]) r[i] = t[i][j];
		}
		l[i] = r[i];
		for(register int j = 0; j < len; j++) {
			int lca = LCA(l[i], r[i]);
			int lca2 = LCA(l[i], t[i][j]);
			if(d[l[i]] + d[r[i]] - 2 * d[lca] < d[l[i]] + d[t[i][j]] - 2 * d[lca2]) r[i] = t[i][j];
		}
	}
	for(register int i = 1; i <= m; i++) {
		if(!l[i]) continue;
		int x = l[i], y = r[i];
		while(x != y) {
			if(d[x] < d[y]) swap(x, y);
			x = fa[x]; if(a[x] != i) {
				G[i].push_back(a[x]);
				in[a[x]]++;
			}
		}
	}
	queue <int> q;
	for(register int i = 1; i <= m; i++) {
		if(!l[i]) continue;
		if(!in[i]) q.push(i);
	}
	while(!q.empty()) {
		int u = q.front(); q.pop();
		print(u, ' ');
		print(l[u], ' ');
		print(r[u], '\n');
		for(it = G[u].begin(); it != G[u].end(); it++) {
			in[*it]--;
			if(!in[*it]) q.push(*it);
		}
	}
	return 0;
}
