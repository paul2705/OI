#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e2+5;
bool f[MAXN][MAXN*9];
int n,a[MAXN];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		char c=getchar(); while (c<'0'||c>'9') c=getchar();
		a[i]=c-'0'; a[i]+=a[i-1];
	}
	for (int i=0;i<=900;i++) f[0][i]=1;
	for (int i=1;i<=n;i++){
		for (int j=0;j<i;j++){
			int x=a[i]-a[j];
			f[i][x]|=f[j][x];
		}
	}
	bool ans=0;
	for (int i=1;i<a[n];i++) ans|=f[n][i];
	if (ans||a[n]==0) printf("YES\n");
	else printf("NO\n");
	return 0;
}
