#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
  //freopen("john.in", "r", stdin);
  //freopen("john.out", "w", stdout);
  int tot;
  scanf("%d", &tot);
  while (tot--) {
    int n, g = 0, t;
    scanf("%d", &n);
    bool flag = 0;
    int s = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &t);
      if (t > 1) flag = 1;
      if (t > 0) s++;
      g ^= t;
    }
    if (flag) {
      if (g == 0) printf("Brother\n"); else printf("John\n");
    } else {
      if (s % 2) printf("Brother\n"); else printf("John\n");
    }
  }
  //fclose(stdin);
  //fclose(stdout);
  return 0;
}
