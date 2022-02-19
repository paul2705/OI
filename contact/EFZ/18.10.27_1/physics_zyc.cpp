#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	freopen("physics.in","r",stdin);
	freopen("physics.out","w",stdout);
	int t;
	double pi=acos(-1);
	scanf("%d",&t);
	while (t-->0){
		double s,v,g;
		double d;
		scanf("%lf%lf%lf%lf",&s,&v,&d,&g);
		double a=s/180.0*pi*2;
		printf("%.5lf\n",sin(a)*v*v/(1-d*d)/g);
	}
	fclose(stdin);fclose(stdout);
}
