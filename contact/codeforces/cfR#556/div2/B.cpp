#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=55;
const int dx[5]={1,1,1,2},dy[5]={-1,0,1,0};
int n;
int a[MAXN][MAXN];
bool ub(int x,int y){ 
	return x<1||x>n||y<1||y>n;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			char c=getchar(); while (c!='.'&&c!='#') c=getchar();
			a[i][j]=(c=='#');
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (a[i][j]) continue;
			if (!a[i][j]){
				bool flag=1;
				for (int k=0;k<4;k++){
					int nx=i+dx[k],ny=j+dy[k];
					if (ub(nx,ny)) flag=0;
					if (a[nx][ny]) flag=0;
					a[nx][ny]=1;
				}
				if (!flag) return printf("NO\n"),0;
			}
		}
	}
	printf("YES\n");
	return 0;
}
