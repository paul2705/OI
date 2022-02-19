#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=500;
int a[maxn][maxn];
int F[4][maxn][maxn];
int main()
{
  int m,n;
  scanf("%d%d",&m,&n);
  for(int i=1;i<=m;i++)
    for(int j=1;j<=n;j++)
      scanf("%d",&a[i][j]);
  memset(F,-1,sizeof(F));
  F[2&1][1][1]=0;
  for(int k=3;k<m+n;k++)
    for(int i=1;i<n;i++)
      for(int j=i+1;j<=n;j++)
      {
        int s=F[k&1][i][j];
        if (F[(k-1)&1][i][j]>s) s=F[(k-1)&1][i][j];
        if (F[(k-1)&1][i-1][j]>s) s=F[(k-1)&1][i-1][j];
        if (F[(k-1)&1][i][j-1]>s) s=F[(k-1)&1][i][j-1];
        if (F[(k-1)&1][i-1][j-1]>s) s=F[(k-1)&1][i-1][j-1];
        if (s==-1) continue; 
        F[k&1][i][j]=s+a[k-i][i]+a[k-j][j];
      }
  printf("%d",F[(m+n-1)&1][n-1][n]);
  return 0;
 } 
