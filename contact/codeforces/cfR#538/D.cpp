#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5e3+5;
int f[MAXN][MAXN][2];
int a[MAXN],b[MAXN],cnt;
int n;
int get(int i,int j){
	return b[i]!=b[j];
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++){
		if (a[i]!=a[i-1]) b[++cnt]=a[i];
	}
	n=cnt;
	for (int i=1;i<=n;i++) f[i][i][0]=f[i][i][1]=0;
	for (int len=1;len<=n;len++){
		for (int i=1;i<=n;i++){
			int j=i+len; if (j>n) break;
			f[i][j][0]=min(f[i+1][j][0]+get(i,i+1),f[i+1][j][1]+get(i,j));
			f[i][j][1]=min(f[i][j-1][0]+get(i,j),f[i][j-1][1]+get(j-1,j));
		}
	}
	printf("%d\n",min(f[1][n][0],f[1][n][1]));
	return 0;
}
