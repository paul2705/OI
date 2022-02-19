#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
#define N 1010
#define M 10010
#define INF (0x3f3f3f3f)
struct peo{
    int t,l,r;
}a[M];
struct edge{
    int nxt,to,cap,cost;
}e[N<<3];
int head[N<<1],edge_cnt;
void add_edge(int x,int y,int z,int w){
    e[edge_cnt]=(edge){head[x],y,z,w};
    head[x]=edge_cnt++;
    e[edge_cnt]=(edge){head[y],x,0,-w};
    head[y]=edge_cnt++;
}
int D[N],Mx[N],down[N],tim[N],S,T;
struct MinCostMaxFlow{
    int d[N<<1],fa[N<<1],Mn[N<<1];
    bool vis[N<<1];
    queue<int>Q;
    int calc(){
        int i,res=0;
        while (1){
            memset(d,63,sizeof(d));
            d[S]=0;
            Q.push(S);
            Mn[S]=INF;
            while (!Q.empty()){
                int x=Q.front(); Q.pop();
                vis[x]=0;
                for (i=head[x];~i;i=e[i].nxt){
                    int To=e[i].to;
                    if (!e[i].cap || d[To]<=d[x]+e[i].cost) continue;
                    d[To]=d[x]+e[i].cost;
                    fa[To]=i;
                    Mn[To]=min(Mn[x],e[i].cap);
                    if (!vis[To]){
                        vis[To]=1;
                        Q.push(To);
                    }
                }
            }
            if (d[T]==INF) return res;
            res+=Mn[T]*d[T];
            int p=T;
            while (p!=S){
                e[fa[p]].cap-=Mn[T];
                e[fa[p]^1].cap+=Mn[T];
                p=e[fa[p]^1].to;
            }
        }
    }
} MCMF;
int main(){
    memset(head,-1,sizeof(head));
    int n,m,K,i,ans=0;
    scanf("%d%d%d",&n,&m,&K);
    for (i=1;i<n;i++) scanf("%d",&D[i]);
    for (i=1;i<=m;i++){
        scanf("%d%d%d",&a[i].t,&a[i].l,&a[i].r);
        down[a[i].r]++;
        Mx[a[i].l]=max(Mx[a[i].l],a[i].t);
    }
    for (i=1;i<n;i++) tim[i+1]=max(tim[i],Mx[i])+D[i];
    for (i=1;i<=m;i++) ans+=tim[a[i].r]-a[i].t;
    S=n*2+1; T=n*2+3;
    int S1=n*2+2;
    add_edge(S,S1,K,0);
    for (i=1;i<n;i++){
        add_edge(i,i+n,max(tim[i]-Mx[i],0),0);
        add_edge(i+n,i+1,INF,-down[i+1]);
        add_edge(S1,i+n,D[i],0);
        add_edge(i+1,T,INF,0);
    }
    printf("%d\n",ans+MCMF.calc());
    return 0;
}
