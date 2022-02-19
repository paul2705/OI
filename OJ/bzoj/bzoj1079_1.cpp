#include<iostream>
#include<cstdio>
#define ll long long
#define mod 1000000007
using namespace std;
ll f[16][16][16][16][16][6];int x[6],n;
bool mark[16][16][16][16][16][6];
ll dp(int a,int b,int c,int d,int e,int k)
{
    ll t=0;
    if(mark[a][b][c][d][e][k])return f[a][b][c][d][e][k];
    if(a+b+c+d+e==0)return 1;
    if(a)  
        t+=(a-(k==2))*dp(a-1,b,c,d,e,1);  
    if(b)  
        t+=(b-(k==3))*dp(a+1,b-1,c,d,e,2);  
    if(c)  
        t+=(c-(k==4))*dp(a,b+1,c-1,d,e,3);  
    if(d)  
        t+=(d-(k==5))*dp(a,b,c+1,d-1,e,4);  
    if(e)  
        t+=e*dp(a,b,c,d+1,e-1,5);  
    mark[a][b][c][d][e][k]=1;
    return f[a][b][c][d][e][k]=(t%mod);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
            int t;
            scanf("%d",&t);
            x[t]++;
            }
    printf("%lld",dp(x[1],x[2],x[3],x[4],x[5],0));
    return 0;
}
