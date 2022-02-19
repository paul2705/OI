#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
using namespace std;

#define LL long long
const int maxn = 5e5 + 7;
int head[maxn], cnt = 1, n, m, st[maxn], tot;
int dep[maxn], f[maxn], F[maxn][22], ds[maxn][22];
struct Node {int v, nxt, w;} G[maxn << 1];
struct DATA {LL v; int id;} a[maxn], b[maxn];
bool vis[maxn]; int tt;

void ins(int u, int v, int w) {
    G[cnt] = (Node) {v, head[u], w}; head[u] = cnt++;
}
void dfs(int x, int fa, int deep, int w) {
    dep[x] = deep; f[x] = fa; ds[x][0] = w; F[x][0] = fa;
    for (int i = 1; i <= 20 && F[F[x][i - 1]][i - 1]; ++i) {
        F[x][i] = F[F[x][i - 1]][i - 1];
        ds[x][i] = ds[F[x][i - 1]][i - 1] + ds[x][i - 1];
    }
    for (int i = head[x]; i; i = G[i].nxt) {
        int v = G[i].v; if(v == fa) continue;
        dfs(v, x, deep + 1, G[i].w);
    }
}
void put_tag(int x) {
    bool p = 1, q = 0;
    for (int i = head[x]; i; i = G[i].nxt) {
        int v = G[i].v; if(v == f[x]) continue;
        put_tag(v); p &= vis[v]; q = 1;
    } if(x != 1 && p && q) vis[x] = 1;
}
void init() {
    tot = tt = 0;
    memset(vis, 0, sizeof vis);
}
bool cmp(DATA a, DATA b) {
    return a.v < b.v;
}
bool check(int res) {
    init();
    for (int i = 1; i <= m; ++i) {
        int x = st[i], t = 0;
        for (int j = 20; j >= 0; --j) if(F[x][j] && t + ds[x][j] <= res) { t += ds[x][j]; x = F[x][j];}
        if(x != 1) vis[x] = 1;
        else {
            x = st[i]; a[++tot].v = res - t;
            for (int j = 20; j >= 0; --j) if(F[x][j] > 1) x = F[x][j];
            a[tot].id = x;
        }
    } put_tag(1);
    for (int i = head[1]; i; i = G[i].nxt) {
        int v = G[i].v; if(vis[v]) continue;
        b[++tt].v = G[i].w; b[tt].id = v;
    }
    sort(a + 1, a + tot + 1, cmp);
    sort(b + 1, b + tt + 1, cmp); int j = 1;
    for (int i = 1; i <= tot; ++i) {
        if(!vis[a[i].id]) vis[a[i].id] = 1;
        else if(a[i].v >= b[j].v) vis[b[j].id] = 1;
        while(vis[b[j].id] && j <= tt) ++j;
    } return j > tt;
}

int main() {
    freopen("yqkz.in","r",stdin);
    freopen("yqkz1.out","w",stdout);
    scanf("%d", &n); int res = 0;
    for (int i = 1; i <= n - 1; ++i) {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        ins(u, v, w); ins(v, u, w); res += w;
    } dfs(1, 0, 1, 0);
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i) scanf("%d", &st[i]);
    int l = 0, r = res, ans = 0, ret = 0;
    for (int i = 1; i <= n; ++i) ret += (dep[i] == 2);
    if(m < ret) {puts("-1"); return 0;}
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(check(mid)) {ans = mid; r = mid - 1;}
        else l = mid + 1;
    } printf("%d\n", ans);
    fclose(stdin);fclose(stdout);
    return 0;
}
