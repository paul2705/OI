#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

const int N = 100010;
std::vector<int> G[N];
int n, m, col[N], Ans[N];
int ansvis[N];

int size[N], son[N], fa[N], dfn[N], idfn[N], dep[N], top[N], dfc = 0;
void dfs1(int p, int f) {
  fa[p] = f;
  dep[p] = dep[f] + 1;
  size[p] = 1;
  for (auto t : G[p]) if (t ^ f) {
    dfs1(t, p);
    size[p] += size[t];
    if (!son[p] || size[son[p]] < size[t]) {
      son[p] = t;
    }
  }
}
void dfs2(int p, int tp) {
  top[p] = tp;
  dfn[p] = ++dfc;
  idfn[dfn[p]] = p;
  if (son[p]) {
    dfs2(son[p], tp);
  }
  for (auto t : G[p]) if (t ^ fa[p] && t ^ son[p]) {
    dfs2(t, t);
  }
}
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)
int tg[N << 2];
inline void pd(int p) {
  if (!tg[p]) return;
  tg[ls] = tg[p];
  tg[rs] = tg[p];
  tg[p] = 0;
}
void modify(int p, int l, int r, int ql, int qr, int v) {
  if (l == ql && r == qr) {
    tg[p] = v;
    return;
  }
  pd(p);
  if (qr <= mid) {
    modify(ls, l, mid, ql, qr, v);
  } else if (ql > mid) {
    modify(rs, mid + 1, r, ql, qr, v);
  } else {
    modify(ls, l, mid, ql, mid, v);
    modify(rs, mid + 1, r, mid + 1, qr, v);
  }
}
void pdall(int p, int l, int r) {
  if (l == r) {
    Ans[idfn[l]] = tg[p];
    return;
  }
  pd(p);
  pdall(ls, l, mid);
  pdall(rs, mid + 1, r);
}
#undef mid
#undef ls
#undef rs
inline void path(int x, int y, int v) {
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
    modify(1, 1, n, dfn[top[x]], dfn[x], v);
    x = fa[top[x]];
  }
  modify(1, 1, n, std::min(dfn[x], dfn[y]), std::max(dfn[x], dfn[y]), v);
}

int main(int argc, char **argv) {
  registerTestlibCmd(argc, argv);
  n = inf.readInt();
  m = inf.readInt();
  for (int i = 1; i <= n; i++) {
    col[i] = inf.readInt();
  }
  for (int i = 1; i < n; i++) {
    int x = inf.readInt(), y = inf.readInt();
    G[x].push_back(y);
    G[y].push_back(x);
  }
  dfs1(1, 0);
  dfs2(1, 1);
  for (int i = 1; i <= m; i++) {
    int c = ouf.readInt(1, m, "C"), x = ouf.readInt(1, n, "A"), y = ouf.readInt(1, n, "B");
    if (ansvis[c]) {
      quitf(_wa, "duplicated C.");
    }
    path(x, y, c);
  }
  pdall(1, 1, n);
  for (int i = 1; i <= n; i++) {
    if (Ans[i] != col[i]) {
      quitf(_wa, "Wrong on node %d expected %d found %d.", i, col[i], Ans[i]);
    }
  }
  quitf(_ok, "Accept.");
}
