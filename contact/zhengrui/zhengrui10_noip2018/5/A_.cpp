#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod=998244353;
const int MAXN=1e6+5;
ll f[25][MAXN];
int n,k;
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) f[1][i]=1;
	for (int i=2;i<=k;i++){
		for (int j=1;j<=n;j++){
			for (int k=1;k<=j-k;k++){
				f[i][j]=(f[i][j]+f[i-1][k])%mod;
			}
		}
	}
	printf("%lld\n",f[k][n]%mod);
	return 0;
}
