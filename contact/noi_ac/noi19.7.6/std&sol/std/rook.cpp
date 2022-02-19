#include <bits/stdc++.h>

#ifdef __WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

using namespace std;

const int mod = 1e4 + 7;

void solve() {
	int n, m, ans = 0;
	cin >> n >> m;
	vector<vector<int> > binom(n + 1, vector<int>(n + 1, 0));
	for (int i = 0; i <= n; ++i) for (int j = binom[i][0] = 1; j <= i; ++j) binom[i][j] = (binom[i - 1][j] + binom[i - 1][j - 1]) % mod;
	vector<int> x(m), y(m), fac(n + 1, 1);
	for (int i = 2; i <= n; ++i) fac[i] = fac[i - 1] * i % mod;
	for (int i = 0; i < m; ++i) cin >> x[i] >> y[i];
	for (int s = 0; s < (1 << m); ++s) {
		int tot = 0;
		vector<int> cntx(n, 0), cnty(n, 0);
		bool flag1 = 0, flag2 = 0;
		for (int i = 0; i < m; ++i) if((s >> i) & 1) {
			++tot;
			++cntx[x[i]];
			++cnty[y[i]];
			if(x[i] == y[i]) flag1 = 1;
			if(x[i] == n - y[i] - 1) flag2 = 1;
		}
		bool ok = 1;
		for (int i = 0; i < n; ++i) if(cntx[i] >= 2 || cnty[i] >= 2) { ok = 0; break; }
		if(!ok) continue;
		int left = n - tot;
		auto F = [&]() {
			return fac[left];
		};
		auto F1 = [&]() {
			int ret = 0, rest = n;
			for (int i = 0; i < n; ++i) if(cntx[i] || cnty[i]) --rest;
			for (int i = 0; i <= left; ++i) ret = ((i & 1 ? -1 : 1) * binom[rest][i] * fac[left - i] + ret) % mod;
			return ret;
		};
		auto F2 = [&]() {
			int ret = 0, rest = n;
			for (int i = 0; i < n; ++i) if(cntx[i] || cnty[n - i - 1]) --rest;
			for (int i = 0; i <= left; ++i) ret = ((i & 1 ? -1 : 1) * binom[rest][i] * fac[left - i] + ret) % mod;
			return ret;
		};
		auto F12 = [&]() {
			int a = 0, b = 0, c = 0, ret = 0;
			for (int l = 0, r = n - 1; l <= r; ++l, --r) {
				int x = 1 + (l != r), y = 1 + (l != r);
				if(cntx[l]) --x;
				if(l < r && cntx[r]) --x;
				if(cnty[l]) --y;
				if(l < r && cnty[r]) --y;
				if(x * y == 1) ++a;
				if(x * y == 2) ++b;
				if(x * y == 4) ++c;
			}
			vector<int> p(1, 1);
			for (int i = 0; i < a; ++i) {
				vector<int> q(p.size() + 1, 0);
				for (int j = 0; j < q.size(); ++j) q[j] = ((j < p.size() ? p[j] : 0) + (j ? p[j - 1] : 0)) % mod;
				p = q;
			}
			for (int i = 0; i < b; ++i) {
				vector<int> q(p.size() + 1, 0);
				for (int j = 0; j < q.size(); ++j) q[j] = ((j < p.size() ? p[j] : 0) + (j ? 2 * p[j - 1] : 0)) % mod;
				p = q;
			}
			for (int i = 0; i < c; ++i) {
				vector<int> q(p.size() + 2, 0);
				for (int j = 0; j < q.size(); ++j) q[j] = ((j < p.size() ? p[j] : 0) + (j && j < p.size() + 1 ? 4 * p[j - 1] : 0) + (j > 1 ? 2 * p[j - 2] : 0)) % mod;
				p = q;
			}
			for (int i = 0; i <= left; ++i) ret = ((i & 1 ? -1 : 1) * (i < p.size() ? p[i] : 0) * fac[left - i] + ret) % mod;
			return ret;
		};
		int coef = tot & 1 ? -1 : 1;
		if(flag1 && flag2) ans = (ans + coef * F()) % mod;
		else if(flag1) ans = (ans + coef * (F() - F2())) % mod;
		else if(flag2) ans = (ans + coef * (F() - F1())) % mod;
		else ans = (ans + coef * (F() - F1() - F2() + F12())) % mod;
	}
	cout << (ans + mod) % mod << endl;
}

int main() {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}
