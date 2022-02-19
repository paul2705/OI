#include <iostream>
const int maxn = 50000;

int x[maxn], y[maxn], p[maxn], q[maxn];
int flag[maxn] = {0};
int ch[maxn];
int n;

long long cross(int x1, int y1, int x2, int y2, int x3, int y3) {
  long long x21 = x2 - x1;
  long long y21 = y2 - y1;
  long long x31 = x3 - x1;
  long long y31 = y3 - y1;
  return x31 * y21 - y31 * x21;
}

bool less(int x1, int y1, int x2, int y2) {
  if(x1 != x2) return x1 < x2;
  return y1 < y2;
}

void solve(int sign) {
  int top = 0;
  for (int i = 0; i < n; i++) {
    while (top > 1) {
      int b = ch[top - 1];
      int a = ch[top - 2];
      if (cross(x[a], y[a], x[b], y[b], x[i], y[i]) * sign <= 0)
        top--;
      else
        break;
    }
    ch[top] = i;
    top++;
  }

  int j = 0;
  while (j < n && less(p[j], q[j], x[0], y[0]))
    j++;
  int k = 0;
  for (; j < n; j++) {
    while (k + 1 < top) {
      int r = ch[k + 1];
      if (!less(p[j], q[j], x[r], y[r]))
        k++;
      else
        break;
    }
    if (k + 1 < top) {
      int l = ch[k];
      int r = ch[k + 1];
      if (cross(x[l], y[l], p[j], q[j], x[r], y[r]) * sign <= 0)
        flag[j]++;
    }
  }  
}

int main() {
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  for (int j = 0; j < n; j++) {
    std::cin >> p[j] >> q[j];
  }
  solve(1);
  solve(-1);
  int ans = 0;
  for (int j = 0; j < n; j++)
    if (flag[j] == 2) ans++;
  std::cout << ans << std::endl;
  return 0;
}
