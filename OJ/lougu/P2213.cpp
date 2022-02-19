#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1005;
int n,m,k,x,y,xl,yl,xr,yr,ans=-0x7fffffff,a[N][N],b[N*2][N*2];
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
    m=n*2-1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) b[i+j-1][n-i+j]=a[i][j];
    for(int i=1;i<=m;i++)
        for(int j=1;j<=m;j++) b[i][j]+=b[i][j-1];
    for(int j=1;j<=m;j++)
        for(int i=1;i<=m;i++) b[j][i]+=b[j-1][i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            x=i+j-1,y=n-i+j;
            xl=x-k,yl=y-k,xr=x+k,yr=y+k;
            if(xl<1) xl=1;
            if(yl<1) yl=1;
            if(xr>m) xr=m;
            if(yr>m) yr=m;
            ans=max(ans,b[xr][yr]-b[xr][yl-1]-b[xl-1][yr]+b[xl-1][yl-1]);
        }
    printf("%d\n",ans);
    return 0;
}
