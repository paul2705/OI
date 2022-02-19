#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn=7000+50;
struct edge{int to;double v,p;double w;};
int n,m;
double l=0,r=500,mid,d[maxn],used[maxn];
vector<edge>G[maxn];
inline int read(){
    char ch=getchar();int data=0;
    while(ch<'0' || ch>'9') ch=getchar();
    do{
        data=data*10+ch-'0';
        ch=getchar();
    }while(ch>='0' && ch<='9');
    return data;
}
inline void add_edge(int x,int y,int v,int p){
    edge e;
    e.to=y;e.v=(double)v;e.p=(double)p;
    G[x].push_back(e);
    return;
}
void init(){
    n=read();m=read();
    for(int i=1;i<=m;i++){
        int x,y;double p,v;
        x=read();y=read();
        scanf("%lf%lf",&v,&p);
        add_edge(x,y,v,p);
    }
    for(int i=1;i<=n;i++) add_edge(0,i,0,0);
    return;
}
void adjust(double now){
    for(int x=1;x<=n;x++)
        for(int y=0;y<G[x].size();y++)
            G[x][y].w=now*G[x][y].p-G[x][y].v;
    return;
}
bool spfa(int x){
    used[x]=true;
    for(int i=0;i<G[x].size();i++){
        double temp=d[x]+G[x][i].w;
        int y=G[x][i].to;
        if(d[y]>temp){
            d[y]=temp;
            if(!used[y]){
                if(spfa(y)) return true;
            }
            else return true;
        }
    }
    used[x]=false;
    return false;
}
bool check(double now){
    for(int i=1;i<=n;i++){
        used[i]=false;
        d[i]=1234567890;
    }
    d[0]=0;
    adjust(now);
    if(spfa(0)) return true;
    return false;
}
void solve(){
    while(r-l>0.01){
        mid=(l+r)/2;
        if(check(mid)) l=mid;
        else r=mid;
    }
    if(l==0)printf("-1\n");
    else printf("%.1lf\n",r);
    return;
}
int main(){
    init();
    solve();
    return 0;
}
