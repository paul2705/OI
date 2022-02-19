#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e2+5;
int f[MAXN][MAXN],a[MAXN];
int n;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),a[i]+=a[i-1];
	for (int i=1;i<=n;i++) f[i][i]=a[i]-a[i-1];
	for (int l=1;l<=n;l++){
		for (int i=1;i<=n;i++){
			int j=i+l; if (j>n) continue;
			f[i][j]=a[j]-a[i-1]-min(f[i+1][j],f[i][j-1]);
		}
	}
	printf("%d %d\n",f[1][n],a[n]-f[1][n]);
	return 0;
}
