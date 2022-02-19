#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll inf=1e15;
const int MAXN=1e5+5;
const int MAXM=2e5+5;
const int MAXT=MAXN*8;
int edge,head[MAXN],tail[MAXM],nex[MAXM];
int d[MAXN],fa[MAXN],sz[MAXN],tp[MAXN],son[MAXN];
int dfn[MAXN],id[MAXN],out[MAXN];
ll a[MAXN],mod;
int n,m,tim,S;
struct tnode{
    int l,r,cl,cr;
    ll dat,tag;
} t[MAXT];
int M,rt;
void add(int u,int v){
    edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
int newnode(int l,int r,int cl,int cr,ll dat){
    t[++M]=(tnode){l,r,cl,cr,dat,0};
    return M;
}
int build(int l,int r){
    if (l==r) return newnode(l,r,0,0,a[id[l]]%mod);
    int mid=(l+r)>>1;
    int cl=build(l,mid),cr=build(mid+1,r);
    return newnode(l,r,cl,cr,(t[cl].dat+t[cr].dat)%mod);
}
void update(int id){
    int l=t[id].l,r=t[id].r;
    int cl=t[id].cl,cr=t[id].cr;
    t[id].dat=(t[cl].dat+t[cr].dat)%mod;
}
void pushdown(int id){
	ll l=t[id].l,r=t[id].r;
    int cl=t[id].cl,cr=t[id].cr;
    ll tag=t[id].tag;
    if (tag==0) return;
    t[id].dat=(t[id].dat+tag*(r-l+1)%mod)%mod;
    t[cl].tag=(t[cl].tag+tag)%mod; 
    t[cr].tag=(t[cr].tag+tag)%mod;
    t[id].tag=0;
}
void modify(int a,int b,int id,ll val){
    int l=t[id].l,r=t[id].r;
    int cl=t[id].cl,cr=t[id].cr;
    pushdown(id);
    if (l>b||r<a) return;
    if (a<=l&&r<=b){
        t[id].tag=(t[id].tag+val)%mod;
        pushdown(id);
        return;
    }
    modify(a,b,cl,val); modify(a,b,cr,val);
    update(id);
}
ll qry(int a,int b,int id){
    int l=t[id].l,r=t[id].r;
    int cl=t[id].cl,cr=t[id].cr;
    pushdown(id);
    if (l>b||r<a) return 0;
    if (a<=l&&r<=b) return t[id].dat%mod;
    return (qry(a,b,cl)+qry(a,b,cr))%mod;
}
void dfs_sz(int u,int p){
    sz[u]=1; d[u]=d[p]+1; fa[u]=p;
    for (int e=head[u];e;e=nex[e]){
        int v=tail[e];
        if (v==p) continue;
        dfs_sz(v,u);
        sz[u]+=sz[v];
        if (sz[son[u]]<sz[v]) son[u]=v;
    }
}
void dfs_tp(int u,int p,int T){
    tp[u]=T; dfn[u]=++tim; id[tim]=u;
    if (son[u]) dfs_tp(son[u],u,T);
    for (int e=head[u];e;e=nex[e]){
        int v=tail[e];
        if (v==p) continue;
        if (v==son[u]) continue;
        dfs_tp(v,u,v);
    }
    out[u]=tim;
}
ll lca(int x,int y,ll val){
    ll ret=0;
    while (tp[x]!=tp[y]){
        if (d[tp[x]]<d[tp[y]]) swap(x,y);
        if (val!=inf) modify(dfn[tp[x]],dfn[x],rt,val);
		else ret=(ret+qry(dfn[tp[x]],dfn[x],rt))%mod;
        x=fa[tp[x]];
    }
	if (d[x]>d[y]) swap(x,y);
    if (val!=inf) modify(dfn[x],dfn[y],rt,val);
	else ret=(ret+qry(dfn[x],dfn[y],rt))%mod;
    return ret;
}
ll sonT(int x,ll val){
    ll ret=0;
    if (val!=inf) modify(dfn[x],out[x],rt,val);
	else ret=(ret+qry(dfn[x],out[x],rt))%mod;
    return ret;
}
int main(){
    scanf("%d%d%d%lld",&n,&m,&S,&mod);
    for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for (int i=1;i<n;i++){
        int u,v; scanf("%d%d",&u,&v);
        add(u,v); add(v,u);
    }
    dfs_sz(S,0);
    dfs_tp(S,0,S);
    rt=build(1,tim);
    for (int i=1;i<=m;i++){
        int op,u,v; ll val; scanf("%d",&op);
        if (op==1){
            scanf("%d%d%lld",&u,&v,&val);
            lca(u,v,val);
        }
        if (op==2){
            scanf("%d%d",&u,&v);
            printf("%lld\n",lca(u,v,inf));
        }
        if (op==3){
            scanf("%d%lld",&u,&val);
            sonT(u,val);
        }
        if (op==4){
            scanf("%d",&u);
            printf("%lld\n",sonT(u,inf));
        }
    }
    return 0;
}
