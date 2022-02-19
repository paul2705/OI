#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edg{
    int x,y,next;
};
queue<int>q;
edg e[1000000];
int d[100000],l[1000000],t[1000000];
int maxn=0,cnt=0;
void add(int x,int y)
{
    e[++maxn]=(edg){x,y,l[x]};
    l[x]=maxn;
}
void topsort()
{
    while(!q.empty()){
        int now=q.front(); q.pop();
        for(int i=l[now];i;i=e[i].next)
            if(!(--d[e[i].y])){
                q.push(e[i].y);
                t[e[i].y]=++cnt;
            }
    }
}
int main(){    
    int n,m1,m2;
    scanf("%d%d%d",&n,&m1,&m2);
    for (int i=1;i<=m1;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);
        ++d[y];
    }
    for (int i=1;i<=n;i++)
        if (!d[i]){
            q.push(i);
            t[i]=++cnt;
        }
    topsort();
    for(int i=1;i<=m2;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        if(t[x]<t[y])printf("%d %d\n",x,y);
        else printf("%d %d\n",y,x);
    }
    return 0;
}
