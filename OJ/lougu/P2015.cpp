#include<iostream>
#include<cstring>
#include<cstdio>
#include<cctype>
#define maxn 105
#define gc() getchar()
#define ll long long
using namespace std;
inline ll read(){
    ll a=0;char p=gc();int f=0;
    while(!isdigit(p)){f|=(p=='-');p=gc();}
    while(isdigit(p)){a=(a<<3)+(a<<1)+(p^48);p=gc();}
    return f?-a:a;
}
struct ahaha{
    int to,next,w;
}e[maxn<<1];
int n,q,head[maxn],f[maxn][maxn],b[maxn],sz;
inline void add(int u,int v,int z){
    e[sz].to=v;e[sz].w=z;e[sz].next=head[u];head[u]=sz++;
}
void dfs(int u,int fa){
    for(int i=head[u];~i;i=e[i].next){
        int v=e[i].to;if(v==fa)continue;   
        dfs(v,u);
        b[u]+=b[v]+1;     
        for(int j=min(q,b[u]);j>=1;--j)
            for(int k=min(b[v],j-1);k>=0;--k)
                f[u][j]=max(f[u][j],f[u][j-k-1]+f[v][k]+e[i].w);
    }
}
int main(){
    memset(head,-1,sizeof head);
    n=read();q=read();
    for(int i=1;i<n;++i){
        int x=read(),y=read(),z=read();
        add(x,y,z);add(y,x,z);    
    }
    dfs(1,0);
    printf("%d",f[1][q]);
    return 0;
}
