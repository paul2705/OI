#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn=1005;
int n,k,f[maxn][maxn];
int main(){
    //freopen("num.in","r",stdin);
    //freopen("num.out","w",stdout);
    scanf("%d%d",&n,&k);
    if(k>(n-1)/2)k=n-k-1;
    f[1][0]=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<=(i-1)/2;j++){
            f[i+1][j]=(f[i+1][j]+f[i][j]*(j+1))%2015;
            f[i+1][j+1]=(f[i+1][j+1]+f[i][j]*(i-j))%2015;
        }
        if(i%2==0)f[i+1][i/2]=(f[i+1][i/2]*2)%2015;
    }   
    printf("%d",f[n][k]);
    return 0;
}
