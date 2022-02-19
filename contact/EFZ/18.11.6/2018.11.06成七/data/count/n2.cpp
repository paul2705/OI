#include <cstdio>
#include <algorithm>

#define ll long long
#define db double
#define ull unsigned long long
#define uint unsigned int
#define FIO ""
#define dbug(...) fprintf(stderr, __VA_ARGS__)

template <typename Y> inline bool updmin(Y &a, Y b){if (a > b) {a = b; return 1;} return 0;}
template <typename Y> inline bool updmax(Y &a, Y b){if (a < b) {a = b; return 1;} return 0;}
template <typename Y> inline Y abs(Y a){if (a < 0) a = -a; return a;}
template <typename Y> inline Y sqr(Y a){return a * a;}

typedef std::pair<int, int> par;
#define fx first
#define fy second
#define mpar std::make_pair
#define pb push_back

int read() {
  int w = 1, q = 0, ch = ' ';
  for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') w = -1;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) q = q * 10 + ch - 48;
  return q * w;
}

inline void FileIO(){freopen(FIO".in", "r", stdin); freopen(FIO".out", "w", stdout);}

const int N = 1010;
int n, m, p;
int fac[N * N], inv[N * N], f[N][N];

inline int C(int x, int y) {
  if (y < 0 || x < y) return 0;
  return (ll)fac[x] * inv[y] % p * inv[x - y] % p;
}

int main() {
  n = read();
  m = read();
  p = read();
  fac[0] = fac[1] = 1;
  inv[0] = inv[1] = 1;
  for (int i = 2; i <= n * m; i++) {
    fac[i] = (ll)fac[i - 1] * i % p;
    inv[i] = p - (ll)p / i * inv[p % i] % p;
  }
  for (int i = 2; i <= n * m; i++) {
    inv[i] = (ll)inv[i - 1] * inv[i] % p;
  }
  f[1][1] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (i < n) {
        int x = (ll)(i + 1) * fac[j] % p * C(n * m - i * j - 1, j - 1) % p;
        f[i + 1][j] = (f[i + 1][j] + (ll)x * f[i][j]) % p;
      }
      if (j < m) {
        int x = (ll)(j + 1) * fac[i] % p * C(n * m - i * j - 1, i - 1) % p;
        f[i][j + 1] = (f[i][j + 1] + (ll)x * f[i][j]) % p;
      }
    }
  }
  printf("%d\n", f[n][m]);
  return 0;
}
