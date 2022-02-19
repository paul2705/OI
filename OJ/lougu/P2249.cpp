#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e6+6;
int n,a[MAXN],m;
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=m;i++){
		int x; scanf("%d",&x);
		int l=0,r=n,mid;
		while (l+1<r){
			mid=(l+r)>>1;
			if (a[mid]<x) l=mid;
			else r=mid;
		}
		if (a[r]!=x) printf("-1 ");
		else printf("%d ",r);
	}
	printf("\n");
	return 0;
}
