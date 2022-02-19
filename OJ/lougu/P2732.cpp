#include<bits/stdc++.h>
using namespace std;
struct node
{
    int s,k[11],p;
}a[210];int n,len;
int bk[1100],cnt;
int t1,t2,t3;
int f[11][11][11][11][11];
int v[6];
int main()
{
    int i,j,k,l,r,ki;
    scanf("%d",&len); 
    for(i=1;i<=len;i++)
    {
        scanf("%d",&a[i].s);
        for(j=1;j<=a[i].s;j++)
        {
            scanf("%d%d",&t1,&t2);
            if(bk[t1]==0) bk[t1]=++cnt;
            a[i].k[bk[t1]]=t2;
        }
        scanf("%d",&a[i].p);
    }
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d%d",&t1,&t2,&t3);
        if(bk[t1]==0) bk[t1]=++cnt;
        v[bk[t1]]=t2;
        len++;
        a[len].s=1;a[len].k[bk[t1]]=1;a[len].p=t3;
    }
    memset(f,127,sizeof(f));
    f[0][0][0][0][0]=0;
    for(ki=1;ki<=len;ki++)
        for(i=a[ki].k[1];i<=v[1];i++)
            for(j=a[ki].k[2];j<=v[2];j++)
                for(k=a[ki].k[3];k<=v[3];k++)
                    for(l=a[ki].k[4];l<=v[4];l++)
                        for(r=a[ki].k[5];r<=v[5];r++)
                            f[i][j][k][l][r]=min(
                            f[i][j][k][l][r],
                            f[i-a[ki].k[1]][j-a[ki].k[2]][k-a[ki].k[3]][l-a[ki].k[4]][r-a[ki].k[5]]+a[ki].p);
    printf("%d\n",f[v[1]][v[2]][v[3]][v[4]][v[5]]);
    return 0;
}
