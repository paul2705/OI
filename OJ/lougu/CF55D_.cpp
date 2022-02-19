#include <stdio.h>
#include <string.h>
#include <algorithm>
#include<iostream> 
using namespace std;
 
typedef long long LL;
 
LL dp[20][1<<8][2520];
 
int digit[20];
 
const int mod = 2520;
 
LL dfs(int len,int mask,int num,bool fp)
{
    if(!len)
    {
        for(int i=0;i<8;i++)
            if(mask & (1 << i) && num % (i+2) != 0)
                return 0;
        return 1;
    }
    if(!fp && dp[len][mask][num] != -1)
        return dp[len][mask][num];
    int fpmax = fp ? digit[len] : 9;
    LL ret = 0;
    for(int i=0;i<=fpmax;i++){
        ret += dfs(len-1,i < 2 ? mask : mask | 1<<(i-2),(num*10 + i) % mod,fp && i == fpmax);
    }
    if(!fp)
        dp[len][mask][num] = ret;
    return ret;
}
 
LL f(LL n)
{
    int len = 0;
    while(n){
        digit[++len] = n % 10;
        n /= 10;
    }
    return dfs(len,0,0,true);
}
 
int main()
{
    memset(dp,-1,sizeof(dp));
    int T;
    LL a,b;


    {
        scanf("%lld%lld",&a,&b);
	cout<<f(b)<<" "<<f(a-1)<<endl;
        printf("%lld\n",f(b)-f(a-1));
    }
    return 0;
}


