#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int MAXN=1010;
int n,m,p;
int res=0;
int nzd[MAXN],mzd[MAXN];
bool used[MAXN*MAXN];

bool check(){
  int total=0;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(nzd[i]==mzd[j]){
	total++;
      }
    }
  }
  if(total==1){
    return true;
  }
  return false;
}

void dfs(int np,int mp){
  if(np==n+1){
    if(check()){
      res++;
      res%=p;
    }
  }
  for(int i=1;i<=n*m;i++){
    if(!used[i]){
      int ccnzd=nzd[np],ccmzd=mzd[mp];
      used[i]=true;
      nzd[np]=max(nzd[np],i);
      mzd[mp]=max(mzd[mp],i);
      if(mp==m){
	dfs(np+1,1);
      }
      else{
	dfs(np,mp+1);
      }
      used[i]=false;
      nzd[np]=ccnzd;
      mzd[mp]=ccmzd;
    }
  }
}

int main(){
  freopen("count.in","r",stdin);
  freopen("count.out","w",stdout);
  scanf("%d %d %d",&n,&m,&p);
  for(int i=1;i<=n;i++){
    nzd[i]=0;
  }
  for(int i=1;i<=m;i++){
    mzd[i]=0;
  }
  dfs(1,1);
  printf("%d",res);
  return 0;
}
