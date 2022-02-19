#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=550;
int a[MAXN][MAXN];
int f[MAXN][MAXN][MAXN];
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) scanf("%d",&a[i][j]);
	}
//	f[1][1][1]=max(a[1][1],0);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
//			if (i==1&&j==1) continue;
			for (int k=1;k<=n;k++){
				int l=i+j-k;
				if (l<=0||l>m) continue;
				if (i==k&&j==l) continue;
				f[i][j][k]=max(f[i-1][j][k-1],f[i-1][j][k]);
				f[i][j][k]=max(f[i][j][k],f[i][j-1][k]);
				f[i][j][k]=max(f[i][j][k],f[i][j-1][k-1]);
				f[i][j][k]+=a[i][j]+a[k][l];
//				cout<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<f[i][j][k]<<endl;
			}
		}
	}
	int ans=max(f[n-1][m][n-1],f[n-1][m][n]);
	ans=max(ans,f[n][m-1][n]);
	ans=max(ans,f[n][m-1][n-1]);
	printf("%d\n",ans);
	return 0;
}
