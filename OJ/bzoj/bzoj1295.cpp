#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
const int inf=1e5;
const int MAXN=35;
const int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
int a[MAXN][MAXN];
int n,m,T;
int d[MAXN][MAXN][MAXN];
struct rec{
	int x,y,k;
};
queue<rec> q;
double ans=0;
double calc(double x1,double y1,double x2,double y2){
	return (double)(sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)));
}
int main(){
	scanf("%d%d%d",&n,&m,&T);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			char c=getchar(); while (c!='0'&&c!='1') c=getchar();
			a[i][j]=c=='0';
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			for (int x=1;x<=n;x++){
				for (int y=1;y<=m;y++){
					for (int k=0;k<=T;k++) d[x][y][k]=inf;
				}
			}
			double res=0;
			if (a[i][j]) d[i][j][0]=0,q.push((rec){i,j,0});
			else d[i][j][1]=0,q.push((rec){i,j,1});
			while (!q.empty()){
				rec u=q.front(); q.pop();
//				cout<<i<<" "<<j<<" "<<u.x<<" "<<u.y<<endl;
				res=max(res,calc(i,j,u.x,u.y));
				for (int _=0;_<4;_++){
					int nx=u.x+dx[_],ny=u.y+dy[_];
					if (a[nx][ny]){
						if (d[nx][ny][u.k]<inf) continue;
						d[nx][ny][u.k]=d[u.x][u.y][u.k]+1;
						q.push((rec){nx,ny,u.k});
					}
					else {
						if (u.k==T) continue;
						if (d[nx][ny][u.k+1]<inf) continue;
						d[nx][ny][u.k+1]=d[u.x][u.y][u.k]+1;
						q.push((rec){nx,ny,u.k+1});
					}
				}
			}
			ans=max(ans,res);
		}
	}
	printf("%.6lf\n",ans);
	return 0;
}
