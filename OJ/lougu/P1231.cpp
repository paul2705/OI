#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int la[200002],en[2000001],rev[2000001],c[2000001],ne[2000001];
int q[200003],level[200002],now[200002];
int n,n1,n2,n3,m1,m2,top;
void bfs(int s){
    memset(level,-1,sizeof(level));
    memset(q,0,sizeof(q));
    int h=0,t=1;
    q[1]=s;
    level[s]=0;
    while (h<t)
      for (int i=la[q[++h]];i;i=ne[i])
        if (c[i]>0&&level[en[i]]<0){
            level[en[i]]=level[q[h]]+1;
            q[++t]=en[i];
        }
}
int dfs(int u,int t,int f){
    if (u==t) return f;
    for (int &i=now[u];i>0;i=ne[i])
      if (c[i]>0&&level[u]<level[en[i]]){
          int d=dfs(en[i],t,min(f,c[i]));
          if (d>0){
              c[i]-=d;
              c[rev[i]]+=d;
              return d;
          }
      }
    return 0;
}
int max_flow(int s,int t){
    int flow=0;
    while (1){
        bfs(s);
        if (level[t]<0) return flow;
        for (int i=0;i<=n+n1;i++) now[i]=la[i];
        int f;
        while ((f=dfs(s,t,1000000000))>0) flow+=f; 
    }
}
void add(int x,int y,int z){
    ne[++top]=la[x];
    en[top]=y;
    c[top]=z;
    rev[top]=top+1;
    la[x]=top;
    ne[++top]=la[y];
    en[top]=x;
    c[top]=0;
    rev[top]=top-1;
    la[y]=top;
}
int main(){
    scanf("%d%d%d",&n1,&n2,&n3);
    n=n1+n2+n3;
    scanf("%d",&m1);
    for (int i=1;i<=m1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        add(b+n1,a,1);
    }
    scanf("%d",&m2);
    for (int i=1;i<=m2;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        add(a+n,b+n1+n2,1);
    }
    for (int i=1;i<=n1;i++) add(i,i+n,1);
    for (int i=1;i<=n2;i++) add(0,i+n1,1);
    for (int i=1;i<=n3;i++) add(i+n1+n2,n+n1+1,1);
    int ans=max_flow(0,n+n1+1);
    printf("%d",ans);
    return 0;
}
