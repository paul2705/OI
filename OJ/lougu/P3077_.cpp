#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct node{int x,y;}l[111111];
long long n,m,r,s,p,q,u,v,i,a[111111],b[111111],f1[111111],f2[111111];
bool cmp(node a,node b) {return (a.x<b.x)||(a.x==b.x&&a.y<b.y);}     //排序的关键字
int main()
{
    cin>>n>>m>>r;
    s=-99999999;
    for (i=1;i<=n;i++)    
    {
        cin>>a[i];
        s=max(s,a[i]);
    }
    for (i=1;i<=m;i++)    
    {
        cin>>b[i];
        s=max(s,b[i]);
    }
    for (i=1;i<=r;i++) cin>>l[i].x>>l[i].y;   //前面全在读入
    sort(l+1,l+1+r,cmp);     //STL模板排序
    f1[l[1].x]=a[l[1].x]+b[l[1].y];
    f2[l[1].y]=f1[l[1].x];
    for (i=2;i<=r;i++)
    {
        if (l[i].x==l[i-1].x&&l[i].y==l[i-1].y) continue;
        p=f1[l[i].x];
         q=f2[l[i].y];
          u=a[l[i].x];
          v=b[l[i].y];
          if (p==0) f2[l[i].y]=max(f2[l[i].y],u+v); else f2[l[i].y]=max(f2[l[i].y],p+v);
          if (q==0) f1[l[i].x]=max(f1[l[i].x],u+v); else f1[l[i].x]=max(f1[l[i].x],q+u);
    }
    for (i=1;i<=n;i++) s=max(f1[i],s);
    for (i=1;i<=m;i++) s=max(f2[i],s);
    cout<<s;
    return 0;
}
