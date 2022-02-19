#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=505;
int fx[MAXN][MAXN],fn[MAXN][MAXN];
int n,m,K,a[MAXN][MAXN];
int ans;
int main(){
	scanf("%d%d%d",&n,&m,&K);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) scanf("%d",&a[i][j]),fx[i][j]=fn[i][j]=a[i][j];
	}
//	memset(fx,0,sizeof(fx)); memset(fn,63,sizeof(fn));
	for (int k=1;k<=min(n,m)-1;k++){
		for (int i=1;i<=n-k;i++){
			for (int j=1;j<=m-k;j++){
				fx[i][j]=max(max(fx[i+1][j],fx[i][j+1]),max(a[i+k][j+k],a[i][j]));
				fn[i][j]=min(min(fn[i+1][j],fn[i][j+1]),min(a[i+k][j+k],a[i][j]));
//				cout<<i<<" "<<j<<" "<<fx[i][j]<<" "<<fn[i][j]<<endl;
				if (fx[i][j]-fn[i][j]>=K) return printf("%d\n",k+1),0;
			}
		}
	}
	printf("-1\n");
	return 0;
}	
