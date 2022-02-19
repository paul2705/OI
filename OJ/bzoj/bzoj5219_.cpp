#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#define N 2039
#define mod 20070831
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;
int n,p,pw[N*N],C[N][N],dp[N][N];
void get_pw()
{
    pw[0]=1;
    for(int a=1,b=n*(n-1)/2;a<=b;a++) pw[a]=pw[a-1]*2%p;
}
void get_C()
{
    for(int a=0;a<=n;a++) C[a][0]=1;
    for(int a=1;a<=n;a++)
    {
        for(int b=1;b<=a;b++)
        {
            C[a][b]=(C[a-1][b]+C[a-1][b-1])%p;
        }
    }
}
int main()
{
    scanf("%d%d",&n,&p);
    get_pw(),get_C();
    for(int a=1;a<=n;a++)
    {
        dp[a][1]=pw[(a-1)*(a-2)/2];
        for(int b=2;b<a;b++)
        {
            dp[a][b]=(ll)dp[b][b]*C[a-1][b-1]%p*pw[(a-b)*(a-b-1)/2]%p;
        }
        dp[a][a]=pw[a*(a-1)/2];
        for(int b=1;b<a;b++) (dp[a][a]-=dp[a][b])%=p;
        (dp[a][a]+=p)%=p;
    }
    for(int a=1;a<=n;a++)
    {
        printf("%d\n",dp[n][a]);
    }
    return 0;
}
