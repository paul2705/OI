#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=55;
char s[MAXN];
int f[MAXN][MAXN];
int n;
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++) f[i][j]=1e9;
	}
	for (int i=1;i<=n;i++) f[i][i]=1;
	for (int l=1;l<=n;l++){
		for (int i=1;i<=n;i++){
			int j=i+l; if (j>n) break;
			if (s[i]==s[j]){
				f[i][j]=min(f[i][j-1],f[i+1][j]);
				f[i][j]=min(f[i][j],f[i+1][j-1]+1);
			}
			else {
				for (int k=i;k<=j;k++) f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]);
			}
		}
	}
	printf("%d\n",f[1][n]);
	return 0;
}
