#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
double x1,y_1,x2,y2,x3,y3;
double sqr(double x){ return x*x; }
double dis(double x1,double y1,double x2,double y2){
	return sqrt(sqr(x2-x1)+sqr(y2-y1));
}
int main(){
	scanf("%lf%lf%lf%lf%lf%lf",&x1,&y_1,&x2,&y2,&x3,&y3);
	printf("%.2lf\n",dis(x1,y_1,x2,y2)+dis(x1,y_1,x3,y3)+dis(x2,y2,x3,y3));
	return 0;
}
