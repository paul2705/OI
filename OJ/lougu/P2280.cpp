#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1e5+5;
const int MAXX=1e4+5;
int a[MAXX][MAXX];
int n,r,ans,mx,my;
int main(){
	scanf("%d%d",&n,&r);
	for (int i=1,x,y,v;i<=n;i++){
		scanf("%d%d%d",&x,&y,&v); x+=r; y+=r;
		a[x][y]=v; mx=max(mx,x); my=max(my,y);
	}
	for (int i=r;i<=mx;i++){
		for (int j=r;j<=my;j++){
			a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
			ans=max(ans,a[i][j]-a[i-r][j]-a[i][j-r]+a[i-r][j-r]);
		}
	}
	printf("%d\n",ans);
	return 0;
}
