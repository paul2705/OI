#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100000+5;
inline int read()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}
int n,m,len;
int a[maxn];
struct node
{
    int l,r,lc,rc;
    long long  c,mul,add;
}tr[maxn<<1];
void bt(int x,int y)
{
    len++; int now=len;
    tr[now].l=x; tr[now].r=y;
    tr[now].lc=tr[now].rc=0;
    if(x==y) 
    { tr[now].c=a[x]; tr[now].mul=a[x]*a[x]; }
    else
    {
        int mid=(x+y)>>1;
        tr[now].lc=len+1; bt(x,mid);
        tr[now].rc=len+1; bt(mid+1,y);
        tr[now].c=tr[tr[now].lc].c+tr[tr[now].rc].c;
        tr[now].mul=tr[tr[now].lc].mul+tr[tr[now].rc].mul;
    }
}
inline void pushdown(int now)
{
    if(tr[now].l==tr[now].r||!tr[now].add) return;
    int lc=tr[now].lc,rc=tr[now].rc;
    tr[lc].mul=tr[lc].mul+2*tr[lc].c*tr[now].add+(tr[lc].r-tr[lc].l+1)*tr[now].add*tr[now].add;
    tr[rc].mul=tr[rc].mul+2*tr[rc].c*tr[now].add+(tr[rc].r-tr[rc].l+1)*tr[now].add*tr[now].add;
    tr[lc].c=tr[lc].c+(tr[lc].r-tr[lc].l+1)*tr[now].add;
    tr[rc].c=tr[rc].c+(tr[rc].r-tr[rc].l+1)*tr[now].add;
    tr[lc].add+=tr[now].add; tr[rc].add+=tr[now].add;
    tr[now].add=0;
}
void update(int now,int x,int y,int d)
{
    if(tr[now].l==x&&tr[now].r==y)
    {
        tr[now].mul=tr[now].mul+2*tr[now].c*d+(tr[now].r-tr[now].l+1)*d*d;
        tr[now].c=tr[now].c+(y-x+1)*d;
        tr[now].add+=d;
    }else
    {
        pushdown(now);
        int lc=tr[now].lc,rc=tr[now].rc;
        int mid=(tr[now].l+tr[now].r)>>1;
        if(y<=mid) update(lc,x,y,d);
        else if(x>=mid+1) update(rc,x,y,d);
        else {  update(lc,x,mid,d); update(rc,mid+1,y,d); }
        tr[now].c=tr[lc].c+tr[rc].c;
        tr[now].mul=tr[lc].mul+tr[rc].mul;
    }
}
long long  getsum(int now,int x,int y)
{
    if(tr[now].l==x&&tr[now].r==y)
        return tr[now].c;
    else
    {
        pushdown(now);
        int lc=tr[now].lc,rc=tr[now].rc;
        int mid=(tr[now].l+tr[now].r)>>1;
        if(y<=mid) return getsum(lc,x,y);
        else if(x>=mid+1) return getsum(rc,x,y);
        else return getsum(lc,x,mid)+getsum(rc,mid+1,y);
    }
}
long long  getmul(int now,int x,int y)
{
    if(tr[now].l==x&&tr[now].r==y)
        return tr[now].mul;
    else
    {
        pushdown(now);
        int lc=tr[now].lc,rc=tr[now].rc;
        int mid=(tr[now].l+tr[now].r)>>1;
        if(y<=mid) return getmul(lc,x,y);
        else if(x>=mid+1) return getmul(rc,x,y);
        else return getmul(lc,x,mid)+getmul(rc,mid+1,y);
    }
}
long long  gcd(long long  a, long long  b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
int main()
{
    //freopen("classroom.in","r",stdin);
    //freopen("classroom.out","w",stdout);
    n=read();m=read();
    for(int i=1;i<=n;i++) a[i]=read();
    bt(1,n);
    for(int i=1;i<=m;i++)
    {
        int p,x,y,d;
        p=read();
        if(p==1)
        {
            x=read(); y=read(); d=read();
            update(1,x,y,d);
        }else
        {
            x=read(); y=read();
            long long  sum,num,fz,fm,t;
            sum=getsum(1,x,y); num=y-x+1;
            if(!sum){cout<<0<<'/'<<1<<endl; continue;}
            t=gcd(sum,num);
            if(p==2) cout<<sum/t<<'/'<<num/t<<endl;
            else if(p==3)
            {
                long long  mul=getmul(1,x,y);
                fz=mul*num-sum*sum;
                fm=num*num;
                t=gcd(fz,fm);
                cout<<fz/t<<'/'<<fm/t<<endl;
            }
        }
    }
    return 0;
}
