#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=3e2+5;
const int MAXC=1e2+5;
int t[MAXC][MAXN][MAXN];
int n,m,q;
int a[MAXN][MAXN];
void add(int c,int x,int y,int val){
	for (;x<=n;x+=x&-x){
		for (int j=y;j<=m;j+=j&-j){
			t[c][x][j]+=val;
		}
	}
}
int sum(int c,int x,int y){
	int ret=0;
	for (;x;x-=x&-x){
		for (int j=y;j;j-=j&-j){
			ret+=t[c][x][j];
		}
	}
	return ret;
}
int calc(int x1,int y1,int x2,int y2,int c){
	return sum(c,x2,y2)-sum(c,x1-1,y2)-sum(c,x2,y1-1)+sum(c,x1-1,y1-1);
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
			add(a[i][j],i,j,1);
		}
	}
	scanf("%d",&q);
	for (int i=1;i<=q;i++){
		int op; scanf("%d",&op);
		if (op==1){
			int x,y,c; scanf("%d%d%d",&x,&y,&c);
			add(a[x][y],x,y,-1);
			add(c,x,y,1);
			a[x][y]=c;
		}
		else {
			int x1,x2,y1,y2,c; scanf("%d%d%d%d%d",&x1,&x2,&y1,&y2,&c);
			printf("%d\n",calc(x1,y1,x2,y2,c));
		}
	}
}
