#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
int n,s,t,i;
double l,r,mid,ans,a[MAXN];
int b[MAXN],q[MAXN];
double sum[MAXN];
bool check(double x){
	int i,l=1,r=0;
	for (int i=1;i<=n;i++) a[i]=(double)b[i]-x;
	sum[0]=0;
	for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for (int i=1;i<=n;i++){
		if (i>=s){
			while (r>=l&&sum[i-s]<sum[q[r]]) r--;
			q[++r]=i-s;
		}
		if (l<=r&&q[l]<i-t) l++;
		if (l<=r&&sum[i]-sum[q[l]]>=0) return 1;
	}
	return 0;
}
int main(){
	scanf("%d",&n);
	scanf("%d%d",&s,&t);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	ans=l=-10000,r=10000;
	while (r-l>1e-5){
//		cout<<l<<" "<<r<<endl;
		mid=(l+r)/2;
		if (check(mid)) ans=l=mid;
		else r=mid;
	}
	printf("%.3lf\n",ans);
	return 0;
}
