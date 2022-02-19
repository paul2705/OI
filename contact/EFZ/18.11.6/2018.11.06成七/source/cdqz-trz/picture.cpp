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

const int MAXN = 1000000 + 5;


char str1[MAXN], str2[MAXN];
int all[MAXN * 4], *mat1[MAXN], *mat2[MAXN], *prefix_sum[MAXN], *pool = all;
LL k1, k2, k3, k4;

IL LL Sum(int x1, int y1, int x2, int y2) {
  return prefix_sum[x2][y2] - prefix_sum[x1 - 1][y2] - prefix_sum[x2][y1 - 1] + prefix_sum[x1 - 1][y1 - 1];
}

int main() {
  freopen("picture.in", "r", stdin);
  freopen("picture.out", "w", stdout);
  int n1, m1;
  scanf("%d%d", &n1, &m1);
  For(i, 0, n1) {
    mat1[i] = pool;
    pool += m1 + 5;
  }
  scanf("%s", str1 + 1);
  For(i, 1, n1) {
    For(j, 1, m1) {
      mat1[i][j] = str1[(i - 1) * m1 + j] - '0';
    }
  }
  int n2, m2;
  scanf("%d%d", &n2, &m2);
  For(i, 0, n2) {
    mat2[i] = pool;
    pool += m2 + 5;
    prefix_sum[i] = pool;
    pool += m2 + 5;
  }
  scanf("%s", str2 + 1);
  For(i, 1, n2) {
    For(j, 1, m2) {
      mat2[i][j] = str2[(i - 1) * m2 + j] - '0';
      prefix_sum[i][j] = mat2[i][j] + prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1];
    }
  }
  LL lcm_n = 1LL * n1 * n2 / std::__gcd(n1, n2), lcm_m = 1LL * m1 * m2 / std::__gcd(m1, m2), ans = 0;
  k1 = lcm_n / n1, k2 = lcm_n / n2, k3 = lcm_m / m1, k4 = lcm_m / m2;
  For(i, 1, n1) {
    LL k5 = (i - 1) * k1 + 1, k6 = i * k1;
    std::pair <LL, LL> pos_i = std::make_pair(k5 / k2 + (bool)(k5 % k2), 
      k6 / k2 + (bool)(k6 % k2));
    For(j, 1, m1) {
      LL k7 = (j - 1) * k3 + 1, k8 = j * k3;
      std::pair <LL, LL> pos_j = std::make_pair(k7 / k4 + (bool)(k7 % k4), 
        k8 / k4 + (bool)(k8 % k4));
      if (pos_i.F == pos_i.S) {
        if (pos_j.F == pos_j.S) {
          ans += (mat1[i][j] == mat2[pos_i.F][pos_j.F]) * (k6 - k5 + 1) * (k8 - k7 + 1);
        } else {
          ans += (mat1[i][j] == mat2[pos_i.F][pos_j.F]) * (k6 - k5 + 1) * (pos_j.F * k4 - k7 + 1);
          ans += (k6 - k5 + 1) * k4 * (mat1[i][j] ? Sum(pos_i.F, pos_j.F + 1, pos_i.F, pos_j.S - 1) :
            pos_j.S - 1 - pos_j.F - Sum(pos_i.F, pos_j.F + 1, pos_i.F, pos_j.S - 1));
          ans += (mat1[i][j] == mat2[pos_i.F][pos_j.S]) * (k6 - k5 + 1) * (k8 - (pos_j.S - 1) * k4);
        }
      } else {
        if (pos_j.F == pos_j.S) {
          ans += (mat1[i][j] == mat2[pos_i.F][pos_j.F]) * (k8 - k7 + 1) * (pos_i.F * k2 - k5 + 1);
          ans += (k8 - k7 + 1) * k2 * (mat1[i][j] ? Sum(pos_i.F + 1, pos_j.F, pos_i.S - 1, pos_j.F) :
            pos_i.S - 1 - pos_i.F - Sum(pos_i.F + 1, pos_j.F, pos_i.S - 1, pos_j.F));
          ans += (mat1[i][j] == mat2[pos_i.S][pos_j.F]) * (k8 - k7 + 1) * (k6 - (pos_i.S - 1) * k2);
        } else {
          ans += (mat1[i][j] == mat2[pos_i.F][pos_j.F]) * (pos_i.F * k2 - k5 + 1) * (pos_j.F * k4 - k7 + 1);
          ans += (mat1[i][j] == mat2[pos_i.F][pos_j.S]) * (pos_i.F * k2 - k5 + 1) * (k8 - (pos_j.S - 1) * k4);
          ans += (mat1[i][j] == mat2[pos_i.S][pos_j.F]) * (k6 - (pos_i.S - 1) * k2) * (pos_j.F * k4 - k7 + 1);
          ans += (mat1[i][j] == mat2[pos_i.S][pos_j.S]) * (k6 - (pos_i.S - 1) * k2) * (k8 - (pos_j.S - 1) * k4);
          ans += (pos_j.F * k4 - k7 + 1) * k2 * (mat1[i][j] ? Sum(pos_i.F + 1, pos_j.F, pos_i.S - 1, pos_j.F) :
            pos_i.S - 1 - pos_i.F - Sum(pos_i.F + 1, pos_j.F, pos_i.S - 1, pos_j.F));
          ans += (pos_i.F * k2 - k5 + 1) * k4 * (mat1[i][j] ? Sum(pos_i.F, pos_j.F + 1, pos_i.F, pos_j.S - 1) :
            pos_j.S - 1 - pos_j.F - Sum(pos_i.F, pos_j.F + 1, pos_i.F, pos_j.S - 1));
          ans += (k8 - (pos_j.S - 1) * k4) * k2 * (mat1[i][j] ? Sum(pos_i.F + 1, pos_j.S, pos_i.S - 1, pos_j.S) :
            pos_i.S - 1 - pos_i.F - Sum(pos_i.F + 1, pos_j.S, pos_i.S - 1, pos_j.S));
          ans += (k6 - (pos_i.S - 1) * k2) * k4 * (mat1[i][j] ? Sum(pos_i.S, pos_j.F + 1, pos_i.S, pos_j.S - 1) :
            pos_j.S - 1 - pos_j.F - Sum(pos_i.S, pos_j.F + 1, pos_i.S, pos_j.S - 1));
          ans += k2 * k4 * (mat1[i][j] ? Sum(pos_i.F + 1, pos_j.F + 1, pos_i.S - 1, pos_j.S - 1) :
            (pos_i.S - 1 - pos_i.F) * (pos_j.S - 1 - pos_j.F) - Sum(pos_i.F + 1, pos_j.F + 1, pos_i.S - 1, pos_j.S - 1));
        }
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}

