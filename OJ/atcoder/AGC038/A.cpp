#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e3+5;
int a[MAXN][MAXN];
int n,m,A,B;
int main(){
	scanf("%d%d%d%d",&n,&m,&A,&B);
	for (int i=1;i<=B;i++){
		for (int j=1;j<=A;j++) a[i][j]=1;
	}
	for (int i=B+1;i<=n;i++){
		for (int j=A+1;j<=m;j++) a[i][j]=1;
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) printf("%d",a[i][j]);
		printf("\n");
	}
	return 0;
}
