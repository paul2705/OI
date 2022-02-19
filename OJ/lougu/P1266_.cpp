#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<algorithm>
#include<ctime>
using namespace std;
const int N=255,M=N*N*2;
int list[M],head[N],nex[M],w[M],len[M],tot;
void add(int a,int b,int c,int d)
{
    tot++;
//  cout<<"add "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    list[tot]=b,len[tot]=c,w[tot]=d;
    nex[tot]=head[a];
    head[a]=tot;
}
double dist[N][505];
bool vis[N][505];
struct pos
{
    int x,s;
    pos(){};
    pos(int nn,int ss){x=nn,s=ss;};
};
int pr[N][505],ps[N][505];
int n,m;
void spfa()
{
    memset(dist,66,sizeof dist);
    queue<pos>q;
    q.push(pos(1,70));dist[1][70]=0;
    vis[1][70]=1;
    while(!q.empty())
    {
         pos v=q.front();q.pop();
         vis[v.x][v.s]=0;
    //   cout<<v.x<<" "<<v.s<<endl;
         for(int i=head[v.x];i;i=nex[i])
         {
                //cout<<i<<endl;
                int u=list[i];
                //cout<<u<<endl;
                if(w[i]==0)//没限速 
                {
                    if(1.0*len[i]/v.s+dist[v.x][v.s]<dist[u][v.s])
                    {
                        dist[u][v.s]=1.0*len[i]/v.s+dist[v.x][v.s];
                        pr[u][v.s]=v.x;
                        ps[u][v.s]=v.s;
                        if(!vis[u][v.s])
                        {
                            q.push(pos(u,v.s));
                            vis[u][v.s]=1;
                        }
                    }
                }
                else
                {
                    int mv=w[i];
			cout<<1.0*len[i]/mv+dist[v.x][v.s]<<" ";
			cout<<dist[u][mv]<<endl;
                    if(1.0*len[i]/mv+dist[v.x][v.s]<dist[u][mv])
                    {
                        dist[u][mv]=1.0*len[i]/mv+dist[v.x][v.s];
                        pr[u][mv]=v.x;
                        ps[u][mv]=v.s;
                        if(!vis[u][mv])
                        {
                            q.push(pos(u,mv));
                            vis[u][mv]=1;
                        }
                    }
                }
        }
    }
}
void print(int a,int b)
{
    if(a!=1)print(pr[a][b],ps[a][b]);
    printf("%d ",a-1);
}
int e=0;
int main()
{
    scanf("%d%d%d",&n,&m,&e);e++;
    for(int i=1;i<=m;i++)
    {
        int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);
        a++,b++;
        add(a,b,d,c);
    }
    spfa();
    double mn=1e30;int ans=0;
    for(int i=1;i<=500;i++)
    {
        if(mn>dist[e][i])
        mn=dist[e][i],ans=i;
    }
    print(pr[e][ans],ps[e][ans]);
    printf("%d\n",e-1);
}
