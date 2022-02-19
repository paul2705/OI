#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
int n,a[MAXN],b[MAXN];
int ans;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	sort(a+1,a+n+1); sort(b+1,b+n+1);
	int l1=1,r1=n,l2=1,r2=n;
	while (l1<=r1&&l2<=r2){
		if (a[l1]>b[l2]) ans+=2,l1++,l2++;
		else if (a[r1]>b[r2]) ans+=2,r1--,r2--;
		else ans+=(a[l1]==b[r2]),l1++,r2--;
	}
	printf("%d ",ans);
	ans=0;
	l1=1,r1=n,l2=1,r2=n;
	while (l1<=r1&&l2<=r2){
		if (b[l1]>a[l2]) ans+=2,l1++,l2++;
		else if (b[r1]>a[r2]) ans+=2,r1--,r2--;
		else ans+=(b[l1]==a[r2]),l1++,r2--;
	}
	printf("%d\n",2*n-ans);
	return 0;
}
