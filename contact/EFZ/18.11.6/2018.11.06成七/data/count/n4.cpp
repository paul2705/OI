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

int f[2][82][82], n, m, p;

int main() {
  n = read();
  m = read();
  p = read();
  if (p == 1) {
    puts("0");
    return 0;
  }
  for (int j = 1; j <= n; j++) {
    for (int k = 1; k <= m; k++) {
      f[1][j][k] = 0;
    }
  }
  f[1][1][1] = n * m % p;
  for (int i = 1; i < n * m; i++) {
    int I = i & 1;
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= m; k++) {
        f[!I][j][k] = 0;
      }
    }
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= m; k++) {
        if (!f[I][j][k]) continue;
        f[!I][j][k] = (f[!I][j][k] + (ll)f[I][j][k] * (j*k-i)) % p;
        f[!I][j+1][k] = (f[!I][j+1][k] + (ll)f[I][j][k] * k*(n-j)) % p;
        f[!I][j][k+1] = (f[!I][j][k+1] + (ll)f[I][j][k] * j*(m-k)) % p;
      }
    }
  }
  int i = (n * m) & 1, ans = 0;
  ans = f[i][n][m];
  printf("%d\n", ans);
}
