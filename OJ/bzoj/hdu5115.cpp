#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e2+5;
int n,a[MAXN],b[MAXN];
int f[MAXN][MAXN];
int main(){
	int T,cnt=0;
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		memset(a,0,sizeof(a)); memset(b,0,sizeof(b));
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		for (int i=1;i<=n;i++) scanf("%d",&b[i]);
		for (int i=1;i<=n;i++){
			for (int j=i;j<=n;j++) f[i][j]=1<<30;
		}
		for (int l=0;l<=n;l++){
			for (int i=1;i<=n;i++){
				int j=i+l; if (j>n) continue;
				for (int k=i;k<=j;k++) f[i][j]=min(f[i][j],f[i][k-1]+f[k+1][j]+a[k]+b[i-1]+b[j+1]);
//			cout<<i<<" "<<j<<" "<<f[i][j]<<endl;
			}
		}
		printf("Case #%d: %d\n",++cnt,f[1][n]);
	}
	return 0;
}
