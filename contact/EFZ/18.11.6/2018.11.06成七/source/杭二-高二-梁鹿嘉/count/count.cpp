#include<cstdio>
int n,m,M,ans;
long long f[100][100];
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	scanf("%d%d%d",&n,&m,&M),f[1][1]=n*m%M;
	for(int i=2,_=n*m;i<=_;i++)
		for(int j=n;j;j--)
			for(int k=m;k;k--)
			f[j][k]=(f[j][k-1]*j*(m-k+1)+f[j-1][k]*(n-j+1)*k+f[j][k]*(j*k-i+1))%M;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) ans=(f[i][j]+ans)%M;
	printf("%d",ans);
	return 0;
}
