#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e6;
int f[60][MAXN];
int n,ans;
int main(){
	scanf("%d",&n);
	for (int i=1,x;i<=n;i++){
		scanf("%d",&x);
		f[x][i]=i+1;
	}
	for (int i=2;i<=58;i++){
		for (int j=1;j<=n;j++){
			if (!f[i][j]) f[i][j]=f[i-1][f[i-1][j]];
			if (f[i][j]) ans=i;
		}
	}
	printf("%d",ans);
	return 0;
}
