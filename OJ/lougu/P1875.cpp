#include <iostream>
#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
int cost[9999],ans[9999];
int soc[3000][3000],n;
bool f[3000];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
      scanf("%d",&cost[i]),ans[i]=1;
    int a,b,c; 
    while(scanf("%d%d%d",&a,&b,&c)!=EOF) 
      soc[a+1][b+1]=soc[b+1][a+1]=c+1;
    for(int i=1;i<n;i++){
        int maxn=0x7fffffff;
        for(int j=1;j<=n;j++)
          if(!f[j]&&cost[j]<maxn) 
            b=j,maxn=cost[j];
        f[b]=1;
        for(int j=1;j<=n;j++)
          if(f[j]&&soc[b][j]){
            if(cost[b]+cost[j]==cost[soc[b][j]])
              ans[soc[b][j]]+=ans[b]*ans[j];
            if(cost[b]+cost[j]<cost[soc[b][j]]) 
              cost[soc[b][j]]=cost[b]+cost[j],ans[soc[b][j]]=ans[b]*ans[j];
         }
     }
     printf("%d %d\n",cost[1],ans[1]);
     return 0;
}
