//Author: dream_maker
#include<bits/stdc++.h>
using namespace std;
//----------------------------------------------
typedef pair<int, int> pi;
typedef long long ll;
typedef double db;
#define fi first
#define se second
#define fu(a, b, c) for (int a = b; a <= c; ++a)
#define fd(a, b, c) for (int a = b; a >= c; --a)
#define fv(a, b) for (int a = 0; a < (signed)b.size(); ++a)
const int INF_of_int = 1e9;
const ll INF_of_ll = 1e18;
template <typename T>
void Read(T &x) {
  bool w = 1;x = 0;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-') w = 0, c = getchar();
  while (isdigit(c)) {
    x = (x<<1) + (x<<3) + c -'0';
    c = getchar();
  }
  if (!w) x = -x;
}
template <typename T>
void Write(T x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) Write(x / 10);
  putchar(x % 10 + '0');
}
//----------------------------------------------
const int N = 90;
int dp[N * N][N][N];
int n, m, p;

int add(int a, int b) {
  return (a += b) >= p ? a - p : a;
}

int sub(int a, int b) {
  return (a -= b) < 0 ? a + p : a;
}

int mul(int a, int b) {
  return 1ll * a * b % p;
}

int main() {
  freopen("count.in", "r", stdin);
  freopen("count.out", "w", stdout);
  Read(n), Read(m), Read(p);
  dp[1][1][1] = mul(n, m);
  fu(i, 2, n * m) {
    fu(j, 1, min(i, n)) {
      fu(k, 1, min(i, m)) {
        dp[i][j][k] = add(dp[i][j][k], mul(dp[i - 1][j][k], sub(mul(j, k), i - 1)));
        if (j != n) dp[i][j + 1][k] = add(dp[i][j + 1][k], mul(dp[i - 1][j][k], mul(n - j, k)));
        if (k != m) dp[i][j][k + 1] = add(dp[i][j][k + 1], mul(dp[i - 1][j][k], mul(m - k, j)));
      }
    }
  }
  Write(dp[n * m][n][m]);
  return 0;
}
