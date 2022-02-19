#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=6e2+5;
const int MAXK=55;
int a[MAXN][MAXN],f[MAXN][MAXK];
int n,k,ans;
int sum(int l,int r){
	return a[r][n]+a[l][r]-a[l][n]-a[r][r];
}
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++) scanf("%d",&a[i][j]);
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++) a[i][j]+=a[i-1][j];
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++) a[i][j]+=a[i][j-1];
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=k;j++){
			for (int l=0;l<i;l++){
				f[i][j]=max(f[i][j],f[l][j-1]+sum(l,i));
			}
		}
		ans=max(ans,f[i][k]);
	}
	printf("%d\n",ans);
	return 0;
}
