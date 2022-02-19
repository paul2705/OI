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

int n1, m1, n2, m2, X = 1000000;
#include <ctime>
#include <random>

int main() {
  std::mt19937 rng((unsigned)time(0));
  n1 = rng() % 1000 + 1;
  m1 = X / n1;
  printf("%d %d\n", n1, m1);
  for (int i = 1; i <= n1 * m1; i++) {
    putchar(48 + !!(rng() % 20));
  }
  puts("");
  m2 = rng() % 1000 + 1;
  n2 = X / m2;
  printf("%d %d\n", n2, m2);
  for (int i = 1; i <= n2 * m2; i++) {
    putchar(48 + !(rng() % 20));
  }
  puts("");
  return 0;
}
