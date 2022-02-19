#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#define rint register int
#define inv inline void
#define big 1e9
using namespace std;
int p,q,a[101],f[20001],que[101],cnt;
bool use[101],vis[20001],g[20001];
inv dp()
{
    for (rint i=0;i<=q;i++) g[i]=0;g[0]=1;
    for (rint i=1;i<=f[q];i++)
        for (rint j=a[que[i]];j<=q;j++)
            if (g[j-a[que[i]]]) g[j]=1;
    if (g[q])
    {
        printf("%d ",f[q]);
        for (rint i=1;i<=f[q];i++) printf("%d ",a[que[i]]);
        exit(0);
    }
}
inv dfs(int x,int dep)
{
    if (dep==f[q]) 
    {
        dp();
        return;
    }
    if (f[q]-dep>p-x) return;
    for (rint i=x+1;i<=p;i++)
    {
        que[dep+1]=i;
        dfs(i,dep+1);
    }
}
int main()
{
    scanf("%d%d",&q,&p);
    for (rint i=1;i<=p;i++) scanf("%d",&a[i]);
    sort(a+1,a+p+1);
    for (rint i=0;i<=q;i++) f[i]=big;f[0]=0;    
    for (rint i=1;i<=p;i++)
        for (rint j=0;j<=q;j++)
        {
            vis[j]=0;
            if (j>=a[i])
            {
                int value=vis[j-a[i]]^1;
                if (f[j-a[i]]+value<=f[j])
                {
                    f[j]=f[j-a[i]]+value;
                    vis[j]=1;
                }
            }
        }
    dfs(0,0);
} 
