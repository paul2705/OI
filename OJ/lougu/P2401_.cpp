#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e3+5;
int f[MAXN][MAXN];
int n,k;
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) f[i][i-1]=f[i][0]=1;
	for (int i=1;i<=n;i++){
		for (int j=1;j<i-1;j++){
			f[i][j]=f[i-1][j]*(j+1)+f[i-1][j-1]*(i-j);
			f[i][j]%=2015;
		}
	}
	printf("%d\n",f[n][k]);
	return 0;
}
