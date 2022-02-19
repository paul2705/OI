#include<iostream>
#include<cstdio>
using namespace std;
int n,cnt0,cnt5;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int tmp; scanf("%d",&tmp);
		if (tmp==0) cnt0++;
		else cnt5++;
	}
	if (cnt5<9&&cnt0==0){
		printf("-1\n");
		return 0;
	}
	for (int i=1;i<=(cnt5/9)*9;i++) printf("5");
	if ((cnt5/9)*9==0) printf("0");
	else for (int i=1;i<=cnt0;i++) printf("0");
	printf("\n");
	return 0;
}
