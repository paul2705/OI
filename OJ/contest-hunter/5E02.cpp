#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int inf=1e9;
const int MAXN=1e2+5;
int f[MAXN][MAXN],mx[MAXN][MAXN];
int pos[MAXN][MAXN],pre[MAXN][MAXN];
int n,m,a[MAXN][MAXN],ans;
void prt(int x,int y){
	if (x==0) return;
	int pos=pre[x][y];
	prt(x-1,pos);
//	ans+=a[x][y];
	printf("%d ",y);
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
			f[i][j]=mx[i][j]=-inf;
		}
	}
	for (int i=0;i<=n;i++) mx[i][0]=-inf;
	for (int i=0;i<=m;i++) mx[0][i]=0;
	for (int i=1;i<=n;i++){
		for (int j=i;j<=m;j++){
			f[i][j]=mx[i-1][j-1]+a[i][j];
			if (mx[i][j-1]<f[i][j]){
				mx[i][j]=f[i][j];
				pos[i][j]=j;
			}
			else {
				mx[i][j]=mx[i][j-1];
				pos[i][j]=pos[i][j-1];
			}
			pre[i][j]=pos[i-1][j-1];
		}
	}
	int pos=0,mx=-inf;
	for (int i=n;i<=m;i++){
		if (mx<f[n][i]){
			mx=f[n][i];
			pos=i;
		}
	}
	printf("%d\n",f[n][pos]);
	prt(n,pos);
//	printf("%d\n",ans);
	return 0;
}
