#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

const int maxn = 1000010;

int n;

typedef long long ll;
const ll inf = 1e18+10;

ll x[10];
ll f[maxn];

int main() {
    freopen("sequences.in", "r", stdin);
    freopen("sequences1.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &x[i]);
    }
    if (n == 2) {
        cout << 1LL*x[1]*x[2]-x[1]-x[2] << endl;
    } else {
        ll mod = x[1];
        ll tmp = 1ll*x[1]*x[2]-x[1]-x[2];
        for (int i = 0; i < mod; i++) f[i] = inf;
        f[0] = 0;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; 1ll*j*x[i] <= tmp; j++) {
                ll t = 1ll*j*x[i]%mod;
                ll v = 1ll*j*x[i];
                for (int k = 0; k < mod; k++) {
                    ll a = (k+t)%mod;
                    ll val = f[k]+v;
                    f[a] = min(f[a], val);
                }
            }
        }
        ll ans = 0;
        for (int i = 0; i < mod; i++) {
			ans = max(ans, f[i]-mod);
        }
        cout << ans << endl;
    }
    return 0;
}
