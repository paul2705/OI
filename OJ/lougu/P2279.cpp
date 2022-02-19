#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 1010
#define maxm 2010
using namespace std;

int head[maxn],point[maxm],nxt[maxm],dep[maxn],fa[maxn],tot=0;
bool vis[maxn];
struct cmp{
    bool operator () (int &a,int &b){
        return dep[a]<dep[b];
    } 
};
priority_queue<int,vector<int>,cmp> q;
void add(int x,int y){
    point[++tot]=y;
    nxt[tot]=head[x];
    head[x]=tot;
}
void dfs(int temp,int father,int depth){
    fa[temp]=father;
    dep[temp]=depth;
    for(int j=head[temp];j;j=nxt[j]){
        if(point[j]==father)
            continue;
        dfs(point[j],temp,depth+1);
    }
}
void dfs2(int temp,int depth){
    if(depth>2)
        return;
    vis[temp]=true;
    for(int j=head[temp];j;j=nxt[j])
        dfs2(point[j],depth+1);
}
int main(){
    int n,cnt,x,y,ans=0;
    scanf("%d",&n),cnt=n;
    for(int i=1;i<=n-1;i++)
        scanf("%d",&x),add(i+1,x),add(x,i+1);
    dfs(1,0,1);
    for(int i=1;i<=n;i++)
        q.push(i);
    while(q.size()){
        while(q.size()&&vis[x=q.top()])
            q.pop();
        if(!q.size())
            break;
        if(fa[fa[x]])
            dfs2(fa[fa[x]],0);
        else
            dfs2(1,0);
        ans++; 
    }
    printf("%d\n",ans);
    return 0;
} 
