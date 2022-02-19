#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cstdio>
#include <set>
using namespace std;
int W[3];
int H[3];
int sx[3];
int sy[3];
bool A[3][10][10];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
struct state {
  state(int d) : d(d) {
    for(int i = 2; i >= 0; i--) {
      sx[i] -= sx[0];
      sy[i] -= sy[0];
    }
    memcpy(ssx, sx, sizeof(ssx));
    memcpy(ssy, sy, sizeof(ssy));
  }
  state(const state& st) {
    d = st.d;
    memcpy(ssx, st.ssx, sizeof(ssx));
    memcpy(ssy, st.ssy, sizeof(ssy));
  }
  state& operator=(const state& st) {
    d = st.d;
    memcpy(ssx, st.ssx, sizeof(ssx));
    memcpy(ssy, st.ssy, sizeof(ssy));
    return *this;
  }
  void unpack() {
    memcpy(sx, ssx, sizeof(ssx));
    memcpy(sy, ssy, sizeof(ssy));
  }
  bool operator<(const state& st) const {
    int r = memcmp(ssx, st.ssx, sizeof(ssx));
    if(!r) r = memcmp(ssy, st.ssy, sizeof(ssy));
    return r < 0;
  }
  int d;
  int ssx[3];
  int ssy[3];
};
bool intersect(int i, int j) {
  return sx[i] < sx[j] + W[j] && sx[j] < sx[i] + W[i] &&
         sy[i] < sy[j] + H[j] && sy[j] < sy[i] + H[i];
}
bool check() {
  for(int i = 0; i < 3; i++) {
    if(sx[i] < -20 || sx[i] > 20 || sy[i] < -20 || sy[i] > 20) return false;
    for(int j = i + 1; j < 3; j++) {
      for(int x = 0; x < W[i]; x++) {
        for(int y = 0; y < H[i]; y++) {
          if(!A[i][x][y]) continue;
          int nx = sx[i] + x - sx[j], ny = sy[i] + y - sy[j];
          if(nx < 0 || nx >= W[j] || ny < 0 || ny >= H[j] ||
             !A[j][nx][ny]) continue;
          return false;
        }
      }
    }
  }
  return true;
}
int main() {
//  freopen("unlock.in", "r", stdin);
//  freopen("unlock.out", "w", stdout);
  int N[3];
  cin >> N[0] >> N[1] >> N[2];
  for(int i = 0; i < 3; i++) {
    int mx = 10, my = 10;
    int gx = 0, gy = 0;
    for(int j = 0; j < N[i]; j++) {
      int x, y; cin >> x >> y;
      A[i][x][y] = true;
      mx = min(mx, x); my = min(my, y);
      gx = max(gx, x + 1); gy = max(gy, y + 1);
    }
    W[i] = gx - mx; H[i] = gy - my;
    for(int x = mx; x < 10; x++)
    for(int y = my; y < 10; y++) {
      A[i][x - mx][y - my] = A[i][x][y];
      if(mx || my) A[i][x][y] = false;
    }
    sx[i] = mx;
    sy[i] = my;
  }
  queue<state> q;
  set<state> vis;
  q.push(state(0));
  while(!q.empty()){
    state st = q.front();
    q.pop();
    st.unpack();
    if(!intersect(0, 1) && !intersect(0, 2) && !intersect(1, 2)) {
      cout << st.d << endl;
      return 0;
    }
    for(int i = 0; i < 3; i++) {
      for(int j = 0; j < 4; j++) {
        st.unpack();
        sx[i]+=dx[j];
        sy[i]+=dy[j];
        state nst = state(st.d + 1);
        if(vis.insert(nst).second && check()) q.push(nst);
      }
    }
  }
  cout << -1 << endl;
  return 0;
}
