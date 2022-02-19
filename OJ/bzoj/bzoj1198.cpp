#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=15;
const int MAXM=20;
struct data{
	int u,v,x,y,id;
} b[MAXM];
int a[MAXM][MAXM],c[MAXM];
int n,m,ans;
bool cmp(int x,int y){
	if (b[x].u==b[y].u) return b[x].v<b[y].v;
	return b[x].u<b[y].u;
}
void dfs(int i,int j,int d){
	if (j>a[i][0]) i++,j=1,d=0;
	if (i>n){
		int tmp=0;
		for (int k=1;k<=m;k++){
			if (!b[k].x) tmp+=b[k].y;
		}
		ans=max(ans,tmp);
		return;
	}
	dfs(i,j+1,d);
	if (d<b[a[i][j]].u&&b[a[i][j]].x){
		b[a[i][j]].x--;
		dfs(i,j+1,b[a[i][j]].v);
		b[a[i][j]].x++;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i][0]);
		for (int j=1;j<=a[i][0];j++) scanf("%d",&a[i][j]);
	}
	for (int i=1;i<=m;i++) scanf("%d%d%d%d",&b[i].u,&b[i].v,&b[i].x,&b[i].y);
	for (int i=1;i<=n;i++) sort(a[i]+1,a[i]+a[i][0]+1,cmp);
	dfs(1,1,0);
	printf("%d\n",ans);
	return 0;
}
