#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=1e3+5;
const int dx[4]={0,0,-1,1},dy[4]={1,-1,0,0};
int a[MAXN][MAXN];
int n,m;
int d[MAXN][MAXN];
struct rec{
	int x,y;
};
queue<rec> q;
bool ub(int x,int y){
	return x<1||x>n||y<1||y>m;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			char c=getchar(); while (c!='#'&&c!='.') c=getchar();
			a[i][j]=(c=='#'); d[i][j]=1e9;
			if (a[i][j]) d[i][j]=0,q.push((rec){i,j});
		}
	}
	while (!q.empty()){
		rec u=q.front(); q.pop();
		for (int i=0;i<4;i++){
			int nx=u.x+dx[i],ny=u.y+dy[i];
			if (ub(nx,ny)) continue;
			if (d[nx][ny]==1e9){
				d[nx][ny]=d[u.x][u.y]+1;
				q.push((rec){nx,ny});
			}
		}
	}
	int ans=0;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) ans=max(ans,d[i][j]);
	}
	printf("%d\n",ans);
	return 0;
}
