#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1e5*5+5;
int a[MAXN],n,m,q[MAXN],ans;
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),a[i]+=a[i-1];
	int l=1,r=0;
	for (int i=1;i<=n;i++){
		while (l<=r&&a[q[r]]>=a[i]) r--;
		q[++r]=i;
		while (q[l]<i-m) l++;
		ans=max(ans,a[i]-a[q[l]]);
	}
	printf("%d\n",ans);
	return 0;
}
