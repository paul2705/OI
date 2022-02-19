#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=3e2+5;
int a[MAXN][MAXN],b[MAXN][MAXN];
int c[MAXN][MAXN];
int n;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			char c=getchar(); while (c!='1'&&c!='0') c=getchar();
			a[i][j]=(c=='1');
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			char c=getchar(); while (c!='1'&&c!='0') c=getchar();
			b[i][j]=(c=='1');
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++) c[i][j]=1;
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (!a[i][j]) continue;
			for (int k=1;k<=n;k++){
				if (c[j][k]&&!b[i][k]) c[j][k]=0;
			}
		}
	}
	for (int i=1;i<=n;i++){
		for (int k=1;k<=n;k++){
			if (b[i][k]){
				int flag=0;
				for (int j=1;j<=n;j++){
					if (c[j][k]&&a[i][j]){
						flag=1;
						break;
					}
				}
				if (!flag) return printf("-1\n"),0;
			}
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++) printf("%d",c[i][j]);
		printf("\n");
	}
	return 0;
}
