#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
double f[1001];
long long len,wei,n,w[1001],v[1001],sum[1001],vmin[1001][1001];
int main ()
{
    scanf ("%lld%lld%lld",&wei,&len,&n);
    for (int b=1;b<=n;++b){scanf ("%lld%lld",&w[b],&v[b]);sum[b]=sum[b-1]+w[b];vmin[b][b]=v[b];}
    for (int b=1;b<n;++b)for (int c=b+1;c<=n;++c)vmin[b][c]=min(v[c],vmin[b][c-1]);
    for (int i=1;i<=n;++i)
    {
        f[i]=(double)len/v[i]+f[i-1];
        for (int j=i-1;j>=1;--j)
            if (sum[i]-sum[j-1]<=wei)f[i]=min(f[i],f[j-1]+(double)len/vmin[j][i]);
            else break;
    }
    printf ("%.1lf",f[n]*60);
    return 0;
}
