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
const int N = 910;
int w1, h1, w2, h2;
char ca[N], cb[N];

int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b) {
  return a / gcd(a, b) * b;
}

namespace Subtask1 {
int a[N][N], b[N][N];
int sa[N][N], sb[N][N];

void solve() {
  fu(i, 1, w1)
    fu(j, 1, h1)
      a[i][j] = ca[(i - 1) * h1 + j] - '0';
  fu(i, 1, w2)
    fu(j, 1, h2)
      b[i][j] = cb[(i - 1) * h2 + j] - '0';
  int lcmw = lcm(w1, w2);
  int lcmh = lcm(h1, h2);
  fu(i, 1, w1) {
    fu(ip, 1, lcmw / w1) {
      int noww = (i - 1) * (lcmw / w1) + ip;
      fu(j, 1, h1) {
        fu(jp, 1, lcmh / h1) {
          int nowh = (j - 1) * (lcmh / h1) + jp;
          sa[noww][nowh] = a[i][j];
        }
      }
    }
  }
  fu(i, 1, w2) {
    fu(ip, 1, lcmw / w2) {
      int noww = (i - 1) * (lcmw / w2) + ip;
      fu(j, 1, h2) {
        fu(jp, 1, lcmh / h2) {
          int nowh = (j - 1) * (lcmh / h2) + jp;
          sb[noww][nowh] = b[i][j];
        }
      }
    }
  }
  int ans = 0;
  fu(i, 1, lcmw)
    fu(j, 1, lcmh) 
      if (sa[i][j] == sb[i][j]) ++ans;
  Write(ans);
}
}

namespace Subtask2 {
/*
#define LD(t) (t << 1) 
#define RD(t) (t << 1 | 1)
int rt[N * 60], ls[N * 60], rs[N * 60], siz[N * 60], tot = 0;

void pushnow(int t, int len) {
  siz[t] = len;
  tag[t] = 1;
}

void pushup(int t) {
  siz[t] = siz[ls[t]] + siz[rs[t]];
}

void pushdown(int t, int l, int r) {
  if (tag[t]) {
    int mid = (l + r) >> 1;
    if (!ls[t]) ls[t] = ++tot;
    pushnow(ls[t], mid - l + 1);
    if (!rs[t]) rs[t] = ++tot;
    pushnow(rs[t], r - mid);
    tag[t] = 0;
  }
}

void insert_y(int &t, int l, int r, int ql, int qr, int vl, int len) {
  if (!t) t = ++tot;
  if (ql == l && r == qr) {
    siz[t] = vl ? (r - l + 1) * len : 0;
    return;
  }
  pushdown(t, l, r);
  int mid = (l + r) >> 1;
  if (qr <= mid) insert_y(ls[t], l, mid, ql, qr, vl);
  else if(ql > mid) insert_y(rs[t], mid + 1, r, ql, qr, vl);
  else {
    insert_y(ls[t], l, mid, ql, mid, vl);
    insert_y(rs[t], mid + 1, r, mid + 1, qr, vl)  
  }
  pushup(t);
}

void insert_x(int &t, int l, int r, int ql, int qr, int pl, int pr, int vl) {
  if (!t) t = ++tot;
  if (ql == l && r == qr) {
    insert_y(rt[t], 1, limit, pl, pr, vl, pr - pl + 1);
    return; 
  }
  int mid = (l + r) >> 1;
  if (qr <= mid) insert_x(ls[t], l, mid, ql, qr, pl, pr, vl);
  else if(ql > mid) insert_x(rs[t], mid + 1, r, ql, qr, pl, pr, vl);
  else {
    insert_x(ls[t], l, mid, ql, mid, pl, pr, vl);
    insert_x(rs[t], mid + 1, r, mid + 1, qr, pl, pr, vl)  
  }
}

int query_y(int t, int l, int r, int ql, int qr) {
  if (!t) return 0;
  if (ql == l && r == qr) return siz[t];
  int mid = (l + r) >> 1;
  if ()
}

int query_x(int t, int l, int r, int ql, int qr, int pl, int pr) {
  if (ql == l && r == qr) return query_y(rt[t], 1, limit, pl, pr);
  int mid = (l + r) >> 1;
  if (qr <= mid) {
    return query_x(ls[t], l, mid, ql, qr, pl, pr);
  } else if (ql > mid) {
    return query_x(rs[t], mid + 1, r, ql, qr, pl, pr);
  } else {
    return query_x(ls[t], l, mid, ql, mid, pl, pr) + query(rs[t], mid + 1, r, mid + 1, qr, pl, pr);
}

pi query_x(int t, int l, int r, int xl, int xr, int yl, int yr) {
  if (xl <= l && r <= xr) return query_y(1, 1, n, yl, yr, t);
  int mid = (l + r) >> 1;
  
}
*/
const int M = 1e6 + 10;
}

int main() {
  freopen("picture.in", "r", stdin);
  freopen("picture.out", "w", stdout);
  Read(w1), Read(h1);
  scanf("%s", ca + 1);
  Read(w2), Read(h2);
  scanf("%s", cb + 1);
  //if (w1 <= 30 && h1 <= 30 && w2 <= 30 && h2 <= 30) 
    Subtask1::solve();
  return 0;
}
