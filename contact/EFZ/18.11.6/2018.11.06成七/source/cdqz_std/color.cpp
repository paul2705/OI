#include <cstdio>
#include <algorithm>

#define ll long long
#define db double
#define ull unsigned long long
#define uint unsigned int
#define FIO "color"
#define dbug(...) fprintf(stderr, __VA_ARGS__)

template <typename Y> inline bool updmin(Y &a, Y b){if (a > b) {a = b; return 1;} return 0;}
template <typename Y> inline bool updmax(Y &a, Y b){if (a < b) {a = b; return 1;} return 0;}
template <typename Y> inline Y abs(Y a){if (a < 0) a = -a; return a;}
template <typename Y> inline Y sqr(Y a){return a * a;}

typedef std::pair<int, int> par;
#define fx first
#define fy second
#define mpar std::make_pair
#define pb push_back

int read() {
  int w = 1, q = 0, ch = ' ';
  for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') w = -1;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) q = q * 10 + ch - 48;
  return q * w;
}

inline void FileIO(){freopen(FIO".in", "r", stdin); freopen(FIO".out", "w", stdout);}

#include <vector>
const int N = 100010;
int n, m, cnt, col[N], dep[N], fa[N][20], id[N][20], U[N], V[N];
int dfn[N], tim = 0;
int deg[N * 22];
std::vector<int> G[N], P[N * 22], poses[N];

inline void adde(int u, int v) {
  if (u == v) return;
  P[u].pb(v);
  deg[v]++;
}

inline void dfs(int x) {
  dfn[x] = ++tim;
  id[x][0] = col[x];
  for (int i = 1; i <= 19; i++) {
    fa[x][i] = fa[fa[x][i - 1]][i - 1];
    if (fa[x][i]) {
      id[x][i] = ++cnt;
      adde(id[x][i], id[x][i - 1]);
      adde(id[x][i], id[fa[x][i - 1]][i - 1]);
    }
  }
  for (auto y : G[x]) if (y != fa[x][0]) {
    fa[y][0] = x;
    dep[y] = dep[x] + 1;
    dfs(y);
  }
}

inline int lca(int u, int v) {
  if (dep[u] < dep[v]) std::swap(u, v);
  for (int i = 19; ~i; i--) {
    if (dep[fa[u][i]] >= dep[v]) {
      u = fa[u][i];
    }
  }
  if (u == v) return u;
  for (int i = 19; ~i; i--) {
    if (fa[u][i] != fa[v][i]) {
      u = fa[u][i];
      v = fa[v][i];
    }
  }
  return fa[u][0];
}
inline int dist(int u, int v) {
  return dep[u] + dep[v] - 2 * dep[lca(u, v)];
}
inline int isanc(int u, int v) {
  if (dep[u] > dep[v]) return 0;
  int d = dep[v] - dep[u];
  for (int i = 0; d; i++, d >>= 1) {
    if (d & 1) {
      v = fa[v][i];
    }
  }
  return v == u;
}
inline void madd(int u, int v) {
  int x = col[u];
  u = fa[u][0];
  for (int i = 19; ~i; i--) {
    if (dep[fa[u][i]] >= dep[v]) {
      adde(x, id[u][i]);
      u = fa[u][i];
    }
  }
}

int main() {
  FileIO();
  n = read();
  m = read();
  cnt = m;
  for (int i = 1; i <= n; i++) {
    col[i] = read();
    poses[col[i]].pb(i);
  }
  for (int i = 1; i < n; i++) {
    int x = read(), y = read();
    G[x].pb(y);
    G[y].pb(x);
  }
  dep[1] = 1;
  dfs(1);
  for (int i = 1; i <= m; i++) {
    if (poses[i].empty()) {
      printf("%d 1 1\n", i);
      continue;
    }
    std::sort(poses[i].begin(), poses[i].end(), [&](int a, int b) {return dfn[a] < dfn[b];});
    int z = lca(poses[i][0], poses[i].back()), x = z, y = z;
    for (size_t _ = 0; _ < poses[i].size(); _++) {
      int w = poses[i][_];
      if (w == z) continue;
      int p = z;
      if (_ && isanc(poses[i][_ - 1], w)) {
        p = poses[i][_ - 1];
      }
      madd(w, p);
      (x == p ? x : y) = w;
    }
    adde(i, col[z]);
    U[i] = x, V[i] = y;
  }
  std::vector<int> q;
  for (int i = 1; i <= cnt; i++) {
    if (!deg[i]) {
      q.pb(i);
    }
  }
  while (!q.empty()) {
    int x = q.back();
    q.pop_back();
    if (x <= m && !poses[x].empty()) {
      printf("%d %d %d\n", x, U[x], V[x]);
    }
    for (auto y : P[x]) {
      if (!--deg[y]) {
        q.pb(y);
      }
    }
  }
  return 0;
}
