#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=5e3+5;
int a[MAXN][MAXN];
int n,R;
int ans=0;
int calc(int x1,int y1,int x2,int y2){
	return a[x2][y2]-a[x1-1][y2]-a[x2][y1-1]+a[x1-1][y1-1];
}
int main(){
	scanf("%d%d",&n,&R);
	for (int i=1;i<=n;i++){
		int x,y,v; scanf("%d%d%d",&x,&y,&v);
		x++; y++;
		a[x][y]+=v;
	}
	for (int i=1;i<=5001;i++){
		for (int j=1;j<=5001;j++){
			a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
		}
	}
	for (int i=1;i<=5001;i++){
		for (int j=1;j<=5001;j++){
			int x1=max(i-R+1,1),y1=max(j-R+1,1);
			ans=max(ans,calc(x1,y1,i,j));
		}
	}
	printf("%d\n",ans);
	return 0;
}
