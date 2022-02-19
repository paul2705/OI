#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include <string>
#include <vector>
using namespace std;

const int lmt=5*100*2;
int n,wlt,cost[101],ming[101],red[101];
int ans=-1,dp[501][lmt+10];
int main() {
    scanf("%d%d",&n,&wlt);
    for (int i=1; i<=n; i++) {
        scanf ("%d%d%d",&cost[i],&ming[i],&red[i]);
    }
    memset(dp,-0x3f,sizeof dp);
    for (int j=wlt; j>=0; j--) {
        dp[j][lmt>>1]=0;
    }
    for (int i=1; i<=n; i++) {
        for (int j=wlt; j>=cost[i]; j--) {
            if (ming[i]>0) {
                for (int k=lmt; k>=ming[i]; k--) {
                    dp[j][k]=max(dp[j][k],dp[j-cost[i]][k-ming[i]]+red[i]);
                }
            } else {
                for (int k=0; k<=lmt+ming[i]; k++) {
                    dp[j][k]=max(dp[j][k],dp[j-cost[i]][k-ming[i]]+red[i]);
                }
            }
        }
    }
    for (int j=wlt; j>=0; j--) {
        for (int k=(lmt>>1); k<=lmt; k++) {
            ans=max(ans,dp[j][k]);
        }
    }
    printf("%d\n",ans);
    return  0;
}
