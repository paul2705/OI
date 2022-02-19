#include <bits/stdc++.h>

#ifdef __WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	constexpr int mod = 1e9 + 7;
	auto pow_mod = [&](int x, int n) {
		int y = 1;
		while(n) {
			if(n & 1) y = (long long) y * x % mod;
			n >>= 1;
			if(n) x = (long long) x * x % mod;
		}
		return y;
	};
	int n, m, s = 0;
	cin >> n >> m;
	vector<int> foo(m), fac(m + 1), ifac(m + 1), coef(m + 1);
	for (int i = 0; i < m; ++i) cin >> foo[i], s += foo[i];
	if(n == 1) {
		if(m == 1 && foo[0] == 1) cout << "1\n";
		else cout << "0\n";
		return 0;
	}
	vector<vector<int> > binom(m + 1, vector<int>(m + 1, 0));
	for (int i = fac[0] = 1; i <= m; ++i) fac[i] = (long long) fac[i - 1] * i % mod;
	ifac[m] = pow_mod(fac[m], mod - 2);
	for (int i = m; i; --i) ifac[i - 1] = (long long) ifac[i] * i % mod;
	for (int i = 0; i <= m; ++i) for (int j = binom[i][0] = 1; j <= i; ++j) binom[i][j] = (binom[i - 1][j - 1] + binom[i - 1][j]) % mod;
	vector<int> cnt(s + 1, 0), nxt(s + 1);
	for (int x: foo) ++cnt[x];
	for (int i = s; i; --i) nxt[i] = (i == s ? s + 1 : (cnt[i + 1] ? i + 1 : nxt[i + 1]));
	coef[1] = 1;
	for (int i = 2; i <= m; ++i) coef[i] = -(long long) (i - 1) * coef[i - 1] % mod;
	vector<int> all;
	int N = 0;
	for (int i = 2; i <= n; ++i) {
		auto isp = [&]() { for (int x = 2; x * x <= i; ++x) if(i % x == 0) return false; return true; };
		if(isp()) {
			int s = 0;
			for (int j = i; j <= n; j *= i) s += n / j;
			N = max(N, s);
			all.push_back(s);
		}
	}
	int ans = 0;
	vector<int> dp(N + 1, 0);
	dp[0] = 1;
	function<void(int, int)> dfs = [&](int mn, int n) {
		static vector<int> a;
		if(!n) {
			int x = 1;
			for (int y: all) x = (long long) x * dp[y] % mod;
			for (int j, i = 0; i < a.size(); ++i) {
				j = i;
				while(j + 1 < a.size() && a[j + 1] == a[i]) ++j;
				x = (long long) x * ifac[j - i + 1] % mod;
				i = j;
			}
			if(!x) return;
			vector<pair<vector<int>, int> > f;
			f.push_back(make_pair(cnt, x));
			for (int n: a) {
				vector<pair<vector<int>, int> > g;
				for (auto &_: f) {
					auto a = _.first;
					int x = _.second;
					function<void(int, int, int, int)> dfs = [&](int i, int x, int sz, int n) {
						if(i == a.size()) {
							if(!n) g.push_back(make_pair(a, (long long) x * coef[sz] % mod));
							return;
						}
						for (int j = 0; j <= a[i] && j * i <= n; ++j) {
							a[i] -= j;
							dfs(nxt[i], (long long) x * binom[a[i] + j][j] % mod, sz + j, n - i * j);
							a[i] += j;
						}
						return;
					};
					dfs(1, x, 0, n);
				}
				sort(g.begin(), g.end());
				f.clear();
				for (int x, j, i = 0; i < g.size(); ++i) {
					j = i; x = g[i].second;
					while(j + 1 < g.size() && g[j + 1].first == g[i].first) ++j, x = (x + g[j].second) % mod;
					if(x) f.push_back(make_pair(g[i].first, x));
					i = j;
				}
			}
			for (auto t: f) ans = (ans + t.second) % mod;
			return;
		}
		for (int x = mn; x <= n; ++x) {
			a.push_back(x);
			for (int i = x; i < dp.size(); ++i) dp[i] = (dp[i] + dp[i - x]) % mod;
			dfs(x, n - x);
			for (int i = dp.size() - 1; i >= x; --i) dp[i] = (dp[i] - dp[i - x]) % mod;
			a.pop_back();
		}
		return;
	};
	dfs(1, s);
	for (auto x: cnt) ans = (long long) ans * ifac[x] % mod;
	cout << (ans + mod) % mod << endl;
	return 0;
}
