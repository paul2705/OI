#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
int n,a,b,c,d,k;
int x,y;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		x=ceil((double)a/c); y=ceil((double)b/d);
		if (x+y>k) printf("-1\n");
		else printf("%d %d\n",k-y,y);
	}
	return 0;
}
