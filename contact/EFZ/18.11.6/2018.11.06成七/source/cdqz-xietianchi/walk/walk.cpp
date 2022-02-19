#include <bits/stdc++.h>
#define mod 998244353
#define g 3
#define ginv 332748118
using namespace std;
const int N = 1e5 + 10;

int add(int x,int y) {
    x += y;
    if (x >= mod)
        x -= mod;
    return x;
}

int qpow(int x,int y) {
    int res = 1;
    while (y) {
        if (y & 1) res = 1ll * res * x % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return res;
}


struct E {
    int to , nex;
} e[N * 2];
int head[N] , ecnt;

int *F[N] , A[N] , B[N] , *cur , dp[N * 40] , S[1010][1010] , S0[N] , fac[N] , inv[N] , facinv[N];
int n , K , fa[N] , p[N] , d[N] ;

void adde(int fr,int to) {
    e[++ecnt]=(E) {
        to,head[fr]
    };
    head[fr]=ecnt;
}
void addedge(int fr,int to) {
    adde(fr,to);
    adde(to,fr);
    d[fr]++;
    d[to]++;
}

int dfn[N] , clk;
void dfs(int o,int fat) {
    fa[o] = fat;
    dfn[++clk] = o;
    for (int j = head[o]; j; j=e[j].nex)
        if (e[j].to != fat) {
            dfs(e[j].to , o);
        }
}

void NTT(int *a,int len,int fl) {
    int i , j , k;
    for (i = 1 , j = len >> 1; i < len; i++) {
        if (i > j) swap(a[i] , a[j]);
        for (k = len >> 1; k & j; k >>= 1) j ^= k;
        j ^= k;
    }

    for (int clen = 2; clen <= len; clen <<= 1) {
        int wn = qpow(fl == 1 ? g : ginv , (mod - 1) / clen );
        for (i = 0; i < len; i += clen) {
            int w = 1;
            for (j = i; j < i + (clen >> 1); j++) {
                int A = a[j] , B = 1ll * w * a[j+(clen>>1)] % mod;
                a[j] = add(A , B);
                a[j+(clen>>1)] = add(A , mod - B);
                w = 1ll * w * wn % mod;
            }
        }
    }

    if (fl == -1) {
        int inv = qpow(len , mod - 2);
        for (int i = 0; i < len; i++) a[i] = 1ll * a[i] * inv % mod;
    }
}

int C(int m,int n) {
    if (m < n) return 0;
    return 1ll * fac[m] * facinv[m - n] % mod * facinv[n] % mod;
}
int a[262144] , b[262144];   
void calcStrlin() {
    for (int i = 0; i <= K; i++) {
        a[i] =  i & 1 ? mod - facinv[i] : facinv[i];
        b[i] = 1ll * qpow(i , K) * facinv[i] % mod;
    }
    int len = ceil(log2(K + 1));
    len = 1 << (len + 1);
    NTT(a , len , 1);
    NTT(b , len , 1);
    for (int i = 0; i < len; i++) a[i] = 1ll * a[i] * b[i] % mod;
    NTT(a , len , -1);
    for (int i = 0; i <= K; i ++) {
        S0[i] = a[i];
    }

}
int main() {
    freopen("walk.in","r",stdin);
    freopen("walk.out","w",stdout);

    fac[0] = 1;
    for (int i = 1; i < N; i++) fac[i] = 1ll * fac[i-1] * i % mod;
    inv[1] = 1;
    for (int i = 2; i < N; i++) inv[i] = 1ll * (mod - (mod / i) ) * inv[mod % i] % mod;
    facinv[0] = facinv[1] = 1;
    for (int i = 2; i < N; i++) facinv[i] = 1ll * facinv[i-1] * inv[i] % mod;

    scanf("%d%d" , &n , &K);
    for (int i = 1; i < n; i++) {
        int u , v;
        scanf("%d%d",&u,&v);
        addedge(u , v);
    }
    for (int i = 2; i <= n; i++) {
        scanf("%d",p + i);
        p[i] = 1ll * p[i] * qpow(1000000 , mod - 2) % mod;
    }
    cur = dp;

    for (int i = 1; i <= n; i++) {
        F[i] = cur;
        F[i][0] = 1;
        cur += K + 10;
    }

    dfs(1 , 0);

    for (int k = 1; k <= K; k++) {
        for (int i = n; i >= 2; i--) {
            int cur = dfn[i] , a = 0 , c = 0;
            for (int j = head[cur]; j; j = e[j].nex) {
                c = add(c , F[e[j].to][k-1]);

                if (e[j].to != fa[cur]) {
                    a = add(a , A[e[j].to]);
                    c = add(c , B[e[j].to]);
                }
            }
            int Inv = qpow(d[cur] , mod - 2);
            c = 1ll * c * Inv % mod;
            c = add(c , 1ll * p[cur] * qpow( add(1 , mod - p[cur]) , mod - 2) % mod * F[cur][k-1] % mod );
            a = 1ll * a * Inv % mod;
            a = add(1 , mod - a);

            A[cur] = qpow(1ll * d[cur] * a % mod , mod - 2) ;
            B[cur] = 1ll * c * qpow(a , mod - 2) % mod;
        }

        for (int i = 2; i <= n; i++) {
            int cur = dfn[i];
            F[cur][k] = add(1ll * F[fa[cur]][k] * A[cur] % mod , B[cur]);
        }
    }

		calcStrlin();
		
		
    	for (int i = 2; i <= n; i++) {
            int res = 0;
            for (int j = 0; j <= K; j++) {
                res = add(res , 1ll * fac[j] * S0[j] % mod * F[i][j] % mod );
            }
            printf("%d\n",res);
        }
    
    return 0;
}
