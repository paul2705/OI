#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1

using namespace std;

const int maxn = 400010;

int n, q;

vector<int> tree[maxn];
vector<int> L[maxn];
vector<int> in[maxn];
int Q[maxn];

int add[maxn<<2], ans[maxn];

void pushDown(int rt) {
    if (add[rt]) {
        add[rt<<1] += add[rt];
        add[rt<<1|1] += add[rt];
    }
    add[rt] = 0;
}

void update(int L, int R, int x, int l, int r, int rt) {
    if (L <= l && r <= R) {
        add[rt] += x;
        return;
    }
    pushDown(rt);
    int m = (l+r) >> 1;
    if (L <= m) update(L, R, x, l, m, rt<<1);
    if (R > m) update(L, R, x, m+1, r, rt<<1|1);
}

int ask(int p, int l, int r, int rt) {
    if (l == r) return add[rt];
    int m = (l+r) >> 1;
    pushDown(rt);
    if (p <= m) return ask(p, l, m, rt<<1);
    else return ask(p, m+1, r, rt<<1|1);
}

int main() {
    freopen("icekingdom.in", "r", stdin);
    freopen("icekingdom1.out", "w", stdout);
    scanf("%d%d", &n, &q);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) sort(tree[i].begin(), tree[i].end());
    for (int i = 1; i <= q; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        L[r].push_back(l);
        in[r].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        update(1, i, 1, 1, n, 1);
        for (int t = int(tree[i].size())-1; t >= 0; t--) {
            int u = tree[i][t];
            if (u > i) continue;
            update(1, u, -1, 1, n, 1);
        }
        for (int j = 0; j < L[i].size(); j++) {
            ans[in[i][j]] = ask(L[i][j], 1, n, 1);
        }
    }
    for (int i = 1; i <= q; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
