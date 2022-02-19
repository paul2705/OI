#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=2e3+5;
int n,a[3][MAXN],b[MAXN][MAXN][3],mx=-1e9;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=2;i++){
		for (int j=1;j<=n;j++) scanf("%d",&a[i][j]);
	}
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			if (j<n-1) b[i][j][0]=b[i][j-1][0]+a[1][j]+a[2][j];
			else b[i][j][0]=-1e9;
			if (j!=i&&j!=n) b[i][j][1]=max(b[i][j-1][1],b[i][j-1][0])+a[2][j];
			else b[i][j][1]=-1e9;
			if (j>i+1) b[i][j][2]=max(b[i][j-1][2],b[i][j-1][1])+a[1][j]+a[2][j];
			else b[i][j][2]=-1e9;
			mx=max(b[i][j][2],mx);
		}
	}
	printf("%d\n",mx);
	return 0;
}
