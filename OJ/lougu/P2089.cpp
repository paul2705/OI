#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAX=55;
int f[MAX][MAX];
int n;
int main(){
	scanf("%d",&n);
	f[0][0]=1;
	for(int i=1;i<=10;i++){
		for(int j=i;j<=3*i;j++){
			f[i][j]=f[i-1][j-1]+f[i-1][j-2]+f[i-1][j-3];
		}
	}
	printf("%d\n",f[10][n]);
	return 0;
}
