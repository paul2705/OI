#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=100005;
int head[N],tail[N*2],nxt[N*2];
int f[N],in[N];
int use[N];
int n,m,ans,t;
void addto(int x,int y){
    nxt[++t]=head[x];
    head[x]=t;
    tail[t]=y;
}
int dfs(int k,int fa){
    if(in[k]==1) return 1;
    int s=0;
    for(int i=head[k];i;i=nxt[i])
        if(fa!=tail[i]){
            s+=dfs(tail[i],k);
        }
    int x=s>>1;
    ans+=min(x,m);
    if(x>=m) return 0;
    else return s&1;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        in[x]++; in[y]++;
        addto(x,y); addto(y,x);
    }
    for(int i=1;i<=n;i++)
        if(in[i]>1){ dfs(i,0); break; }
    printf("%d",ans);
    return 0;
}
