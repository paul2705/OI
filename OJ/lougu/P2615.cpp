#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAXN=50;
int a[MAXN][MAXN];
int n,x,y,cnt=0;
int main(){
	scanf("%d",&n);
	x=1; y=(n+1)/2; 
	while (cnt<n*n){
		a[x][y]=++cnt;
		if (x==1&&y<n) x=n,y++;
		else if (y==n&&x>1) x--,y=1;
		else if (x==1&&y==n) x++;
		else if (a[x-1][y+1]==0) x--,y++;
		else x++;
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++) printf("%d ",a[i][j]);
		printf("\n");
	}
	return 0;
}
