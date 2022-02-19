#include<bits/stdc++.h>
const int N=85;
int n,m,mo,i,j,k,l;
int f[N*N][N][N];
int main(){
	freopen("count.in","r",stdin);freopen("count.out","w",stdout);
	scanf("%d%d%d",&n,&m,&mo);
	f[1][1][1]=n*m;
	for(i=1;i<n*m;++i)
		for(j=1;j<=n;++j)
			for(k=1;k<=m;++k){
				if(i<j*k)f[i+1][j][k]=(f[i+1][j][k]+1ll*(j*k-i)*f[i][j][k])%mo;
				if(k<m)f[i+1][j][k+1]=(f[i+1][j][k+1]+1ll*(m-k)*j*f[i][j][k])%mo;
				if(j<n)f[i+1][j+1][k]=(f[i+1][j+1][k]+1ll*(n-j)*k*f[i][j][k])%mo;
			}
	printf("%d\n",f[n*m][n][m]);
	return 0;
}
