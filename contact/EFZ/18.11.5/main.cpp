#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef long long ll;

const int maxn = 500010;
const int inf = 0x3f3f3f3f;

int a[maxn], t[maxn], s[maxn];
int tree[maxn<<2];

void pushUp1(int rt) {
    tree[rt] = min(tree[rt<<1], tree[rt<<1|1]);
}

void pushUp0(int rt) {
    tree[rt] = tree[rt<<1] + tree[rt<<1|1];
}

void build0(int l, int r, int rt) {
    if (l == r) {
        tree[rt] = 0;
        return;
    }
    int m = (l+r) >> 1;
    build0(l, m, rt<<1);
    build0(m+1, r, rt<<1|1);
    pushUp0(rt);
}

void build1(int l, int r, int rt) {
    if (l == r) {
        tree[rt] = a[l];
        return;
    }
    int m = (l+r) >> 1;
    build1(l, m, rt<<1);
    build1(m+1, r, rt<<1|1);
    pushUp1(rt);
}

void update0(int p, int v, int l, int r, int rt) {
    if (l == r) {
        tree[rt] ++;
        return;
    }
    int m = (l + r) >> 1;
    if (p <= m) update0(p, v, l, m, rt<<1);
    else update0(p, v, m+1, r, rt<<1|1);
    pushUp0(rt);
}

void update1(int p, int l, int r, int rt) {
    if (l == r) {
        a[l] = inf;
        tree[rt] = inf;
        return;
    }
    int m = (l + r) >> 1;
    if (p <= m) update1(p, l, m, rt<<1);
    else update1(p, m+1, r, rt<<1|1);
    pushUp1(rt);
}

int query0(int L, int R, int l, int r, int rt) {
    if (L > R) return 0;
    if (L <= l && r <= R) return tree[rt];
    int m = (l + r) >> 1;
    int ret = 0;
    if (L <= m) ret += query0(L, R, l, m, rt<<1);
    if (R > m) ret += query0(L, R, m+1, r, rt<<1|1);
    return ret;
}

int query1(int v, int l, int r, int rt) {
    if (l == r) {
        return (tree[rt] <= v) ? l : -1;
    }
    int m = (l + r) >> 1;
    if (tree[rt<<1|1] <= v) return query1(v, m+1, r, rt<<1|1);
    else return query1(v, l, m, rt<<1);
}

int n, m;

int main() {
    freopen("sort.in","r",stdin);
    freopen("sort.out","w",stdout);
    ll ans = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) t[i] = a[i];
    sort(t+1, t+n+1);
    for (int i = 1; i <= n; i++) a[i] = int(lower_bound(t+1, t+n+1, a[i])-t);
    build0(1, n, 1);
    for (int i = n; i >= 1; i--) {
        s[i] = query0(1, a[i]-1, 1, n, 1);
        update0(a[i], 1, 1, n, 1);
        ans += s[i];
    }
    build1(1, n, 1);
    for (int i = 1; i <= m; i++) {
        int x = 0;
        scanf("%d", &x);
        int v = a[x];
        if (v < inf) {
            while (1) {
                int in = query1(v, 1, n, 1);
                if (in < x) break;
                update1(in, 1, n, 1);
                ans -= s[in];
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
