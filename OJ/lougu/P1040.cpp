#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=35;
int a[MAXN],n,ans;
int f[MAXN][MAXN],root[MAXN][MAXN];
void print(int l,int r){
	if (l>r||r<l) return;
	printf("%d ",root[l][r]);
	print(l,root[l][r]-1); print(root[l][r]+1,r);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) f[i][i]=a[i],f[i][i-1]=1,root[i][i]=i;
	for (int l=2;l<=n;l++){
		for (int i=1;i<=n;i++){
			int j=i+l-1;
			for (int k=i;k<=j;k++){
				if (f[i][j]<f[i][k-1]*f[k+1][j]+f[k][k]){
					f[i][j]=f[i][k-1]*f[k+1][j]+f[k][k];
					root[i][j]=k;
				}
			}
		}
	}
	printf("%d\n",f[1][n]);
	print(1,n);
	return 0;
}
