#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2005, MOD = 998244353;
int pw[MAXN][MAXN], cnt[MAXN], n;
ll f[MAXN][MAXN], fac[MAXN], rev[MAXN];
ll modpow(ll a, int b) {
	ll res = 1;
	for (; b; b >>= 1) {
		if (b & 1) res = res * a % MOD;
		a = a * a % MOD;
	}
	return res;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int t; scanf("%d", &t);
		++cnt[t];
	}
	for (int i = n; i > 0; i--) cnt[i] += cnt[i + 1];
	fac[0] = 1;
	for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % MOD;
	rev[n] = modpow(fac[n], MOD - 2);
	for (int i = n; i > 0; i--) rev[i - 1] = rev[i] * i % MOD;
	for (int i = 0; i <= n; i++) {
		for (int j = pw[i][0] = 1; j <= n; j++)
			pw[i][j] = pw[i][j - 1] * rev[i] % MOD;
	}
	for (int i = 1; i <= n + 1; i++) f[i][0] = 1;
	for (int i = n; i > 0; i--)
	for (int j = 1; j <= cnt[i]; j++)
	for (int k = 0; k * i <= j; k++)
		(f[i][j] += f[i + 1][j - k * i] * fac[cnt[i] - j + k * i] % MOD * rev[cnt[i] - j] % MOD * pw[i][k] % MOD * rev[k]) %= MOD;
	printf("%lld\n", f[1][n]);
	return 0;
}
