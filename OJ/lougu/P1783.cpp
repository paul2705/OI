#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
const int maxn=805;
int n,w;
struct edge{
   int u,v;
   float c;
}e[maxn*maxn];
int x[maxn],y[maxn],W;
int f[maxn];
float getdist(int i,int j){
  return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}
bool cmp(edge e1,edge e2){
  return e1.c<e2.c;
}
int getfather(int root){
  if(f[root]==-1)return root;
  else return f[root]=getfather(f[root]);
}
void init(){
     memset(f,-1,sizeof(f));
     n=0;w=0;
     scanf("%d%d",&W,&n);
     if(n==0)exit(0);
     int i,j;
     for(i=1;i<=n;i++)
       scanf("%d%d",y+i,x+i);
     for(i=1;i<n;i++)
       for(j=i+1;j<=n;j++)
         e[++w]=(edge){i,j,getdist(i,j)/2};
     for(i=1;i<=n;i++){
         e[++w]=(edge){i,0,y[i]};
         e[++w]=(edge){i,n+1,W-y[i]};
     }
     sort(e+1,e+w+1,cmp);
}
void work(){
     int i=0,p,q;
     while(getfather(0)!=getfather(n+1)){
       i++;
       p=getfather(e[i].u);
       q=getfather(e[i].v);
       if(p!=q)f[p]=q;
     }
     printf("%.2f\n",e[i].c);
}
int main(){
    init();
    work();
    return 0;
}
