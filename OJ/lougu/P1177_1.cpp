#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
int a[MAXN],n;
void qsort(int l,int r){
	int i=l,j=r,tmp=a[(l+r)/2];
	do {
		while (a[i]<tmp) i++;
		while (a[j]>tmp) j--;
		if (i<=j){
			swap(a[i],a[j]);
			i++; j--;
		}
	} while (i<=j);
	if (i<=r) qsort(i,r);
	if (l<=j) qsort(l,j);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	qsort(1,n);
	for (int i=1;i<=n;i++) printf("%d ",a[i]);
	printf("\n");
	return 0;
}
