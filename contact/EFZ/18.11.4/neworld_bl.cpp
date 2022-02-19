#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=550;
int a[MAXN][MAXN],ans[MAXN][MAXN];
int n,m,r,c,l,p,q;
int calc(int x,int y){
	int mx=a[x][y];
	mx=max(mx,ans[x-1][y]);
	mx=max(mx,ans[x+1][y]);
	mx=max(mx,ans[x][y-1]);
	mx=max(mx,ans[x][y+1]);
	return mx-a[x][y];
}
int main(){
	freopen("neworld.in","r",stdin);
	freopen("neworld1.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) scanf("%d",&a[i][j]);
	}
	scanf("%d%d%d%d%d",&r,&c,&l,&p,&q);
	ans[r][c]=l;
	while (1){
		bool f=1;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++){
				if (i==r&&j==c) continue;
				if (ans[i][j]!=calc(i,j)){
					f=0;
					ans[i][j]=calc(i,j);
					break;
				}
			}
		}
		if (f) break;
	}
//	for (int i=1;i<=n;i++){
//		for (int j=1;j<=m;j++) cout<<ans[i][j]<<" ";
//		cout<<endl;
//	}
	printf("%d\n",ans[p][q]);
	fclose(stdin); fclose(stdout);
	return 0;
}
