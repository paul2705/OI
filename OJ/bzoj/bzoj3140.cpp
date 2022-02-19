#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#define il inline
#define RG register
#define ll long long
#define pos(i,j,k) ((i-1)*b*c+(j-1)*c+k)
using namespace std;
int e[5005][5005],vis[5005],lk[5005],sz[5005],d[5005],a,b,c,cnt,ans;
il int gi(){
  RG int x=0,q=1; RG char ch=getchar();
  while ((ch<'0' || ch>'9') && ch!='-') ch=getchar();
  if (ch=='-') q=-1,ch=getchar();
  while (ch>='0' && ch<='9') x=x*10+ch-48,ch=getchar();
  return q*x;
}
il int dfs(RG int x){
  for (RG int i=1;i<=c;++i){
    if (!e[x][i] || vis[i]==cnt) continue; vis[i]=cnt;
    if (!lk[i] || dfs(lk[i])) return lk[i]=x,1;
  }
  return 0;
}
il void dfs(RG int x,RG int tot){
  if (x>a){
    for (RG int i=1;i<=c;++i) vis[i]=lk[i]=0; cnt=0;
    for (RG int i=1;i<=b;++i) ++cnt,tot+=dfs(i);
    ans=min(ans,tot); return;
  }
  if (tot>=ans) return;
  for (RG int i=1;i<=b;++i)
    for (RG int j=1;j<=c;++j) e[i][j]+=d[pos(x,i,j)];
  dfs(x+1,tot);
  for (RG int i=1;i<=b;++i)
    for (RG int j=1;j<=c;++j) e[i][j]-=d[pos(x,i,j)];
  if (sz[x]) dfs(x+1,tot+1); return;
}
il void work(){
  a=gi(),b=gi(),c=gi(),memset(d,0,sizeof(d)),memset(sz,0,sizeof(sz));
  if (a<=b && a<=c){
    for (RG int i=1;i<=a;++i)
      for (RG int j=1;j<=b;++j)
        for (RG int k=1;k<=c;++k) d[pos(i,j,k)]=gi();
  } 
  else if (b<=a && b<=c){
    swap(a,b);
    for (RG int i=1;i<=b;++i)
      for (RG int j=1;j<=a;++j)
        for (RG int k=1;k<=c;++k) d[pos(j,i,k)]=gi();
  } 
  else{
    swap(a,c);
    for (RG int i=1;i<=c;++i)
      for (RG int j=1;j<=b;++j)
        for (RG int k=1;k<=a;++k) d[pos(k,j,i)]=gi();
  }
  for (RG int i=1;i<=a;++i)
    for (RG int j=1;j<=b;++j)
      for (RG int k=1;k<=c;++k) sz[i]+=d[pos(i,j,k)];
  ans=1<<30,dfs(1,0),printf("%d\n",ans); return;
}
int main(){
#ifndef ONLINE_JUDGE
  freopen("clear.in","r",stdin);
  freopen("clear.out","w",stdout);
#endif
  RG int T=gi();
  while (T--) work();
  return 0;
}
