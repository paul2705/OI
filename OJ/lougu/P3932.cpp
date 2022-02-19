#include <iostream>
#include <cstdio>
using namespace std;

typedef long long LL;

const LL MOD = 19260817;
const int MAXN = 200010;

int n, m;
LL d[MAXN], a[MAXN]; 
LL sum_a[MAXN], sum_d[MAXN], sum_mul[MAXN];
LL calc_ans(int x, int l, int r, bool left) {
    if(l > r) return 0;
    LL ans1 = ((sum_a[r] - sum_a[l-1]) % MOD + MOD) % MOD;
    ans1 = ans1 * sum_d[x] % MOD;
    LL ans2 = ((sum_mul[r] - sum_mul[l-1]) % MOD + MOD) % MOD;
    if(!left) swap(ans1, ans2);
    return ((ans1 - ans2) % MOD + MOD) % MOD;
}
int main() {
    scanf("%d%d", &n, &m);
    for(int i=2; i<=n; i++) {
        scanf("%lld", &d[i]);
        sum_d[i] = (sum_d[i-1] + (d[i] %= MOD)) % MOD;
    }
    for(int i=1; i<=n; i++) {
        scanf("%lld", &a[i]);
        sum_a[i] = (sum_a[i-1] + (a[i] %= MOD)) % MOD;
        sum_mul[i] = (sum_mul[i-1] + a[i] * sum_d[i] % MOD) % MOD;
    }
    for(int i=1, x, l, r; i<=m; i++) {
        scanf("%d%d%d", &x, &l, &r);
        LL ans1 = calc_ans(x, l, min(r, x-1), true);
        LL ans2 = calc_ans(x, max(l, x+1), r, false);
        printf("%lld\n", (ans1 + ans2) % MOD);
    }
    return 0;
}

