#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll N=2e3+50,inf=1e17;

ll gti(void)
{
    char c=getchar();
    ll ret=0,st=1;
    for (;!isdigit(c);c=getchar()) if (c=='-') st=-1;
    for (;isdigit(c);c=getchar()) ret=ret*10+c-'0';
    return ret*st;
}

struct P
{
    ll a,b,x,y;
    bool operator<(const P &b)const
    {
        return a<b.a;
    }
}p[N*N];
ll mx[4],f[N*N],now[4];
void upd(ll *mx,ll i)
{
    mx[0]=max(mx[0],f[i]-p[i].x-p[i].y);
    mx[1]=max(mx[1],f[i]-p[i].x+p[i].y);
    mx[2]=max(mx[2],f[i]+p[i].x-p[i].y);
    mx[3]=max(mx[3],f[i]+p[i].x+p[i].y);
}
int main(void)
{
    ll n=gti(),m=gti(),ans=0,tag=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            p[(i-1)*m+j]=(P){gti(),0,i,j};
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            p[(i-1)*m+j].b=gti();
    sort(p+1,p+1+n*m);
    mx[0]=mx[1]=mx[2]=mx[3]=-inf;
    for (int i=1;i<=n*m;i++)
    {
        if (p[i].a==0) continue;
        int j=i;
        for (;p[j+1].a==p[j].a;j++);
        if (!tag)
        {
            tag=true;
            for (int k=i;k<=j;k++)
            {
                f[k]=p[k].b;
                ans=max(ans,f[k]);
                upd(mx,k);
            }
        }
        else
        {
            now[0]=now[1]=now[2]=now[3]=-inf;
            for (int k=i;k<=j;k++)
            {
                f[k]=max(f[k],mx[0]+p[k].b+p[k].x+p[k].y);
                f[k]=max(f[k],mx[1]+p[k].b+p[k].x-p[k].y);
                f[k]=max(f[k],mx[2]+p[k].b-p[k].x+p[k].y);
                f[k]=max(f[k],mx[3]+p[k].b-p[k].x-p[k].y);
                ans=max(ans,f[k]);
                upd(now,k);
            }
            for (int i=0;i<4;i++)
                mx[i]=max(mx[i],now[i]);
        }
        i=j;
    }
    printf("%lld\n",ans);
    return 0;
}

