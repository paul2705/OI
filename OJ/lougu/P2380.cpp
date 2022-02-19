#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=505;
int a[MAXN][MAXN],b[MAXN][MAXN];
int f[MAXN][MAXN];
int n,m;
int main(){
	scanf("%d%d",&n,&m);
while (n!=0&&m!=0){
memset(f,0,sizeof(f)); memset(a,0,sizeof(a)); memset(b,0,sizeof(b));
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) scanf("%d",&a[i][j]);
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) scanf("%d",&b[i][j]);
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++) a[i][j]+=a[i][j-1],b[i][j]+=b[i-1][j];
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			f[i][j]=max(f[i-1][j]+a[i][j],f[i][j-1]+b[i][j]);
		}
	}
	printf("%d\n",f[n][m]);
	scanf("%d%d",&n,&m);
}
	return 0;
}
	
