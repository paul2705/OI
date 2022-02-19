//Author: dream_maker
#include<bits/stdc++.h>
using namespace std;
//----------------------------------------------
typedef pair<int, int> pi;
typedef long long ll;
typedef double db;
#define fi first
#define se second
#define fu(a, b, c) for (int a = b; a <= c; ++a)
#define fd(a, b, c) for (int a = b; a >= c; --a)
#define fv(a, b) for (int a = 0; a < (signed)b.size(); ++a)
const int INF_of_int = 1e9;
const ll INF_of_ll = 1e18;
template <typename T>
void Read(T &x) {
  bool w = 1;x = 0;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-') w = 0, c = getchar();
  while (isdigit(c)) {
    x = (x<<1) + (x<<3) + c -'0';
    c = getchar();
  }
  if (!w) x = -x;
}
template <typename T>
void Write(T x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) Write(x / 10);
  putchar(x % 10 + '0');
}
//----------------------------------------------
const int N = 1e5 + 10;
struct Edge {
  int v, nxt;
};
struct Map {
  Edge E[N << 1];
  int head[N], tot;
  Map() {
    memset(head, 0, sizeof(head));
    tot = 0;
  }
  void add(int u, int v) {
    E[++tot] = (Edge) {v, head[u]};
    head[u] = tot;
  }
} a, b;
int n, m;
int dep[N], fa[N], du[N];
int fro[N], to[N], w[N];
bool vis[N], mark[N], path[N];
vector<int> g[N];
void dfs(int u, int father) {
  dep[u] = dep[father] + 1;
  fa[u] = father;
  for (int i = a.head[u]; i; i = a.E[i].nxt) {
    int v = a.E[i].v;
    if (v == father) continue;
    dfs(v, u);
  }
}  
int Lca(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  while (dep[x] != dep[y]) x = fa[x];
  while (x != y) x = fa[x], y = fa[y];
  return x;
}
priority_queue<pi > q;
void bfs1(int col) {
  fu(i, 1, n) vis[i] = path[i] = 0;
  fu(i, 1, m) mark[i] = 0;
  int prt = g[col][0];
  fv(i, g[col]) {
    prt = Lca(prt, g[col][i]);
    vis[g[col][i]] = 1;
    q.push(pi(dep[g[col][i]], g[col][i]));
  }
  while (q.size()) {
    int u = q.top().se; q.pop();
    if (w[u] != col && !mark[w[u]]) {
      mark[w[u]] = 1;
      ++du[col];
      b.add(w[u], col);
    }
    if (prt == u) break;
    if (!vis[fa[u]]) {
      vis[fa[u]] = 1;
      q.push(pi(dep[fa[u]], fa[u]));
    }
  }
  fu(i, 1, n) vis[i] = 0;
  fv(i, g[col]) q.push(pi(dep[g[col][i]], g[col][i]));
  fro[col] = q.top().second; q.pop();
  int now = fro[col];
  vis[now] = 1;
  while (now != prt) {
    now = fa[now];
    vis[now] = 1;
  }
  while (q.size()) {
    if (vis[q.top().se]) {
      q.pop();
    } else {
      to[col] = q.top().se;
      break;
    }
  }
  while (q.size()) q.pop();
  if (!to[col])to[col] = prt;
}
queue<int> q1;
int topoid[N], ind = 0;
void bfs2() {
  fu(i, 1, m) if (!du[i]) q1.push(i);
  while (q1.size()) {
    int u = q1.front(); q1.pop();
    topoid[++ind] = u;
    for (int i = b.head[u]; i; i = b.E[i].nxt) {
      int v = b.E[i].v;
      if (--du[v] == 0) q1.push(v);
    }
  }
}
int main() {
  freopen("color.in", "r", stdin);
  freopen("color.out", "w", stdout);
  Read(n); Read(m);
  fu(i, 1, n) {
    Read(w[i]);
    g[w[i]].push_back(i);
  }
  fu(i, 2, n) {
    int u, v; Read(u), Read(v);
    a.add(u, v);
    a.add(v, u);
  }
  dfs(1, 0);
  fu(i, 1, m) bfs1(i);
  bfs2();
  fd(i, m, 1) Write(topoid[i]), putchar(' '), Write(fro[topoid[i]]), putchar(' '), Write(to[topoid[i]]), putchar('\n'); 
  return 0;
}
