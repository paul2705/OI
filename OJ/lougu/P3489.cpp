#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<vector>
#define mp(x,y,z) (make_pair(make_pair(x,y),z))  
using namespace std;
const int INF=1e9,N=205,M=6005;
struct edge{
    int link,next,val,st;
}e[M];
int tot,head[N],n,m,p,k,S[N];
inline void add_edge(int u,int v,int w,int st){
    e[++tot]=(edge){v,head[u],w,st}; head[u]=tot;
}
inline void insert(int u,int v,int w,int st){
    add_edge(u,v,w,st);
    add_edge(v,u,w,st); 
}
inline void init(){
    scanf("%d%d%d%d",&n,&m,&p,&k);
    for (int i=1;i<=k;i++){
        int u,v,s; scanf("%d%d",&u,&s);
        for (int j=1;j<=s;j++){
            scanf("%d",&v);
            S[u]|=1<<v-1;
        }
    }
    for (int i=1;i<=m;i++){
        int u,v,w,s,st;
        scanf("%d%d%d%d",&u,&v,&w,&s);
        st=0;
        for (int j=1;j<=s;j++){
            int id;
            scanf("%d",&id);
            st|=1<<id-1; 
        }
        insert(u,v,w,st);
    }
}
int dis[N][1<<13];
bool vis[N][1<<13];
priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int> >,greater<pair<pair<int,int>,int> > >heap; 
inline int dijkstra(){
    memset(dis,127,sizeof(dis));
    dis[1][0]=0; heap.push(mp(0,1,0));
    while (!heap.empty()){
        int s=heap.top().first.first;
        int u=heap.top().first.second;
        int st=heap.top().second;
        heap.pop();
        if (u==n) return s;
        if (vis[u][st]) continue;
        vis[u][st]=1; st|=S[u];
        for (int i=head[u];i;i=e[i].next){
            int v=e[i].link;
            if ((e[i].st|st)!=st) continue;
            if (dis[v][st]>s+e[i].val){
                dis[v][st]=s+e[i].val;
                heap.push(mp(dis[v][st],v,st)); 
            }
        }
    }
    return -1;
}
inline void solve(){
    printf("%d\n",dijkstra());
}
int main(){
    init();
    solve();
    return 0;
}
