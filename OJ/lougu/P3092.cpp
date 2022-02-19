#include<iostream>
#include<queue>
#include<cstring>
#include<cstdio>
#define re register
#define int long long
#define maxn 100001
using namespace std;
int f[65540],a[maxn],b[17],n,m,num,p[maxn];
int c[17];
inline void check(int x)
{
    memset(c,0,sizeof(c));
    int pp=m;
    while(x)
    {
        if(x&1) c[pp]=1;
        pp--;
        x>>=1;
    }
}
inline int read()
{
    char c=getchar();
    int x=0;
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9')
      x=(x<<3)+(x<<1)+c-48,c=getchar();
    return x;
}
inline int find(int x)
{
    int l=1,r=n,tot=0;
    while(l<=r)
    {
        int mid=l+r>>1;
        if(p[mid]<=x) l=mid+1,tot=mid;
        else r=mid-1;
    }
    return tot;
}
signed main()
{
    m=read();
    n=read();
    for(re int i=1;i<=m;i++) b[i]=read(),num+=b[i];
    for(re int i=1;i<=n;i++) a[i]=read();
    p[1]=a[1];
    for(re int i=2;i<=n;i++) p[i]=p[i-1]+a[i];
    for(re int i=0;i<=(1<<m)-1;i++)
    {
        deque<int> q;
        for(re int j=1;j<=m;j++)
        {
            if(!(i&(1<<(m-j)))) continue;
            int k=i^(1<<(m-j));
            while(q.size()&&q.back()<p[f[k]]+b[j]) q.pop_back();
            q.push_back(p[f[k]]+b[j]);
        }
        f[i]=find(q.front());
    }
    int ans=-1;
    for(re int i=0;i<=(1<<m)-1;i++)
    {
        if(f[i]!=n) continue;
        check(i);
        int tot=0;
        for(re int j=1;j<=m;j++)
        if(c[j]==0) tot+=b[j];
        if(tot>ans) ans=tot; 
    }
    cout<<ans;
    return 0;
}
