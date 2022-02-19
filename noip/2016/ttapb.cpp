#include<iostream>
#define ll long long
using namespace std;
const int M=3e5+11;
#ifndef Judge
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
#endif
char buf[1<<21],*p1=buf,*p2=buf;
inline int read(){
    int x=0,f=1; char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0'; return x*f;
} char sr[1<<21],z[20];int C=-1,Z;
inline void Ot(){fwrite(sr,1,C+1,stdout),C=-1;}
inline void print(int x){
    if(C>1<<20)Ot();if(x<0)sr[++C]=45,x=-x;
    while(z[++Z]=x%10+48,x/=10);
    while(sr[++C]=z[Z],--Z);sr[++C]=' ';
} int n,m,pat,mx;
int w[M],s[M],cnt1[M],cnt2[M<<1],ans[M],siz[M],dep[M],son[M],f[M],top[M],head[M];
vector<int> q1[M],q2[M],q3[M];
struct operation{ int u,v,lca,dis; }a[M];
struct Edge{ int to,next; Edge(int to,int next):to(to),next(next){} Edge(){} }e[M<<1];
inline void add(int u,int v){
    e[++pat]=Edge(v,head[u]),head[u]=pat;
    e[++pat]=Edge(u,head[v]),head[v]=pat;
}
#define v e[i].to
void dfs(int u,int fa){
    siz[u]=1,dep[u]=dep[f[u]=fa]+1;
    for(int i=head[u];i;i=e[i].next) if(v^fa){
        dfs(v,u),siz[u]+=siz[v];
        if(siz[v]>siz[son[u]]) son[u]=v;
    }
}
void dfs(int u){
    if(!top[u]) top[u]=u; if(!son[u]) return ;
    top[son[u]]=top[u], dfs(son[u]);
    for(int i=head[u];i;i=e[i].next)
        if(v^f[u] && v^son[u]) dfs(v);
}
void dfs1(int u){
    int now=w[u]+dep[u],cun; if(now<=mx) cun=cnt1[now];
    for(int i=head[u];i;i=e[i].next) if(v^f[u]) dfs1(v);
    cnt1[dep[u]]+=s[u]; if(now<=mx) ans[u]=cnt1[now]-cun;
    for(int i=0;i<q1[u].size();++i) --cnt1[dep[q1[u][i]]];
}
void dfs2(int u){
    int now=dep[u]-w[u]+n,cum=cnt2[now];
    for(int i=head[u];i;i=e[i].next) if(v^f[u]) dfs2(v);
    for(int i=0;i<q2[u].size();++i) ++cnt2[q2[u][i]+n];
    ans[u]+=cnt2[now]-cum;
    for(int i=0;i<q3[u].size();++i) --cnt2[q3[u][i]+n];
}
#undef v
inline int LCA(int u,int v){
    while(top[u]^top[v]){
        dep[top[u]]>dep[top[v]]?u=f[top[u]]:v=f[top[v]];
    } return dep[u]<dep[v]?u:v;
}
int main(){
    n=read(),m=read();
    for(int i=1,u,v;i<n;++i)
        u=read(),v=read(),add(u,v);
    for(int i=1;i<=n;++i) w[i]=read();
    for(int i=1;i<=m;++i) a[i].u=read(),a[i].v=read();
    dep[1]=1,dfs(1,0),dfs(1); for(int i=1;i<=n;++i) mx=max(mx,dep[i]);
    for(int i=1;i<=m;++i){
        a[i].lca=LCA(a[i].u,a[i].v),++s[a[i].u];
        a[i].dis=dep[a[i].u]+dep[a[i].v]-dep[a[i].lca]*2;
        q1[a[i].lca].push_back(a[i].u);
    } dfs1(1);
    for(int i=1;i<=m;++i){
        q2[a[i].v].push_back(dep[a[i].v]-a[i].dis);
        q3[a[i].lca].push_back(dep[a[i].v]-a[i].dis);
    } dfs2(1);
    for(int i=1;i<=m;++i) if(dep[a[i].u]-dep[a[i].lca]==w[a[i].lca]) --ans[a[i].lca];
    for(int i=1;i<=n;++i) print(ans[i]); return Ot(),putchar('\n'),0;
}
