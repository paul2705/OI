#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5e3+5;
int n,l[MAXN],r[MAXN];
int f[MAXN][MAXN];
int mx[MAXN][MAXN];
int main(){
	freopen("third.in","r",stdin);
	freopen("third.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d%d",&l[i],&r[i]);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			f[i][j]=max(f[i][j-1],f[i-1][j]);
			if (l[i]<=j&&j<=r[i]) f[i][j]=max(f[i][j],f[i-1][j-1]+1);
		}
	}
	printf("%d\n",f[n][n]);
	fclose(stdin); fclose(stdout);
	return 0;
}
