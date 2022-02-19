#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a,b,c,d,ans;
int main(){
	scanf("%d%d%d%d",&a,&b,&c,&d);
	ans=2*(b+d+1)+2*(max(a,c)+1);
//	ans+=abs(a-c);
	printf("%d\n",ans);
	return 0;
}
