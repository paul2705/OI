#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<cstdio>
#define maxn 100100
using namespace std;
struct node{ int next,to; } e[maxn*2];
int cnt,head[maxn],n;
int c[maxn],fa[maxn],num[maxn];
void add(int u,int v){
    e[++cnt].next=head[u];
    e[cnt].to=v;
    head[u]=cnt;
}
void add_tree(int x,int k){
    for(int i=x;i<=n;i+=i&(-i)) c[i]+=k;
}
int query(int x){
    int sum=0;
    for(int i=x;i>0;i-=i&(-i)) sum+=c[i];
    return sum;
}
struct NOde{ int w,place; } a[maxn];
int cmp1(NOde x,NOde y){ return x.w<y.w; }
int cmp2(NOde x,NOde y){ return x.place<y.place; }
void dfs(int now){
    add_tree(a[now].w,1);
    int last=query(n)-query(a[now].w);
    for(int i=head[now];i;i=e[i].next){
        int to=e[i].to;
        if(fa[now]!=to) dfs(to);
    }
    num[now]+=query(n)-query(a[now].w)-last;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i].w);
        a[i].place=i;
    }
    sort(a+1,a+1+n,cmp1);
    for(int i=1;i<=n;i++) a[i].w=i;
    sort(a+1,a+1+n,cmp2);
    for(int i=2;i<=n;i++){
        int x;
        scanf("%d",&x);
        add(x,i);
        add(i,x);
        fa[i]=x;
    }
    dfs(1);
    for(int i=1;i<=n;i++) printf("%d\n",num[i]);
    return 0;
}
