#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN=1e5+5;
const double eps=1e-8;
int n;
double a,m[MAXN],s[MAXN];
int main(){
	scanf("%d%lf",&n,&a);
	for (int i=1;i<=n;i++) scanf("%lf",&m[i]);
	for (int i=1;i<=n;i++){
		s[i]=s[i-1]+m[i];
		int r=(int)floor(i*a+eps);
		double ret=0;
		if (i<=1000){
			for (int j=1;j<=r;j++) ret+=m[j]*m[i]/(double)(i-j);
		}
		else ret=s[r]*m[i]/(i-0.5*r);
		printf("%.6lf\n",ret);
	}
	return 0;
}
