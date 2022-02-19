#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=6;
int a[MAXN][MAXN],b[MAXN][MAXN];
int n,m,ans=1e9;
bool bd(){
	bool fl=1;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if (a[i][j]==1) fl=0;
		}
	}
	return fl;
}
bool ful(int x,int y,int xx,int yy){
	bool fl=1;
	for (int i=x;i<=xx;i++){
		for (int j=y;j<=yy;j++){
			if (a[i][j]==0) fl=0;
		}
	}
	return fl;
}
void chg(int x,int y,int xx,int yy,int val){
	for (int i=x;i<=xx;i++){
		for (int j=y;j<=yy;j++) a[i][j]=val;
	}
}
void dfs(int d){
	if (d>=ans) return;
	if (bd()){
		ans=min(ans,d);
		return;
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			for (int k=i;k<=n;k++){
				for (int l=j;l<=m;l++){
					if (ful(i,j,k,l)){
						chg(i,j,k,l,0);
						dfs(d+1);
						chg(i,j,k,l,1);
					}
				}
			}
		}
	}
}

int main(){
	freopen("merging.in","r",stdin);
	freopen("merging1.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) scanf("%d",&a[i][j]);
	}
	dfs(0);
	printf("%d\n",ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
