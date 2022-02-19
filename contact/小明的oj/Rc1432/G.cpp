#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=1e4+5;
const int MAXE=1e4*5+5;
int edge,use[MAXN],head[MAXN],tail[MAXE],nex[MAXE];
int redge,ruse[MAXN],rhead[MAXN],rtail[MAXE],rnext[MAXE];
int u,v,n,m,cnt,vs[MAXN],cmp[MAXN];
void add(int u,int v){
    edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
    redge++,rnext[redge]=rhead[v],rhead[v]=redge,rtail[redge]=u;
}
void dfs(int u){
    use[u]=true;
    for (int e=head[u];e;e=nex[e]){
        int v=tail[e];
        if (!use[v]) dfs(v);
    }
    vs[cnt++]=u;
}
void rdfs(int u,int k){
    ruse[u]=true;
    cmp[u]=k;
    for (int e=rhead[u];e;e=rnext[e]){
        int v=rtail[e];
        if (!ruse[v]) rdfs(v,k);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;i++){
        scanf("%d%d",&u,&v);
        add(u,v);
    }
    memset(use,0,sizeof(use)); memset(ruse,0,sizeof(ruse));
    for (int i=1;i<=n;i++) if (!use[i]) dfs(i);
    int k=0;
    for (int i=cnt-1;i>=0;i--) if (!ruse[vs[i]]) rdfs(vs[i],k++);
    int u=0,num=0;
    for (int i=1;i<=n;i++) if (cmp[i]==k-1) u=i,num++;
    memset(ruse,0,sizeof(ruse));
    rdfs(u,0);
    for (int i=1;i<=n;i++) if (!ruse[i]) num=0;
    printf("%d\n",num);
    return 0;
}

