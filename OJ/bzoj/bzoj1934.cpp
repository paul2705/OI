#include<vector>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define rep(i,n) for(int i=0;i<n;++i)
#define F(i,j,n) for(int i=j;i<=n;++i)
#define D(i,j,n) for(int i=j;i>=n;--i)
#define pb push_back
using namespace std;
inline int getint(){
    int v=0,sign=1; char ch=getchar();
    while(ch<'0'||ch>'9'){ if (ch=='-') sign=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){ v=v*10+ch-'0'; ch=getchar();}
    return v*sign;
}
const int N=320,M=200000,INF=~0u>>2;
typedef long long LL;
int n,m;
struct edge{
    int from,to,v;
};
inline int pack(int i,int j){return (i-1)*m+j;}
struct Net{
    edge E[M];
    int head[N],next[M],cnt;
    void add(int x,int y,int v){
        E[++cnt]=(edge){x,y,v};
        next[cnt]=head[x]; head[x]=cnt;
        E[++cnt]=(edge){y,x,0};
        next[cnt]=head[y]; head[y]=cnt;
    }
    int s,t,cur[N],d[N],Q[N];
    void init(){
        n=getint();m=getint();
        cnt=1;
        s=0; t=n+1;
        F(i,1,n)
            if (getint()) add(s,i,1);
            else add(i,t,1);
        int x,y;
        F(i,1,m){
            x=getint(); y=getint();
            add(x,y,1);
            add(y,x,1);
        }
    }
    bool mklevel(){
        memset(d,-1,sizeof d);
        d[s]=0;
        int l=0,r=-1;
        Q[++r]=s;
        while(l<=r){
            int x=Q[l++];
            for(int i=head[x];i;i=next[i])
                if (d[E[i].to]==-1 && E[i].v){
                    d[E[i].to]=d[x]+1;
                    Q[++r]=E[i].to;
                }
        }
        return d[t]!=-1;
    }
    int dfs(int x,int a){
        if (x==t||a==0) return a;
        int flow=0;
        for(int &i=cur[x];i && flow<a;i=next[i])
            if (d[E[i].to]==d[x]+1 && E[i].v){
                int f=dfs(E[i].to,min(a-flow,E[i].v));
                E[i].v-=f;
                E[i^1].v+=f;
                flow+=f;
            }
        if (!flow) d[x]=-1;
        return flow;
    }
    int Dinic(){
        int flow=0;
        while(mklevel()){
            F(i,s,t) cur[i]=head[i];
            flow+=dfs(s,INF);
        }
        return flow;
    }
}G1;
int main(){
    G1.init();
    printf("%d\n",G1.Dinic());
    return 0;
}
