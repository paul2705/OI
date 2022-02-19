#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int n,m,Cnt,Flag,Ans;
int Head[1005],Dis[1005],Cut[1005][1005],f[1005],Inq[1005];
struct Node{
    int to,Next,w;
}e[1000005];
inline void Insert(int u,int v,int w){
    e[++Cnt].to = v;
    e[Cnt].Next = Head[u];
    Head[u] = Cnt;
    e[Cnt].w = w;
}
inline void Spfa(){
    queue<int> q;
    memset(Inq,0,sizeof(Inq));
    memset(Dis,INF,sizeof(Dis));
    q.push(1);
    Dis[1] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        Inq[u] = 0;
        for(int i=Head[u];i;i=e[i].Next){
            if(Cut[u][e[i].to] == 0 && Dis[e[i].to] > Dis[u] + e[i].w){
                if(!Flag)f[e[i].to] = u;
                Dis[e[i].to] = Dis[u] + e[i].w; 
                if(!Inq[e[i].to]){
                    Inq[e[i].to] = 1;
                    q.push(e[i].to);
                }
            }
        }
    }
}
inline int Read(){
    int Out = 0,f = 1;char ch = getchar();
    while(!isdigit(ch)){if(ch == '-')f = -1;ch = getchar();}
    while(isdigit(ch)){Out = Out * 10 + ch - '0';ch = getchar();}
    return Out * f;
}
int main(){
    n = Read();
    m = Read();
    for(int i=1;i<=m;i++){
        int u = Read(),v = Read(),w = Read();
        Insert(u,v,w);
        Insert(v,u,w);
    }
    Spfa();
    Flag = 1;
    for(int i=n;i!=1;i=f[i]){
        Cut[f[i]][i] = 1;
        Cut[i][f[i]] = 1;
        Spfa();
        Cut[f[i]][i] = 0;
        Cut[i][f[i]] = 0;
        Ans = Ans > Dis[n] ? Ans:Dis[n];
    }
    printf("%d\n",Ans);
    return 0;
}
