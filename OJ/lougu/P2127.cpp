#include <stdio.h>
#include <algorithm>
using namespace std;
int n;
long long cost=0;
struct stu{
    int num; 
    long long v; 
}a[100008];
bool vis[100008]; 
bool cmp(stu x,stu y)
{    return x.v<y.v;    } 
inline long long read() {
    long long x=0; char ch=getchar();
    while (ch<'0' || ch>'9') ch=getchar();
    while (ch>='0' && ch<='9')
    {
        x=(x<<3)+(x<<1)+ch-48;
        ch=getchar();
    }
    return x;
} 
int main() {
    int i,j;  scanf("%d",&n);
    for (i=1; i<=n; ++i){
        a[i].v=read(); 
        a[i].num=i; 
    }
    sort(a+1,a+n+1,cmp);
    for (i=1; i<=n; ++i){
        if (!vis[i]){
            int x=i;
            long long tot=0,sum=0,mins=0x3f7f7f7f7f7f7f;
            while (!vis[x]){
                vis[x]=1;
                sum+=a[x].v;
                if (mins>a[x].v)
                  mins=a[x].v;
                tot++;
                x=a[x].num; 
            }
            long long a1=sum+(tot-2)*mins;
            long long a2=sum+a[1].v*(tot+1)+mins; 
            if (a1<a2) cost+=a1;   else cost+=a2; 
        }
    }
    printf("%lld",cost); 
    return 0;
}
