#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 2005 
using namespace std;
int n,m,tot,q[N],x[N],sq[N];
long double f[N][N];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&q[i],&x[i]);
		tot+=q[i];
		sq[i]=sq[i-1]+q[i];
	}
	for(int i=1,j,k;i<=m;i++){
		int po=1ll*n*sq[i]/tot;
		f[i][po]=1;
		for(j=1;j<=po;++j)
			f[i][po]*=(long double)sq[i]/tot;
		k=j;
		for(j=1;j<=n-po;++j,++k)
			f[i][po]*=(long double)k/j*(tot-sq[i])/tot;
		for(j=po-1;~j;--j)
			f[i][j]=f[i][j+1]*(tot-sq[i])/sq[i]*(j+1)/(n-j);
		for(j=po+1;j<=n;++j)
			f[i][j]=f[i][j-1]*sq[i]/(tot-sq[i])*(n-j+1)/j;
	}
	for(int i=1;i<=m;++i)
		for(int j=n-1;~j;--j)
			f[i][j]+=f[i][j+1];
	long double ans=0;
	for(int i=1,j,k;i<=n;i++){
		for(j=1;j<=m;++j)
			if(f[j][i]>=0.5) break;
		for(k=1;k<=m;++k)
			ans+=abs(x[j]-x[k])*(f[k][i]-f[k-1][i]);
	}
	printf("%0.9lf",(double)ans);
}
