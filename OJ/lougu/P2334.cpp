#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cstring>
#include<iostream>
#define LL long long
#define INF (2139062143)
#define N (1005)
using namespace std;
int n,ans=1e9,d; 
int c[N],h[N][11],map[2555*10][N],f[2555*10][N];
template <typename T> void read(T&t) {
    t=0;
    bool fl=true;
    char p=getchar();
    while (!isdigit(p)) {
        if (p=='-') fl=false;
        p=getchar();
    }
    do {
        (t*=10)+=p-48;p=getchar();
    }while (isdigit(p));
    if (!fl) t=-t;
}
int main(){
    read(n);
    for (int i=1;i<=n;i++){
        read(c[i]);
        for (int j=1;j<=c[i];j++) read(h[i][j]);
    }
    for (int j=1;j<=2550*10;j++) map[j][0]=0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=2550*10;j++){
            map[j][i]=h[i][(j-1)%c[i]+1];
        }
    }
    memset(f,127,sizeof(f));
    f[1][0]=0;
    d=1;
    for (int i=2;i<=2550*10;i++){
        d=d^1;
        for (int j=0;j<=n;j++){
            if (j>0) f[d][j]=f[d^1][j-1]+map[i][j];
            f[d][j]=min(f[d][j],f[d^1][j]+map[i][j]);
            if (j<n) f[d][j]=min(f[d][j],f[d^1][j+1]+map[i][j]);
            //printf("%d ",f[i][j]);
        } 
        ans=min(ans,f[d][n]);
    }
    printf("%d",ans);
    return 0;
}

