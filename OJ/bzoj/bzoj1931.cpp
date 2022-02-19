#include<cstdio>
typedef long long ll;
const int N=70,B=10000,MAXL=30;
int n,i,j,a[N],b[N],v[N],fun;
inline int max(int a,int b){return a>b?a:b;}
struct Num{
  int a[MAXL],len,fu;
  Num(){len=1,fu=a[1]=0;}
  Num operator+(Num b){
    Num c;
    c.len=max(len,b.len)+2;
    int i;
    for (i=1;i<=c.len;i++)c.a[i]=0;
    if (fu==b.fu){
      for (i=1;i<=len;i++) c.a[i]=a[i];
      for (i=1;i<=b.len;i++) c.a[i]+=b.a[i];
      for (i=1;i<=c.len;i++)
		  if (c.a[i]>=B)
			  c.a[i+1]++,c.a[i]-=B;
      while (c.len>1&&!c.a[c.len]) c.len--;
      c.fu=fu;
    }else{
      bool flag=0;
      if(len==b.len){
        for (i=len;i;i--)
			if(a[i]!=b.a[i]){
				if (a[i]>b.a[i]) flag=1;
				break;
			}
      }
	  else{
        if(len>b.len) flag=1;
      }
      if(flag){
        for (i=1;i<=len;i++) c.a[i]=a[i];
        for (i=1;i<=b.len;i++) c.a[i]-=b.a[i];
        for (i=1;i<=c.len;i++)
			if(c.a[i]<0)
				c.a[i+1]--,c.a[i]+=B;
        while (c.len>1&&!c.a[c.len]) c.len--;
        c.fu=fu;
      }
	  else{
        for (i=1;i<=b.len;i++) c.a[i]=b.a[i];
        for (i=1;i<=len;i++) c.a[i]-=a[i];
        for (i=1;i<=c.len;i++)
			if(c.a[i]<0)
				c.a[i+1]--,c.a[i]+=B;
        while (c.len>1&&!c.a[c.len]) c.len--;
        c.fu=b.fu;
      }
    }
    return c;
  }
  Num operator-(Num b){
    b.fu^=1;
    return *this+b;
  }
  Num operator*(Num b){
    Num c;
    c.len=len+b.len+2;
    c.fu=fu^b.fu;
    int i,j;
    for(i=1;i<=c.len;i++)c.a[i]=0;
    for(i=1;i<=len;i++)for(j=1;j<=b.len;j++){
      c.a[i+j-1]+=a[i]*b.a[j];
      if(c.a[i+j-1]>=B){
        c.a[i+j]+=c.a[i+j-1]/B;c.a[i+j-1]%=B;
        if(c.a[i+j]>=B)c.a[i+j+1]+=c.a[i+j]/B,c.a[i+j]%=B;
      }
    }
    while(c.len>1&&!c.a[c.len])c.len--;
    return c;
  }
  void write(){
    printf("%d",a[len]);
    for(int i=len-1;i;i--)printf("%04d",a[i]);
  }
  void set(int x){
    fu=0;
    len=1;
    a[1]=x;
  }
} f[N],C[N][N],ans,tmp;
void solve(int x,int y){
  int i,j,now;
  for(i=0;i<x;i++)b[i]=a[i];
  b[x]=y;
  for(i=0;i<n;i++)v[i]=0;
  for(i=0;i<=x;i++){
    if(v[b[i]])return;
    v[b[i]]=1;
  }
  for(now=i=0;i<=x;i++)now+=b[i]==i;
  if(now>fun)return;
  now=fun-now;
  int ret=0;
  for(i=x+1;i<n;i++)if(!v[i])ret++;
  for(i=now;i<=ret;i++){
    Num t=f[n-1-x-i]*C[ret][i]*C[i][now];
    if((i-now)&1)ans=ans-t;else ans=ans+t;
  }
}
int main(){
  scanf("%d",&n);
  for(f[0].set(i=1);i<=n;i++)tmp.set(i),f[i]=f[i-1]*tmp;
  for(C[0][0].set(i=1);i<=n;i++)for(C[i][0].set(j=1);j<=i;j++)C[i][j]=C[i-1][j-1]+C[i-1][j];
  for(i=0;i<n;i++)scanf("%d",&a[i]),fun+=a[i]==i;
  printf("%d ",fun);
  for(i=0;i<n;i++)for(j=0;j<a[i];j++)solve(i,j);
  ans.write();
  return 0;
}
