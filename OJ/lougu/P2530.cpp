#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n,a[101],f[101][11][11][11];
int dfs(int g[4],int x){
    if(f[x][g[1]][g[2]][g[3]]!=0) return f[x][g[1]][g[2]][g[3]];
    if(g[1]==0&&g[2]==0&&g[3]==0) return 0;
    int num=100000000;
    for(int i=1;i<=3;i++)
        if(g[i]!=0){
            int t1=g[1],t2=g[2],t3=g[3],j,t=g[i];
            g[i]=0;
            for(j=x;j<=x+t-1&&j<=n;j++) g[a[j]]++;
            num=min(num,dfs(g,j));
            g[1]=t1,g[2]=t2,g[3]=t3;
        }
    num++;
    f[x][g[1]][g[2]][g[3]]=num;
    return num;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        char j;
        cin>>j;
        switch(j){
            case 'A': a[i]=1;break;
            case 'B': a[i]=2;break;
            case 'C': a[i]=3;break;
        }
    }
    int g[4]={0},i;
    for(i=1;i<=10&&i<=n;i++) g[a[i]]++;
    cout<<dfs(g,i)<<endl;
    return 0;
}
