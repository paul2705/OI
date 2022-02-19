#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const double esp=1e-6;
double f[11][2050];
int n,won[2050][2050];
int main(){
	scanf("%d",&n); int m=(1<<n);
	for (int i=1;i<=m;i++){
		for (int j=1;j<=m;j++) scanf("%d",&won[i][j]);
	}
	for (int i=1;i<=m;i++) f[0][i]=1;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			int pos=ceil((double)j/(1<<(i-1)));
			int posa=((pos&1)==0?pos-1:pos+1);
			for (int k=posa*(1<<(i-1))-(1<<(i-1))+1;k<=posa*(1<<(i-1));k++){
				f[i][j]+=f[i-1][j]*won[j][k]/100*f[i-1][k];
			}
		}
	}
	double mx=-1; int ans;
	for (int i=1;i<=m;i++){	
		if (f[n][i]>mx+esp) mx=f[n][i],ans=i;
	}
	printf("%d\n",ans);
	return 0;
}
