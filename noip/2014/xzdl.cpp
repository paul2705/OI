#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
struct edge{
    int from,to;
} e[200005],re[200005];
int vs[10005],cvs[10005],divs[10005],n,m,u,v,x,s,tot,rtot;
int dist[10005],nex[200005],head[10005],rnex[200005],rhead[10005];
void dfs(int u){
    for (int i=rhead[u];i;i=rnex[i]){
        int v=re[i].to;
        if (!vs[v]){
            vs[v]=true;
            dfs(v);
        }
    }
}
void SPFA(int s){
    queue<int> que;
    memset(dist,50,sizeof(dist));
    memset(divs,0,sizeof(divs));
    que.push(s); dist[s]=0; divs[s]=1;
    while (!que.empty()){
        int u=que.front(); que.pop();
        divs[u]=0;
        for (int i=head[u];i;i=nex[i]){
            int v=e[i].to;
            if (!cvs[v]) continue;
            if (dist[v]>dist[u]+1){
                dist[v]=dist[u]+1;
                if (!divs[v]){
                    divs[v]=1;
                    que.push(v);
                }
            }
        }
    }
}
void addedge(int u,int v){
    tot++;
    e[tot].from=u; e[tot].to=v;
    nex[tot]=head[u];
    head[u]=tot;
}
void addrdge(int u,int v){
    rtot++;
    re[rtot].from=u; re[rtot].to=v;
    rnex[rtot]=rhead[u];
    rhead[u]=rtot;
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++){
        scanf("%d%d",&u,&v);
        if (u==v) continue;
        addedge(u,v);
        addrdge(v,u);
    }
    scanf("%d%d",&x,&s);
    memset(vs,0,sizeof(vs));vs[s]=1;
    dfs(s);
    for (int i=1;i<=n;i++){
        cvs[i]=1;
    }
    for (int i=1;i<=n;i++){
        if (vs[i]) continue;
        for (int j=rhead[i];j;j=rnex[j]){
            int v=re[j].to;
            cvs[v]=0;
        }
    }
    /*for (int i=1;i<=n;i++){
        printf("%d ",cvs[i]);
    }*/
    if (vs[x]==0) {
        printf("-1");
        return 0;
    }
    SPFA(x);
    printf("%d",dist[s]);
    return 0;
} 
