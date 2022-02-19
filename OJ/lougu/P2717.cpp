#include<stdio.h>

int n,k;
int a[100010]={0},temp[100010]={0};
long long ans=0;

void merge(int s1,int e1,int s2,int e2)
{
    int s=s1,e=e2,i=s1;
    while(s1<=e1&&s2<=e2)
    {
        if(a[s1]<=a[s2])
        {
            ans+=e2-s2+1;
            temp[i++]=a[s1++];
        }
        else
            temp[i++]=a[s2++];
    }
    while(s1<=e1) temp[i++]=a[s1++];
    while(s2<=e2) temp[i++]=a[s2++];
    for(i=s;i<=e;i++) a[i]=temp[i];
}
void msort(int l,int r)
{
    if(l==r) return;
    int mid=(l+r)>>1;
    msort(l,mid);
    msort(mid+1,r);
    merge(l,mid,mid+1,r);
}

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1,b;i<=n;i++)
    {
        scanf("%d",&b);
        b-=k;
        a[i]=a[i-1]+b;
    }
    msort(0,n);
    printf("%lld",ans);
    return 0;
}
