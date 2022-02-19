#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN=2e5+5;
struct rec{
	double x,y;
} a[MAXN];
int n,m,t[MAXN];
double ans;
bool cmp(rec a,rec b){ return a.x==b.x?a.y<b.y:a.x<b.x; }
bool cmps(int i,int j){ return a[i].y<a[j].y; }
double sq(double x){ return x*x; }
double dist(int i,int j){
	double x=sq(a[i].x-a[j].x),y=sq(a[i].y-a[j].y);
	return sqrt(x+y);
}
double min(double a,double b){ return a>b?b:a; }
double merge(int l,int r){
	double d=1e9;
	if (l==r) return d;
	if (l+1==r) return dist(l,r);
	int mid=(l+r)>>1;
	double d1=merge(l,mid); double d2=merge(mid+1,r);
	d=min(d1,d2);
	int k=0;
	for (int i=l;i<r;i++) if (fabs(a[mid].x-a[i].x)<=d) t[k++]=i;
	sort(t,t+k,cmps);
	for (int i=0;i<k;i++){
		for (int j=i+1;j<k&&a[t[j]].y-a[t[i]].y<d;j++){
			d=min(d,dist(t[i],t[j]));
		}
	}
	return d;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lf %lf",&a[i].x,&a[i].y);
	sort(a+1,a+n+1,cmp);
	printf("%.4lf\n",merge(1,n));
	return 0;
}
