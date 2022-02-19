#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e2+5;
int g[MAXN][MAXN];
int n,cnt;
int main(){
	scanf("%d",&n);
	if (n%2==0){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				if (j==n-i+1) continue;
				g[i][j]=g[j][i]=1;
			}
		}
	}
	else {
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				if (j==n-i) continue;
				g[i][j]=g[j][i]=1;
			}
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			if (!g[i][j]) continue;
			cnt++;
		}
	}
	printf("%d\n",cnt);
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			if (!g[i][j]) continue;
			printf("%d %d\n",i,j);
		}
	}
	return 0;
}
