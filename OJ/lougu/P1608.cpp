#include<bits/stdc++.h>
#define Ll long long
using namespace std;
const int N=2e3+5;
int g[N][N],d[N],cnt[N];
bool in[N];
int n,m,x,y,z;
void SPFA(int S,int E){
    memset(d,63,sizeof d);
    queue<int>Q;
    Q.push(S);d[S]=0;cnt[S]=1;
    while(!Q.empty()){
        int x=Q.front();Q.pop();in[x]=0;
        if(x==E)continue;
        for(int k=1;k<=n;k++){
            if(d[x]+g[x][k]==d[k])cnt[k]+=cnt[x];
            if(d[x]+g[x][k]<d[k]){
                d[k]=d[x]+g[x][k];
                cnt[k]=cnt[x];
            }
            if(cnt[k]&&!in[k])in[k]=1,Q.push(k);
        }cnt[x]=0;
    }
}
int main()
{
    memset(g,63,sizeof g);
    scanf("%d%d",&n,&m);
    while(m--){
        scanf("%d%d%d",&x,&y,&z);
        g[x][y]=min(g[x][y],z);
    }
    SPFA(1,n);
    if(d[n]==g[0][0])printf("No answer");else printf("%d %d",d[n],cnt[n]);
}
