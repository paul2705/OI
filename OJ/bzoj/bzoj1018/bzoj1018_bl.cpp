#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
const int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
int mp[3][MAXN][5];
int n;
bool use[3][MAXN];
char op[10];
void dfs(int x,int y){
	if (use[x][y]) return;
	use[x][y]=1;
	for (int i=0;i<4;i++){
		int nx=x+dx[i],ny=y+dy[i];
		if (mp[x][y][i+1]) dfs(nx,ny);
	}
}
int main(){
	freopen("bzoj1018.in","r",stdin);
	freopen("bzoj10181.out","w",stdout);
	scanf("%d",&n);
	while (~scanf("%s",op)){
		if (op[0]=='E') break;
		char c=op[0]; int x=c=='O';
		int sx,sy,tx,ty;
		scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
		if (sy>ty) swap(sx,tx),swap(sy,ty);
		if (c=='C'||c=='O'){
			if (sx==tx) mp[sx][sy][2]=mp[tx][ty][4]=x;
			else mp[1][sy][3]=mp[2][ty][1]=x;
		}
		else {
			memset(use,0,sizeof(use));
			dfs(sx,sy);
			if (use[tx][ty]) printf("Y\n");
			else printf("N\n");
		}
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
