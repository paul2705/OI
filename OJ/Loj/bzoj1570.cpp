#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iostream>
#include <queue>
#define MAXN 100010
#define inf 1<<30
using namespace std;
int dis[MAXN];queue<int> q;
struct edge{
    int first;
    int next;
    int to;
    int caw;
}a[MAXN*2];
int u[MAXN],v[MAXN],can[MAXN];
int S=0,T=MAXN-5,n,m,k,num=1;
void rezero(){
    for (int i=2;i<=num;i+=2){
        a[i].caw+=a[i^1].caw,a[i^1].caw=0;
    }
}
void addedge(int from,int to,int caw){
    a[++num].to=to;
    a[num].caw=caw;
    a[num].next=a[from].first;
    a[from].first=num;
}
void link(int x,int y,int z){
    addedge(x,y,z),addedge(y,x,0);
}
bool bfs(){
    memset(dis,0,sizeof(dis));
    while (!q.empty()) q.pop();
    dis[S]=1;q.push(S);
    while (!q.empty()){
        int now=q.front();q.pop();
        for (int i=a[now].first;i;i=a[i].next){
            int to=a[i].to,caw=a[i].caw;
            if (!dis[to]&&caw){
                dis[to]=dis[now]+1;
                q.push(to);
                if (to==T) return 1;
            }
        }
    }
    return 0;
}
int dfs(int now,int flow){
    if (now==T) return flow;
    int tag=0;
    for (int i=a[now].first;i;i=a[i].next){
        int to=a[i].to,caw=a[i].caw;
        if (dis[to]==dis[now]+1&&caw){
            int minn=dfs(to,min(caw,flow-tag));
            a[i].caw-=minn;
            a[i^1].caw+=minn;
            tag+=minn;
            if (tag==flow) return tag;
        }
    }
    if (!tag) dis[now]=0;
    return tag;
}
int dinic(){
    int maxflow=0;
    while (bfs()){ maxflow+=dfs(S,inf); }
    return maxflow;
}
int main(){    
    scanf("%d%d%d",&n,&m,&k);
    for (int i=1;i<=m;i++) scanf("%d%d%d",&u[i],&v[i],&can[i]);
    link(S,1,k);
    for (int day=1;day<=n+k;day++){
        rezero();
        for (int i=1;i<=m;i++) link((day-1)*n+u[i],n*day+v[i],can[i]);
        for (int i=1;i<=n;i++) link((day-1)*n+i,n*day+i,inf);
        link(day*n+n,T,inf);
        int hh=dinic();
        if (hh>=k){
            printf("%d\n",day);
            return 0;
        }
    }
    puts("-1");
    return 0;
}
