#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=205;
ll f[MAXN][MAXN];
bool use[MAXN][MAXN];
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	int x,y; scanf("%d%d",&x,&y);
	use[x][y]=use[x-2][y-1]=use[x-2][y+1]=1;
	use[x+2][y-1]=use[x+2][y+1]=1;
	use[x-1][y-2]=use[x-1][y+2]=1;
	use[x+1][y-2]=use[x+1][y+2]=1;
	f[0][0]=1;
	for (int i=0;i<=n;i++){
		for (int j=0;j<=m;j++){
			if (i==0&&j==0) continue;
			if (use[i][j]) continue;
			f[i][j]=max(f[i][j],f[i-1][j]+f[i][j-1]);
//			printf("%d %d %d\n",i,j,f[i][j]);
		}
	}
	printf("%lld\n",f[n][m]);
	return 0;
}

