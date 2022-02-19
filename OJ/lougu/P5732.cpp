#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN=25;
int c[MAXN][MAXN];
int n;
int main(){
	scanf("%d",&n);
	n--;
	for (int i=0;i<=n;i++){
		c[i][0]=c[i][i]=1;
		for (int j=1;j<i;j++){
			c[i][j]=c[i-1][j-1]+c[i-1][j];
		}
	}
	for (int i=0;i<=n;i++){
		for (int j=0;j<=i;j++) printf("%d ",c[i][j]);
		printf("\n");
	}
	return 0;
}
