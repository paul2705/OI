#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=3e5+5;
int a[MAXN],b[MAXN];
int n,m;
int main(){
	scanf("%d%d",&n,&m); a[0]=1e9;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),a[i]=min(a[i],a[i-1]);
	for (int i=1;i<=m;i++) scanf("%d",&b[i]);
	int las=n+1;
	for (int i=1;i<=m;i++){
		do{ las--; }
		while (b[i]>a[las]);
		if (!las) return printf("0\n"),0;
	}
	printf("%d\n",las);
	return 0;
}
