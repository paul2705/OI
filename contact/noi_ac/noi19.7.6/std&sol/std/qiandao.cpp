#include <bits/stdc++.h>

using namespace std;

void judge() {
	freopen("qiandao.in", "r", stdin);
	freopen("qiandao.out", "w", stdout);
}

const int maxm = 1e5 + 1000;

long long n, b, a[maxm], B;
int m, r[61];
vector<pair<long long, vector<pair<long long, int> > > > pwn;
bool A[maxm];

vector<pair<long long, int> > decomp(long long x) {
	vector<pair<long long, int> > all;
	for (long long p = 2; p * p <= x; ++p) if(x % p == 0) {
		int q = 0;
		while(x % p == 0) ++q, x /= p;
		all.push_back(make_pair(p, q));
	}
	if(x > 1) all.push_back(make_pair(x, 1));
	return all;
}

bool isp[maxm];
vector<long long> pme, scnt, bcnt, f1, f2;

void powerful_number() {
	vector<pair<long long, int> > v;
	function<void(long long, int)> dfs = [&](long long x, int i) {
		if(i == pme.size()) { pwn.push_back(make_pair(x, v)); return; }
		long long p = pme[i];
		if(x * p > n) {
			pwn.push_back(make_pair(x, v));
			return;
		}
		dfs(x, i + 1);
		x *= p;
		if(x > n) return;
		for(int cnt = 2;; ++cnt) {
			x *= p;
			if(x > n) return;
			v.push_back(make_pair(pme[i], cnt));
			dfs(x, i + 1);
			v.pop_back();
		}
	};
	dfs(1, 0);
	return;
}

const int SZ = 6000011;

struct Hash {
	int head[SZ], nxt[SZ], cnt;
	long long val[SZ];
	
	Hash(): cnt(0) { memset(nxt, 0, sizeof nxt); memset(head, 0, sizeof head); }
	
	inline int I(const long long &x) {
		int y = x % SZ;
		for (register int i = head[y]; i; i = nxt[i]) {
			if(val[i] == x) return i;
		}
		++cnt;
		nxt[cnt] = head[y];
		head[y] = cnt;
		val[cnt] = x;
		return cnt;
	}
} hsh;

long long coef[SZ];

int main() {
	ios::sync_with_stdio(false);
//	judge();
	cin >> n >> m >> b;
	auto BEG = clock();
	for (int i = 0; i < m; ++i) {
		cin >> a[i];
		if(b % a[i] == 0) b = n + 1;
		if(a[i] < maxm) A[a[i]] = 1;
	}
	sort(a, a + m);
	for (int i = 1; i <= 60; ++i) cin >> r[i];
	B = sqrt(n) + 1;
	for (int x = 2; x <= B; ++x) isp[x] = 1;
	for (int x = 2; x <= B; ++x) {
		if(isp[x]) pme.push_back(x);
		for (int p: pme) {
			int i = x * p;
			if(i > B) break;
			isp[i] = 0;
			if(x % p == 0) break;
		}
	}
	powerful_number();
	scnt = vector<long long>(B + 1, 0);
	bcnt = vector<long long>(B + 1, 0);
	for (long long x = 1; x <= B; ++x) {
		scnt[x] = x - 1;
		bcnt[x] = n / x - 1;
	}
	for (long long p: pme) {
		long long q = p * p, t = scnt[p - 1];
		for (long long x = 1; ; ++x) {
			long long n = ::n / x;
			if(n <= B || n < q) break;
			long long foo = n / p;
			bcnt[x] -= (foo <= B ? scnt[foo] : bcnt[x * p]) - t;
		}
		for (long long x = B; x >= q; --x) scnt[x] -= scnt[x / p] - t;
	}
	f1 = vector<long long>(B + 1, 0);
	f2 = vector<long long>(B + 1, 0);
	function<long long(long long, long long)> Q = [&](long long l, long long r) {
		int i = lower_bound(a, a + m, r + 1) - a, j = lower_bound(a, a + m, l) - a;
		return i - j;
	};
	for (int pme_i = pme.size() - 1; ~pme_i; --pme_i) {
		long long p = pme[pme_i], q = p * p, qq = (pme_i == pme.size() - 1 ? ::n + 1 : pme[pme_i + 1] * pme[pme_i + 1]);
		long long Q1 = Q(p, p);
		auto S = [&](long long n) { // [2, n] 中质因子 >= p + 1 的与 a 互质的数的个数
			if(n < qq) return n >= p ? (n <= B ? (scnt[n] - Q(p + 1, n) - scnt[p]) : (bcnt[::n / n] - Q(p + 1, n) - scnt[p])) : 0;
			return n <= B ? f1[n] : f2[::n / n];
		};
		for (long long x = 1; ; ++x) {
			long long n = ::n / x;
			if(n <= B || n < q) break;
			long long ret = S(n);
			if(!Q1) {
				long long q = n / p;
				while(q) {
					ret += S(q) + 1;
					q /= p;
				}
			}
			f2[x] = ret;
		}
		for (long long x = B; x >= q; --x) {
			long long ret = S(x);
			if(!Q1) {
				long long q = x / p;
				while(q) {
					ret += S(q) + 1;
					q /= p;
				}
			}
			f1[x] = ret;
		}
	}
	vector<long long> small(6);
	for (int n = 0; n <= 5; ++n) {
		int cnt = 0;
		for (int i = 1; i <= n; ++i) {
			bool flag = 1;
			for (int j = 0; j < m && j < 10; ++j) if(i % a[j] == 0) flag = 0;
			if(flag == 1) ++cnt;
		}
		small[n] = cnt;
	}
	function<long long(long long)> Qa = [&](long long n) { // [1, n] 中与 a 互质的数的个数
		if(n <= 5) {
			return small[n];
		}
		return (n <= 1 ? n : ((n <= B ? f1[n] : f2[::n / n]) + 1ll));
	};
	function<long long(long long)> Qab = [&](long long n) { // [1, n] 中与 a 互质且不是 b 的倍数的数的个数
		if(n <= 1) return n;
		return Qa(n) - Qa(n / b);
	};
	if(r[1] == 0) {
		long long ans = Qab(n);
		
		for (auto z: pwn) {
			auto x = z.first;
			auto all = z.second;
			int f = 1;
			for (auto t: all) f *= r[t.second];
			if(f == 1 && x % b != 0) {
				bool flag = 0;
				for (auto t: all) {
					if(t.first < maxm) {
						if(A[t.first]) { flag = 1; break; }
					}
					else if(Q(t.first, t.first)) { flag = 1; break; }
				}
				if(!flag) --ans;
			}
		}
		cout << ans << endl;
		return 0;
	}
	if(r[1] == 1) {
		sort(pwn.begin(), pwn.end());
		long long ans = 0;
		for (auto z: pwn) {
			auto x = z.first;
			if(x == 1) continue;
			long long d = 1, B = b;
			auto all = z.second;
			int f = 1;
			for (auto t: all) {
				f *= r[t.second];
				for (int i = 0; i < t.second; ++i) if(B % t.first == 0) B /= t.first, d *= t.first;
			}
			if(x % b != 0) {
				bool flag = 0;
				for (auto t: all) {
					if(t.first < maxm) {
						if(A[t.first]) { flag = 1; break; }
					}
					else if(Q(t.first, t.first)) { flag = 1; break; }
				}
				if(!flag) {
					long long n = ::n / x, e = b / d;
					long long t = (n <= 1 ? n : Qa(n) - Qa(n / e));
					long long c = f ? 0 : 1;
					function<void(long long, int)> dfs = [&](long long x, int i) {
						if(i == all.size()) {
							c -= coef[hsh.I(x)];
							return;
						}
						dfs(x, i + 1);
						long long p = all[i].first;
						x *= p;
						for (int j = 2; j <= all[i].second; ++j) {
							x *= p;
							dfs(x, i + 1);
						}
						return;
					};
					dfs(1, 0);
					ans += t * c;
					coef[hsh.I(x)] = c;
				}
			}
		}
		cout << ans << endl;
		return 0;
	}
}
