#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e5+5;
const int dx[4]={0,0,-1,1},dy[4]={1,-1,0,0};
//0: Rgt
//1: Lft
//2: Up
//3: Dwn
int n,m,q;
int x,y,nx,ny;
int a[MAXN],b[MAXN];
bool ub(int x,int y){
	return x<1||x>n||y<1||y>m;
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	scanf("%d%d",&x,&y);
	for (int i=1;i<=q;i++){
		char c=getchar(); while (c!='R'&&c!='L'&&c!='U'&&c!='D') c=getchar();
		if (c=='R') a[i]=0;
		if (c=='L') a[i]=1;
		if (c=='U') a[i]=2;
		if (c=='D') a[i]=3;
	}
	for (int i=1;i<=q;i++){
		char c=getchar(); while (c!='R'&&c!='L'&&c!='U'&&c!='D') c=getchar();
		if (c=='R') b[i]=0;
		if (c=='L') b[i]=1;
		if (c=='U') b[i]=2;
		if (c=='D') b[i]=3;
	}
	for (int i=1;i<=q;i++){
		nx=x+dx[a[i]]; ny=y+dy[a[i]];
		if (a[i]==0&&y>=(m+1)/2) x=nx,y=ny;
		if (a[i]==1&&y<=(m+1)/2) x=nx,y=ny;
		if (a[i]==2&&x<=(n+1)/2) x=nx,y=ny;
		if (a[i]==3&&x>=(n+1)/2) x=nx,y=ny;
		cout<<"T: "<<x<<" "<<y<<endl;
		if (ub(x,y)) return printf("NO\n"),0;
		nx=x+dx[b[i]], ny=y+dy[b[i]];
		if (m%2==1&&n%2==1&&x==(n+1)/2&&y==(m+1)/2) continue;
		if (b[i]==0&&y<=(m+1)/2) x=nx,y=ny;
		if (b[i]==1&&y>=(m+1)/2) x=nx,y=ny;
		if (b[i]==2&&x>=(n+1)/2) x=nx,y=ny;
		if (b[i]==3&&x<=(n+1)/2) x=nx,y=ny;
		cout<<"A: "<<x<<" "<<y<<endl;
		if (ub(x,y)) return printf("NO\n"),0;
	}
	printf("YES\n");
	return 0;
}
