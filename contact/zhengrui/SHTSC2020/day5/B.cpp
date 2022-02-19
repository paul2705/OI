#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<deque>
using namespace std;
typedef long long ll;
const int maxn=5500000;
int head[maxn],cnt,n,m;
int prime[]={(int)1e9+7,(int)1e9+9,998244353,19260817};
ll has[maxn][4];
struct gg {
    int u,v,ty,next;
}side[maxn*2];
deque<int>q;
inline void get_hash(int x,int ori,int ty) {//ty=1 *2
    for(int i=0;i<1;i++) {
        if(ty)has[x][i]=(has[ori][i]*2);
        else has[x][i]=(has[ori][i]+1);
        if(has[x][i]>=prime[i])has[x][i]-=prime[i];
    }
}
inline bool check_equ(int u,int v) {
    for(int i=0;i<1;i++)if(has[u][i]!=has[v][i])return 0;
    return 1;
}
inline void insert(int u,int v,int ty) {
    side[++cnt]=(gg){u,v,ty,head[u]};head[u]=cnt;
}
void debug() {
    int sz=q.size();cout<<">>";
    for(int i=1;i<=sz;i++)cout<<q.front()<<' ',q.push_back(q.front()),q.pop_front();
    cout<<endl;
}
int sta[maxn],stk[maxn],top;
int main() {
    scanf("%d%d",&n,&m);
    for(int j=1;j<=m;j++) {
        int k,ty,xk,xb,xm,xl,yk,yb,ym,yl;
        scanf("%d%d%d%d%d%d%d%d%d%d",&k,&ty,&xk,&xb,&xm,&xl,&yk,&yb,&ym,&yl);
        for(int i=0,u,v;i<k;i++) {
            u=(1ll*xk*i+xb)%xm+xl;v=(1ll*yk*i+yb)%ym+yl;
            insert(u,v,ty);insert(v,u,ty);
            // cout<<u<<' '<<v<<' '<<ty<<endl;
        }
    }
    q.push_back(1);sta[1]=3;has[1][0]=has[1][1]=has[1][2]=has[1][3]=1;
    while(!q.empty()) {
        // debug();
        while(!q.empty()&&sta[q.front()]==3&&q.front()!=1)q.pop_front();
        if(q.empty())break;
        top=0;sta[q.front()]=3;
        stk[++top]=q.front();q.pop_front();
        while(!q.empty()&&(check_equ(q.front(),stk[top])||sta[q.front()]==3)){if(sta[q.front()]==3){q.pop_front();continue;}sta[q.front()]=3,stk[++top]=q.front(),q.pop_front();}
        for(int i=1,x;i<=top;i++) {
            x=stk[i];
            for(int j=head[x];j;j=side[j].next) {
                int v=side[j].v,ty=side[j].ty;
                if(sta[v]==3)continue;
                if(ty) {
                    if(sta[v])continue;
                    sta[v]=1;
                    get_hash(v,x,1);q.push_back(v);
                }else {
                    if(sta[v]==2)continue;
                    sta[v]=2;
                    get_hash(v,x,0);q.push_front(v);
                }
                // debug();
            }
            // debug();
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++) {
        if(sta[i])ans^=(has[i][0]);//cout<<">>"<<i<<' '<<has[i][0]<<endl;
    }
    printf("%lld",ans);
    return 0;
    //cout<<"6 5"<<endl;
    //for(int i=1;i<=5;i++)cout<<"1 "<<Rnd()%2<<' '<<Rnd()%n+1<<' '<<Rnd()%n+1<<' '<<Rnd()%n+1<<' '<<" 0 "<<Rnd()%n+1<<' '<<Rnd()%n+1<<' '<<Rnd()%n+1<<' '<<" 0"<<endl;
}
