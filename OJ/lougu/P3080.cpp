#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const long long maxn=1000+10;
long long s[maxn],dp[maxn][maxn][2];
long long n,lenl;
int main()
{
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&s[i]);
    }s[n+1]=0;
    sort(s+1,s+n+2);
    for(long long i=1;i<=n+1;i++){
        if(s[i]==0){
            lenl=i-1;break;
        }
    }dp[lenl+1][lenl+1][0]=dp[lenl+1][lenl+1][1]=0;
    for(long long i=lenl;i>=1;i--)dp[i][lenl+1][0]=dp[i+1][lenl+1][0]+(n+1-(lenl+1-i))*(s[i+1]-s[i]),
                                  dp[i][lenl+1][1]=dp[i][lenl+1][0]+(n-(lenl+1-i))*(s[lenl+1]-s[i]);
    for(long long i=lenl+2;i<=n+1;i++)dp[lenl+1][i][1]=dp[lenl+1][i-1][1]+(n+1-(i-lenl-1))*(s[i]-s[i-1]),
                                      dp[lenl+1][i][0]=dp[lenl+1][i][1]+(n-(i-lenl-1))*(s[i]-s[lenl+1]);
    for(long long i=lenl;i>=1;i--){
        for(long long j=lenl+2;j<=n+1;j++){
            dp[i][j][0]=min(dp[i+1][j][0]+(n+1-(j-i))*(s[i+1]-s[i]),dp[i+1][j][1]+(n+1-(j-i))*(s[j]-s[i]));
            dp[i][j][1]=min(dp[i][j-1][1]+(n+1-(j-i))*(s[j]-s[j-1]),dp[i][j-1][0]+(n+1-(j-i))*(s[j]-s[i]));
        }
    }
    printf("%lld\n",min(dp[1][n+1][0],dp[1][n+1][1]));
    return 0;
}

