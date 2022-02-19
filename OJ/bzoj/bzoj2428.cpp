#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
 
int n,m,blg[105]; double ave,a[105],sum[105];
double solve(){
    sum[0]=1e100; int i;
    for (i=1; i<=m; i++) sum[i]=0;
    for (i=1; i<=n; i++){ blg[i]=rand()%m+1; sum[blg[i]]+=a[i]; }
    double t=1e5,last,ans=0; 
    for (i=1; i<=m; i++) ans+=(sum[i]-ave)*(sum[i]-ave);
    for (; t>1e-3; t*=0.98){
        last=ans;
        int x=rand()%n+1,y=0;
        if (t<500) y=rand()%m+1; else
            for (i=1; i<=m; i++) if (sum[i]<sum[y]) y=i;
        ans+=a[x]*(a[x]+sum[y]-sum[blg[x]])*2;
        if (ans>last) ans=last;
        else{ sum[blg[x]]-=a[x]; blg[x]=y; sum[y]+=a[x]; }
    }
    return ans;
}
int main(){
    srand(20160310);
    scanf("%d%d",&n,&m); int i; double ans=1e100;
    for (i=1; i<=n; i++){
        scanf("%lf",&a[i]); ave+=a[i];
    }
    ave/=m;
    for (i=1; i<=1000; i++) ans=min(ans,solve());
    printf("%.2f\n",sqrt(ans/m));
    return 0;
}
