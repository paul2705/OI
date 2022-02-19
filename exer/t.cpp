#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a=3,b=4,c=5,d=6;
int main(){
	int ans=0;
  for (int i=1;i<=b;i++){
		ans+=d/a+c;
    ans-=b;
    if (ans>10) b--;
  }
  printf("%d\n",ans);
  return 0;
}
