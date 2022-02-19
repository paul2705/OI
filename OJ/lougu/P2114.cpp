#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,ans,x,a1=0,a2=-1;
char str[5];
int main(){
	scanf("%d%d",&n,&m);
	while (n--){
		scanf("%s%d",str,&x);
		if (str[0]=='A') a1&=x,a2&=x;
		if (str[0]=='X') a1^=x,a2^=x;
		if (str[0]=='O') a1|=x,a2|=x;
	}
	for (int i=29;~i;i--){
		if (a1>>i&1) ans+=1<<i;
		else if (a2>>i&1&&(1<<i)<=m) ans+=1<<i,m-=1<<i;
	}
	printf("%d",ans);
	return 0;
}
