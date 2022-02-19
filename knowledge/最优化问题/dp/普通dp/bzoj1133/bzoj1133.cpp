#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=605;
const int MAXK=55;
const int inf=1e9;
int f[MAXN][MAXK];
int pre[MAXN][MAXK];
int n,m;
int a[MAXN][MAXN];
int res[MAXN],cnt;
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++) scanf("%d",&a[i][j]);
	}
	for (int i=1;i<=n;i++){
		for (int j=n;j>=1;j--) a[i][j]+=a[i][j+1]+a[i-1][j]-a[i-1][j+1];
	}
//	for (int i=1;i<=n;i++){
//		for (int j=1;j<=n;j++) printf("%d ",a[i][j]);
//		cout<<endl;
//	}
	for (int i=0;i<=n;i++){
		for (int j=0;j<=m;j++) f[i][j]=-inf;
	}
	f[0][0]=0;
	for (int i=1;i<=n;i++){
		for (int k=1;k<=m;k++){
			for (int j=0;j<=i-1;j++){
				if (f[i][k]<f[j][k-1]+a[i][i+1]-a[j][i+1]){
					pre[i][k]=j;
					f[i][k]=f[j][k-1]+a[i][i+1]-a[j][i+1];
				}
			}
		}
	}
	int ans=0;
	for (int i=m;i<=n;i++){
		if (f[i][m]>f[ans][m]) ans=i;
	}
//	printf("%d\n",f[ans][m]);
	int x=ans,y=m;
	while (x){
		res[cnt++]=x;
		x=pre[x][y]; y--;
	}
	sort(res,res+cnt);
	for (int i=0;i<cnt;i++) printf("%d ",res[i]);
	printf("\n");
	return 0;
}
