#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<iterator>
#include<utility>
#include<queue>
using namespace std;

int nodenum,edgenum;
int g[510][510]={0},dis[510][510]={0},fx,wx,tx,C[510][510]={0};
int esum[510]={0};

inline void readx(int& x)
{
    x=0;
    register char ch=0; int k=1;
    while (ch<'0' || ch>'9') { ch=getchar(); if (ch=='-') k=-1; }
    while (ch>='0' && ch<='9') { x=x*10+ch-'0'; ch=getchar(); }
    x*=k;
}

void SPFA(int nodex)
{
    bool vis[510]={0};
    register int prex,u,v;
    queue<int> que;

    vis[nodex]=true; dis[nodex][nodex]=0; que.push(nodex);
    while (!que.empty())
    {
        u=que.front(); que.pop();
        vis[u]=false;
        for (register int i=1;i<=nodenum;i++) if (g[u][i])
        {
            if (dis[nodex][i]>dis[nodex][u]+g[u][i])
            {
                dis[nodex][i]=dis[nodex][u]+g[u][i];
                if (!vis[i])
                {
                    que.push(i);
                    vis[i]=true;
                }
            }
        }
    }
}

int main()
{
    memset(dis,0x3f,sizeof(dis));
    readx(nodenum); readx(edgenum);
    for (register int i=1;i<=edgenum;i++)
    {
        readx(fx); readx(tx); readx(wx);
        g[fx][tx]=g[tx][fx]=wx;
    }

    for (register int i=1;i<=nodenum;i++) SPFA(i);

    //init
    for (register int i=1;i<=nodenum;i++)
    {
        memset(esum,0,sizeof(esum));
        for (register int j=1;j<=nodenum;j++) if (i!=j && dis[i][j]!=dis[0][0])
        {
            for (register int k=1;k<=nodenum;k++) if (g[k][j])
            {
                if (dis[i][k]+g[k][j]==dis[i][j]) esum[j]++;
            }
        }
        for (register int j=1;j<=nodenum;j++) if (i!=j)
        {
            for (register int k=1;k<=nodenum;k++) if (i!=k)
            {
                if (dis[i][k]+dis[k][j]==dis[i][j]) C[i][j]+=esum[k];
            }
        }
    }

    for (register int i=1;i<=nodenum;i++)
        for (register int j=i+1;j<=nodenum;j++) printf("%d ",C[i][j]);

    return 0;
}
