#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int inf=1e7;
const int MAXN=2e2+5;
int f[MAXN][MAXN][MAXN];
int s[5][MAXN][MAXN];
int n,m,X,Y,K,a[MAXN][MAXN];
int main(){
	scanf("%d%d%d%d%d",&n,&m,&X,&Y,&K);
	for (int i=0;i<=K;i++){
		for (int j=1;j<=n;j++){
			for (int k=1;k<=m;k++) f[i][j][k]=-inf;
		}
	}
	for (int i=0;i<=4;i++){
		for (int j=1;j<=n;j++){
			for (int k=1;k<=m;k++) s[i][j][k]=-inf;
		}
	}
	f[0][X][Y]=0; 
	s[1][0][Y]=X; s[2][0][Y]=-X;
	s[3][0][X]=Y; s[4][0][X]=-Y;
	for (int i=1;i<=K;i++){
		int l,r,tp; scanf("%d%d%d",&l,&r,&tp);
		for (int j=1;j<=n;j++){
			for (int k=1;k<=m;k++){
				f[i][j][k]=s[tp][i-1][k]-j;
				s[1][i][k]=max(s[1][i][k],f[i][j][k]+j);
				s[2][i][k]=max(s[2][i][k],f[i][j][k]-j);
				s[3][i][j]=max(s[3][i][j],f[i][j][k]+k);
				s[4][i][j]=max(s[4][i][j],f[i][j][k]-k);
			}
		}
	}
	int ans=0;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) ans=max(ans,f[n][i][j]);
	}
	printf("%d\n",ans);
	return 0;
}
