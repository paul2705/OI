#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define ll long long
#define inf 100000000000000
using namespace std;
ll dp[2][200001],n,p,q,mn;
int main(){
    memset(dp,127,sizeof(dp));
    scanf("%lld%lld%lld",&n,&p,&q);
    for(ll i=1;i<=n;i++){
        dp[1][i]=mn+q*i;
        for(ll j=i;(i-j)*(i-j)<=q&&j>=0;j--)
            dp[0][i]=min(dp[0][i],dp[1][j]+p*(i-j)*(i-j));
        mn=min(mn,dp[0][i]-q*i);
    }
    printf("%lld\n",min(dp[0][n],dp[1][n]));
    return 0;
}
