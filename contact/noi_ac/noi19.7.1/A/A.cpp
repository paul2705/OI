#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=2e3+5;
const int mod=998244353;
int f[MAXN][MAXN],C[MAXN][MAXN];
int n,a[MAXN],s[MAXN];
int inv[MAXN],rfac[MAXN];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),s[a[i]]++;
	for (int i=n;i>=1;i--) s[i]+=s[i+1];
	inv[1]=1;
	for (int i=2;i<=n;i++) inv[i]=(ll)inv[mod%i]*(ll)(mod-mod/i)%mod;
	rfac[1]=1; rfac[0]=1;
	for (int i=2;i<=n;i++) rfac[i]=(ll)rfac[i-1]*(ll)inv[i]%mod;
	for (int i=0;i<=n;i++) C[0][i]=1;
	for (int i=0;i<=n;i++){
		C[i][0]=C[i][i]=1;
		for (int j=1;j<i;j++){
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
		}
//		for (int j=0;j<=i;j++) cout<<C[i][j]<<" ";
//		cout<<endl;
	}
	for (int i=1;i<=n+1;i++) f[i][0]=1;
	for (int i=n;i>=1;i--){
		for (int j=1;j<=s[i];j++){
			int ret=1;
			for (int k=0;k<=(j/i);k++){
//				cout<<": "<<i<<" "<<j<<" "<<k<<endl;
				ret=(ll)ret*(ll)C[i*k][i]%mod;
				f[i][j]=(f[i][j]+(ll)C[s[i]-j+i*k][i*k]*(ll)ret%mod*(ll)rfac[k]%mod*(ll)f[i+1][j-i*k]%mod)%mod;
			}
//			cout<<i<<" "<<j<<" "<<f[i][j]<<endl;
		}
	}
	printf("%d\n",f[1][n]);
	return 0;
}
