#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int n,map[155][155],sum[155];
struct node
{
    int next,to,dis,cap;
}edge[50005];
int head[1001],size=1;
void putin(int from,int to,int dis,int cap)
{
    size++;
    edge[size].next=head[from];
    edge[size].to=to;
    edge[size].dis=dis;
    edge[size].cap=cap;
    head[from]=size;
}
void in(int from,int to,int dis,int cap)
{
    putin(from,to,dis,cap);
    putin(to,from,-dis,0);
}
bool vis[1001];
int dist[1001],pre[1001],cost;
bool spfa(int r,int t){
    memset(dist,63,sizeof(dist));
    int mmax=dist[0];
    queue<int> mem;
    mem.push(r);
    dist[r]=0;
    vis[r]=1;
    while(!mem.empty()){
    int x=mem.front();mem.pop();
    vis[x]=0;
    for(int i=head[x];i!=-1;i=edge[i].next){
        int y=edge[i].to;
        if(edge[i].cap&&dist[y]>dist[x]+edge[i].dis){
        dist[y]=dist[x]+edge[i].dis;
        pre[y]=i;
            if(!vis[y]){
                mem.push(y);
                vis[y]=1;
            }
        }
    }
    }
    if(dist[n*2+1]==mmax)return 0;
    else return 1;
}
void change(){
    int x=n*2+1;
    while(x!=0){
	cost+=edge[pre[x]].dis;
	edge[pre[x]].cap-=1;
	edge[pre[x]^1].cap+=1;
	x=edge[pre[x]^1].to;
    }
}
int main(){
    int i,j;
    memset(head,-1,sizeof(head));
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    	for(j=1;j<=n;j++)
            scanf("%d",&map[i][j]),sum[j]+=map[i][j];
    for(i=1;i<=n;i++){
    	in(0,i,0,1);
    	in(i+n,n*2+1,0,1);
   	for(j=1;j<=n;j++)
       	   in(i,j+n,sum[i]-map[j][i],1);
    }
    while(spfa(0,n*2+1))change();
    printf("%d\n",cost);
    return 0;
}
