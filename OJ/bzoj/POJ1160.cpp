#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e3+5;
int f[MAXN][MAXN],s[MAXN][MAXN];
int n,m,a[MAXN],w[MAXN][MAXN];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++){
		w[i][i]=0;

	for (int k=2;k<=m;k++){
		for (int i=n;i>=1;i--){
			int l=s[k-1][i],r=s[k][i+1];
			for (int j=l;j<=r;j++){
				int cos=cost(j+1,i);
				if (f[k][i]>f[k-1][j]+cos){
					s[k][i]=j;
					f[k][i]=f[k-1][j]+cos;
				}
			}
		}
	}
	printf("%d",f[m][n]);
	return 0;
}
