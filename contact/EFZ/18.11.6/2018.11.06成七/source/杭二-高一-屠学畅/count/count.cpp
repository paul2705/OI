#include<cstdio>
#include<algorithm>
#include<ctype.h>
#include<string.h>
#include<math.h>

using namespace std;
#define ll long long

const int N = 82;
int n, m, p, f[N*N][N][N];
inline void update(int &x, ll y){ x=(x+y)%p;}
int main() {
	freopen("count.in", "r", stdin);
	freopen("count.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &p);
	f[1][1][1]=n*m;
	for(int i=1; i<n*m; ++i){
		for(int j=1; j<=n; ++j)
			for(int k=1; k<=m; ++k){
				update(f[i+1][j][k], (ll)(j*k-i)*f[i][j][k]);
				update(f[i+1][j+1][k], (ll)(n-j)*k*f[i][j][k]);
				update(f[i+1][j][k+1], (ll)(m-k)*j*f[i][j][k]);
			}
	}
	return printf("%d\n", f[n*m][n][m]), 0;
}
