#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const int MAXN=105;
int a[MAXN],n=0;
int main(){
	scanf("%d",&a[++n]);
	while (a[n]!=0) scanf("%d",&a[++n]);
	for (int i=n-1;i>=1;i--) printf("%d ",a[i]);
	printf("\n");
	return 0;
}
