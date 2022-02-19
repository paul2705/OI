#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e2+5;
int a[MAXN][MAXN];
int n,m,ans;
int dx[8]={0,0,1,1,1,-1,-1,-1};
int dy[8]={1,-1,1,-1,0,1,-1,0};
void dfs(int x,int y){
	if (!a[x][y]) return;
	a[x][y]=0;
	for (int i=0;i<8;i++){
		int nx=x+dx[i],ny=y+dy[i];
		dfs(nx,ny);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			char c=getchar();
			while (c!='W'&&c!='.') c=getchar();
			a[i][j]=(c=='W');
		}
	}
//	for (int i=1;i<=n;i++){
//		for (int j=1;j<=m;j++) printf("%d",a[i][j]);
//		printf("\n");
//	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if (a[i][j]){
//				cout<<i<<" "<<j<<endl;
				dfs(i,j);
				ans++;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
