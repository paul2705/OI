#include<iostream>
#include<cstdio>
using namespace std;
int v,i,m,n,j,k,a[125][125];
int f[4]={0,1,0,-1},g[4]={1,0,-1,0};
char c;
void search(int x,int y,int t,int bs){
    if(bs>k) k=bs; 
    if(a[x+f[t]][y+g[t]]==1) { 
        a[x][y]=2;
        search(x+f[t],y+g[t],t,bs+1);
        a[x][y]=1; 
    }
    else if(a[x+f[t]][y+g[t]]==0)
        for(int i=0;i<4;i++)
            if((a[x+f[i]][y+g[i]]==1)&&((i+t)%2!=0)){ 
                a[x][y]=2;  
                search(x+f[i],y+g[i],i,bs+1);
                a[x][y]=1;
            } 
}
int main(){
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++){
        cin>>c>>v;
        a[c-'A'+1][v]=1;
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++){
            if(a[i][j]==1) a[i][j]=0;
            else a[i][j]=1;
        }
    search(1,1,0,1);
    search(1,1,1,1);
    printf("%d",k);
}
