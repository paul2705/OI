#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e2+5;
struct coin{
	int m,v;
	double c;
} a[MAXN];
int n,T;
double ans;
bool cmp(coin a,coin b){
	return a.c>b.c;
}
int main(){
	scanf("%d%d",&n,&T);
	for (int i=1;i<=n;i++){
		scanf("%d%d",&a[i].m,&a[i].v);
		a[i].c=(double)a[i].v/a[i].m;
	}
	sort(a+1,a+n+1,cmp);
	int i=1;
	while (T&&i<=n){
		if (a[i].m<=T){
			T-=a[i].m;
			ans+=a[i].v;
		}
		else {
			ans+=a[i].c*T;
			T=0;
		}
		i++;
	}
	printf("%.2lf\n",ans);
	return 0;
}
