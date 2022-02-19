#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int MAXN=1e3+5;
const int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
char mp[MAXN][MAXN];
int n,m,f[MAXN][MAXN][2];
int d,r;
struct rec{ int x,y,id; };
bool check(int x,int y){ return mp[x][y]=='.'&&x>=1&&x<=n&&y>=1&&y<=m; }
void bfs(){
	queue<rec> q; q.push((rec){1,1,0});
	f[1][1][0]=0;
	while (!q.empty()&&f[n][m][0]==1e9&&f[n][m][1]==1e9){
		int x=q.front().x,y=q.front().y,id=q.front().id; q.pop();
		for (int i=0;i<4;i++){
			int nx=x+dx[i],ny=y+dy[i];
			if (check(nx,ny)&&f[nx][ny][id]==1e9){
				f[nx][ny][id]=f[x][y][id]+1;
				q.push((rec){nx,ny,id});
				if (id==0&&check(nx+d,ny+r)&&f[nx+d][ny+r][1]==1e9){
					f[nx+d][ny+r][1]=f[nx][ny][0]+1;
					q.push((rec){nx+d,ny+r,1});
				}
			}
		}
	}
}
int main(){
	scanf("%d%d%d%d",&n,&m,&d,&r);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			char c=getchar(); while (c!='.'&&c!='#') c=getchar();
			mp[i][j]=c; f[i][j][0]=f[i][j][1]=1e9;
		}
	}
	bfs();
	int ans=min(f[n][m][0],f[n][m][1]);
	if (ans==1e9) printf("-1\n");
	else printf("%d\n",ans);
	return 0;
}
