#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=500;
int n,m,r;
int f[MAXN][MAXN];
int a[MAXN],b[MAXN];
int main(){
	scanf("%d%d%d",&n,&m,&r);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=m;i++) scanf("%d",&b[i]);
	int mn=1e9,mx=0;
	for (int i=1;i<=n;i++) mn=min(mn,a[i]);
	for (int i=1;i<=m;i++) mx=max(mx,b[i]);
	if (mn>mx) return printf("%d\n",r),0;
	printf("%d\n",(r/mn)*mx+(r-(r/mn)*mn));
	return 0;
}
