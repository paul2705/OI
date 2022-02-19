#include <bits/stdc++.h>

#define IL __inline__ __attribute__((always_inline))

#define For(i, a, b) for (int i = a, i##end = b; i <= i##end; ++ i)
#define FOR(i, a, b) for (int i = a, i##end = b; i < i##end; ++ i)
#define Rep(i, a, b) for (int i = a, i##end = b; i >= i##end; -- i)
#define REP(i, a, b) for (int i = (a) - 1, i##end = b; i >= i##end; -- i)

typedef long long LL;

template <class T>
IL bool chkmax(T &a, const T b) {
  return a < b ? ((a = b), 1) : 0;
}

template <class T>
IL bool chkmin(T &a, const T b) {
  return a > b ? ((a = b), 1) : 0;
}

template <class T>
IL T mymax(const T a, const T b) {
  return a > b ? a : b;
}

template <class T>
IL T mymin(const T a, const T b) {
  return a < b ? a : b;
}

template <class T>
IL T myabs(const T &a) {
  return a > 0 ? a : -a;
}

const int INF = 0X3F3F3F3F;
const double EPS = 1E-10, PI = acos(-1.0);

#define DEBUG(...) fprintf(stderr, __VA_ARGS__)
#define OK DEBUG("Passing [%s] in LINE %d...\n", __FUNCTION__, __LINE__)
#define F first
#define S second
/*************************header*************************/

const int MAXN = 1000 + 5;

int MOD;

IL int add(int a, int b) {
  a += b;
  return a >= MOD ? a - MOD : a;
}

IL int mul(int a, int b) {
  return 1LL * a * b % MOD;
}

IL int FastPow(int a, int p) {
  int res = 1;
  for (int base = a; p; p >>= 1, base = mul(base, base)) {
    if (p & 1) {
      res = mul(res, base);
    }
  }
  return res;
}

int a[MAXN * MAXN], mat[MAXN][MAXN];

int main() {
  freopen("count.in", "r", stdin);
  freopen("count.out", "w", stdout);
  int n, m;
  scanf("%d%d%d", &n, &m, &MOD);
  For(i, 1, n * m) {
    a[i] = i;
  }
  LL ans = 0;
  do {
    For(i, 1, n) {
      For(j, 1, m) {
        mat[i][j] = a[(i - 1) * m + j];
      }
    }
    int cnt = 0;
    For(i, 1, n) {
      int cur = 0, pos = -1;
      For(j, 1, m) {
        if (chkmax(cur, mat[i][j])) {
          pos = j;
        }
      }
      bool ok = 1;
      For(j, 1, n) {
        if (i != j && mat[j][pos] > mat[i][pos]) {
          ok = 0;
          break;
        }
      }
      cnt += ok;
    }
    if (cnt == 1) {
      ++ ans;
    }
  } while (std::next_permutation(a + 1, a + n * m + 1));
  printf("%lld\n", ans % MOD);
  return 0;
}

