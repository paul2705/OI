#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5*2+5;
const int MAXM=1e6+6;
int edge,head[MAXN],next[MAXM*2],fir[MAXM*2],tail[MAXM*2],w[MAXM*2];
int n,m,k,fa[MAXN],ans[MAXM*2],cnt=0;
void add  (int u,int v,int c){ next[++edge]=head[u],head[u]=edge,fir[edge]=u,tail[edge]=v,w[edge]=c; }
int  Find (int u){ return u==fa[u] ? u : fa[u]=Find(fa[u]); }
void uion (int u,int v){ fa[Find(u)]=Find(v); }
void make(int c){
    for (int i=1;i<=n;i++) fa[i]=i;
    for (int i=1;i<=n;i++){
        for (int e=head[i];e;e=next[e]){
            int v=tail[e];
            if (w[e]==c) uion(i,v);
        }
    }
    for (int i=1;i<=n;i++){
        for (int e=head[i];e;e=next[e]){
            int v=tail[e];
            if (w[e]==1-c){
                if (Find(i)!=Find(v)){
                    uion(i,v); ans[cnt++]=e;
                }
            }
        }
    }
}
int cnt0=0,cnt1=0;
void G(){
    for (int i=1;i<=n;i++) fa[i]=i;
    for (int i=0;i<cnt;i++){
        int e=ans[i],u=fir[e],v=tail[e];
        uion(u,v);
        if (w[e]==0) cnt0++; else cnt1++;
    }
    for (int i=1;i<=n;i++){
        for (int e=head[i];e;e=next[e]){
            int v=tail[e];
            if ((w[e]==0&&cnt0>=k)||(w[e]==1)) continue;
            if (Find(i)!=Find(v)){
                uion(i,v); cnt0++; ans[cnt++]=e;
            }
        }
    }
    for (int i=1;i<=n;i++){
        for (int e=head[i];e;e=next[e]){
            int v=tail[e];
            if ((w[e]==0)||(w[e]==1&&cnt1>=n-k-1)) continue;
            if (Find(i)!=Find(v)){
                uion(i,v); cnt1++; ans[cnt++]=e;
            }
        }
    }
}
bool check(){
    if (cnt0<k) return false;
    for (int i=1;i<=n;i++) fa[i]=i;
    for (int i=0;i<cnt;i++){
        int e=ans[i],u=fir[e],v=tail[e];
        uion(u,v);
    }
    for (int i=2;i<=n;i++)
        if (Find(i)!=Find(i-1)) return false;
    return true;
}
void print(){
    for (int i=0;i<cnt;i++){
        int e=ans[i];
        printf("%d %d %d\n",fir[e],tail[e],w[e]);
    } 
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for (int i=0,u,v,w;i<m;i++){
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w); add(v,u,w);
    }
    make(1); if (cnt>k) return printf("no solution\n"),0;
    make(0); if (cnt>n-1) return printf("no solution\n"),0;
    G(); if (check()) print(); else return printf("no solution\n"),0;
    return 0;
}
