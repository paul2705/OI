#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5e5+5;
int a[MAXN];
int n;
int s,l,r;
int main(){
	scanf("%d",&n);
	r=(n+1)*n;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s+=a[i]; l+=a[i]-n+1;
		r-=n-a[i];
	}
	l=max(l,0); r=min(r,n);
	printf("%d %d %d\n",s,l,r);
	return 0;
}
