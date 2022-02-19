#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
int a[MAXN],n,m;
int t1[MAXN],cnt1;
int t2[MAXN],cnt2;
void merge(int l,int m,int r){
	int l1=l,l2=m+1,cnt1=l;
	while (l1<=m&&l2<=r){
		if (a[l1]<a[l2]) t1[cnt1++]=a[l1++];
		else t1[cnt1++]=a[l2++];
	}
	while (l1<=m) t1[cnt1++]=a[l1++];
	while (l2<=r) t1[cnt1++]=a[l2++];
	for (int i=l;i<=r;i++) a[i]=t1[i];
}
void solve1(){
	for (int i=1;i<=m;i++){
		int op; scanf("%d",&op);
		if (op==1){
			int l,m,r; scanf("%d%d%d",&l,&m,&r);
			merge(l,m,r);
		}
		else {
			int pos; scanf("%d",&pos);
			printf("%d\n",a[pos]);
		}
	}
}
void solve2(){

}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	if (n<=2000&&m<=2000) solve1();
	else solve2();
	return 0;
}
