#include<iostream>
#include<algorithm>
#include<cstdio>
#define mod 9999991
int n;
long long ans=1;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n-2;i++) ans=(ans*n)%mod;
    for(int i=1;i<=n-1;i++) ans=(ans*i)%mod;
    printf("%lld\n",ans);
    return 0;
}
