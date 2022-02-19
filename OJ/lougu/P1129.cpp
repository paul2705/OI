#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=5e2+5;
int n,ans,T;
bool use[MAXN];
int a[MAXN][MAXN],mat[MAXN];
bool dfs(int x){
	for (int i=1;i<=n;i++){
		if (a[x][i]&&!use[i]){
			use[i]=1;
			if (!mat[i]||dfs(mat[i])){
				mat[i]=x;
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	scanf("%d",&T);
	while (T--){
		memset(mat,0,sizeof(mat)); memset(a,0,sizeof(a));
		ans=0;
		scanf("%d",&n);
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++) scanf("%d",&a[i][j]);
		}
		for (int i=1;i<=n;i++){
			memset(use,0,sizeof(use));
			ans+=dfs(i);
		}
		if (ans==n) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
