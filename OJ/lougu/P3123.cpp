#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int g[10][10];
int x[10];long long ans=0;
int v[233][8]={0};
void dfs(int now){
    if (now==7){
        long long sum=1ll*(x[0]+x[1]+x[2]+x[2]+x[3]+x[1])*(x[4]+x[5]+x[1]+x[2])*(x[6]+x[5]*2);
        if (sum%7==0){
            long long tmp=1;
            for (int i=0;i<7;i++)
                tmp*=g[i][x[i]];
            ans+=tmp;
        }
        return ;
    }
    for (int i=0;i<7;i++){
        if (!g[now][i]) continue;
        x[now]=i;
        dfs(now+1);
    }
}
int main(){
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        char c;int l;
        cin>>c>>l;
        l=(l%7+7)%7;
        if (c=='B') g[0][l]++;
        if (c=='E') g[1][l]++;
        if (c=='S') g[2][l]++;
        if (c=='I') g[3][l]++;
        if (c=='G') g[4][l]++;
        if (c=='O') g[5][l]++;
        if (c=='M') g[6][l]++;        
    }
    dfs(0);
    cout<<ans;
    return 0;
}
