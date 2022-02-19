#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=1e3+5;
const int MAXM=1e4+5;
int n,m,f[MAXM],mx[MAXM];
struct rec{
	int x,y,t;
} a[MAXM];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) scanf("%d%d%d",&a[i].t,&a[i].x,&a[i].y);
	a[0].t=-1e5;
	for (int i=1;i<=m;i++){
		int j=i-1;
		for (j=i-1;j>=0;j--){
			if (abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y)<=a[i].t-a[j].t)
				f[i]=max(f[i],f[j]+1);
			if (a[i].t-a[j].t>2*n) break;
		}
		if (j>=0) f[i]=max(f[i],mx[j]+1);
		mx[i]=max(mx[i-1],f[i]);
//		cout<<i<<" "<<f[i]<<endl;
	}
	printf("%d\n",mx[m]);
	return 0;
}
