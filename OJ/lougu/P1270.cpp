#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1001
using namespace std;
int n,cnt,tot;
int f[maxn][maxn];
void dfs(){
    int root=++cnt,limit,time;
    scanf("%d%d",&limit,&tot);
    limit<<=1;
    if(tot){
        for(int time=limit;time<=n;time++)
          f[root][time]=min((time-limit)/5,tot); 
    }
    else{
        int left=cnt+1,right; dfs();
        right=cnt+1; dfs();
        for(int time=limit;time<=n;time++)
          for(int lctime=0;lctime<=time-limit;lctime++){
              f[root][time]=max(f[root][time],f[left][lctime]+f[right][time-limit-lctime]);
          }
    }
}
int main(){
    scanf("%d",&n);n--;
    dfs();
    printf("%d\n",f[1][n]);
    return 0;
}
