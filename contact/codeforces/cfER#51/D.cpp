#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e3+5;
const ll mod=998244353;
ll f[MAXN][2*MAXN][5];
int n,k;
int main(){
	cin>>n>>k;
	f[1][1][0]=f[1][1][3]=1;
	f[1][2][1]=f[1][2][2]=1;
	for (int i=2;i<=n;i++){
		for (int j=1;j<=k;j++){
			f[i][j][0]=(f[i][j][0]+f[i-1][j][2]+f[i-1][j][1]+f[i-1][j][0]+f[i-1][j-1][3])%mod;
			if (j>1) f[i][j][1]=(f[i][j][1]+f[i-1][j-1][3]+f[i-1][j-1][0]+f[i-1][j][1]+f[i-1][j-2][2])%mod;
			if (j>1) f[i][j][2]=(f[i][j][2]+f[i-1][j-1][3]+f[i-1][j-2][1]+f[i-1][j-1][0]+f[i-1][j][2])%mod;
			f[i][j][3]=(f[i][j][3]+f[i-1][j][2]+f[i-1][j][1]+f[i-1][j][3]+f[i-1][j-1][0])%mod;
//			cout<<i<<" "<<j<<" "<<f[i][j][0]<<" "<<f[i][j][1]<<" "<<f[i][j][2]<<" "<<f[i][j][3]<<endl;
		}
	}
	cout<<(f[n][k][0]+f[n][k][1]+f[n][k][2]+f[n][k][3])%mod<<endl;
	return 0;
}
