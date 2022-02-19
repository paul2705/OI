#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=2e3+5;
struct rec{
	int x,y;
} a[MAXN];
int n,m;
long long f[MAXN][MAXN][3];
long long sq(long long x){ return x*x; }
long long dist(int i,int j){ return sq(a[i].x-a[j].x)+sq(a[i].y-a[j].y); }
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y);
	for (int i=n+1;i<=n+m;i++) scanf("%d%d",&a[i].x,&a[i].y);
	memset(f,120,sizeof(f)); f[1][0][0]=0;
	for (int i=1;i<=n;i++){
		for (int j=0;j<=m;j++){
			f[i][j][0]=min(f[i][j][0],min(f[i-1][j][0]+dist(i-1,i),f[i-1][j][1]+dist(i,n+j)));
			if (j) f[i][j][1]=min(f[i][j][1],min(f[i][j-1][0]+dist(i,n+j),f[i][j-1][1]+dist(n+j-1,n+j)));
		}
	}
	printf("%lld\n",f[n][m][0]);
	return 0;
}
