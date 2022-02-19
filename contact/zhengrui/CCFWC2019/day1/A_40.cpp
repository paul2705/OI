#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e2+5;
ll f[MAXN][MAXN][MAXN];
ll n,m,s,p;
ll pow[MAXN];
int main(){
	scanf("%lld%lld%lld%lld",&n,&m,&s,&p);
	pow[0]=1;
	for (int i=1;i<=max(n,m);i++) pow[i]=pow[i-1]*(s+1)%p;
	f[1][1][0]=1;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			for (int k=0;k<=s;k++){
				for (int l=0;l<=k;l++){
					if (j>1){
						if (i==n) f[i][j][k]=(f[i][j][k]+f[i][j-1][k-l])%p;
						else f[i][j][k]=(f[i][j][k]+f[i][j-1][k-l]*(l+1)%p*pow[n-i-1]%p)%p;
					}
					if (i>1){
						if (j==m) f[i][j][k]=(f[i][j][k]+f[i-1][j][k-l])%p;
						else f[i][j][k]=(f[i][j][k]+f[i-1][j][k-l]*l%p*pow[m-j-1]%p)%p;
					}
				}
			}
		}
	}
	printf("%lld\n",f[n][m][s]);
	return 0;
}

