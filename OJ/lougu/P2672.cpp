#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
struct rec{
	int s,t;
} a[MAXN];
int n,m,mx,ans;
bool b;
bool cmp(rec a,rec b){
	int va=a.t,vb=b.t;
	if (a.s>mx) va+=(a.s-mx)*2;
	if (b.s>mx) vb+=(a.s-mx)*2;
	return va>vb;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i].s);
	for (int i=1;i<=n;i++) scanf("%d",&a[i].t);
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;i++){
		if (a[i].s>mx) b=1,mx=a[i].s;
		else b=0;
		ans+=a[i].t;
		printf("%d\n",mx*2+ans);
		if (b) sort(a+i+1,a+n+1,cmp);
	}
	return 0;
}
