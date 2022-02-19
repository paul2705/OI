#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN=505;
const double eps=1e-10;
int dis[MAXN][MAXN];
int n,m;
struct rec{
	double x,y;
	double operator * (const rec& b) const {
		return x*b.y-y*b.x; 
	}
	rec operator - (const rec& b) const {
		return (rec){x-b.x,y-b.y};
	}
} a[MAXN],b[MAXN];
bool inc(rec x,rec y){
	if (x.x>y.x) swap(x,y);
	for (int i=1;i<=m;i++){
		if (b[i].x<x.x||b[i].x>y.x) return 0;
	}
	if (x.y>y.y) swap(x,y);
	for (int i=1;i<=m;i++){
		if (b[i].y<x.y||b[i].y>y.y) return 0;
	}
	return 1;
}
int jud(rec x,rec y){
	int cnt1=0,cnt2=0;
	for (int i=1;i<=m;i++){
		double t=(x-y)*(b[i]-y);
		if (t>eps) cnt1++;
		if (t<-eps) cnt2++;
		if (cnt1*cnt2>0) return 0;
	}
	if (cnt1==0&&cnt2==0&&inc(x,y)) return printf("2\n"),-1;
	if (cnt1>0) return 1;
	if (cnt2>0) return 2;
	return 3;
}
bool spj(){
	for (int i=1;i<=n;i++){
		if (fabs(a[i].x-a[1].x)>eps||fabs(a[i].y-a[1].y)>eps) return 0;
	}
	for (int i=1;i<=m;i++){
		if (fabs(b[i].x-a[1].x)>eps||fabs(b[i].y-a[1].y)>eps) return 0;
	}
	printf("1\n");
	return 1;
}
int main(){
	scanf("%d%d",&n,&m);
	double tmp;
	for (int i=1;i<=n;i++) scanf("%lf%lf%lf",&a[i].x,&a[i].y,&tmp);
	for (int i=1;i<=m;i++) scanf("%lf%lf%lf",&b[i].x,&b[i].y,&tmp);
	if (spj()) return 0;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++) dis[i][j]=1e8;
	}
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			int t=jud(a[i],a[j]);
			if (t==-1) return 0;
			if (t==1) dis[i][j]=1;
			if (t==2) dis[j][i]=1;
			if (t==3) dis[i][j]=dis[j][i]=1;
		}
	}
	int ans=1e8;
	for (int k=1;k<=n;k++){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
//	for (int i=1;i<=n;i++){
//		for (int j=1;j<=n;j++) printf("%d ",dis[i][j]);
//		printf("\n");
//	}
	for (int i=1;i<=n;i++) ans=min(ans,dis[i][i]);
	if (ans==1e8||ans<=2) printf("-1\n");
	else printf("%d\n",ans);
	return 0;
}
