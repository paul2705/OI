#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define ll long long
#define re register
#define il inline
#define lson (now<<1)
#define rson (now<<1|1)
#define fp(i,a,b) for(re int i=a;i<=b;i++)
#define fq(i,a,b) for(re int i=a;i>=b;i--)
using namespace std;
int n,p,q[350]={},h[350]={},f[350][350]={},ans;
il int gi()
{
    re int x=0;
    re int t=1;
    re char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
    if(ch=='-') t=-1,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-48,ch=getchar();
    return x*t;
}
int main()
{
    n=gi();p=gi();
    memset(f,0x3f3f3f,sizeof(f));
    f[1][1]=1;f[0][0]=0;f[1][0]=2;
    fp(i,1,p) q[i]=gi(),h[i]=gi();
    fp(i,1,p) q[i]+=q[i-1],h[i]+=h[i-1];
    fp(i,2,p)
    {
        fp(j,1,i)
            fp(k,0,i-j)
            if((q[i]-q[i-j])+(h[i-j]-h[i-j-k])<=n)
                f[i][j]=min(f[i][j],f[i-j][k]+1);
        fp(j,1,p)
            if(h[i]-h[i-j]<=n) f[i][0]=min(f[i][0],f[i][j]+1);
    }
    ans=f[p][0]+1;
    fp(i,1,p)
        if(h[p]-h[i-p]<=n) ans=min(ans,f[p][i]+2);
    printf("%d\n",ans);
    return 0;
}
