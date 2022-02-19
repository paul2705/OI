#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
int a[10][10],lim;
struct stp{
	int x,y,g;
} ans[10];
int cnt[20],mx;
bool over=0,use[10][10];
bool cmp(stp a,stp b){ return a.y==b.y?a.x<b.x:a.y<b.y; }
void print(){
	for (int i=1;i<=7;i++){
		for (int j=1;j<=5;j++) cout<<a[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
}
void drop(int x,int y){
	int lb=x,ub=x;
	while (lb>0&&a[lb][y]==0) lb--; lb++;
	while (ub<=7&&a[ub][y]==0) ub++;
	for (int i=ub;i<=7;i++){
		for (int j=i;j>lb;j--) swap(a[j][y],a[j-1][y]);
		lb++;
	}
}
void check(int x,int y,int col){
	use[x][y]=1; cnt[x+6]++; cnt[y]++;
	for (int i=0;i<4;i++){
		int nx=x+dx[i],ny=y+dy[i];
		if (nx<1||nx>7||ny<1||ny>5) continue;
		if (!use[nx][ny]&&a[nx][ny]==col) check(nx,ny,col);
	}
}
bool change(int x,int y,int g){
	int nx=x,ny=y+g;
	if (nx<1||nx>7||ny<1||ny>5) return 0;
//	if (g==1&&a[nx][ny]==0) return 0;
	if (g==0&&a[nx][ny]!=0) return 0;
	if (a[x][y]==a[nx][ny]) return 0;
	swap(a[nx][ny],a[x][y]);
	if (a[x][y]==0) drop(x,y);
	if (a[nx][ny-1]==0) drop(nx,ny-1);
	bool f=1;
	while (f){
		f=0;
		for (int i=1;i<=7;i++){
			for (int j=1;j<=5;j++){
				if (a[i][j]==0) continue;
				check(i,j,a[i][j]);
				for (int k=1;k<=5;k++){
					if (cnt[k]>=3){
						f=1;
						for (int l=1;l<=7;l++){
							if (use[l][k]) a[l][k]=0;
						}
					}
				}
				for (int k=1;k<=7;k++){
					if (cnt[k+6]>=3){
						f=1;
						for (int l=1;l<=5;l++){
							if (use[k][l]) a[k][l]=0;
						}
					}
				}
				for (int k=1;k<=5;k++){
					if (cnt[k]>=3){
						int y=1;
						for (;y<=7;y++){
							if (a[y][k]==0) break;
						}
						drop(y,k);
					}
					cnt[k]=0;
				}
				for (int k=1;k<=7;k++){
					if (cnt[k+6]>=3){
						for (int l=1;l<=5;l++){
							if (a[k][l]==0) drop(k,l);
						}
					}
					cnt[k+6]=0;
				}
				for (int k=1;k<=7;k++){
					for (int l=1;l<=5;l++) use[k][l]=0;
				}
			}
		}
	}
	return 1;
}
/*bool check_col(){
	for (int i=1;i<=mx;i++){
		if (cnt[i]>=1&&cnt[i]<=2) return 1;
	}
	return 0;
}*/
void dfs(int d){
//	cout<<d<<endl;
	if (over) return;
	bool fl=1;
	for (int i=1;i<=7;i++){
		for (int j=1;j<=5;j++){
			if (a[i][j]>0) fl=0;
		}
	}
	if (fl&&d==lim+1){
//		sort(ans+1,ans+lim+1,cmp);
		for (int i=1;i<=lim;i++) printf("%d %d %d\n",ans[i].y-1,ans[i].x-1,ans[i].g);
		over=1;
		return;
	}
//	if (check_col()) return;
	if (d>=lim+1) return;
	int b[10][10];
	for (int j=1;j<=5;j++){
		for (int i=1;i<=7;i++){
			if (a[i][j]==0) break;
			for (int i=1;i<=7;i++){
				for (int j=1;j<=5;j++) b[i][j]=a[i][j];
			}
			if (change(i,j,1)){
				ans[d]=(stp){i,j,1};
				dfs(d+1);
				for (int i=1;i<=7;i++){
					for (int j=1;j<=5;j++) a[i][j]=b[i][j];
				}
			}
			if (change(i,j,-1)){
				ans[d]=(stp){i,j,-1};
				dfs(d+1);
				for (int i=1;i<=7;i++){
					for (int j=1;j<=5;j++) a[i][j]=b[i][j];
				}
			}
		}
	}
}
int main(){
	scanf("%d",&lim);
	for (int i=1;i<=5;i++){
		int j=1,x=0; scanf("%d",&x);
		while (x!=0){
			a[j++][i]=x; cnt[x]++; mx=max(mx,x);
			scanf("%d",&x);
		}
	}
	dfs(1);
	if (!over) printf("-1\n");
	return 0;
}
