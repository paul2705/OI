#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<set>
#include<queue>
#define pa pair<int,int>
#define inf 1000000000
#define ll long long
using namespace std;
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,K,cnt,ed;
int bin[22],a[22];
int dis[22][22],d[20005],last[20005];
int f[1048576][22];
bool vis[20005];
struct data{int to,next,v;}e[400005];
void insert(int u,int v,int w)
{
    e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;e[cnt].v=w;
    e[++cnt].to=u;e[cnt].next=last[v];last[v]=cnt;e[cnt].v=w;
}
void dijkstra(int x)
{
    priority_queue<pa,vector<pa>,greater<pa> >q;
    for(int i=1;i<=n;i++)d[i]=inf;
    for(int i=1;i<=n;i++)vis[i]=0;
    d[x]=0;q.push(make_pair(0,x));
    while(!q.empty())
    {
        int now=q.top().second;q.pop();
        if(vis[now])continue;vis[now]=1;
        for(int i=last[now];i;i=e[i].next)
            if(d[now]+e[i].v<d[e[i].to])
            {
                d[e[i].to]=d[now]+e[i].v;
                q.push(make_pair(d[e[i].to],e[i].to));
            }
    }
    for(int i=1;i<=K+1;i++)
        dis[x][i]=d[i];
    dis[x][0]=d[n];
}
void dp()
{
    for(int now=0;now<=ed;now++)
        for(int x=1;x<=K+1;x++)
            if(f[now][x]!=-1)
                for(int i=2;i<=K+1;i++)
                {
                    int to=(now|bin[i-2]);
                    if((now&a[i])==a[i])
                        if(f[to][i]>f[now][x]+dis[x][i]||f[to][i]==-1)
                            printf("in: %d %d\n",x,i),f[to][i]=f[now][x]+dis[x][i];
                }
}
int main()
{
    bin[0]=1;for(int i=1;i<22;i++)bin[i]=bin[i-1]<<1;
    n=read();m=read();K=read();ed=bin[K]-1;
    for(int i=1;i<=m;i++)
    {
        int u=read(),v=read(),w=read();
        insert(u,v,w);
    }
    for(int i=1;i<=K+1;i++)dijkstra(i);
	for (int i=1;i<=K+1;i++){
		for (int j=1;j<=K+1;j++) cout<<dis[i][j]<<" ";
		cout<<endl;
	}
int x=read();
    for(int i=1;i<=x;i++)
    {
        int u=read(),v=read();
        a[v]+=bin[u-2];
    }
	for (int i=1;i<=K+1;i++) cout<<a[i]<<" ";
	cout<<endl;
	memset(f,-1,sizeof(f));
    f[0][1]=0;
    dp();
    int ans=inf;
    for(int i=1;i<=K+1;i++){
    	cout<<i<<" "<<f[ed][i]<<endl;
        if(f[ed][i]!=-1)ans=min(ans,f[ed][i]+dis[i][0]);
	}
    printf("%d",ans);
    return 0;
}
