#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=2e3+5;
ll f[MAXN][MAXN],pw[MAXN*MAXN];
ll C[MAXN][MAXN];
ll n,p;
int main(){
	scanf("%lld%lld",&n,&p);pw[0]=1;
	for (int i=1;i<=n*(n-1)/2;i++) pw[i]=pw[i-1]*2%p;
	for (int i=1;i<=n;i++){
		C[i][0]=C[i][i]=1;
		for (int j=1;j<i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%p;
	}
	for (int i=1;i<=n;i++){
		f[i][1]=pw[(i-1)*(i-2)/2];
		for (int j=2;j<i;j++)
			f[i][j]=(ll)f[j][j]*C[i-1][j-1]%p*pw[(i-j)*(i-j-1)/2]%p;
		f[i][i]=pw[(i-1)*i/2];
		for (int j=1;j<i;j++) f[i][i]=(f[i][i]-f[i][j])%p;
	}
	for (int i=1;i<=n;i++) printf("%lld\n",(f[n][i]+p)%p);
	return 0;
}
