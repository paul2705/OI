#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int T,n,x,y,d;
int mn;
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d%d%d",&n,&x,&y,&d);
		mn=1e9;
		if (abs(y-x)%d==0) mn=min(mn,(int)abs(y-x)/d);
		if ((y-1)%d==0) mn=min(mn,(int)(y-1)/d+(int)ceil((double)x/d));
		if ((n-y)%d==0) mn=min(mn,(int)(n-y)/d+(int)ceil((double)(n-x)/d));
		if (mn==1e9) printf("-1\n");
		else printf("%d\n",mn);
	}
	return 0;
}
