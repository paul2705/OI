#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 2110;
struct data {
    int h, t;
    bool friend operator < (const data &a, const data &b) {
        return a.h > b.h;
    }
} a[N];
int pre, n;
ll ans = 1000000000000000ll;
int dp[2][N][N], sum[N];
int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d%d", &a[i].h, &a[i].t);
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i].t;
    memset(dp, 0x3f3f, sizeof(dp));
    dp[pre][0][0] = 0;
    for(int i = 1; i <= n; ++i)
    {
        pre ^= 1;
        memset(dp[pre], 0x3f3f, sizeof(dp[pre]));
        for(int j = 0; j <= sum[n]; ++j)
            for(int k = 0; k <= sum[n]; ++k) if(dp[pre ^ 1][j][k] < 0x3f3f3f3f)
            {
                if(j == 0) dp[pre][j + a[i].t][k] = min(dp[pre][j + a[i].t][k], dp[pre ^ 1][j][k] + a[i].h);
                else if(j + a[i].t <= sum[n]) dp[pre][j + a[i].t][k] = min(dp[pre][j + a[i].t][k], dp[pre ^ 1][j][k]);
                if(k == 0) dp[pre][j][k + a[i].t] = min(dp[pre][j][k + a[i].t], dp[pre ^ 1][j][k] + a[i].h);
                else if(k + a[i].t <= sum[n]) dp[pre][j][k + a[i].t] = min(dp[pre][j][k + a[i].t], dp[pre ^ 1][j][k]);
                if(sum[i] - j - k == a[i].t) dp[pre][j][k] = min(dp[pre][j][k], dp[pre ^ 1][j][k] + a[i].h);
                else if(sum[i] - j - k > a[i].t) dp[pre][j][k] = min(dp[pre][j][k], dp[pre ^ 1][j][k]);
            }
    }
    for(int i = 1; i <= sum[n]; ++i)
        for(int j = 1; j <= sum[n]; ++j) if(i + j < sum[n] && dp[pre][i][j] < 0x3f3f3f3f) ans = min(ans, (max((ll)i, max((ll)j, sum[n] - (ll)i - (ll)j)) * (ll)dp[pre][i][j]));
    printf("%lld\n", ans);
    return 0;
}
