#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
#define re register
#define inf 50000001
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
using namespace std;
struct po{
    int nxt,to,dis,from;
    double f;
};
po edge[200001],E[200001];
int head[80050],dfn[80050],top[80050],col[80050],stack[80050],vis[80050];
int H[80050],nm,w[200001];
int dis[80050],b[80050],n,m,num,cnt,tp,color_num,s;
inline int read()
{
    int x=0,c=1;
    char ch=' ';
    while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
    while(ch=='-') c*=-1,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*c;
}
inline void add_edge(int from,int to,int dis,double f)
{
    edge[++num].nxt=head[from];
    edge[num].from=from;
    edge[num].to=to;
    edge[num].dis=dis;
    edge[num].f=f;
    head[from]=num;
}
inline void add_E(int from,int to,int dis)
{
    E[++nm].nxt=H[from];
    E[nm].to=to;
    E[nm].dis=dis;
    H[from]=nm;
}
inline void Tarjan(int u)
{
    dfn[u]=++cnt;
    top[u]=cnt;
    vis[u]=1;
    stack[++tp]=u;
    for(re int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(!dfn[v]){
            Tarjan(v);
            top[u]=min(top[u],top[v]);
        }else if(vis[v]) top[u]=min(top[u],dfn[v]);
    }
    if(dfn[u]==top[u]){
        color_num++;
        col[u]=color_num;
        vis[u]=0;
        while(stack[tp]!=u){
            col[stack[tp]]=color_num;
            vis[stack[tp--]]=0;
        }
        tp--;
    }
}
inline void spfa()
{
    memset(dis,-1,sizeof(dis));
    queue<int> q;
    q.push(s);
    dis[s]=w[s];
    b[s]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        b[u]=0;
        for(re int i=H[u];i;i=E[i].nxt){
            int v=E[i].to;
            if(dis[v]<dis[u]+E[i].dis+w[v]){
                dis[v]=dis[u]+E[i].dis+w[v];
                if(!b[v]) b[v]=1,q.push(v);
            }
        }
    }
}
int main()
{
    n=read();m=read();
    for(re int i=1;i<=m;i++){
        int x,y,l;
        double f;
        x=read();y=read();l=read();cin>>f;
        add_edge(x,y,l,f);
    }

    for(re int i=1;i<=n;i++)
    if(!dfn[i]) Tarjan(i);

    for(re int i=1;i<=m;i++){
        if(col[edge[i].to]==col[edge[i].from]){
            int id=col[edge[i].to];
            int t=edge[i].dis;
            while(t){
                w[id]+=t;
                t=(int)t*edge[i].f;
            }
        }else{
            int x=col[edge[i].from],y=col[edge[i].to];
            add_E(x,y,edge[i].dis);
        }
    }
    s=read();
    s=col[s];

    spfa();
    int ans=0;
    for(re int i=1;i<=color_num;i++)
    ans=max(dis[i],ans);
    cout<<ans;
}
