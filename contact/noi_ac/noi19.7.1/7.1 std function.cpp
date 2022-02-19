#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 3500005, MAXP = 300005, MOD = 1000000007;
ll modpow(ll a, int b) {
	ll res = 1;
	for (; b; b >>= 1) {
		if (b & 1) res = res * a % MOD;
		a = a * a % MOD;
	}
	return res;
}
int pw[MAXP], pr[MAXP], K, pc;
bool vis[MAXN];
ll S[25][25], sum[1000005], n, ans;
ll calc(ll n) {
	n %= MOD;
	if (n <= 1000000) return sum[n];
	ll mul = n + 1, res = 0;
	for (int j = 0; j <= K && j <= n; j++) {
		res = (res + S[K][j] * mul) % MOD;
		mul = mul * (n - j) % MOD;
	}
	return res;
}
void dfs(int p, ll rem, ll coef) {
	ans = (ans + coef * calc(rem)) % MOD;
	for (int i = p; i <= pc; i++) {
		if ((ll)pr[i] * pr[i] > rem) break;
		ll co = coef * pw[i] % MOD;
		for (ll j = rem / pr[i] / pr[i]; j; j /= pr[i]) dfs(i + 1, j, co);
	}
}
int main() {
	scanf("%lld%d", &n, &K);
	S[0][0] = 1;
	for (int i = 1; i <= K; i++)
	for (int j = 1; j <= i; j++)
		S[i][j] = (S[i - 1][j - 1] + j * S[i - 1][j]) % MOD;
	int m = (int)sqrt(n);
	for (int i = 2; i <= m; i++) if (!vis[i]) {
		++pc, pw[pc] = modpow(pr[pc] = i, K);
		pw[pc] = (ll)pw[pc] * (MOD + 1 - pw[pc]) % MOD;
		for (int j = i + i; j <= m; j += i) vis[j] = true;
	}
	for (int i = 0; i <= K; i++)
		S[K][i] = S[K][i] * modpow(i + 1, MOD - 2) % MOD;
	for (int i = 1; i <= 1000000 && i <= n; i++)
		sum[i] = (sum[i - 1] + modpow(i, K)) % MOD;
	dfs(1, n, 1);
	printf("%lld\n", ans);
	return 0;
}
