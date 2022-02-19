#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int L=1e5+5;
int n,k,dis[L],ans,diso[L],dist[L];
vector<int>w[L];
void dfs(int o,int fa,int p)
{
    for(int i=0;i<w[o].size();i++)
    {
        int v=w[o][i];
        if(v==fa)
            continue;
        if(p==0)
        {
            diso[v]=diso[o]+1;
            dfs(v,o,0);
        }
        if(p==1)
        {
            dis[v]=dis[o]+1;
            if(w[v].size()==1)
            {
                dist[o]=min(dist[o],1);
                dist[v]=0;
            }
            else
            {
                dfs(v,o,1);
                dist[o]=min(dist[v]+1,dist[o]);
            }
        }
        if(p==2)
        {
            if(diso[v]>=dist[v])
                ans++;
            else
                dfs(v,o,2);
        }
    }
}
int main()
{
    memset(dis,0x3f,sizeof(dis));
    memset(dist,0x3f,sizeof(dist));
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++)
    {
        int t1,t2;
        scanf("%d%d",&t1,&t2);
        w[t1].push_back(t2);
        w[t2].push_back(t1);
    }
    dfs(k,0,0);
    dis[k]=0;
    dfs(k,0,1);
    dfs(k,0,2);
    printf("%d",ans);
    return 0;
}
