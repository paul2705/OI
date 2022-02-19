#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=1e2+5;
const int MAXK=15;
const int inf=1e9;
const int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
int n,K,A,B,C;
int a[MAXN][MAXN];
int dist[MAXN][MAXN][MAXK];
int use[MAXN][MAXN][MAXK];
struct rec{
	int x,y,k;
};
queue<rec> q;
bool out(int x,int y){
	return x<1||x>n||y<1||y>n;
}
int main(){
	scanf("%d%d%d%d%d",&n,&K,&A,&B,&C);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			char c=getchar(); while (c!='0'&&c!='1') c=getchar();
			a[i][j]=c=='1';
//			cout<<a[i][j];
			for (int k=0;k<=K;k++) dist[i][j][k]=inf;
		}
//		cout<<endl;
	}
	dist[1][1][0]=0; use[1][1][0]=1;
	q.push((rec){1,1,0});
	while (!q.empty()){
		rec u=q.front(); q.pop();
//		cout<<n<<endl;
//		cout<<u.x<<" "<<u.y<<" "<<u.k<<" "<<dist[u.x][u.y][u.k]<<endl;
		use[u.x][u.y][u.k]=0;
		if (a[u.x][u.y]==1&&u.k!=0){
			if (dist[u.x][u.y][0]>dist[u.x][u.y][u.k]+A){
				dist[u.x][u.y][0]=dist[u.x][u.y][u.k]+A;
				if (!use[u.x][u.y][0]){
					use[u.x][u.y][0]=1;
					q.push((rec){u.x,u.y,0});
				}
			}
			continue;
		}
		else {
			if (dist[u.x][u.y][0]>dist[u.x][u.y][u.k]+A+C){
				dist[u.x][u.y][0]=dist[u.x][u.y][u.k]+A+C;
				if (!use[u.x][u.y][0]){
					use[u.x][u.y][0]=1;
					q.push((rec){u.x,u.y,0});
				}
			}
		}
		if (u.k<K){
			for (int i=0;i<4;i++){
				int nx=u.x+dx[i],ny=u.y+dy[i],nk=u.k+1;
				if (out(nx,ny)) continue;
				int val=0;
				if (dx[i]<0||dy[i]<0) val=B;
				if (dist[nx][ny][nk]>dist[u.x][u.y][u.k]+val){
					dist[nx][ny][nk]=dist[u.x][u.y][u.k]+val;
					if (!use[nx][ny][nk]){
						use[nx][ny][nk]=1;
						q.push((rec){nx,ny,nk});
					}
				}
			}
		}
	}
	int ans=inf;
//	for (int i=0;i<=K;i++) cout<<dist[n][n][i]<<endl;
	for (int i=0;i<=K;i++) ans=min(ans,dist[n][n][i]);
	printf("%d\n",ans);
	return 0;
}
