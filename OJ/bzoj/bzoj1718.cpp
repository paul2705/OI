// 桥（无向图） 断到以后 图不再联通
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5e3+5;
const int MAXM=2e4+5;
int edge=1,head[MAXN],from[MAXM],tail[MAXM],nex[MAXM];
int n,m,low[MAXN],dfn[MAXN],cnt;
int fa[MAXN],mx,ans;
int ind[MAXN];
void add(int u,int v){
    edge++,nex[edge]=head[u],head[u]=edge,from[edge]=u,tail[edge]=v;
}
int find(int x){ return fa[x]==x?x:fa[x]=find(fa[x]); }
void uion(int x,int y){ fa[find(x)]=find(y); }
void dfs(int u,int pe){
    dfn[u]=low[u]=++cnt;
    for (int e=head[u];e;e=nex[e]){
        int v=tail[e];
        if ((e^1)!=pe){
            if (dfn[v]==0){ dfs(v,e); low[u]=min(low[u],low[v]); }
            else low[u]=min(low[u],dfn[v]);
        }
//	cout<<u<<" "<<low[u]<<" "<<dfn[u]<<endl;
        if (low[u]<dfn[u]){
            int f=from[pe];
//            cout<<f<<" "<<u<<endl;
		uion(f,u);
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) fa[i]=i;
    for (int i=1,u,v;i<=m;i++){
        scanf("%d%d",&u,&v);
        add(u,v); add(v,u);
    }
    dfs(1,0);
    for (int e=2;e<=edge;e++){
        int u=from[e],v=tail[e];
        int fu=find(u),fv=find(v);
        mx=max(mx,max(fu,fv));
//	cout<<u<<" "<<fu<<" "<<ind[fu]<<endl;
//	cout<<v<<" "<<fv<<" "<<ind[fv]<<endl;
        if (fu!=fv) ind[fv]++;
    }
    for (int i=1;i<=mx;i++){
//	cout<<i<<" "<<ind[i]<<endl;
        if (ind[i]==1) ans++;
    }
//    cout<<ans<<endl;
    if (ans%2==0) printf("%d\n",ans/2);
    else printf("%d\n",ans/2+1);
    return 0;
}
