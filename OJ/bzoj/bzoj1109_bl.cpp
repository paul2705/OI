#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e3+5;
int n,a[MAXN],f[MAXN][MAXN];
int ans=0;
int main(){
	freopen("bzoj1109.in","r",stdin);
//	freopen("bzoj1109_bl.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=n;i>=1;i--){
		for (int j=1;j<=i;j++){
			f[i][j]=max(f[i+1][j],f[i+1][j+1]+(a[i]==j));
		}
		ans=max(ans,f[i][1]);
//		printf("%d\n",f[i][1]);
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++) printf("%d ",f[i][j]);
		printf("\n");
	}
	printf("%d\n",ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
