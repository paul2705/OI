#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=25;
ll f[MAXN][MAXN];
int n;
int main(){
	scanf("%d",&n);
	for (int i=0;i<=n;i++) f[0][i]=1;
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			if (i==j) f[i][j]=f[i-1][j];
			f[i][j]=f[i-1][j]+f[i][j-1];
		}
	}
	printf("%lld\n",f[n][n]);
	return 0;
}
