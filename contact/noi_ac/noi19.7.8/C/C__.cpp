#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<numeric>
using namespace std;

using LL = long long;

namespace _buff {

const size_t BUFF = 1 << 19;
char ibuf[BUFF], *ib = ibuf, *ie = ibuf;
char getc() {
    if (ib == ie) {
        ib = ibuf;
        ie = ibuf + fread(ibuf, 1, BUFF, stdin);
    }
    return ib == ie ? -1 : *ib++;
}

}

LL read() {
    using namespace _buff;
    LL ret = 0;
    bool pos = true;
    char c = getc();
    for (; (c < '0' || c > '9') && c != '-'; c = getc()) {
        assert(~c);
    }
    if (c == '-') {
        pos = false;
        c = getc();
    }
    for (; c >= '0' && c <= '9'; c = getc()) {
        ret = (ret << 3) + (ret << 1) + (c ^ 48);
    }
    return pos ? ret : -ret;
}

const size_t N = 3e6 + 5;

template <typename T>
void chkmin(T &dp, const T &val) {
    if (val < dp) dp = val;
}

template <typename T>
void chkmax(T &dp, const T &val) {
    if (val > dp) dp = val;
}

void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x == 0) {
        putchar('0');
        return;
    }
    static char dig[64];
    int tp = 0;
    for (; x; x /= 10) {
        dig[++tp] = (x % 10) ^ '0';
    }
    while (tp) {
        putchar(dig[tp--]);
    }
}

int n;
LL a[N], b[N], sum[N];
__int128 ans = -1e30;
#define fi first
#define se second

void solve(int l, int r) {
        if (l + 1 == r) {
        /* cerr << "checking " << a[l] << ' ' << b[l] << '\n'; */
        chkmax(ans, (__int128) a[l] * b[l]);
        return;
    }
    int mid = (l + r) >> 1;
    solve(l, mid);
    solve(mid, r);

    using P = pair<LL, pair<LL, LL> >;
    static P lft[N], rht[N];
    int lft_tp = 0, rht_tp = 0;

    /* do left */ {
        LL cur = 1e18, mn = 1e18, mx = -1e18;
        for (int i = mid - 1; i >= l; --i) {
            if (a[i] < cur) {
                if (i < mid - 1) {
                    lft[lft_tp++] = make_pair(cur, make_pair(mn, mx));
                }
                mn =  1e18;
                mx = -1e18;
                cur = a[i];
            }
            chkmin(mn, -sum[i - 1]);
            chkmax(mx, -sum[i - 1]);
        }
        lft[lft_tp++] = make_pair(cur, make_pair(mn, mx));
    } /* do right */ {
        LL cur = 1e18, mn = 1e18, mx = -1e18;
        for (int i = mid; i < r; ++i) {
            if (a[i] < cur) {
                if (i > mid) {
                    rht[rht_tp++] = make_pair(cur, make_pair(mn, mx));
                }
                mn =  1e18;
                mx = -1e18;
                cur = a[i];
            }
            chkmin(mn, sum[i]);
            chkmax(mx, sum[i]);
        }
        rht[rht_tp++] = make_pair(cur, make_pair(mn, mx));
    }

    /* do left */ {
        LL mn = 1e18, mx = -1e18;
        for (int i = 0, j = 0; i < lft_tp; ++i) {
            for (; j < rht_tp && rht[j].fi >= lft[i].fi; ++j) {
                chkmin(mn, rht[j].se.fi);
                chkmax(mx, rht[j].se.se);
            }
            if (j) {
                chkmax(ans, (__int128) lft[i].fi * (lft[i].se.fi + mn));
                chkmax(ans, (__int128) lft[i].fi * (lft[i].se.se + mx));
            }
        }
    } /* do right */ {
        LL mn = 1e18, mx = -1e18;
        for (int i = 0, j = 0; i < rht_tp; ++i) {
            for (; j < lft_tp && lft[j].fi >= rht[i].fi; ++j) {
                chkmin(mn, lft[j].se.fi);
                chkmax(mx, lft[j].se.se);
            }
            if (j) {
                chkmax(ans, (__int128) rht[i].fi * (rht[i].se.fi + mn));
                chkmax(ans, (__int128) rht[i].fi * (rht[i].se.se + mx));
            }
        }
    }
}

int main() {
	freopen("1.in","r",stdin);
	n = read();
    generate_n(a + 1, n, read);
    generate_n(b + 1, n, read);
    partial_sum(b + 1, b + n + 1, sum + 1);
    solve(1, n + 1);
    print(ans);
    return 0;
}
