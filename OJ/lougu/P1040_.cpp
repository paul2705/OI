#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=35;
int f[MAXN][MAXN],root[MAXN][MAXN];
int a[MAXN],n;
void dfs(int l,int r){
	if (l>r) return;
	int mid=root[l][r];	
	printf("%d ",mid);
	dfs(l,mid-1); dfs(mid+1,r);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),f[i][i]=a[i],root[i][i]=i;
	for (int l=1;l<=n;l++){
		for (int i=1;i<=n;i++){
			int j=i+l; if (j>n) continue;
			if (f[i][j]<f[i+1][j]+a[i]){
				f[i][j]=f[i+1][j]+a[i]; root[i][j]=i;
			}
			if (f[i][j]>f[i][j-1]+a[j]){
				f[i][j]=f[i][j-1]+a[j]; root[i][j]=j;
			}
			for (int k=i+1;k<j;k++){
				if (f[i][j]<f[i][k-1]*f[k+1][j]+a[k]){
					f[i][j]=f[i][k-1]*f[k+1][j]+a[k];
					root[i][j]=k;
				}
			}
		}
	}
	printf("%d\n",f[1][n]);
	dfs(1,n);
	return 0;
}
