#include<iostream>
#include<cstdio>
#include<cmath>
#include<cmath>
#include<cstring>
using namespace std;
const int MAXN=1e6+10;
char sda[MAXN],sdb[MAXN];
int sdh1,sdw1,sdh2,sdw2;
long long h,w;
int kdh1,kdw1,kdh2,kdw2;

int gcd(int a,int b){
  return b==0?a:gcd(b,a%b);
}

int main(){
  freopen("picture.in","r",stdin);
  freopen("picture.out","w",stdout);
  scanf("%d %d",&sdh1,&sdw1);
  scanf("%s",sda+1);
  scanf("%d %d",&sdh2,&sdw2);
  scanf("%s",sdb+1);
  // cout<<"fuck you"<<endl;
  h=(long long)(sdh1*sdh2);
  w=(long long)(sdw1*sdw2);
  // cout<<"fuck you"<<endl;
  // cout<<sdh1<<" "<<sdh2<<" "<<sdw1<<" "<<sdw2<<" "<<endl;
  // cout<<gcd(sdh1,sdh2)<<" "<<gcd(sdw1,sdw2)<<endl;
  h/=gcd(sdh1,sdh2);
  w/=gcd(sdw1,sdw2);
  // cout<<"fuck you"<<endl;
  kdh1=h/sdh1,kdh2=h/sdh2,kdw1=h/sdw1,kdw2=h/sdw2;
  long long ans=0;
  for(int i=1;i<=h;i++){
    for(int j=1;j<=w;j++){
      if(sda[((i-1)/kdh1)*sdw1+(j-1)/kdw1]==sdb[((i-1)/kdh2)+(j-1)/kdw2]){
	ans++;
      }
    }
  }
  printf("%lld\n",ans);
  return 0;
}
