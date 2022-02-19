#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
const int maxn=500005;
int a[maxn],f[maxn],b[maxn],p[maxn],N,K,tot;
void _qsort(int l,int r)
{
    int i,j,m,t;
    i=l;j=r;
    m=p[(i+j)>>1];
    while(i<=j)
    {
        while(p[i]<m)i++;
        while(p[j]>m)j--;
        if(i<=j)
        {
            t=p[i];p[i]=p[j];p[j]=t;
            i++;j--;
        }
    }
    if(i<r)_qsort(i,r);
    if(l<j)_qsort(l,j);
}
int _midfind(int l,int r,int k)
{
    int i,j,mid;
    i=l;j=r;
    while(i<=j)
    {
        mid=(i+j)>>1;
    if(f[mid]<k)i=mid+1;
    else j=mid-1;
    }
    return j;
}
void _work()
{
    int i,j,k,n;
    for(i=k=1;i<p[1];i++)
        if(a[i]<a[p[1]])
        {
            b[k]=a[i];
            k++;
        }
    b[k]=a[p[1]];k++;
    for(j=1;j<K;j++)
    {
        for(i=p[j];i<p[j+1];i++)
            if(a[p[j]]<a[i]&&a[i]<a[p[j+1]])
            {
                b[k]=a[i];
                k++;
            }
        b[k]=a[p[j+1]];k++;
    }
    for(i=p[K];i<=N;i++)
        if(a[i]>a[p[K]])
        {
            b[k]=a[i];
            k++;
        }
	for (int i=1;i<k;i++) cout<<b[i]<<" "; cout<<endl;
    n=k-1;
    f[0]=-999999999;
    f[1]=b[1];
    for(i=2;i<=n+5;i++)f[i]=999999999;
    tot=1;
    for(i=2;i<=n;i++)
    {
        j=_midfind(1,tot+1,b[i]);
        f[j+1]=b[i];
        if(j>=tot)tot=j+1;
    }
    printf("%d",tot);
}
void _input()
{
    int i,j,k;
    scanf("%d%d",&N,&K);
    for(i=1;i<=K;i++)
        scanf("%d",&p[i]);
    _qsort(1,K);
    for(i=1;i<=N;i++)
        scanf("%d",&a[i]);
    for(i=2;i<=K;i++)
        if(a[p[i-1]]>a[p[i]])
        {
            printf("impossible");
            return;
    }
    _work();
}
int main()
{
    _input();
    return 0;
}
