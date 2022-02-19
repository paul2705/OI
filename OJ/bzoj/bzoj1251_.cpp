#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <queue>
#include <map>
#include <vector>
using namespace std;
#define go(i, j, n, k) for(int i = j; i <= n; i += k) 
#define fo(i, j, n, k) for(int i = j; i >= n; i -= k)
#define rep(i, x) for(int i = h[x]; i; i = e[i].nxt)
#define mn 50010
#define inf 1 << 30
#define ll long long
inline int read(){
    int x = 0, f = 1; char ch = getchar();
    while(ch > '9' || ch < '0') { if(ch == '-') f = -f; ch = getchar(); }
    while(ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
} 
struct tree{
    int ch[2], pri, sze, w;
    int maxx;
    int col, coll;
} z[mn];
inline void update(int rt) {
    z[rt].sze = 1;
    z[rt].maxx = z[rt].w;
    if(z[rt].ch[0]) {
        z[rt].sze += z[z[rt].ch[0]].sze;
        z[rt].maxx = max(z[rt].maxx, z[z[rt].ch[0]].maxx);
    }
    if(z[rt].ch[1]) {
        z[rt].sze += z[z[rt].ch[1]].sze;
        z[rt].maxx = max(z[rt].maxx, z[z[rt].ch[1]].maxx);
    }
}
inline void push_col(int rt) {
    if(z[rt].col) {
        if(z[rt].ch[0]) {
            z[z[rt].ch[0]].col += z[rt].col;
            z[z[rt].ch[0]].maxx += z[rt].col;
            z[z[rt].ch[0]].w += z[rt].col;
        }
        if(z[rt].ch[1]) {
            z[z[rt].ch[1]].col += z[rt].col;
            z[z[rt].ch[1]].maxx += z[rt].col;
            z[z[rt].ch[1]].w += z[rt].col;
        }
        z[rt].col = 0;
//      update(rt);
    }
    if(z[rt].coll) {
        if(z[rt].ch[0]) z[z[rt].ch[0]].coll ^= 1;
        if(z[rt].ch[1]) z[z[rt].ch[1]].coll ^= 1;
        swap(z[rt].ch[0], z[rt].ch[1]);
        z[rt].coll = 0;
    }
}
int cnt;
inline int newnode(int w = 0) {
    z[++cnt].maxx = w;
    z[cnt].w = w;
    z[cnt].pri = rand();
    z[cnt].sze = 1;
    z[cnt].col = z[cnt].coll = 0;
    return cnt;
} 
inline int merge(int x, int y) {
    if(!x || !y) return x + y;
    if(z[x].pri < z[y].pri) {
        push_col(x);
        z[x].ch[1] = merge(z[x].ch[1], y);
        update(x);
        return x;
    } else {
        push_col(y);
        z[y].ch[0] = merge(x, z[y].ch[0]);
        update(y);
        return y;
    }
}
inline void split(int rt, int k, int &x, int &y) {
    if(!rt) x = y = 0;
    else {
        push_col(rt);
        if(k <= z[z[rt].ch[0]].sze) {
            y = rt, split(z[rt].ch[0], k, x, z[rt].ch[0]);
        } else {
            x = rt, split(z[rt].ch[1], k - z[z[rt].ch[0]].sze - 1, z[rt].ch[1], y);
        }
        update(rt);
    }
}
inline void debug(int rt) {
    if(!rt) return;
    if(z[rt].ch[0]) debug(z[rt].ch[0]);
    printf("%d %d %d %d\n", z[rt].w, z[rt].maxx, z[rt].pri, z[rt].sze);
    if(z[rt].ch[1]) debug(z[rt].ch[1]);

}
int n, m, rot, xx, yy, zz;
int main() {
	freopen("bzoj1251.in","r",stdin);
	freopen("bzoj1251_.out","w",stdout);
	n = read(), m = read();
    go(i, 1, n, 1) {
        rot = merge(rot, newnode(0));
    }
    go(i, 1, m, 1) {
        int s = read(), l = read(), r = read(), v;
        if(s == 1) {
            v = read();
            split(rot, r, xx, zz);
            split(xx, l - 1, xx, yy);
            z[yy].col += v;
            z[yy].maxx += v;
            z[yy].w += v;
            rot = merge(merge(xx, yy), zz);
        } else if(s == 2) {
            split(rot, r, xx, zz);
            split(xx, l - 1, xx, yy);
            z[yy].coll ^= 1;
            rot = merge(merge(xx, yy), zz);
        } else if(s == 3) {
            split(rot, r, xx, zz);
            split(xx, l - 1, xx, yy);
            printf("%d\n", z[yy].maxx);
            rot = merge(merge(xx, yy), zz);
        }
    }
//  debug(rot);
	fclose(stdin); fclose(stdout);
    return 0;
}
