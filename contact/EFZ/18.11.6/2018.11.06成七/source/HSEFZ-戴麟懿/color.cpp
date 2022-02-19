#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, st, ed) for(register int i = (st); i <= (ed); ++i)
#define per(i, st, ed) for(register int i = (st); i >= (ed); --i)

const int maxn = 1e5+5;
struct graph{
    int v, nxt;
}edges[maxn*2];
int head[maxn];
void link(int u, int v){
    static int cnt = 0;
    edges[++cnt].v = v;
    edges[cnt].nxt = head[u];
    head[u] = cnt;
}
int a[maxn], b[maxn], p[maxn];
int dep[maxn]; 
void dfs(int u, int fa){
    dep[u] = dep[fa]+1;
    for(int e = head[u]; e; e = edges[e].nxt){
        int v = edges[e].v;
        if(v == fa) continue;
        dfs(v, u);
    }
}
queue<int> q;
bool vis[505];
void bfs(int src){
    memset(vis, 0, sizeof vis);
    q.push(src);   
    while(!q.empty()){
        int u = q.front(), v; q.pop();
        for(int e = head[u]; e; e =edges[e].nxt){
            v = edges[e].v;
            if(!vis[v]){
                vis[v] = 1;
                q.push(v);
                u = 0;
        }
    }
}
signed main(){
    scanf("%d%d", &n, &m);
    rep(i, 1, n) scanf("%d", p+i);
    rep(i, 1, n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        link(u, v), link(v, u);
    }
    dfs(1, 0);
    
    rep(i, 1, m){
        int mxdep = 0, mxp = 0;
        rep(j, 1, n) {
            if(p[j] == i && dep[j] < mxdep){
                mxdep = dep[j];
                mxp = j;
            }
        }
        if(mxp == 0) continue;
        cnt = 0;
        bfs(mxp);
        int mxdis = 0; mxp = 0;
        rep(j, 1, cnt) { 
            if(dis[val[j]] < mxdis){
                mxdis = dis[val[j]];
            }
        }
        //get mxdis
    }
    return 0;
}
