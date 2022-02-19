#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<queue>
using namespace std;
#define MAX 52000
#define lson (t[x].ch[0])
#define rson (t[x].ch[1])
inline int read()
{
    int x=0,t=1;char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
    if(ch=='-')t=-1,ch=getchar();
    while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
    return x*t;
}
map<pair<int,int>,int> M;
struct qq{int opt,ans;int u,v;}q[MAX];
struct Line{int v,next;}e[MAX*4];
struct edge{int u,v,br;}E[MAX*4];
int h[MAX],cnt=1,tot,n,m;
int S[MAX<<2],top;
inline void Add(int u,int v){e[cnt]=(Line){v,h[u]};h[u]=cnt++;}
struct Node
{
    int ch[2],ff;
    int sum,rev,v;
    int ly;
}t[MAX<<2];
bool isroot(int x){return t[t[x].ff].ch[0]!=x&&t[t[x].ff].ch[1]!=x;}
void pushup(int x){t[x].sum=t[lson].sum+t[rson].sum+t[x].v;}
void rotate(int x)
{
    int y=t[x].ff,z=t[y].ff;
    int k=t[y].ch[1]==x;
    if(!isroot(y))t[z].ch[t[z].ch[1]==y]=x;t[x].ff=z;
    t[y].ch[k]=t[x].ch[k^1];t[t[x].ch[k^1]].ff=y;
    t[x].ch[k^1]=y;t[y].ff=x;
    pushup(y);pushup(x);
}
void putrev(int x){swap(lson,rson);t[x].rev^=1;}
void putly(int x){t[x].ly=1;t[x].sum=t[x].v=0;}
void pushdown(int x)
{
    if(t[x].rev)
    {
        if(lson)putrev(lson);
        if(rson)putrev(rson);
        t[x].rev^=1;
    }
    if(t[x].ly)
    {
        if(lson)putly(lson);
        if(rson)putly(rson);
        t[x].ly=0;
    }
}
void Splay(int x)
{
    S[top=1]=x;
    for(int i=x;!isroot(i);i=t[i].ff)S[++top]=t[i].ff;
    while(top)pushdown(S[top--]);
    while(!isroot(x))
    {
        int y=t[x].ff,z=t[y].ff;
        if(!isroot(y))
            (t[y].ch[1]==x)^(t[z].ch[1]==y)?rotate(x):rotate(y);
        rotate(x);
    }
}
void access(int x){for(int y=0;x;y=x,x=t[x].ff)Splay(x),t[x].ch[1]=y,pushup(x);}
void makeroot(int x){access(x);Splay(x);putrev(x);}
void split(int x,int y){makeroot(x);access(y);Splay(y);}
void cut(int x,int y){split(x,y);t[y].ch[0]=t[x].ff=0;pushup(y);}
void link(int x,int y){makeroot(x);t[x].ff=y;}
int findroot(int x){access(x);Splay(x);while(lson)x=lson;return x;}
int main(){
    n=read();m=read();
    for(int i=1;i<=m;++i){
        int u=read(),v=read();
        if(u>v)swap(u,v);
        E[i]=(edge){u,v};
        M[make_pair(u,v)]=i;
        t[i+n].v=1;
    }
    while(1){
        int c=read();if(c==-1)break;
        int u=read(),v=read();if(u>v)swap(u,v);
        q[++tot]=(qq){c,0,u,v};
        if(!c)E[q[tot].ans=M[make_pair(u,v)]].br=1;
    }
    for(int i=1;i<=m;++i)
        if(!E[i].br){
            if(findroot(E[i].u)!=findroot(E[i].v))
                link(E[i].u,i+n),link(E[i].v,i+n);
            else split(E[i].u,E[i].v),putly(E[i].v);
        }
    for(int i=tot;i;--i)
    {
        if(q[i].opt)
        {
            split(q[i].u,q[i].v);
            q[i].ans=t[q[i].v].sum;
        }
        else
        {
            if(findroot(q[i].u)!=findroot(q[i].v))
                link(q[i].u,q[i].ans+n),link(q[i].v,q[i].ans+n);
            else split(q[i].u,q[i].v),putly(q[i].v);
        }
    }
    for(int i=1;i<=tot;++i)
        if(q[i].opt)printf("%d\n",q[i].ans);
    return 0;
}
