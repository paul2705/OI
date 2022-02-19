#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
#define int LL
typedef long long LL;
const int N = 2010, INF = 0x3f3f3f3f3f3f3f3fll;
struct Edge {
    int nex, v, c, len;
    Edge(){}
    Edge(int N, int V, int C, int L) {
        nex = N, v = V, c = C, len = L;
    }
}edge[2000010]; int tp = 1;
int e[N], n, tot, d[N], pre[N], flow[N], Time, vis[N];
std::queue<int> Q;
inline void add(int x, int y, int z, int w) {
    edge[++tp] = Edge(e[x], y, z, w);
    e[x] = tp;
    edge[++tp] = Edge(e[y], x, 0, -w);
    e[y] = tp;
    return;
}
inline bool SPFA(int s, int t) {
    memset(d, 0x3f, sizeof(d));
    Q.push(s);
    ++Time;
    d[s] = 0;
    vis[s] = Time;
    flow[s] = INF;
    while(Q.size()) {
        int x = Q.front();
        Q.pop();
        vis[x] = 0;
        for(int i = e[x]; i; i = edge[i].nex) {
            int y = edge[i].v;
            if(edge[i].c && d[y] > d[x] + edge[i].len) {
                d[y] = d[x] + edge[i].len;
                pre[y] = i;
                flow[y] = std::min(flow[x], edge[i].c);
                if(vis[y] != Time) {
                    vis[y] = Time;
                    Q.push(y);
                }
            }
        }
    }
    return d[t] < INF;
}
inline void update(int s, int t) {
    int f = flow[t];
    while(s != t) {
        int i = pre[t];
        edge[i].c -= f;
        edge[i ^ 1].c += f;
        t = edge[i ^ 1].v;
    }
    return;
}
inline int solve(int s, int t, int &cost) {
    cost = 0;
    int ans = 0;
    while(SPFA(s, t)) {
        //printf("!");
        ans += flow[t];
        cost += flow[t] * d[t];
        update(s, t);
    }
    return ans;
}
signed main() {   
    scanf("%lld", &n);
    int s = 2 * n + 5, t = s + 1, x, y, z;
    for(int i = 1; i <= n; i++) {
        scanf("%lld%lld%lld", &x, &y, &z);
        add(s, i, z, 0);
        add(i, 2 * n + 1, z, x + y);
        add(i, 2 * n + 2, z, y - x);
        add(i, 2 * n + 3, z, x - y);
        add(i, 2 * n + 4, z, -x - y);
    }
    for(int i = 1; i <= n; i++) {
        scanf("%lld%lld%lld", &x, &y, &z);
        add(n + i, t, z, 0);
        add(2 * n + 1, n + i, z, -x - y);
        add(2 * n + 2, n + i, z, x - y);
        add(2 * n + 3, n + i, z, y - x);
        add(2 * n + 4, n + i, z, x + y);
    }
    //puts("OVER");
    int cost = 0;
    solve(s, t, cost);
    printf("%lld\n", -cost);
    return 0;
}
