#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e6+6;
struct rec{
	int l,r;
} a[MAXN];
int n;
bool cmp(rec a,rec b){
	return a.r==b.r?a.l>b.l:a.r<b.r;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d%d",&a[i].l,&a[i].r);
	sort(a+1,a+n+1,cmp);
	int now=0,cnt=0;
	for (int i=1;i<=n;i++){
		if (a[i].l>=now) now=a[i].r,cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}
