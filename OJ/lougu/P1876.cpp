#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
double n;
int ans;
int main(){
	scanf("%lf",&n);
	ans=sqrt(n);
	for (int i=1;i<=ans;i++) printf("%d ",i*i);
	printf("\n");
	return 0;
}
