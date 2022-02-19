#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1e2+5;
const int MAXM=15;
const int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
int a[MAXN][MAXM];
int n,k;
bool use[MAXN][MAXM];
int res[MAXN],cnt;
int dfs(int x,int y,int col){
	use[x][y]=1;
	int sz=1;
	for (int i=0;i<4;i++){
		int nx=x+dx[i],ny=y+dy[i];
		if (use[nx][ny]) continue;
		if (nx<1||nx>n||ny<1||ny>10) continue;
		if (a[nx][ny]!=col) continue;
		sz+=dfs(nx,ny,col);
	}
	return sz;
}
void clr(int x,int y,int col){
	a[x][y]=0;
	for (int i=0;i<4;i++){
		int nx=x+dx[i],ny=y+dy[i];
		if (nx<1||nx>n||ny<1||ny>10) continue;
		if (a[nx][ny]!=col) continue;
		clr(nx,ny,col);
	}
}
void drop(int j){
	cnt=0;
	for (int i=n;i>=1;i--){
		if (a[i][j]>0) res[++cnt]=a[i][j];
	}
	int lb=1,i;
	for (i=n;i>=1&&lb<=cnt;i--) a[i][j]=res[lb++];
	for (;i>=1;i--) a[i][j]=0;
}
int main(){
	freopen("mooyomooyo.in","r",stdin);
	freopen("mooyomooyo.out","w",stdout);
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=10;j++){
			char c=getchar(); while (c<'0'||c>'9') c=getchar();
			a[i][j]=c-'0';
		}
	}
	while (1){
		bool f=0;
		for (int i=0;i<=n+1;i++){
			for (int j=0;j<=11;j++) use[i][j]=0;
		}
//		for (int i=1;i<=n;i++){
//			for (int j=1;j<=10;j++) printf("%d ",a[i][j]);
//			printf("\n");
//		}
		for (int i=1;i<=n;i++){
			for (int j=1;j<=10;j++){
				if (a[i][j]>0){
					int sz=dfs(i,j,a[i][j]);
//					cout<<i<<" "<<j<<" "<<a[i][j]<<" "<<sz<<endl;
					if (sz>=k) f=1,clr(i,j,a[i][j]);
				}
			}
		}
		if (!f) break;
		for (int i=1;i<=10;i++) drop(i);
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=10;j++) printf("%d",a[i][j]);
		printf("\n");
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
