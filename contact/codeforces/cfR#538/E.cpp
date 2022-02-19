#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int l,r,mid,mn1,mn2;
bool check(int x){
	int res=0;
	printf("> %d\n",x);
	scanf("%d",&res);
	return res;
}
int main(){
	fflush(stdout);
	l=0,r=1e9+1;
	while (l+1<r){
		mid=(l+r)>>1;
		if (check(mid)) l=mid;
		else r=mid+1;
	}
	mn1=l;
	l++; r=1e9+1;
	while (l+1<r){
		mid=(l+r)>>1;
		if (check(mid)) l=mid;
		else r=mid+1;
	}
	mn2=l;
	printf("! %d %d\n",mn1,mn2-mn1);
	return 0;
}
