#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e2+5;
int a[MAXN][MAXN],b[MAXN][MAXN];
int n,d,m;
void dfs(int x,int y){
	cout<<x<<" "<<y<<endl;
	if (x<0||y<0||x>n||y>n) return;
	if (a[x][y]==1||b[x][y]==1) return;
	b[x][y]=1;
	dfs(x+1,y); dfs(x-1,y); dfs(x,y+1); dfs(x,y-1);
}
int main(){
	scanf("%d%d",&n,&d);
	int i,j;
	for (i=0,j=d;i<=n-d&&j<=n;i++,j++) a[i][j]=1;
	for (i--,j--;i<=n&&j>=n-d;i++,j--) a[i][j]=1;
	for (i--,j++;i>=d&&j>=0;i--,j--){
		for (int k=j;a[i][k]!=1;k++) a[i][k]=1;
	}
	for (i++,j++;i>=0&&j<=d;i--,j++){
		for (int k=j;a[i][k]!=1;k++) a[i][k]=1;
	}
	scanf("%d",&m);
	for (int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y);
		if (a[x][y]) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
