#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=50;
int f[MAXN][MAXN],b[MAXN][MAXN];
int n,a[MAXN];
void dfs(int l,int r){
	if (l>r) return;
	int mid=b[l][r];
	printf("%d ",mid);
	dfs(l,mid-1);
	dfs(mid+1,r);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) f[i][i-1]=1,f[i][i]=a[i],b[i][i]=i;
	for (int l=1;l<=n;l++){
		for (int i=1;i<=n;i++){
			int j=i+l; if (j>n) break;
			for (int k=i;k<=j;k++){
				if (f[i][j]<f[i][k-1]*f[k+1][j]+a[k]){
					f[i][j]=f[i][k-1]*f[k+1][j]+a[k];
					b[i][j]=k;
				}
			}
		}
	}
	printf("%d\n",f[1][n]);
	dfs(1,n);
	cout<<endl;
	return 0;
}
