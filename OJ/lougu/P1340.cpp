#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=205,M=6005;
int n,w,Enum,H[M<<1],fa[N];
long long Ans[M];
bool use[M<<1],cannot[M<<1];
struct Edge{
    int fr,to,nxt,val,id;
    bool operator <(const Edge &a)const {
        return val<a.val;
    }
}e[M<<1];
int read(){
    int now=0;bool f=false;char c=getchar();
    while(c>'9'||c<'0'){
        if(c=='-')f=1;
        c=getchar();
    }
    while(c>='0'&&c<='9')now=(now<<3)+(now<<1)+c-'0',c=getchar();
    return f?-now:now;
}
void AddEdge(int u,int v,int w){
    e[++Enum].to = v;
    e[Enum].fr = u;
    e[Enum].nxt = H[u];
    e[Enum].val = w;
    H[u] = Enum;
}
int Find(int x){
    return x==fa[x]?x:fa[x]=Find(fa[x]);
}
long long Kruskal(){
    memset(use,0,sizeof use);
    for(int i=1;i<=n;i++) fa[i]=i;
    int k=0;
    long long tot=0;
    for(int i=1;i<=Enum;i++){
        if(cannot[e[i].id]) continue;
        int r1=Find(e[i].fr),r2=Find(e[i].to);
        if(r1!=r2){
            ++k;tot+=e[i].val;
            use[e[i].id]=1;//printf("use:%d\n",e[i].id);
            fa[r1]=r2;
        }
        if(k==n-1) break;
    }
    return k==n-1?tot:-1;
}
int main(){
    n=read(),w=read();
    for(int a,b,c,i=1;i<=w;i++) a=read(),b=read(),c=read(),AddEdge(a,b,c),e[i].id=i;
    sort(e+1,e+Enum+1);
    Ans[w]=Kruskal();
    for(int i=w-1;i;i--){
        cannot[i+1]=1;
        if(use[i+1]) Ans[i]=Kruskal();
        else Ans[i]=Ans[i+1];
        if(Ans[i]==-1){
            for(int j=1;j<i;j++) Ans[j]=-1;
            break;
        }
    }
    for(int i=1;i<=w;i++) printf("%lld\n",Ans[i]);
    return 0;
}
