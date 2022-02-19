#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
#define maxn 510
#define nx x+xx[i]
#define ny y+yy[i]
int l[maxn][maxn],r[maxn][maxn];
int high[maxn][maxn];
int n,m;
bool vis[maxn][maxn];
int xx[4]={-1,0,1,0};
int yy[4]={0,1,0,-1};
int qx[maxn*maxn],qy[maxn*maxn];
inline void dfs(int x,int y){
    vis[x][y]=true;
    for (int i=0;i<4;i++){
        if (nx<1 || nx>n || ny<1 || ny>m) continue;
        if (high[nx][ny]>=high[x][y]) continue;
        if (!vis[nx][ny])dfs(nx,ny);
        l[x][y]=min(l[x][y],l[nx][ny]);
        r[x][y]=max(r[x][y],r[nx][ny]);
    }
}
inline int read(){
    int ret=0;
    char c=getchar();
    while (c<'0' || c>'9') c=getchar();
    while (c>='0' && c<='9'){
        ret=ret*10+c-'0';
        c=getchar();
    }
    return ret;
}
int main(){
    n=read();
    m=read();
    memset(vis,false,sizeof(vis));
    memset(l,0x3f,sizeof(l));
    memset(r,0,sizeof(r));
    for (int i=1;i<=m;i++) l[n][i]=r[n][i]=i;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++) high[i][j]=read();
    for (int i=1;i<=m;i++)
        if (!vis[1][i]) dfs(1,i);
    bool flag=false;
    int cnt=0;
    for (int i=1;i<=m;i++)    
        if (!vis[n][i]){
            flag=true;
            cnt++;
        }
    if (flag){
        puts("0");
        printf("%d",cnt);
        return 0;
    }
    int left=1;
    while (left<=m){
        int maxr=0;
        for (int i=1;i<=m;i++)
            if (l[1][i]<=left)
                maxr=max(maxr,r[1][i]);
        cnt++;
        left=maxr+1;
    }
    puts("1");
    printf("%d",cnt);
}
