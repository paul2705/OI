#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN=1e5+5;
const double eps=1e-9;
struct rec{
	double x,y;
} a[MAXN];
int n;
bool f=0,f1=0,f3=0;
int cmp(double a,double b){
	if (fabs(a-b)<eps) return 2;
	return a<b;
}
bool cmpd(rec a,rec b){ return a.x<b.x; }
double sq(double x){ return x*x; }
double dist(double x,double y,double xx,double yy){
	return sqrt(sq(x-xx)+sq(y-yy));
}
bool chequ(double x,double y){
	for (int i=1;i<=n;i++){
		if (cmp(dist(x,y,a[i].x,a[i].y),y)<1) return 0;
	}
	return 1;
}
bool check(double x,bool f){
	double l=0,r=2e7+5,ml,mr;
	while (l+eps<r){
		ml=(l+r)/2.0;
		mr=(ml+r)/2.0;
		if (chequ(ml,x)<chequ(mr,x)) l=ml;
		else r=mr;
	}
	if (f) printf("%.8lf ",mr);
	return chequ(mr,x);
}
int main(){
	scanf("%d",&n);
	double las=0;
	for (int i=1;i<=n;i++){
		scanf("%lf%lf",&a[i].x,&a[i].y);
		if (cmp(a[i].y,0)==1) f=1;
		else if (cmp(a[i].y,0)==0) f1=1;
		else if (las==0) las=a[i].x;
		else f3=1;
	}
	if (f3||(f1&&f)) return printf("-1\n"),0;
	sort(a+1,a+n+1,cmpd);
	double l=0,r=2e7+5,ml,mr;
	while (l+eps<r){
		ml=(l+r)/2.0;
		mr=(ml+r)/2.0;
		if (check(ml,0)<=check(mr,0)) l=ml;
		else r=mr;
	}
	if (check(l,0)) printf("%.8lf\n",l);
	return 0;
}
