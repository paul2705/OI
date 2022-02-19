#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
double a[10],s;
int main(){
	for (int i=1;i<=7;i++) scanf("%lf",&a[i]),s+=a[i];
	printf("%.3lf\n",5040*a[1]/s*a[2]/(s-1)*a[3]/(s-2)*a[4]/(s-3)*a[5]/(s-4)*a[6]/(s-5)*a[7]);
	return 0;
}
