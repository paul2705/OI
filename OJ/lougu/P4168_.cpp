#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

const int maxn = 40010;
int n, m, block, tot, a[maxn], cnt[maxn][210], f[210][210], tmp[maxn], c[maxn];
int belong[maxn], bl[210], br[210];
vector<int> v;

void init() {
    for (int i = 1; i <= n; i++) {
        cnt[a[i]][belong[i]]++;
    }
    for (int j = 1; j <= belong[n]; j++) {
        for (int i = 1; i <= tot; i++) {
            cnt[i][j] += cnt[i][j - 1];
        }
    }
    for (int i = 1; i <= belong[n]; i++) {
        memset(tmp, 0, sizeof(tmp));
        for (int j = i, cur = 0; j <= belong[n]; j++) {
            for (int k = bl[j]; k <= br[j]; k++) {
                tmp[a[k]]++;
                if (!cur || tmp[a[k]] > tmp[cur] || (tmp[a[k]] == tmp[cur] && a[k] < cur)) {
                    cur = a[k];
                }
            }
            f[i][j] = cur;
        }
    }
}

int query(int l, int r) {
    int res = 0, val = 0;
    if (belong[l] == belong[r] || belong[l] + 1 == belong[r]) {
        for (int i = l; i <= r; i++) {
            c[a[i]] = 0;
        }
        for (int i = l; i <= r; i++) {
            c[a[i]]++;
            if (!res || c[a[i]] > c[res] || (c[a[i]] == c[res] && a[i] < res)) {
                res = a[i];
            }
        }
    } else {
        tot = 0;
        res = f[belong[l] + 1][belong[r] - 1], val = cnt[res][belong[r] - 1] - cnt[res][belong[l]];
        for (int i = l; i <= br[belong[l]]; i++) {
            tmp[++tot] = a[i];
        }
        for (int i = bl[belong[r]]; i <= r; i++) {
            tmp[++tot] = a[i];
        }
        for (int i = 1; i <= tot; i++) {
            c[tmp[i]] = cnt[tmp[i]][belong[r] - 1] - cnt[tmp[i]][belong[l]];
        }
        for (int i = 1; i <= tot; i++) {
            c[tmp[i]]++;
        }
        for (int i = 1; i <= tot; i++) {
            if (!res || c[tmp[i]] > val || (c[tmp[i]] == val && tmp[i] < res)) {
                res = tmp[i];
                val = c[tmp[i]];
            }
        }
        for (int i = 1; i <= tot; i++) {
            c[tmp[i]] = 0;
        }
    }
    return res;
}

int main() {
    scanf("%d %d", &n, &m);
    block = sqrt(n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        belong[i] = (i - 1) / block + 1;
        if (!bl[belong[i]]) {
            bl[belong[i]] = i;
        }
        br[belong[i]] = i;
        v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    int end = unique(v.begin(), v.end()) - v.begin();
    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(v.begin(), v.begin() + end, a[i]) - v.begin() + 1;
    }
    tot = end;
    init();
    int lastans = 0;
    while (m--) {
        int l, r;
        scanf("%d %d", &l, &r);
        l = (l + lastans - 1) % n + 1, r = (r + lastans - 1) % n + 1;
        if (l > r) {
            swap(l, r);
        }
        printf("%d\n", lastans = v[query(l, r) - 1]);
    }
    return 0;
}
