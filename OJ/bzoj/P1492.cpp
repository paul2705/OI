#define ll long long
#define mod 100000 
#include<iostream>
#define N 1000010
#include<cstdio>
using namespace std;
ll n,m;
ll num[N];
ll pr[N],is[N],pn;
void get_p(ll k)
{
    for(ll i=2;i<=k;++i)
    {
        if(!is[i]) pr[++pn]=i;
        for(ll j=1;pr[j]*i<=k&&j<=pn;++j)
        {
            is[pr[j]*i]=1;
            if(i%pr[j]==0) break; 
        } 
    }
}
void turn(ll nu,ll fl)
{
    for(ll i=1;i<=pn;++i)
    {
        if(nu<pr[i]) {break;}
        ll now=pr[i];
        ll tmp=num[i];
        while(nu>=now)
        {
            num[i]+=(nu/now)*fl;
            now*=pr[i];
        }
    }
}
ll ans[10000000];
ll an;
void Big_pow(ll it)//高精乘低精,ans*it
{
    ll jw=0;
    for(ll i=1;i<=an;++i)
    {
        ans[i]=1ll*ans[i]*it+jw;
        jw=ans[i]/mod;
        ans[i]%=mod;
    }
    while(jw)
    {
        ans[++an]=jw%mod;
        jw/=mod;
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    get_p(n+m);
    turn(n+m,1);
    turn(n,-1);
    turn(m,-1);
    ans[++an]=1;
    for(ll i=1;i<=pn;++i)
    {
        while(num[i]--) Big_pow(pr[i]);
    }
    for(int i=20;i>=1;--i)
    {
        printf("%05d",ans[i]);
        if(i&1) putchar('\n');
    }
    return 0;
}

