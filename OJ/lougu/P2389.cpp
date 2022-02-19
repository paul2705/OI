#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5e2+5;
int f[MAXN][MAXN];
int n,k,a[MAXN];
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),a[i]+=a[i-1];
	for (int j=1;j<=n;j++){
		int mx=0;
		for (int i=1;i<=n;i++){
			f[i][j]=max(f[i-1][j],mx+a[i]);
			mx=max(mx,f[i][j-1]-a[i]);
		}
	}
	printf("%d\n",f[n][k]);
	return 0;
}
