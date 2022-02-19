#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
int n,t;
struct rec{
	int t,b,s;
} a[MAXN];
bool cmp(rec a,rec b){
	return a.s>b.s;
}
int main(){
	int Z;
	scanf("%d",&Z);
	while (Z--){
		scanf("%d%d",&n,&t);
		for (int i=1;i<=n;i++) scanf("%d%d",&a[i].t,&a[i].b),a[i].s=a[i].t+a[i].b;
		sort(a+1,a+n+1,cmp);
		bool f=true;
		for (int i=1;i<=n;i++){
			if (t<=a[i].t){
				f=false; break;
			}
			t+=a[i].b;
		}
		if (f&&t>0) printf("+1s\n");
		else printf("-1s\n");
	}
	return 0;
}
