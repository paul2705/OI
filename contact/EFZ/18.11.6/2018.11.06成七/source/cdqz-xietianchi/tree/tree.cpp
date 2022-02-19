#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <iostream>
#define fx first
#define fy second
#define mp make_pair
#define pb push_back
#define mod 1000000007
#define debug(x) cerr<<#x<<" = "<<x<<endl
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef pair<db,db> pdd;

const int N = 3e2 + 10;
int qpow(int x,int y,int p = mod) {
    int res = 1;
    while (y) {
        if (y & 1) res = 1ll * res * x % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return res;
}
int add(int x,int y) {
    x += y;
    if (x >= mod)
        x -= mod;
    return x;
}
int a[N][N];
int gauss(int n) {
    int res = 1 , j;

    for (int i = 1; i <= n; i++) {
        j = i;
        while (j <= n && !a[j][i]) j++;
        if (j > n) return 0;

        if (i != j) {
            for (int k = 1; k <= n; k++) swap(a[j][k] , a[i][k]);
            res = mod - res;
        }

        int del = qpow( a[i][i] , mod - 2);
        res = 1ll * res * a[i][i] % mod;
        for (j = 1; j <= n; j++) a[i][j] = 1ll * a[i][j] * del % mod;

        for (j = 1; j <= n; j++)
            if (i != j) {
                del = a[j][i];
                for (int k = 1; k <= n; k++) a[j][k] = add(a[j][k] , mod - 1ll * a[i][k] * del % mod);
            }
    }

    return res;
}
int n , lim,c[N];

void addedge(int u,int v) {
    a[u][u]++;
    a[v][v]++;
    a[u][v]--;
    a[v][u]--;
}
int main() {
	freopen("tree.in","r",stdin);
	
	freopen("tree.out","w",stdout);
    scanf("%d%d",&n,&lim);
    for (int i = 1; i <= n; i++) scanf("%d",&c[i]);
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (c[i] != c[j]) addedge(i , j);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (a[i][j] < 0) a[i][j] += mod;

    int ans=  gauss(n - 1);
    printf("%d\n",ans);
    return 0;
}

