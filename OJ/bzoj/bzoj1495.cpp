#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1030
#define ls x << 1
#define rs x << 1 | 1
using namespace std;
typedef long long ll;
int n , m , a[N] , t[N];
ll c[N] , w[N][N] , v[N][N] , f[N << 1][N];
void init(int x , int d){
    if(!d) return;
    int i , j;
    init(ls , d - 1) , init(rs , d - 1);
    for(i = x << d ; i < ((x << 1) + 1) << (d - 1) ; i ++ )
        for(j = ((x << 1) + 1) << (d - 1) ; j < (x + 1) << d ; j ++ )
            v[i - m][x] += w[i - m][j - m] , v[j - m][x] += w[i - m][j - m];
}
void dfs(int x , int d){
    int i , j;
    if(!d){
        f[x][a[x - m]] = 0;
        f[x][a[x - m] ^ 1] = c[x - m];
        for(i = x >> 1 ; i ; i >>= 1) f[x][t[i]] += v[x - m][i];
        return;
    }
    memset(f[x] , 0x3f , sizeof(ll) * ((1 << d) + 1));
    t[x] = 1 , dfs(ls , d - 1) , dfs(rs , d - 1);
    for(i = 0 ; i <= 1 << (d - 1) ; i ++ )
        for(j = 0 ; j <= (1 << (d - 1)) - i ; j ++ )
            f[x][i + j] = min(f[x][i + j] , f[ls][i] + f[rs][j]);
    t[x] = 0 , dfs(ls , d - 1) , dfs(rs , d - 1);
    for(i = 1 ; i <= 1 << (d - 1) ; i ++ )
        for(j = (1 << (d - 1)) - i + 1 ; j <= 1 << (d - 1) ; j ++ )
            f[x][i + j] = min(f[x][i + j] , f[ls][i] + f[rs][j]);
}
int main(){
    int i , j;
    ll ans = 1ll << 62;
    scanf("%d" , &n) , m = 1 << n;
    for(i = 0 ; i < m ; i ++ ) scanf("%d" , &a[i]);
    for(i = 0 ; i < m ; i ++ ) scanf("%lld" , &c[i]);
    for(i = 0 ; i < m ; i ++ )
        for(j = i + 1 ; j < m ; j ++ )
            scanf("%lld" , &w[i][j]);
    init(1 , n);
    dfs(1 , n);
    for(i = 0 ; i <= m ; i ++ ) ans = min(ans , f[1][i]);
    printf("%lld\n" , ans);
    return 0;
}

