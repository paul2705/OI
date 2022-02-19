#include<cstdio> 
#include<iostream> 
#include<cstring> 
#include<cmath> 
#include<cctype> 
#include<algorithm> 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define interesting int
const int N=100;
int n,m,mod;
int f[N*N][N][N];
int main(){
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
	scanf("%d%d%d",&n,&m,&mod);
	f[1][1][1]=n*m;
	for(int i=2;i<=n*m;i++){
		for(int j=1;j<=n;j++){
			for(int k=(i-1)/j+1;k<=m;k++){
				f[i][j][k]=(1ll*f[i-1][j][k]*(j*k-i+1)+1ll*f[i-1][j-1][k]*k*(n-j+1)+1ll*f[i-1][j][k-1]*j*(m-k+1))%mod;
			}
		}
	}
	printf("%d",f[m*n][n][m]);
	return 0;
}
