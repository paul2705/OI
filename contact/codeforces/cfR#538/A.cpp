#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a,b,c,x,y,z;
bool flag=1;
int main(){
	scanf("%d%d%d",&x,&y,&z);
	scanf("%d%d%d",&a,&b,&c);
	if (x>a) flag=0;
	a-=x;
	if (y>a+b) flag=0;
	int s=a+b-y;
	if (z>s+c) flag=0;
	if (flag) printf("YES\n");
	else printf("NO\n");
	return 0;
}
