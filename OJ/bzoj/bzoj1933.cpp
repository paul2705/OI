#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
  
#define F(i,j,k) for (int i=j;i<=k;++i)
#define D(i,j,k) for (int i=j;i>=k;--i)
#define inf 0x3f3f3f3f
  
int dp[2][2105][2105],n,sumt,prst[80];
struct Book{int h,t;}a[80];
bool cmp(Book x,Book y)
{return x.h>y.h;}
int main()
{
    int now=1,pre=0;
    memset(dp[now],0x3f,sizeof dp[now]);
    dp[now][0][0]=0;
    scanf("%d",&n);
    F(i,1,n) scanf("%d%d",&a[i].h,&a[i].t),sumt+=a[i].t;
    sort(a+1,a+n+1,cmp);
    F(i,1,n) prst[i]=prst[i-1]+a[i].t;
    F(i,0,n-1)
    {
        now^=1;pre^=1;
        memset(dp[now],0x3f,sizeof dp[now]);
        F(j,0,sumt) F(k,0,sumt) if (dp[pre][j][k]!=inf)
        {
            if (j!=0)
                dp[now][j+a[i+1].t][k]=min(dp[now][j+a[i+1].t][k],dp[pre][j][k]);
            else
                dp[now][j+a[i+1].t][k]=min(dp[now][j+a[i+1].t][k],dp[pre][j][k]+a[i+1].h);
            if (k!=0)
                dp[now][j][k+a[i+1].t]=min(dp[now][j][k+a[i+1].t],dp[pre][j][k]);
            else
                dp[now][j][k+a[i+1].t]=min(dp[now][j][k+a[i+1].t],dp[pre][j][k]+a[i+1].h);
            if (prst[i]-j-k!=0)
                dp[now][j][k]=min(dp[now][j][k],dp[pre][j][k]);
            else
                dp[now][j][k]=min(dp[now][j][k],dp[pre][j][k]+a[i+1].h);
        }
    }
    int ans=inf;
    F(i,0,sumt) F(j,0,sumt)
    if (dp[now][i][j]!=inf)
        if (i*j*(prst[n]-i-j)!=0)
        {
            ans=min(ans,max(i,max(j,prst[n]-i-j))*dp[now][i][j]);
        }
    printf("%d\n",ans);
}
