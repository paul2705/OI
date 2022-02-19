#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e5+5;
int a[MAXN],n;
int main(){
	scanf("%d",&n);
	if (n%2==0) return printf("NO\n"),0;
	printf("YES\n");
	n*=2; int cnt=1;
	for (int i=1;i<=n/2;i++){
		if (i%2==1) a[i]=cnt++,a[i+n/2]=cnt++;
		else a[i+n/2]=cnt++,a[i]=cnt++;
	}
	for (int i=1;i<=n;i++) printf("%d ",a[i]);
	printf("\n");
	return 0;
}
