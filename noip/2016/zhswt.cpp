#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e3+5;
int C[MAXN][MAXN],r[MAXN][MAXN];
int n,k;
int main(){
	scanf("%d%d",&n,&k);
	for (int i=0;i<=2000;i++){
		r[i][0]=r[i][i]=1;
		for (int j=1;j<i;j++){
			r[i][j]=(r[i-1][j]+r[i-1][j-1])%k;
			if (r[i][j]==0) C[i][j]=C[i][j-1]+C[i-1][j]-C[i-1][j-1]+1;
			else C[i][j]=C[i][j-1]+C[i-1][j]-C[i-1][j-1];
		}
		for (int j=i;j<=2000;j++) C[i][j]=C[i][j-1];
	}
	for (int i=1;i<=n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",C[x][y]);
	}
	return 0;
}
