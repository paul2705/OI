#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=35;
struct rec{
	int x,y;
} q[MAXN*MAXN];
int dx[5]={0,0,1,-1};
int dy[5]={1,-1,0,0};
int a[MAXN][MAXN],b[MAXN][MAXN];
int l,r;
int n;
void bfs(int x,int y){
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++) b[i][j]=a[i][j];
	}
	l=0,r=-1; q[++r]=(rec){x,y};
	while (r-l+1>0){
		rec now=q[l++];
//		cout<<now.x<<" "<<now.y<<endl;
		for (int i=0;i<5;i++){
			int x=now.x+dx[i];
			int y=now.y+dy[i];
			if (x<1||x>n||y<1||y>n) continue;
			if (b[x][y]==0){
				b[x][y]=2;
				q[++r]=(rec){x,y};
			}
		}
	}
	return;
}
bool judge(){
	for (int i=1;i<=n;i++){
		if (b[i][1]==2) return 0;
		if (b[i][n]==2) return 0;
		if (b[1][i]==2) return 0;
		if (b[n][i]==2) return 0;
	}
	return 1;
}
void prt(){
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++) printf("%d ",b[i][j]);
		printf("\n");
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++) scanf("%d",&a[i][j]);
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (a[i][j]==0){
//				cout<<i<<" "<<j<<endl;
				bfs(i,j);
//				prt();
//				printf("\n");
				if (judge()){
					prt();
					return 0;
				}
			}
		}
	}
	return 0;
}
