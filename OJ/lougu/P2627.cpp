#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
long long dl[100010],dlindex[100010],head=0,tail=0,f[100010];
long long n,k,a[100010],fc[100010];
long long sum=0;
int main()
{
    cin>>n>>k;
    for(long long i=1;i<=n;i++)
    {
    cin>>a[i];
    sum+=a[i];
    }
    for(long long i=1;i<=n;i++)
    {
        f[i]=a[i]+dl[head];
        while(f[i]<dl[tail]&&head<=tail)
            tail--;
        while(dlindex[head]<i-k)
            head++;
        tail++;
        dlindex[tail]=i;
        dl[tail]=f[i];
    }    
    long long ans=0x7f7f7f7f7f7f;
        for(long long i=n-k;i<=n;i++)    
    ans=min(ans,f[i]);    
    cout<<sum-ans;
}
