#pragma GCC optimize(2)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using std::min;
using std::max;
using std::swap;
using std::vector;
typedef double db;
typedef long long ll;
#define pb(A) push_back(A)
#define pii std::pair<int,int>
#define all(A) A.begin(),A.end()
#define mp(A,B) std::make_pair(A,B)
const int N=1e6+5;

int val[N],stk[N],top,dfn[N];
int head2[N],tot,sze[N];ll ans;
int n,m,sum,cnt,head[N],low[N],siz;
struct Edge{
    int to,nxt;
}edge[N<<1],edge2[N<<1];
void add(int x,int y){
    edge[++cnt].to=y;
    edge[cnt].nxt=head[x];
    head[x]=cnt;
}
void add2(int x,int y){
    edge2[++cnt].to=y;
    edge2[cnt].nxt=head2[x];
    head2[x]=cnt;
}
int getint(){
    int X=0,w=0;char ch=getchar();
    while(!isdigit(ch))w|=ch=='-',ch=getchar();
    while( isdigit(ch))X=X*10+ch-48,ch=getchar();
    if(w) return -X;return X;
}
void tarjan(int now){
    stk[++top]=now; siz++;
    dfn[now]=low[now]=++tot;
    for(int i=head[now];i;i=edge[i].nxt){
        int to=edge[i].to;
        if(!dfn[to]) {
            tarjan(to),low[now]=min(low[now],low[to]);
            if(low[to]>=dfn[now]) {
                sum++;val[sum]=1;int z;
                do{
                    z=stk[top--]; val[sum]++;
                    add2(sum,z),add2(z,sum);
                }while(z!=to);
                add2(sum,now),add2(now,sum);
            }
        } else low[now]=min(low[now],dfn[to]);
    }
}
void dfs2(int now,int fa=0){
    sze[now]=(now<=n);
    for(int i=head2[now];i;i=edge2[i].nxt){
        int to=edge2[i].to;
        if(to==fa) continue;
        dfs2(to,now);
        ans+=2ll*val[now]*sze[now]*sze[to];
        sze[now]+=sze[to];
    } 
	ans+=2ll*val[now]*sze[now]*(siz-sze[now]);
}
int main(){
    sum=n=getint(),m=getint();
    for(int i=1;i<=m;i++){
        int x=getint(),y=getint();
        add(x,y),add(y,x);
    } cnt=0;
    for(int i=1;i<=n;i++) val[i]=-1;
    for(int i=1;i<=n;i++) if(!dfn[i]) siz=0,tarjan(i),dfs2(i);
    printf("%lld\n",ans);
    return 0;
}
