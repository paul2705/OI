#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct ding{
    int x,y;
}p[600];
struct bian{
    int to,next;
}edge[300000];
ding f2[600],f[600];
int n,h[5]={0,-1,1,0,0},l[5]={0,0,0,1,-1};
int indx[50000];
int num=0,cnt=0,head[10000],dis[10000];
bool vis[10000];
bool check3(int x1,int y1,int x2,int y2,int x3,int y3){
  if (x2==x3) return ((x1==x2)&&(y1>min(y2,y3))&&(y1<max(y2,y3)));
  else return ((y1==y2)&&(x1>min(x2,x3))&&(x1<max(x2,x3)));
}
bool check2(ding tot,int a,int b){
  bool fg=true;
  for (int i=1;i<=n;i++) if ((tot.x==f[i].x)&&(tot.y==f[i].y)) {fg=false;break;}
  fg=fg||(f2[a].x==f2[b].x)||(f2[a].y==f2[b].y);
  for (int i=1;i<=n;i++)
  if (check3(f[i].x,f[i].y,f2[a].x,f2[a].y,tot.x,tot.y)||check3(f[i].x,f[i].y,f2[b].x,f2[b].y,tot.x,tot.y)) {fg=false; break;} 
  if (fg) return true;
  return false;
}
bool check1(int a,int b){
  ding tot; tot.x=f2[a].x; tot.y=f2[b].y; 
  if (check2(tot,a,b)) return true;
  tot.x=f2[b].x; tot.y=f2[a].y; 
  if (check2(tot,a,b)) return true;
  return false;
}
void add(int u,int v){
  edge[++num].to=v;
  edge[num].next=head[u];
  head[u]=num;
}
int calc(int a,int b){return (abs(f2[a].x-f2[b].x)+abs(f2[a].y-f2[b].y));} 
int dijkstra(int a,int b){
  for (int i=1;i<=cnt;i++) {dis[i]=2100000000; vis[i]=false;}
  for (int i=1;i<=n;i++) if ((indx[i]!=b)&&(indx[i]!=a)) vis[indx[i]]=true;
  dis[a]=0;
  for (int i=1;i<=cnt;i++){
      int now=1;
      for (int j=1;j<=cnt;j++) if (((dis[j]<dis[now])||(vis[now]))&&(!vis[j])) now=j;
      if ((vis[now])||(dis[now]==2100000000)) return -1;
      if (now==b) return dis[b];
      vis[now]=true;
      for (int j=head[now];j;j=edge[j].next){
        int y1=edge[j].to;
      if (!vis[y1]) dis[y1]=min(dis[y1],dis[now]+calc(now,y1));
    }
  }
  return -1;
}
int main(){
  scanf("%d",&n);
  for (int i=1;i<=n;i++) {
    scanf("%d%d",&p[i].x,&p[i].y);
    ding tot; tot.x=p[i].x; tot.y=p[i].y;
    f[i]=tot;
  }
  for (int i=1;i<=n;i++){
    f2[++cnt]=f[i]; indx[i]=cnt;
    for (int j=1;j<=4;j++){
     bool fg=true; 
     ding tot;tot.x=p[i].x+h[j]; tot.y=p[i].y+l[j];
     for (int k=1;k<=n;k++) if ((tot.x==f[k].x)&&(tot.y==f[k].y)) {fg=false;break;}
     if (fg) f2[++cnt]=tot;
    }
  } 
  for (int i=1;i<=cnt;i++)
   for (int j=i+1;j<=cnt;j++)
    if (check1(i,j)) {add(i,j);add(j,i);}
  int ans=0;
  for (int i=1;i<=n;i++){
      int sum=0;
      if (i!=n) sum=dijkstra(indx[i],indx[i+1]);
      else sum=dijkstra(indx[i],indx[1]); 
      if (sum==-1) {cout<<"-1"<<endl; return 0;}
      else ans+=sum;
  }
  printf("%d\n",ans);
  return 0;
}
