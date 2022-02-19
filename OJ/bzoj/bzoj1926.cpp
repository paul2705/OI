#include<iostream>
#include<cstdio>
#include<cstring>
#define N 210
#define M 1010
#define C 500005
using namespace std;
int f[N][N][M],s[N][N][M];
int n,m,x1,y1,x2,y2,h,q,v[M],a[N][N];
int c[C],ls[C*20],rs[C*20],sum[C*20],size[C*20],root[C],sz;
void insert(int x,int l,int r,int &y,int p){
  y=++sz;size[y]=size[x]+1;sum[y]=sum[x]+p;
  ls[y]=ls[x];rs[y]=rs[x];
  if (l==r) return;
  int mid=(l+r)>>1;
  if (p<=mid) insert(ls[x],l,mid,ls[y],p);
  else insert(rs[x],mid+1,r,rs[y],p);
}
int query1(int x,int l,int r,int y,int ll,int rr){
  if (l==ll&&r==rr)return sum[y]-sum[x];
  int mid=(l+r)>>1;
  if (rr<=mid) return query1(ls[x],l,mid,ls[y],ll,rr);
  else if (ll>mid) return query1(rs[x],mid+1,r,rs[y],ll,rr);
  else return query1(ls[x],l,mid,ls[y],ll,mid)+query1(rs[x],mid+1,r,rs[y],mid+1,rr);
}
int query2(int x,int l,int r,int y,int ll,int rr){
  if (l==ll&&r==rr)return size[y]-size[x];
  int mid=(l+r)>>1;
  if (rr<=mid) return query2(ls[x],l,mid,ls[y],ll,rr);
  else if (ll>mid) return query2(rs[x],mid+1,r,rs[y],ll,rr);
  else return query2(ls[x],l,mid,ls[y],ll,mid)+query2(rs[x],mid+1,r,rs[y],mid+1,rr);
}
int cal(int k,int x1,int y1,int x2,int y2){
  return f[x2][y2][k]-f[x1-1][y2][k]-f[x2][y1-1][k]+f[x1-1][y1-1][k];
}
int get(int k,int x1,int y1,int x2,int y2){
  return s[x2][y2][k]-s[x1-1][y2][k]-s[x2][y1-1][k]+s[x1-1][y1-1][k];
}
void pre(){
  for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++)
      scanf("%d",&a[i][j]),v[a[i][j]]++;
  for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++){
	  for (int k=1;k<=1000;k++)
	    s[i][j][k]=s[i][j-1][k]+s[i-1][j][k]-s[i-1][j-1][k];
      s[i][j][a[i][j]]++;
    }	
  for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++)
      for (int k=1000;k>=1;k--){
        f[i][j][k]=f[i][j][k+1]+k*s[i][j][k];
        s[i][j][k]+=s[i][j][k+1];
	  }
}
int main(){
  scanf("%d%d%d",&n,&m,&q);
  if (n<=200&&m<=200){
  	pre();
    while (q--){
      scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&h);
	  int l=1,r=1000,num=0,t=-1;
	  while (l<=r){
	    int mid=(l+r)>>1;
	    int temp=cal(mid,x1,y1,x2,y2);
	    if (temp>=h){num=temp;t=mid;l=mid+1;}
	    else r=mid-1;
	  }
	  if (t==-1){printf("Poor QLW\n");continue;}
	  int tot=get(t,x1,y1,x2,y2),p=v[t];
	  while (p&&num-t>=h){p--;num-=t;tot--;}
	  printf("%d\n",tot); 
    }
  }
  else{
    n=m;
    for (int i=1;i<=n;i++) scanf("%d",&c[i]),v[c[i]]++;
    for (int i=1;i<=n;i++) insert(root[i-1],1,1000,root[i],c[i]); 
    while (q--){
      scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&h);
      x1=y1;x2=y2;
      int l=1,r=1000,t=-1,num(0);
      while (l<=r){
        int mid=(l+r)>>1;
		int temp=query1(root[x1-1],1,1000,root[x2],mid,1000);
		if (temp>=h){t=mid;num=temp;l=mid+1;}
		else r=mid-1; 
      }
      if (t==-1){printf("Poor QLW\n");continue;}
	  int tot=query2(root[x1-1],1,1000,root[x2],t,1000),p=v[t];
	  while (p&&num-t>=h){p--;num-=t;tot--;}
	  printf("%d\n",tot); 
    }
  }
}
