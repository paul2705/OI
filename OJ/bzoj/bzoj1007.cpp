#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN=5e4+5;
const double eps=1e-8;
struct rec{
	double a,b;
	int id;
} a[MAXN];
int n;
bool cmp(rec a,rec b){ return fabs(a.a-b.a)<eps?a.b<b.b:a.a<b.a; }
int st[MAXN],top;
struct dt{
	double x,y;
};
dt dot(int i,int j){
	double x=(a[j].b-a[i].b)/(a[i].a-a[j].a);
	double y=a[i].a*x+a[i].b;
	return (dt){x,y};
}
int ans[MAXN],cnt;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lf%lf",&a[i].a,&a[i].b),a[i].id=i;
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;i++){
		while (top>=1&&fabs(a[st[top]].a-a[i].a)<eps) top--;
		while (top>=2&&dot(st[top-1],st[top]).x>=dot(st[top-1],i).x) top--;
		st[++top]=i;
	}
	for (int i=1;i<=top;i++) ans[cnt++]=a[st[i]].id;
	sort(ans,ans+cnt);
	for (int i=0;i<cnt;i++) printf("%d ",ans[i]);
	printf("\n");
	return 0;
}
