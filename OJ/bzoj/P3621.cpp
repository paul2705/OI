#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
#define ll long long
#define inf 0x7f7f7f7f
using namespace std; 
int n,l[100005],r[100005],ans,minn=inf,maxx; 
void dfs(int u,int dep){
    if(u==-1){
        maxx=max(maxx,dep);
        minn=min(minn,dep);
        return;
    }
    dfs(l[u],dep+1);dfs(r[u],dep+1);
    return;
}
int work(int u,int dep){
    int x=0,y=0;
    if(u==-1){
        if(dep==minn) return 1;
        return 2;
    }
    x=work(l[u],dep+1),y=work(r[u],dep+1);
    if((x==1 && y==2) || (x==1 && y==3) || (x==3 && y==2)) ans++;  
    if(x==3 && y==3){puts("-1");exit(0);}  
    return (x|y); 
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d",&l[i],&r[i]);
    dfs(1,0);
    if(maxx-minn>1) return puts("-1"),0;
    if(maxx==minn) return puts("0"),0;
    work(1,0);
    printf("%d\n",ans);
    return 0;
}
