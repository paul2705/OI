#include <bits/stdc++.h>
#define maxn 500010
using namespace std;
struct Edge{
    int from,to,next;
    Edge(int a=0,int b=0,int c=0){
        from=a,to=b,next=c;
    }
}l[maxn];
struct new_Edge{
    int to,next;
    new_Edge(int a=0,int b=0){
        to=a,next=b;
    }
}e[maxn];
int head[maxn],cnt,n,cnt_n,top,m,ind,dfn[maxn],low[maxn],in[maxn],pin[maxn];
int a[maxn],id[maxn],num,siz[maxn],new_head[maxn],sta[maxn],pma[maxn],vis[maxn];
int dp[maxn][2];
void Add(int x,int y){
    l[++cnt]=Edge(x,y,head[x]);
    head[x]=cnt;
}
void new_Add(int x,int y){
    e[++cnt_n]=new_Edge(y,new_head[x]);
    new_head[x]=cnt_n;
}
void dfs(int u){
    low[u]=dfn[u]=++ind;
    in[u]=1,sta[++top]=u;
    for (int i=head[u];i;i=l[i].next){
        int v=l[i].to;
        if (!dfn[v]) dfs(v),low[u]=min(low[u],low[v]);
        else if (in[v]) low[u]=min(low[u],low[v]);
    }
    if (low[u]==dfn[u]){
        int j=-1;num++;
        while(j!=u){
            j=sta[top--];
            id[j]=num;
            siz[num]+=a[j];
            in[j]=0;
            pma[num]=max(pma[num],a[j]);
        }
    } 
}
void tsort(){
    queue<int>q;
    for (int i=1;i<=n;i++) dp[i][0]=siz[i],dp[i][1]=pma[i];
    for (int i=1;i<=n;i++) if (!pin[i]) q.push(i);
    while(!q.empty()){
        int hq=q.front();q.pop();
        for (int i=new_head[hq];i;i=e[i].next){
            int v=e[i].to;
            if (dp[hq][0]+siz[v]>dp[v][0]){
                dp[v][0]=dp[hq][0]+siz[v];
                dp[v][1]=max(dp[hq][1],pma[v]);
            }
            if (dp[hq][0]+siz[v]==dp[v][0])
                dp[v][1]=max(dp[v][1],dp[hq][1]);
            pin[v]--;if (pin[v]<=0) q.push(v);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1,t1,t2;i<=m;i++){
        cin>>t1>>t2;Add(t1,t2);
    }
    for (int i=1;i<=n;i++)
        if (!dfn[i]) dfs(i);
    for (int i=1;i<=m;i++)
        if (id[l[i].from]!=id[l[i].to]){
            new_Add(id[l[i].from],id[l[i].to]);
            pin[id[l[i].to]]++;
        }
    int res=1;tsort();
    for (int i=2;i<=num;i++)
        if (dp[i][0]>dp[res][0]||dp[i][0]==dp[res][0]&&dp[i][1]>=dp[res][1]) res=i;
    cout<<dp[res][0]<<" "<<dp[res][1]<<endl;
    return 0;
}
