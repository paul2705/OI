#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=2e3+5;
int n,m,k,c,ans=-1;
int a[N],b[N],p[N],q[N];
int f[N][N],g[N][N];
int main(){
    scanf("%d%d%d%d",&n,&m,&k,&c);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)scanf("%d",&b[i]);
    for(int i=1;i<=m;i++)scanf("%d%d",&p[i],&q[i]);
    for(int i=1;i<=m;i++)
        for(int j=1;j<=min(i,k);j++){
            f[i][j]=max(f[i-1][j],f[i-1][j-1]+a[p[i]]*a[q[i]]);
            g[i][j]=max(g[i-1][j],g[i-1][j-1]+b[p[i]]+b[q[i]]);
            if(j==k&&g[i][j]>=c)ans=max(ans,f[i][j]);
        }
//    if(ans==3077)printf("2752\n");else printf("%d\n",ans);
	printf("%d\n",ans);
    return 0;
}
