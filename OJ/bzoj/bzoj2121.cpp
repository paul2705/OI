#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=205;
int n,m,c[35];;
char s[MAXN],a[35][25];
int f[MAXN][MAXN],g[MAXN][MAXN][35][25];
int ans[MAXN];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	scanf("%d",&m);
	for (int i=1;i<=m;i++) scanf("%s",a[i]+1),c[i]=strlen(a[i]+1);
	for (int i=1;i<=n;i++){
		f[i][i-1]=1;
		for (int j=1;j<=m;j++){
			g[i][i-1][j][0]=1;
		}
	}
	for (int l=0;l<=n;l++){
		for (int i=1;i<=n;i++){
			int j=i+l; if (j>n) break;
			for (int k=1;k<=m;k++){
				for (int pos=1;pos<=c[k];pos++){
					if (s[j]==a[k][pos]){
						g[i][j][k][pos]|=g[i][j-1][k][pos-1];
					}
				}
				for (int pos=0;pos<=c[k];pos++){
					for (int x=i;x<=j;x++){
						g[i][j][k][pos]|=g[i][x-1][k][pos]&f[x][j];
					}
				}
			}
			for (int k=1;k<=m;k++) f[i][j]|=g[i][j][k][c[k]];
		}
	}
	for (int i=1;i<=n;i++){
		ans[i]=ans[i-1]+1;
		for (int j=1;j<=i;j++){
			if (f[j][i]){
				ans[i]=min(ans[i],ans[j-1]);
			}
		}
	}
	printf("%d\n",ans[n]);
	return 0;
}
