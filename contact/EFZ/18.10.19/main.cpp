#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#define pr pair<int,int>

using namespace std;

const int maxn = 200010;

struct seg {
    int l, r;
};

bool operator<(const seg &a, const seg & b) {
    return a.r < b.r;
}

int n, m;
int l[maxn], r[maxn], t[maxn];
seg s[maxn];

int fge(int v) {
    return int(lower_bound(t+1, t+m+1, v)-t);
}

int lle(int v) {
    int q = int(lower_bound(t+1, t+m+1, v)-t);
    while (q > 0 && (q == m+1 || t[q] > v)) -- q;
    return q;
}

set<int> st;

int main() {
    freopen("dream.in", "r", stdin);
    freopen("dream1.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &l[i], &r[i]);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &t[i]);
        st.insert(i);
    }
    sort(t+1, t+m+1);
    for (int i = 1; i <= n; i++) {
        s[i].l = fge(l[i]);
        s[i].r = lle(r[i]);
    }
    sort(s+1, s+n+1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        set<int>::iterator iter = st.lower_bound(s[i].l);
        if (iter != st.end() && (*iter) <= s[i].r) {
            ++ ans;
            st.erase(iter);
        }
    }
    printf("%d\n", ans);
    return 0;
}
