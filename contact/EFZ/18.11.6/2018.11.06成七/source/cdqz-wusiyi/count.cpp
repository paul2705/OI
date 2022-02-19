#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=1010;
int n,m,p,f[2][N][N];

int main() {
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	scanf("%d%d%d",&n,&m,&p);
	f[1][1][1]=n*m%p;
	for(int i=1,t=1;i<n*m;i++,t^=1) {
		for(int j=1;j<=n;j++) {
			for(int k=1;k<=m;k++) {
				f[t^1][j][k]=(1ll*f[t][j][k]*(j*k-i)%p+1ll*f[t][j-1][k]*(n-j+1)*k%p+1ll*f[t][j][k-1]*(m-k+1)*j%p)%p;
			}
		}
	}
	printf("%d\n",f[(n*m)&1][n][m]);
	return 0;
}
