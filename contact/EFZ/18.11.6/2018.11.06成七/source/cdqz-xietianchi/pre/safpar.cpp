#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
const int N = 1e5 + 10;
const int inf = 1e9 + 10;
int n , a[N] , f[N];
struct Node {
  int mx , mn;
  int tg , val;
} tr[N << 2];

void build(int x, int l, int r) {
  tr[x].mx = -inf;
  tr[x].mn = inf;
  if (l == r) return;
  int mid = l + r >> 1;
  build(x << 1, l, mid);
  build(x << 1 | 1, mid + 1, r);

}

int add(int x,int y) {
  x += y;
  if (x >= mod)
    x -= mod;
  return x;
}
void up(int x) {
  tr[x].val = add(tr[x << 1].val , tr[x << 1 | 1].val);
  tr[x].mx  = max(tr[x << 1].mx  , tr[x << 1 | 1].mx);
  tr[x].mn  = min(tr[x << 1].mn  , tr[x << 1 | 1].mn);

}

void down(int x) {
  if (tr[x].tg) {
    tr[x << 1].mn += tr[x].tg;
    tr[x << 1].mx += tr[x].tg;
    tr[x << 1].tg += tr[x].tg;

    tr[x << 1 | 1].mn += tr[x].tg;
    tr[x << 1 | 1].mx += tr[x].tg;
    tr[x << 1 | 1].tg += tr[x].tg;

    tr[x].tg = 0;
  }
}

void fix(int x,int l,int r) {
  if (tr[x].mn > 0 && tr[x].mx <= 0) return;

  if (l == r) {
    if (tr[x].mn <= 0) {
      tr[x].mx = tr[x].mn;
      tr[x].mn = inf;
      tr[x].val = f[l - 1];
    } else {
      tr[x].mn = tr[x].mx;
      tr[x].mx = -inf;
      tr[x].val = 0;
    }
    return;

  }
  int mid = l + r >> 1;
  down(x);
  fix(x << 1 , l , mid);
  fix(x << 1 | 1 , mid + 1 , r);
  up(x);
}

void insert(int x,int l,int r,int ql,int qr,int val) {

  if (ql <= l && r <= qr) {
    tr[x].tg += val;
    tr[x].mn += val;
    tr[x].mx += val;

    fix(x , l , r);
    return ;
  }

  int mid = l + r >> 1;
  down(x);
  if (ql <= mid) insert(x << 1 , l , mid , ql , qr , val);
  if (mid < qr ) insert(x << 1 | 1 , mid + 1 , r , ql , qr , val);
  up(x);
}



void modify(int x,int l,int r,int pos,int val) {
  if (l == r) {
    if (val <= 0) {
      tr[x].val = f[l - 1];
      tr[x].mx = val;
      tr[x].mn = inf;
    } else {
      tr[x].val = 0;
      tr[x].mn = val;
      tr[x].mx = inf;
    }

    return;
  }

  int mid = l + r >> 1;
  down(x);
  if (pos <= mid) modify(x << 1 , l , mid , pos , val);
  else			modify(x << 1 | 1 , mid + 1 , r , pos , val);
  up(x);
}


vector <int> endpos[N];
int least_maxn[N];

int mn[N][18] , mx[N][18];
int sta[N] , top;
int main() {
  freopen("safpar.in","r",stdin);
  scanf("%d",&n);
  for (int i = 1; i <= n; i++) scanf("%d",a + i);
  for (int i = 1; i <= n; i++) mn[i][0] = mx[i][0] = a[i];

  for (int j = 1; j < 18; j++)
    for (int i = 1; i <= n - (1 << j) + 1; i++) {
      mn[i][j] = min(mn[i][j-1] , mn[ i + (1<<(j-1)) ][j-1]);
      mx[i][j] = max(mx[i][j-1] , mx[ i + (1<<(j-1)) ][j-1]);
    }

  for (int i = 1; i <= n; i++) {
    int now = i , minm = inf , maxn = -inf;
    for (int k = 17; k >= 0; k--)
      if (now <= n && now - i + 1 + (1 << k) - 1 < min(mn[now][k] , minm ) ) {
        minm = min(minm , mn[now][k]);
        maxn = max(maxn , mx[now][k]);
        now += 1 << k;
      }

    if (now <= n) {
      endpos[now].push_back(i);
    }

    if (now <= n) {
      least_maxn[i] = max(maxn , a[now]);
    } else {
      least_maxn[i] = maxn;
    }
  }

  f[0] = 1;
  a[0] = inf;
  build(1 , 1 , n);

  for (int i = 1; i <= n; i++) {
    while (top && a[ sta[top] ] <= a[i]) {
      insert(1 , 1 , n , sta[top - 1] + 1 , sta[top] , a[ sta[top] ] - a[i] );
      top--;
    }



    sta[++top] = i;
    for (int j = 0; j < endpos[i].size(); j++) {
      modify(1 , 1 , n , endpos[i][j] , i - endpos[i][j] + 1 - least_maxn[ endpos[i][j] ]);//len - mx
    }
    f[i] = tr[1].val;
    insert(1 , 1 , n , 1 , n , 1);
  }

  cout<<f[n];

  return 0;
}
