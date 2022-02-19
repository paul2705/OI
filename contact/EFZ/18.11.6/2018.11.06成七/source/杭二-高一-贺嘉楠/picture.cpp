#if 0
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<utility>
#include<stdlib.h>
#include<time.h>
#else
#include<bits/stdc++.h>
#endif

#if 0
#include<cmath>
#endif

#define REP(i,l,r) for (reg int i=(l);i<=(r);++i)
#define RREP(i,r,l) for (int i=(r);i>=(l);--i)
#define rep(i,l,r) for (int i=(l);i<(r);++i)
#define rrep(i,r,l) for (int i=(r);i>(l);--i)
#define foredge(i,u) for (int i=la[u];i;i=ne[i])
#define mem(a) memset(a,0,sizeof(a))
#define memid(a) memset(a,63,sizeof(a))
#define memax(a) memset(a,127,sizeof(a))
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define reg register
#define tpn typename
#define fr(a) freopen(a,"r",stdin)
#define fw(a) freopen(a,"w",stdout)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;

template <tpn A> inline A Max(const A &x,const A &y){
    return x>y?x:y;
}
template <tpn A> inline A Min(const A &x,const A &y){
    return x<y?x:y;
}
template <tpn A> inline void Swap(A &x,A &y){
    x^=y,y^=x,x^=y;
}
template <tpn A> inline A Abs(const A &x){
    return x>0?x:-x;
}
#if 1
template <tpn A> inline void read(A &x){
    char c;
    A neg=1;
    do{
        c=getchar();
    }while ((c<'0'||c>'9')&&c!='-');
    if (c=='-') neg=-1,c=getchar();
    x=0;
    do{
        x=x*10+c-48;
        c=getchar();
    }while (c>='0'&&c<='9');
    x*=neg;
}
template <tpn A,tpn B> inline void read(A &a,B &b){
read(a),read(b);}
template <tpn A,tpn B,tpn C> inline void read(A &a,B &b,C &c){
read(a),read(b),read(c);}
template <tpn A,tpn B,tpn C,tpn D> inline void read(A &a,B &b,C &c,D &d){
read(a),read(b),read(c),read(d);}
template <tpn A> inline void put(const A &tmp){
    A x=tmp;
    if (x==0){
        putchar('0');
        return;
    }
    if (x<0) putchar('-'),x=-x;
    char buf[30];
    int buf_size=0;
    while (x){
        buf[++buf_size]=x%10+48;
        x/=10;
    }
    RREP(i,buf_size,1) putchar(buf[i]);
}
#else
namespace fastIO {
    #define buf_size 100000
    #define LL long long
    bool error;
    inline char gc() {
        static char buf[buf_size + 1], *l = buf, *r = buf;
        if (l == r) {
            l = buf;
            r = buf + fread(buf, 1, buf_size, stdin);
            if (l == r) {
                error = 1;
                return -1;
            }
        }
        return *l ++;
    }
    inline bool blank(char ch) {
        return ch == '\n' || ch == '\t' || ch == ' ' || ch == '\r' || error;
    }
    inline bool read_int(int &x) {
        char ch;
        int f = 1;
        while (blank(ch = gc()));
        if (error) return false;
        x = 0;
        if (ch == '-') f = -1, ch = gc();
        while (1) {
            x = (x << 1) + (x << 3) + ch - '0';
            if (!isdigit(ch = gc())) break;
        }
        x *= f;
        return true;
    }
    inline bool read_LL(LL &x) {
        char ch;
        LL f = 1;
        while (blank(ch = gc()));
        if (error) return false;
        x = 0;
        if (ch == '-') f = -1, ch = gc();
        while (1) {
            x = (x << 1) + (x << 3) + ch - '0';
            if (!isdigit(ch = gc())) break;
        }
        x *= f;
        return true;
    }
    inline bool read_char(char &x) {
        char ch;
        while (blank(ch = gc()));
        if (error) return false;
        x = ch;
        return true;
    }
    inline void put_int(int x) {
        if (!x) {
            putchar('0');
            return;
        }
        if (x < 0) {
            x = -x;
            putchar('-');
        }
        static int out[13];
        int len = 0;
        while (x) {
            out[++ len] = x % 10;
            x /= 10;
        }
        while (len) putchar(out[len --] + '0');
    }
    inline void put_LL(LL x) {
        if (!x) {
            putchar('0');
            return;
        }
        if (x < 0) {
            x = -x;
            putchar('-');
        }
        static LL out[20];
        int len = 0;
        while (x) {
            out[++ len] = x % 10;
            x /= 10;
        }
        while (len) putchar(out[len --] + '0');
    }
    #undef buf_size
    #undef LL
}
using namespace fastIO;
#endif
inline int mul_mod(int a,int b,int mo){
    int ret;
    __asm__ __volatile__ ("\tmull %%ebx\n\tdivl %%ecx\n":"=d"(ret):"a"(a),"b"(b),"c"(mo));
    return ret;
}
const int N = 1000005;
char s[N], t[N];
ll n, m, nn, mm, H, W, ans;
ll lux, luy, rdx, rdy, x, y, xx, yy, tlux, tluy, trdx, trdy;
ll gcd(ll a,ll b){
    return !b ? a : gcd(b, a % b);
}
int main(){
    fr("picture.in");
    fw("picture.out");
    read(n, m);
    scanf("%s", s);
    read(nn, mm);
    scanf("%s", t);
    H = n * nn / gcd(n, nn);
    W = m * mm / gcd(m, mm);
    rep(i, 0, n)
    rep(j, 0, m){
        lux = i * H / n;
        luy = j * W / m;
        rdx = (i + 1) * H / n - 1;
        rdy = (j + 1) * W / m - 1;
        x = lux / (H / nn);
        y = luy / (W / mm);
        xx = rdx / (H / nn);
        yy = rdy / (W / mm);
        REP(ii, x, xx)
        REP(jj, y, yy)
        if (s[i * m + j] == t[ii * mm + jj]){
            tlux = ii * H / nn;
            tluy = jj * W / mm;
            trdx = (ii + 1) * H / nn - 1;
            trdy = (jj + 1) * W / mm - 1;
            tlux = Max(tlux, lux);
            tluy = Max(tluy, luy);
            trdx = Min(trdx, rdx);
            trdy = Min(trdy, rdy);
            ans += (trdx - tlux + 1) * (trdy - tluy + 1);
        }
    }
    cout << ans << endl;
    return 0;
}