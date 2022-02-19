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

int getbit() {
  int ch = ' ';
  for (; ch != '0' && ch != '1'; ch = getchar());
  return ch - '0';
}

inline void FileIO(){freopen(FIO".in", "r", stdin); freopen(FIO".out", "w", stdout);}

#include <vector>
std::vector<std::vector<int> > A;

ll n1, m1, n2, m2, a, b, c, d;

inline ll sum(ll x1, ll y1, ll x2, ll y2) {
  return A[x2][y2] - A[x1 - 1][y2] - A[x2][y1 - 1] + A[x1 - 1][y1 - 1];
}

inline ll calc(ll x, ll y) {
  if (!x || !y) return 0;
  ll ret = 0;
  ll cx = x / a, cy = y / b;
  ll dx = x % a, dy = y % b;
  ret += A[cx][cy] * a * b;
  ret += sum(cx + 1, 1, cx + 1, cy) * dx * b;
  ret += sum(1, cy + 1, cx, cy + 1) * a * dy;
  ret += sum(cx + 1, cy + 1, cx + 1, cy + 1) * dx * dy;
  return ret;
}

int main() {
  n1 = read();
  m1 = read();
  A = std::vector<std::vector<int> > ((int)n1 + 3, std::vector<int> ((int)m1 + 3, 0));
  for (int i = 1; i <= n1; i++) {
    for (int j = 1; j <= m1; j++) {
      A[i][j] = getbit() + A[i - 1][j] + A[i][j - 1] - A[i - 1][j - 1];
    }
  }
  n2 = read();
  m2 = read();
  ll tmpn = std::__gcd(n1, n2), tmpm = std::__gcd(m1, m2);
  a = n2 / tmpn, b = m2 / tmpm;
  c = n1 / tmpn, d = m1 / tmpm;
  ll ans = 0;
  for (ll sx = 1; sx <= n2; sx++) {
    for (ll sy = 1; sy <= m2; sy++) {
      ll qx = sx * c, qy = sy * d;
      ll ss = calc(qx, qy) - calc(qx - c, qy) - calc(qx, qy - d) + calc(qx - c, qy - d);
      if (!getbit()) {
        ss = c * d - ss;
      }
      ans += ss;
    }
  }
  printf("%lld\n", ans);
}
