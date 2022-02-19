#undef DEBUG
//#define DON2
//#define DWITHOUT_BLOCK
//#define DOM2logN
#define DOMlog2MlogN
#define DWITH_BLOCK

#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

const int proot = 3;

long long N;
int D, M, A, B;
vector< pair<int, long long> > blocks;
vector<int> fac, ifac;
double TBEG, TEND;

namespace ON2 {
	vector< vector<int> > P;

	void solve() {
		P.resize(N + 1);
		for (int x = 0; x <= N; ++x) {
			P[x].assign(N - x + 1, 0);
		}
		P[0][0] = 1;
		sort(blocks.begin(), blocks.end());
		for (int z = 1; z <= N; ++z) {
			for (int x = 0; x <= z; ++x) {
				int y = z - x;
				int foo = lower_bound(blocks.begin(), blocks.end(), make_pair(x, (long long) y)) - blocks.begin();
				if(foo < blocks.size() && blocks[foo].first == x && blocks[foo].second == y) {
					continue;
				}
				if(x) {
					P[x][y] = ((long long) B * P[x - 1][y] + P[x][y]) % mod;
				}
				if(y) {
					P[x][y] = ((long long) A * P[x][y - 1] + P[x][y]) % mod;
				}
			}
		}
		int ans = 0;
		for (int x = 0; x <= N; x += D) {
			for (int y = 0; x + y <= N; y += D) {
				ans = (ans + P[x][y]) % mod;
			}
		}
		printf("%d\n", ans);
#ifdef DEBUG
		fprintf(stderr, "ON2 %d\n", ans);
		fprintf(stderr, "%.12f\n", 1. * (clock() - TBEG) / CLOCKS_PER_SEC);
#endif
		return;
	}
}

int pow_mod(int x, int n) {
	int y = 1;
	while(n) {
		if(n & 1) {
			y = (long long) y * x % mod;
		}
		x = (long long) x * x % mod;
		n >>= 1;
	}
	return y;
}

int pow_mod(int x, int n, int mod) {
	int y = 1;
	while(n) {
		if(n & 1) {
			y = (long long) y * x % mod;
		}
		x = (long long) x * x % mod;
		n >>= 1;
	}
	return y;
}

int pow_mod(int x, long long n) {
	int y = 1;
	while(n) {
		if(n & 1) {
			y = (long long) y * x % mod;
		}
		x = (long long) x * x % mod;
		n >>= 1;
	}
	return y;
}

int pow_mod(int x, long long n, int mod) {
	int y = 1;
	while(n) {
		if(n & 1) {
			y = (long long) y * x % mod;
		}
		x = (long long) x * x % mod;
		n >>= 1;
	}
	return y;
}

int inv(int x) {
	return pow_mod(x, mod - 2);
}

void bf_mul(vector<int> &a, vector<int> &b, vector<int> &c, int mod) {
	vector<long long> d(a.size() + b.size() - 1, 0);
	for (int i = 0; i < a.size(); ++i) {
		int x = a[i];
		for (int j = 0; j < b.size(); ++j) {
			long long &t = d[i + j];
			t = (long long) x * b[j] + t;
			if((j & 7) == 7) {
				t %= mod;
			}
		}
	}
	c.clear();
	for (auto &t: d) {
		c.push_back(t % mod);
	}
	return;
}

int lowbit(int x) {
	return x & (-x);
}

int getpw2(int x) {
	while(x != lowbit(x)) {
		x += lowbit(x);
	}
	return x;
}

void dft(vector<int> &a, bool rev) {
	int n = a.size();
	for (int i = 0, j = 0; i < n; ++i) {
		if(i < j) {
			swap(a[i], a[j]);
		}
		for (int k = n >> 1; (j ^= k) < k; k >>= 1);
	}
	vector<int> w(n, 0);
	w[0] = 1;
	for (int hl = 1, l = 2; l <= n; hl = l, l <<= 1) {
		int wn = pow_mod(proot, (mod - 1) / l);
		if(rev) {
			wn = pow_mod(wn, mod - 2);
		}
		for (register int i = hl - 1; ~i; --i) {
			w[i << 1] = w[i];
			w[(i << 1) | 1] = (long long) w[i] * wn % mod;
		}
		for (int i = 0; i < n; i += l) {
			for (register int j = 0, x; j < hl; ++j) {
				int &t = a[i + hl + j];
				x = (long long) w[j] * t % mod;
				t = (a[i + j] - x) % mod;
				a[i + j] = (a[i + j] + x) % mod;
			}
		}
	}
	if(rev) {
		int inv = pow_mod(n, mod - 2);
		for (int i = 0; i < n; ++i) {
			a[i] = (long long) inv * a[i] % mod;
		}
	}
	return;
}

void ntt_mul(vector<int> &a, vector<int> &b, vector<int> &c) {
	int M = a.size() + b.size() - 1, N = getpw2(M);
	vector<int> A(N, 0), B(N, 0);
	for (int i = 0; i < a.size(); ++i) {
		A[i] = a[i];
	}
	for (int i = 0; i < b.size(); ++i) {
		B[i] = b[i];
	}
	dft(A, 0);
	dft(B, 0);
	for (int i = 0; i < N; ++i) {
		A[i] = (long long) A[i] * B[i] % mod;
	}
	dft(A, 1);
	c.clear();
	for (int i = 0; i < M; ++i) {
		c.push_back(A[i] < 0 ? A[i] + mod : A[i]);
	}
	return;
}

void mtt_mul(vector<int> &a, vector<int> &b, vector<int> &c, int mod) {
}

void mul(vector<int> &a, vector<int> &b, vector<int> &c, int mod) {
#ifdef DOM2logN
	bf_mul(a, b, c, mod);
	return;
#endif
	if(a.size() < 20 || b.size() < 20) {
		bf_mul(a, b, c, mod);
	}
	else if (mod == ::mod) {
		ntt_mul(a, b, c);
	}
	else {
		mtt_mul(a, b, c, mod);
	}
	return;
}

void cyc_mul(vector<int> &a, vector<int> &b, vector<int> &c) {
#ifdef DOM2logN
	bf_mul(a, b, c, mod);
	for (int i = D; i < c.size(); ++i) {
		c[i - D] = (c[i - D] + c[i]) % mod;
	}
	c.resize(D);
	return;
#endif
#ifdef DOMlog2MlogN
	mul(a, b, c, mod);
	for (int i = D; i < c.size(); ++i) {
		c[i - D] = (c[i - D] + c[i]) % mod;
	}
	c.resize(D);
	return;
#endif
}

void prepare() {
	fac.resize(D + 1);
	ifac.resize(D + 1);
	fac[0] = 1;
	for (int i = 1; i <= D; ++i) {
		fac[i] = (long long) fac[i - 1] * i % mod;
	}
	ifac[D] = pow_mod(fac[D], mod - 2);
	for (int i = D; i; --i) {
		ifac[i - 1] = (long long) ifac[i] * i % mod;
	}
	return;
}

int C(int n, int m) {
	return m < 0 || n < m ? 0 : (long long) fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}

namespace WITHOUT_BLOCK {
	namespace OM2logN {
		void solve() {
			vector<int> h(D, 0), ans(D, 0); // h = (Bx + A)^D mod (x^D - 1)
			for (int i = 0; i <= D; ++i) {
				int &t = h[i == D ? 0 : i];
				t = ((long long) C(D, i) * pow_mod(B, i) % mod * pow_mod(A, D - i) + t) % mod;
			}
			N /= D;
			if(N & 1) {
				ans = h;
			}
			vector< vector<int> > pw_h, s_pw;
			pw_h.push_back(h);
			s_pw.push_back(h);
			for (long long i = 2; i <= N; i <<= 1) {
				vector<int> &t = s_pw.back();
				bf_mul(t, pw_h.back(), h, mod);
				for (int i = D; i < h.size(); ++i) {
					h[i - D] = (h[i - D] + h[i]) % mod;
				}
				h.resize(D);
				for (int i = 0; i < D; ++i) {
					h[i] = (h[i] + t[i]) % mod;
				}
				s_pw.push_back(h);

				bf_mul(pw_h.back(), pw_h.back(), h, mod);
				for (int i = D; i < h.size(); ++i) {
					h[i - D] = (h[i - D] + h[i]) % mod;
				}
				h.resize(D);
				pw_h.push_back(h);

				if(N & i) {
					bf_mul(ans, pw_h.back(), ans, mod);
					for (int i = D; i < ans.size(); ++i) {
						ans[i - D] = (ans[i - D] + ans[i]) % mod;
					}
					ans.resize(D);
					for (int i = 0; i < D; ++i) {
						ans[i] = (ans[i] + s_pw.back()[i]) % mod;
					}
				}
			}
			++ans[0];
			printf("%d\n", (ans[0] + mod) % mod);
#ifdef DEBUG
			fprintf(stderr, "OM2logN %d\n", (ans[0] + mod) % mod);
			fprintf(stderr, "%.12f\n", 1. * (clock() - TBEG) / CLOCKS_PER_SEC);
#endif
			return;
		}
	}

	namespace OMlog2MlogN {
		void solve() {
			vector<int> h(D, 0), ans(D, 0); // h = (Bx + A)^D mod (x^D - 1)
			for (int i = 0; i <= D; ++i) {
				int &t = h[i == D ? 0 : i];
				t = ((long long) C(D, i) * pow_mod(B, i) % mod * pow_mod(A, D - i) + t) % mod;
			}
			N /= D;
			if(N & 1) {
				ans = h;
			}
			vector< vector<int> > pw_h, s_pw;
			pw_h.push_back(h);
			s_pw.push_back(h);
			for (long long i = 2; i <= N; i <<= 1) {
				vector<int> &t = s_pw.back();
				cyc_mul(t, pw_h.back(), h);
				for (int i = 0; i < D; ++i) {
					h[i] = (h[i] + t[i]) % mod;
				}
				s_pw.push_back(h);

				cyc_mul(pw_h.back(), pw_h.back(), h);
				pw_h.push_back(h);

				if(N & i) {
					cyc_mul(ans, pw_h.back(), ans);
					for (int i = 0; i < D; ++i) {
						ans[i] = (ans[i] + s_pw.back()[i]) % mod;
					}
				}
			}
			++ans[0];
			printf("%d\n", (ans[0] + mod) % mod);
#ifdef DEBUG
			fprintf(stderr, "OMlog2MlogN %d\n", (ans[0] + mod) % mod);
			fprintf(stderr, "%.12f\n", 1. * (clock() - TBEG) / CLOCKS_PER_SEC);
#endif
			return;
		}
	}
}

namespace WITH_BLOCK {
	namespace OMlog2MlogN {
		vector<int> h; 
		void calc(long long N, vector<int> &ans) {
#ifdef DEBUG
			fprintf(stderr, "calc(%I64d)\n", N);
#endif
			ans.clear();
			ans.assign(D, 0);
			if(N < 0) {
				return;
			}
			if(N & 1) {
				ans = h;
			}
			vector< vector<int> > pw_h, s_pw;
			pw_h.push_back(h);
			s_pw.push_back(h);
			for (long long i = 2; i <= N; i <<= 1) {
				vector<int> &t = s_pw.back(), h;
				cyc_mul(t, pw_h.back(), h);
				for (int i = 0; i < D; ++i) {
					h[i] = (h[i] + t[i]) % mod;
				}
				s_pw.push_back(h);

				cyc_mul(pw_h.back(), pw_h.back(), h);
				pw_h.push_back(h);

				if(N & i) {
					cyc_mul(ans, pw_h.back(), ans);
					for (int i = 0; i < D; ++i) {
						ans[i] = (ans[i] + s_pw.back()[i]) % mod;
					}
				}
			}
			++ans[0];
			return;
		}

		void pow_h(long long N, vector<int> &h) {
#ifdef DEBUG
			fprintf(stderr, "pow_h(%I64d)\n", N);
#endif
			vector<int> x(D, 0);
			h.clear();
			h.assign(D, 0);
			x[0] = A;
			x[1] = B;
			h[0] = 1;
			while(N) {
				if(N & 1) {
					cyc_mul(x, h, h);
				}
				cyc_mul(x, x, x);
				N >>= 1;
			}
			return;
		}

		void solve() {
			h.assign(D, 0);
			for (int i = 0; i <= D; ++i) {
				int &t = h[i == D ? 0 : i];
				t = ((long long) C(D, i) * pow_mod(B, i) % mod * pow_mod(A, D - i) + t) % mod;
			}
			sort(blocks.begin(), blocks.end(), [&](pair<int, long long> a, pair<int, long long> b) {
					return a.second + a.first < b.second + b.first;
					});
			++M;
			vector<int> g(M, 0), f(D, 0);
			g[0] = f[0] = 1;
			long long z = 0;
			int ans = 0;
			for (int i = 0; i < blocks.size();) {
#ifdef DEBUG
				fprintf(stderr, "i = %d\n", i);
#endif
				vector<int> h;
				int j = i;
				long long nz = blocks[i].second + blocks[i].first;
				while(j + 1 < blocks.size() && blocks[j + 1].second + blocks[j + 1].first == nz) {
					++j;
				}

#ifdef DEBUG
				fprintf(stderr, "solve[%I64d, %I64d)\n", z, nz);
#endif
				long long foo = !z ? 0 : (z - 1) / D + 1, bar = (nz - 1) / D - foo, gap;
#ifdef DEBUG
				fprintf(stderr, "bar = %I64d\n", bar);
#endif
				if(bar >= 0) {
					calc(bar, h);
					gap = foo * D - z;
					vector<int> l(D, 0);
					for (int i = 0; i <= gap; ++i) {
						l[i] = (long long) C(gap, i) * pow_mod(B, i) % mod * pow_mod(A, gap - i) % mod;
					}
					cyc_mul(l, f, l);
					mul(h, l, l, mod);
					for (int i = 0; i < l.size(); i += D) {
						ans = (ans + l[i]) % mod;
					}
				}

				gap = nz - z;

				pow_h(gap, h);
				cyc_mul(h, f, f);
#ifdef DEBUG
				fprintf(stderr, "new F(x) calculated\n");
#endif

				h.clear();
				h.push_back(pow_mod(A, gap));
				for (int i = 1; i < M; ++i) {
					h.push_back((gap - i + 1) % mod * h.back() % mod * B % mod * inv(A) % mod * inv(i) % mod);
				}
				mul(h, g, g, mod);
				g.resize(M);
				while(i <= j) {
					int x = blocks[i++].first, y = x % D;
					f[y] = (f[y] - g[x]) % mod;
					g[x] = 0;
				}
#ifdef DEBUG
				fprintf(stderr, "new G(x) calculated\n");
#endif
				z = nz;
			}
#ifdef DEBUGg
			fprintf(stderr, "solve[%I64d, %I64d]\n", z, N);
#endif
			long long foo = !z ? 0 : (z - 1) / D + 1, bar = N / D - foo;
			if(bar >= 0) {
				vector<int> h;
				calc(bar, h);
				long long gap = foo * D - z;
				vector<int> l(D, 0);
				for (int i = 0; i <= gap; ++i) {
					l[i] = (long long) C(gap, i) * pow_mod(B, i) % mod * pow_mod(A, gap - i) % mod;
				}
				cyc_mul(l, f, l);
				mul(h, l, l, mod);
				for (int i = 0; i < l.size(); i += D) {
					ans = (ans + l[i]) % mod;
				}
			}
			printf("%d\n", (ans + mod) % mod);
#ifdef DEBUG
			fprintf(stderr, "WITH_BLOCK OMlog2MlogN %d\n", (ans + mod) % mod);
			fprintf(stderr, "%.12f\n", 1. * (clock() - TBEG) / CLOCKS_PER_SEC);
#endif
			return;
		}
	}
}

int main() {
#ifdef DEBUG
	TBEG = clock();
	//freopen("input.txt", "r", stdin);
#endif
	scanf("%d%d", &A, &B);
	int K;
#ifdef DEBUG
	scanf("%I64d%d%d%d", &N, &D, &M, &K);
#else
	scanf("%lld%d%d%d", &N, &D, &M, &K);
#endif
	while(K--) {
		int x;
		long long y;
#ifdef DEBUG
		scanf("%d%I64d", &x, &y);
#else
		scanf("%d%lld", &x, &y);
#endif
		blocks.push_back(make_pair(x, y));
	}
#ifdef DON2
#ifdef DEBUG
	//freopen("ON2.out", "w", stdout);
#endif
	ON2::solve();
	return 0;
#endif
	prepare();
#ifdef DWITHOUT_BLOCK
	#ifdef DOM2logN
#ifdef DEBUG
		freopen("WITHOUT_BLOCK_OM2logN.out", "w", stdout);
#endif
		WITHOUT_BLOCK::OM2logN::solve();
		return 0;
	#endif
	#ifdef DOMlog2MlogN
#ifdef DEBUG
		freopen("WITHOUT_BLOCK_OMlog2MlogN.out", "w", stdout);
#endif
		WITHOUT_BLOCK::OMlog2MlogN::solve();
		return 0;
	#endif
#endif
#ifdef DWITH_BLOCK
	#ifdef DOM2logN
	#endif
	#ifdef DOMlog2MlogN
#ifdef DEBUG
		freopen("WITH_BLOCK_OMlog2MlogN.out", "w", stdout);
#endif
		WITH_BLOCK::OMlog2MlogN::solve();
		return 0;
	#endif
#endif
}
