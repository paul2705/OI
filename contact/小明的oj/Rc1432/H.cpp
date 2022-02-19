#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e5+5;
const int MAXM=MAXN*4;
int edge,head[MAXN],nex[MAXM],tail[MAXM];
int low[MAXN],n,dfn[MAXN],cnt;
int s[MAXM],top,bel[MAXN],num[MAXN],scc;
bool use[MAXN];
int mx=1e9;
void add(int u,int v){
    edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void tarjan(int u){
    dfn[u]=low[u]=++cnt;
    s[top++]=u; use[u]=1;
    for (int e=head[u];e;e=nex[e]){
        int v=tail[e];
        if (!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if (use[v]) low[u]=min(low[u],dfn[v]);
    }
    if (low[u]==dfn[u]){
        int x=s[top-1]; top--; scc++;
        bel[u]=scc; num[scc]++; use[u]=0;
        while (x!=u){
            bel[x]=scc; num[scc]++;
            use[x]=0;
            x=s[top-1]; top--;
        }
    }
}
int main(){
    scanf("%d",&n);
    for (int i=1,x;i<=n;i++){
        scanf("%d",&x); add(i,x);
    }
    for (int i=1;i<=n;i++){
        if (!dfn[i]) tarjan(i);
    }
    for (int i=1;i<=scc;i++){
        if (num[i]>1) mx=min(mx,num[i]);
    }
    printf("%d\n",mx);
    return 0;
}
