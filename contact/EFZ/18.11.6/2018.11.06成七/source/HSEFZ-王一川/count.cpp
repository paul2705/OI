#include<cstdio>
using namespace std;
int n,m,i,j,k;
long long p,ans;
long long dp[6403][83][83];

//int max(int aa,int bb) {if (aa<bb) return bb;return aa;}

int main() {
freopen("count.in","r",stdin);
freopen("count.out","w",stdout);
scanf("%d%d%lld\n",&n,&m,&p);
/*if (n==1) {
if (m==1) ans=1;else ans=0;}
if (n==2) {
if (m==1) ans=0;if (m==2) ans=12%p;if (m==3) ans=(42*30)%p;
}
if (n==3) {
if (m==1) ans=0;if (m==2) ans=(42*30)%p;if (m==3) ans=108864%p;
}
printf("%lld\n",ans);*/
for (k=1;k<=n*m;k++) for (i=1;i<=n;i++) for (j=1;j<=m;j++) dp[k][i][j]=0;
dp[1][1][1]=(n*m)%p;
for (i=1;i<=n;i++) for (j=1;j<=m;j++) for (k=i+j-1;k<=i*j;k++) {
if (k!=1) {dp[k][i][j]+=dp[k-1][i][j]*(j*i-k+1);
if (j!=1) dp[k][i][j]+=dp[k-1][i][j-1]*(m-j+1)*i;
if (i!=1) dp[k][i][j]+=dp[k-1][i-1][j]*(n-i+1)*j;}
dp[k][i][j]%=p;
}
//printf("%lld %lld %lld %lld\n",dp[3][2][1],dp[2][2][2],dp[3][2][2],dp[4][2][2]);
printf("%lld\n",dp[n*m][n][m]);

//for (i=1;i<=n;i++) for (j=1;j<=m;j++) printf("%d %d:%lld\n",i,j,dp[60][i][j]);

fclose(stdin);
fclose(stdout);
return 0;
}
