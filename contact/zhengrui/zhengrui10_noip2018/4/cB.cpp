#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const double eps=1e-5;
const int MAXN=505;
struct rec{
	int x,y;
} a[MAXN];
int n,m,fa[MAXN];
double sq(double x){ return x*x; }
double dis(int x,int y){ return sqrt(sq(a[x].x-a[y].x)+sq(a[x].y-a[y].y)); }
int find(int x){ return fa[x]==x?x:fa[x]=find(fa[x]); }
void uion(int x,int y){ fa[find(x)]=find(y); }
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y);
	double l=0,r=m,mid;
	while (r-l>eps){
		mid=(l+r)/2.0;
		for (int i=1;i<=n+2;i++) fa[i]=i;
		for (int i=1;i<=n;i++){
			for (int j=i;j<=n;j++){
				if (dis(i,j)<mid) uion(i,j);
			}
		}
		for (int i=1;i<=n;i++){
			if (a[i].y<mid) uion(i,n+1);
		}
		for (int i=1;i<=n;i++){
			if (a[i].y>m-mid) uion(i,n+2);
		}
		if (find(n+1)==find(n+2)) r=mid;
		else l=mid;
	}
	printf("%.3lf\n",l);
	return 0;
}
