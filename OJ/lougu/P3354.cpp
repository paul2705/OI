#include<cstring> 
#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;
int son[105],bro[105];
int w[105],v[105],d[105],dis[105][105];
int n,i,k,f[105][105][105];
void dfs(int u,int liml){
 int s=son[u];
 int b=bro[u];
 for(int l=1; l<=liml; l++)
   dis[u][l]=dis[v[u]][l-1]+d[u];
 if(s!=0) dfs(s,liml+1);
 if(b!=0) dfs(b,liml);
 for(int i=0; i<=n; i++)
  for(int j=0; j<=n-i; j++)
   for(int l=1; l<=liml; l++){
    f[u][i+j][l]=min(f[u][i+j][l],f[s][i][l+1]+f[b][j][l]+w[u]*dis[u][l]); 
    f[u][i+j+1][l]=min(f[u][i+j+1][l],f[s][i][1]+f[b][j][l]);
   }
}
int main(){
 cin>>n>>k;
 for(int i=1; i<=n; i++){
  cin>>w[i]>>v[i]>>d[i];
  bro[i]=son[v[i]];
  son[v[i]]=i;
 }
 memset(f,0x7f,sizeof(f));
 for (int i = 0; i <= n; i++) 
   for (int j = 0; j <= n; j++)
     f[0][i][j] = 0;
 dfs(son[0],1);
 cout<<f[son[0]][k][1]<<endl; 
 return 0;
}
