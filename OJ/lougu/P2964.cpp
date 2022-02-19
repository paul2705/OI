#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int N=2005;
int n,c[N],sum[N],f[N][N];
int main(){
    scanf("%d",&n);
    for (int i=n;i>=1;i--) scanf("%d",&c[i]);
    for (int i=1;i<=n;i++) sum[i]=sum[i-1]+c[i];
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            f[i][j]=f[i][j-1];
            int k=2*j-1;
            if (k<=i) f[i][j]=max(f[i][j],sum[i]-f[i-k][k]);
            k++;
            if (k<=i) f[i][j]=max(f[i][j],sum[i]-f[i-k][k]);
        }
    }
    printf ("%d\n",f[n][1]);
    return 0;
}
