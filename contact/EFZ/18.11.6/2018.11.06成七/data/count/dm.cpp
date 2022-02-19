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

#include <ctime>
#include <random>

inline bool isprime(int p) {
  for (int i = 2; i * i <= p; i++) {
    if (!(p % i)) return 0;
  }
  return 1;
}

int main() {
  std::mt19937 rng((unsigned)time(0));
  int p = 4;
  while (!isprime(p)) {
    p = rng() % 900000000 + 100000000;
  }
  int n = 1000 - rng() % 20;
  int m = 1000 - rng() % 20;
  printf("%d %d %d\n", n, m, p);
  return 0;
}
