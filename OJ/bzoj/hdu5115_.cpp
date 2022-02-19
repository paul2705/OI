#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
#define N 220
#define INF 0xfffffff

int main()
{
    int T, n, a[N], b[N], dp[N][N], t=1;
    scanf("%d", &T);
    while(T--)
    {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        scanf("%d", &n);
        for(int i=1; i<=n; i++)
            scanf("%d", &a[i]);
        for(int i=1; i<=n; i++)
            scanf("%d", &b[i]);
        for(int i=1; i<=n; i++)
        {
            for(int j=i; j<=n; j++)
                dp[i][j]=INF;
     ///       dp[i][i]=a[i]+b[i-1]+b[i+1];
        }
        for(int l=0; l<=n; l++)
        {
            for(int i=1; i+l<=n; i++)
            {
                int j=i+l;
                for(int k=i; k<=j; k++)
                {
                    dp[i][j]=min(dp[i][j], dp[i][k-1]+dp[k+1][j]+a[k]+b[i-1]+b[j+1]);
                }
            }
        }
        printf("Case #%d: %d\n", t++, dp[1][n]);
    }
    return 0;
}
