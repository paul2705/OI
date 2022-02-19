#include<iostream>
#include<algorithm>
#include<cstring>
#define maxn 101000
#include<queue>
using namespace std;
int tot=0,head[4*maxn],dist1[maxn],dist2[maxn];
int m,ed;
struct node{
    int v,val,next;
}edge[200000];
void add(int x,int y,int val){
    tot++;
    edge[tot].v=y;
    edge[tot].val=val;
    edge[tot].next=head[x];
    head[x]=tot;
    tot++;
    edge[tot].v=x;
    edge[tot].val=val;
    edge[tot].next=head[y];
    head[y]=tot;
}
void dijkstra(){
    memset(dist1,0x3F,sizeof(dist1));
    memset(dist2,0x3F,sizeof(dist2));
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
    q.push(make_pair(0,1));
    dist1[1]=0;
    while(!q.empty()){
        int temp=q.top().second,dis=q.top().first;
        q.pop();
        if(dis>dist2[temp]) continue;
        for(int i=head[temp];i;i=edge[i].next){
            int cnt=edge[i].v;
            if(dist1[cnt]>dis+edge[i].val){
                dist1[cnt]=dis+edge[i].val;
                q.push(make_pair(dist1[cnt],cnt));
            }
            if(dist2[cnt]>dis+edge[i].val&&dis+edge[i].val>dist1[cnt]){
                dist2[cnt]=dis+edge[i].val;
                q.push(make_pair(dist2[cnt],cnt));
            }
        }
    }
}
int main(){
    cin>>ed>>m;
    for(int i=1;i<=m;i++){
        int x,y,val;
        cin>>x>>y>>val;
        add(x,y,val);
    }
    dijkstra();
    cout<<dist2[ed]<<endl;
    return 0;
} 
