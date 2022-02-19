#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int l,r; scanf("%d%d",&l,&r);
		int x=r/2+1;
		if (x<l) x=l;
		printf("%d\n",r%x);
	}
	return 0;
}
