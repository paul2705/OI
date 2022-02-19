#include<iostream>
#include<cstdio>
#include<cstdlib>
#define ll long long
#define inf 100000000000000
using namespace std;
ll dp[2][200001],N,P,Q,Min0;
int main()
{
    cin>>N>>P>>Q;
    for(ll i=1;i<=N;i++)dp[0][i]=dp[1][i]=inf;
    for(ll i=1;i<=N;i++)
    {
        dp[1][i]=Min0+Q*i;
        for(ll j=i;(i-j)*(i-j)<=Q&&j>=0;j--)
            dp[0][i]=min(dp[0][i],dp[1][j]+P*(i-j)*(i-j));
        Min0=min(Min0,dp[0][i]-Q*i);
    }
    printf("%lld\n",min(dp[0][N],dp[1][N]));
    return 0;
}
