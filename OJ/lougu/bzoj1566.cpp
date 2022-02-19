#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5e2+5;
const int mod=1024523;
int f[MAXN][MAXN][MAXN],u[MAXN],d[MAXN];
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		char a=getchar(); while (a!='A'&&a!='B') a=getchar();
		u[i]=a=='A';
	}
	for (int i=1;i<=m;i++){
		char a=getchar(); while (a!='A'&&a!='B') a=getchar();
		d[i]=a=='A';
	}
	f[0][0][0]=1;
	for (int i=0;i<n+m;i++){
		int t=i&1;
		for (int j=0;j<=n&&j<=i;j++){
			for (int k=0;k<=n&&k<=i;k++){
				if (f[t][j][k]){
					int l=i-j,r=i-k;
					if (u[j+1]==u[k+1]){
						f[!t][j+1][k+1]+=f[t][j][k];
						f[!t][j+1][k+1]%=mod;
					}
					if (u[j+1]==d[r+1]){
						f[!t][j+1][k]+=f[t][j][k];
						f[!t][j+1][k]%=mod;
					}
					if (d[l+1]==u[k+1]){
						f[!t][j][k+1]+=f[t][j][k];
						f[!t][j][k+1]%=mod;
					}
					if (d[l+1]==d[r+1]){
						f[!t][j][k]+=f[t][j][k];
						f[!t][j][k]%=mod;
					}
					f[t][j][k]=0;
				}
			}
		}
	}
	printf("%d\n",f[(n+m)&1][n][n]);
	return 0;
}
