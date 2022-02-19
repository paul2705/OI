#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int _ = 10005;
const int INF = 1e9;
struct edge{int to,next;}a[_<<1];
int n,head[_],cnt,val[_],dp[3][_];
int gi(){
    int x=0,w=1;char ch=getchar();
    while ((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
    if (ch=='-') w=-1,ch=getchar();
    while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
    return x*w;
}
void Link(int u,int v){
    a[++cnt]=(edge){v,head[u]};
    head[u]=cnt;
}
void dfs(int u,int fa){
    int sum=0;dp[2][u]=val[u];
    for (int e=head[u];e;e=a[e].next){
        int v=a[e].to;
        if (v==fa) continue;
        dfs(v,u);
        sum+=min(dp[1][v],dp[2][v]);
        dp[2][u]+=min(min(dp[0][v],dp[1][v]),dp[2][v]);
    }
    dp[0][u]=sum;dp[1][u]=INF;
    for (int e=head[u];e;e=a[e].next){
        int v=a[e].to;
        if (v==fa) continue;
        dp[1][u]=min(dp[1][u],sum-min(dp[1][v],dp[2][v])+dp[2][v]);
    }
}
int main(){
    n=gi();
    for (int i=1,k,u,v;i<=n;i++){
        u=gi();val[u]=gi();
        k=gi();
        for (int j=1;j<=k;j++)
            v=gi(),Link(u,v),Link(v,u);
    }
    dfs(1,0);
    printf("%d\n",min(dp[1][1],dp[2][1]));
    return 0;
}
