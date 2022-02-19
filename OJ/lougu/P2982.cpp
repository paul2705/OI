#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn=1000001;
const int inf=1e9;
int n,m,tot[maxn],dfn[maxn],idfn[maxn],a[maxn];
struct Node{
    int sum,tag;
}tree[maxn<<1|1];
struct Edge{
    int next,to;
}edge[maxn<<1];
int num_edge=-1,head[maxn];
void add_edge(int from,int to){
    edge[++num_edge].next=head[from];
    edge[num_edge].to=to;
    head[from]=num_edge;
}
int cnt;
void dfs(int x,int fa){
    dfn[x]=++cnt; 
    idfn[cnt]=x;
    tot[x]=1;
    for (int i=head[x]; i!=-1; i=edge[i].next){
        int to=edge[i].to;
        if (to!=fa){
            dfs(to,x);
            tot[x]+=tot[to];
        }
    }
}
void pushup(int rt) {tree[rt].sum=tree[rt<<1].sum+tree[rt<<1|1].sum;}
void pushdown(int rt,int ln,int rn){
    if (tree[rt].tag){
        tree[rt<<1].tag+=tree[rt].tag;
        tree[rt<<1|1].tag+=tree[rt].tag;
        tree[rt<<1].sum+=tree[rt].tag*ln;
        tree[rt<<1|1].sum+=tree[rt].tag*rn;
        tree[rt].tag=0;
    }
}
void change(int L,int R,int C,int l,int r,int rt){
    if (L<=l && r<=R){
        tree[rt].sum+=(r-l+1)*C; tree[rt].tag+=C; return;
    }
    int mid=(l+r)>>1;
    pushdown(rt,mid-l+1,r-mid);
    if (L<=mid) change(L,R,C,l,mid,rt<<1);
    if (R>mid)  change(L,R,C,mid+1,r,rt<<1|1);
    pushup(rt);
}
int ques(int x,int l,int r,int rt){
    if (l==r && x==l) return tree[rt].sum;
    int mid=(l+r)>>1;
    pushdown(rt,mid-l+1,r-mid);
    if (x<=mid) return ques(x,l,mid,rt<<1);
    else return ques(x,mid+1,r,rt<<1|1);
}
int main(){
    memset(head,-1,sizeof(head));
    scanf("%d",&n); 
    for (int i=1; i<=n-1; i++){
        int x,y; scanf("%d%d",&x,&y);
        add_edge(x,y); add_edge(y,x);
    }
    dfs(1,0);
    for (int i=1; i<=n; i++){
        int x; scanf("%d",&x);// printf("%d %d\n",dfn[x],dfn[x]+tot[x]-1);
        printf("%d\n",ques(dfn[x],1,n,1));
        change(dfn[x],dfn[x]+tot[x]-1,1,1,n,1);
    }
    return 0;
}
