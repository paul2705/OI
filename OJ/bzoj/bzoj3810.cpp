#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const ll INF=0x7fffffff;
int f[305][305][2][2][2][2];
int n,m;
ll k;
int dfs(int n,int m,int l,int r,int u,int d){
    if (n>m) swap(n,m),swap(l,u),swap(r,d);
    if (l>r) swap(l,r);
    if (d>u) swap(u,d);
    if (f[n][m][l][r][u][d]==-1){
        f[n][m][l][r][u][d]=min(INF,(n*m-k)*(n*m-k));
        if (u||d||(l&&r))
            for (int y=1;y<m;y++)
                f[n][m][l][r][u][d]=min(f[n][m][l][r][u][d],dfs(n,y,l,0,u,d)+dfs(n,m-y,0,r,u,d));
        if (l||r||(u&&d))
            for (int x=1;x<n;x++)
                f[n][m][l][r][u][d]=min(f[n][m][l][r][u][d],dfs(x,m,l,r,0,d)+dfs(n-x,m,l,r,u,0));
    }
    return f[n][m][l][r][u][d];
}
int main(){
    scanf("%d%d%lld",&n,&m,&k);
    memset(f,-1,sizeof(f));
    cout << dfs(n,m,1,1,1,1);
    return 0;
}
