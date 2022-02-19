#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
//const int MAXN=5e2+5;
const int MAXN=510,S=501,T=502,SHIFT=250;
struct edge
{
    int v,f,len;
    edge *next,*rev;
}*h[MAXN],pool[MAXN*MAXN*2];
int top;
inline void addedge(int u,int v,int c,int w)
{
    edge *tmp=&pool[++top];tmp->v=v;tmp->f=c;tmp->len=w;tmp->next=h[u];h[u]=tmp;
    edge *pmt=&pool[++top];pmt->v=u;pmt->f=0;pmt->len=-w;pmt->next=h[v];h[v]=pmt;
    tmp->rev=pmt;pmt->rev=tmp;
}
int totf,totc;
queue<int> q;
int inq[MAXN],dis[MAXN],last[MAXN];
edge *laste[MAXN];
inline int spfa()
{
    while(!q.empty())q.pop();
    memset(dis,0x3f,sizeof(dis));
    memset(last,0,sizeof(last));
    memset(laste,0,sizeof(laste));
    dis[S]=0;inq[S]=1;
    q.push(S);
    while(!q.empty())
    {
        int u=q.front();q.pop();
        inq[u]=0;
        for(edge *tmp=h[u];tmp;tmp=tmp->next)
        {
            if(tmp->f&&dis[tmp->v]>dis[u]+tmp->len)
            {
                dis[tmp->v]=dis[u]+tmp->len;
                last[tmp->v]=u;
                laste[tmp->v]=tmp;
                if(!inq[tmp->v])
                {
                    inq[tmp->v]=1;
                    q.push(tmp->v);
                }
            }
        }
    }
    if(dis[T]==0x3f3f3f3f)return -1;
    int cur=T;
    while(cur!=S)
    {
        laste[cur]->f--;laste[cur]->rev->f++;
        cur=last[cur];
    }
    return dis[T];
}
int main()
{
    int n;
    scanf("%d",&n);
    int m,l,r,t;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d%d",&m,&l,&r,&t);
        addedge(S,i,1,0);
        for(int j=l;j<=r;j++)
        {
            addedge(i,j+SHIFT,1,abs(m-j)*t);
        }
        addedge(i+SHIFT,T,1,0);
    }
    int tmp;
    while((tmp=spfa())!=-1)
    {
        totf++;
        totc+=tmp;
    }
    if(totf==n)printf("%d\n",totc);
    else printf("NIE\n");
    return 0;
}
