#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=15;
double a[MAXN];
int n;
double cl,cr;
double check(double x){
	double ret=0;
	for (int i=1;i<=n+1;i++){
		ret=(ret*x+a[i]);
	}
	return ret;
}
int main(){
	scanf("%d%lf%lf",&n,&cl,&cr);
	for (int i=1;i<=n+1;i++) scanf("%lf",&a[i]);
	double lmid,rmid;
	while (cr-cl>1e-7){
		lmid=(cr+cl)/2;
		rmid=(lmid+cr)/2;
		if (check(lmid)>check(rmid)) cr=rmid;
		else cl=lmid;
	}
	printf("%.5lf\n",cl);
	return 0;
}
