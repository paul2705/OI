#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5e4+5;
int a[MAXN],n,mid;
void rev(int l,int r){
	if (l>=r) return;
	printf("%d %d\n",l,r);
	reverse(a+l,a+r+1);
}
void work(int l,int r){
	if (l>=r) return;
	int m=(l+r)>>1;
	work(l,m); work(m+1,r);
	int x=m,y=m+1;
	while (x>=l&&a[x]>mid) x--;
	while (y<=r&&a[y]<=mid) y++;
	rev(x+1,y-1);
}
void qsort(int l,int r){
	if (l>=r) return;
	bool f=true;
	for (int i=l;i<r;i++) f&=a[i]<=a[i+1];
	if (f) return;
	mid=a[l+rand()%(r-l+1)];
	work(l,r);
	int loc;
	for (int i=l;i<=r;i++){
		if (a[i]<=mid) loc=i;
		else break;
	}
	qsort(l,loc); qsort(loc+1,r);
}
int main(){
	srand(20180910);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	qsort(1,n);
	printf("-1 -1\n");
	return 0;
}
