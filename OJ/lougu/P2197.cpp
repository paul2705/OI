#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,T,cnt;
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		scanf("%d",&cnt);
		for (int i=1,x;i<n;i++) scanf("%d",&x),cnt^=x;
		if (cnt) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
