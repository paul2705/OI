#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
inline void re(int &x)
{
    x=0;bool flag=false;
    char c=getchar();
    while(c<'0'||c>'9'){
        flag=c=='-';
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<1)+(x<<3)+(c^'0');
        c=getchar();
    }
    if(flag)x=-x;
    return ;
}
int dp[550][70];
int n,T;
int m1,m2;
int f[70],t[70],d[70],e[70];
int now;
int main()
{
    re(n);
    while(n){
        re(T);
        f[1]=0;
        for(int i=1;i<n;i++){
            re(t[i]);
            f[i+1]=f[i]+t[i];
        }
        re(m1);
        for(int i=1;i<=m1;i++) re(d[i]);
        re(m2);
        for(int i=1;i<=m2;i++) re(e[i]);
        for(int i=0;i<=T;i++)
            for(int j=1;j<=n;j++)
                dp[i][j]=9999;
        dp[0][1]=0;
        for(int i=0;i<=T;i++)
            for(int j=1;j<=n;j++){
                if(dp[i][j]==9999)continue;
                dp[i+1][j]=min(dp[i+1][j],dp[i][j]+1);
                for(int k=1;k<=m1;k++)
                    if(j<n&&f[j]+d[k]==i)
                        dp[i+t[j]][j+1]=min(dp[i+t[j]][j+1],dp[i][j]);
                for(int k=1;k<=m2;k++)
                    if(j>1&&f[n]-f[j]+e[k]==i)
                        dp[i+t[j-1]][j-1]=min(dp[i+t[j-1]][j-1],dp[i][j]);
            }
        printf("Case Number %d: ",++now);
        if(dp[T][n]<9999)printf("%d\n",dp[T][n]);
        else printf("impossible\n");
        re(n);
    }
    return 0;
}
