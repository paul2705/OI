#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=5e3+5;
int n,t,ans;
int s[MAXN],b[MAXN],f[MAXN][MAXN];
int main(){
	scanf("%d%d",&n,&t);
	for (int i=1;i<=n;i++) scanf("%d",&s[i]);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	for (int i=1;i<=n;i++) f[i][0]=f[i-1][0]-s[i];
	for (int i=1;i<=n;i++){
		for (int j=1;j<=i;j++){
			if (j%t==0) f[i][j]=max(f[i-1][j-1]+s[i]+b[i],f[i-1][j]-s[i]);
			else f[i][j]=max(f[i-1][j-1]+s[i],f[i-1][j]-s[i]);
		}
	}
	for (int i=1;i<=n;i++) ans=max(ans,f[n][i]);
	printf("%d\n",ans);
	return 0;
}
